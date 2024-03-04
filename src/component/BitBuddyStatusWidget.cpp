//
// Created by Ryan Hecht  on 2024-03-04.
//

#include "component/BitBuddyStatusWidget.h"
#include "service/EventDispatcherService.h"
#include "model/SingleAttributeEvent.h"

#include <QVBoxLayout>
#include <iostream>

const int LABEL_WIDTH = 80;
const int PROGRESS_BAR_WIDTH = 120;
const int PLACE_HOLDER_ATTRIBUTE_MAX = 10; // Placeholder max value for the progress bar

/**
 * REBUILD THIS WHEN DANIEL IS FINISHED!!!!
 */
BitBuddyStatusWidget::BitBuddyStatusWidget(QWidget *parent) : QWidget(parent) {
  auto *layout = new QVBoxLayout(this);
  layout->setAlignment(Qt::AlignTop);

  for (int attr = static_cast<int>(BitBuddyAttribute::Attribute::HUNGER);
       attr <= static_cast<int>(BitBuddyAttribute::Attribute::HYGIENE); ++attr) {

    auto attribute = static_cast<BitBuddyAttribute::Attribute>(attr);

    // Create a horizontal layout for the label and the progress bar
    auto *hLayout = new QHBoxLayout();
    auto *label = new QLabel(QString::fromStdString(BitBuddyAttribute::toString(attribute)), this);
    label->setFixedWidth(LABEL_WIDTH);
    hLayout->addWidget(label);

    // Create and configure the progress bar
    auto *bar = new QProgressBar(this);
    bar->setFixedWidth(PROGRESS_BAR_WIDTH);
    bar->setRange(0, PLACE_HOLDER_ATTRIBUTE_MAX);
    hLayout->addWidget(bar);

    layout->addLayout(hLayout); // Add the horizontal layout to the main vertical layout

    attributeBars.insert(attribute, bar);
    setAttributeLevel(attribute, PLACE_HOLDER_ATTRIBUTE_MAX);
  }

  EventDispatcherService::getInstance().registerListener(this);
}

void BitBuddyStatusWidget::setAttributeLevel(BitBuddyAttribute::Attribute attribute, int level) {
  if (attributeBars.contains(attribute)) {
    attributeBars[attribute]->setValue(level);
  }
}

void BitBuddyStatusWidget::onEvent(const Event &event) {
  std::cout << "BitBuddyStatusWidget received an event!" << std::endl;
  const auto *specificEvent = dynamic_cast<const SingleAttributeEvent *>(&event);
  if (specificEvent) {
    auto attribute = specificEvent->getAttribute();
    auto currentLevel = attributeBars[attribute]->value();
    setAttributeLevel(attribute, currentLevel + specificEvent->getIncrement());
  }
}