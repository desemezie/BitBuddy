//
// Created by Ryan Hecht  on 2024-03-04.
//

#include "service/EventGeneratorService.h"

#include "model/BitBuddyEvents.h"

#include <random>
#include <chrono>
#include <iostream>

// Constants for event generation timing
constexpr int TARGET_MEAN_SECONDS = 10; // Target mean time for event generation
constexpr int TIME_SPREAD_SECONDS = 5; // Spread of time around the mean
constexpr int MIN_DELAY_SECONDS = 2;   // Minimum delay between events
constexpr int MAX_DELAY_SECONDS = 20;  // Maximum delay between events

EventGeneratorService &EventGeneratorService::getInstance() {
  static EventGeneratorService instance;
  return instance;
}

void EventGeneratorService::startService() {
  if (!running.load()) { // Check if the service is not already running
    running.store(true);
    eventGeneratorServiceThread = std::thread([this]() {
      std::mt19937 generator(std::random_device{}());
      // Normal distribution centered around TARGET_MEAN_SECONDS with a spread of TIME_SPREAD_SECONDS
      std::normal_distribution<> normalDistribution(TARGET_MEAN_SECONDS, TIME_SPREAD_SECONDS);

      while (running.load()) {
        generateEvent();

        // Generate a weighted random delay
        int delaySeconds = static_cast<int>(std::round(normalDistribution(generator)));
        // Clamp the delay between MIN_DELAY_SECONDS and MAX_DELAY_SECONDS
        delaySeconds = std::max(MIN_DELAY_SECONDS, std::min(delaySeconds, MAX_DELAY_SECONDS));

        std::this_thread::sleep_for(std::chrono::seconds(delaySeconds));
      }
    });
  }
}

void EventGeneratorService::stopService() {
  if (running.load()) {
    running.store(false);
    if (eventGeneratorServiceThread.joinable()) {
      eventGeneratorServiceThread.join();
    }
  }
}

EventGeneratorService::~EventGeneratorService() {
  stopService();
}

void EventGeneratorService::generateEvent() {
  std::mt19937 generator(std::random_device{}());

  // Extract probabilities from the predefined events
  std::vector<double> probabilities;
  probabilities.reserve(PREDEFINED_EVENTS.size());
  for (const auto &event : PREDEFINED_EVENTS) {
    probabilities.push_back(event.getProbability());
  }

  // Use the extracted probabilities for event distribution
  std::discrete_distribution<> eventDistribution(probabilities.begin(), probabilities.end());

  // Select a random event based on the distribution
  const auto &selectedEvent = PREDEFINED_EVENTS[eventDistribution(generator)];
  QMetaObject::invokeMethod(&EventDispatcherService::getInstance(),
                            "dispatchEvent",
                            Qt::QueuedConnection,
                            Q_ARG(const Event*, &selectedEvent));
}

