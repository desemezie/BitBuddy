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
  if (!running.load()) {
    running.store(true);
    paused.store(false); // Make sure paused is false when starting
    eventGeneratorServiceThread = std::thread([this]() {
      std::mt19937 generator(std::random_device{}());
      std::normal_distribution<> normalDistribution(TARGET_MEAN_SECONDS, TIME_SPREAD_SECONDS);

      while (running.load()) {
        // Check if paused
        {
          std::unique_lock<std::mutex> lock(pauseMutex);
          pauseCondition.wait(lock, [this] { return !paused.load(); });
        }

        generateEvent();

        int delaySeconds = static_cast<int>(std::round(normalDistribution(generator)));
        delaySeconds = std::max(MIN_DELAY_SECONDS, std::min(delaySeconds, MAX_DELAY_SECONDS));
        std::this_thread::sleep_for(std::chrono::seconds(delaySeconds));
      }
    });
  } else if (paused.load()) { // If the service is running but paused, resume it
    resumeService();
  }
}

void EventGeneratorService::stopService() {
  paused.store(true);
}

EventGeneratorService::~EventGeneratorService() {
  running.store(false);
  resumeService(); // Ensure the thread isn't waiting on the condition variable
  if (eventGeneratorServiceThread.joinable()) {
    eventGeneratorServiceThread.join();
  }
}

void EventGeneratorService::resumeService() {
  paused.store(false);
  pauseCondition.notify_one();
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

