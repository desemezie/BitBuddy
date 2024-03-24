//
// Created by Ryan Hecht  on 2024-03-04.
//

#include "component/BitBuddyStatusWidget.h"
#include "service/EventDispatcherService.h"
#include "model/SingleAttributeEvent.h"
#include "model/BitBuddy.h"
#include "model/audio.h"

#include <QVBoxLayout>
#include <iostream>

const int LABEL_WIDTH = 80;
const int PROGRESS_BAR_WIDTH = 120;

BitBuddyStatusWidget::BitBuddyStatusWidget(BitBuddy *bitBuddy, QWidget *parent) : QWidget(parent) {
  auto *layout = new QVBoxLayout(this);
  layout->setAlignment(Qt::AlignTop);

  for (int attr = static_cast<int>(BitBuddyAttributeName::UniqueName::HUNGER);
       attr <= static_cast<int>(BitBuddyAttributeName::UniqueName::HYGIENE); ++attr) {
    auto attribute = static_cast<BitBuddyAttributeName::UniqueName>(attr);

    // Create a horizontal layout for the label and the progress bar
    auto *hLayout = new QHBoxLayout();
    auto *label = new QLabel(QString::fromStdString(BitBuddyAttributeName::toString(attribute)), this);
    label->setFixedWidth(LABEL_WIDTH);
    label->setStyleSheet("QLabel { color : black; }");//sets progress bar's color to black
    hLayout->addWidget(label);

    // Create and configure the progress bar
    auto *bar = new QProgressBar(this);
    bar->setFixedWidth(PROGRESS_BAR_WIDTH);
    bar->setRange(0, MAX_ATTRIBUTE_VALUE);
    hLayout->addWidget(bar);

    layout->addLayout(hLayout); // Add the horizontal layout to the main vertical layout

    attributeBars.insert(attribute, bar);
    setAttributeLevel(attribute, bitBuddy->getAttributeValue(attribute));
  }

  connect(bitBuddy, &BitBuddy::attributeUpdated, this, &BitBuddyStatusWidget::onAttributeUpdated);
}

void BitBuddyStatusWidget::setAttributeLevel(BitBuddyAttributeName::UniqueName attributeName, int level) {
  if (attributeBars.contains(attributeName)) {
    attributeBars[attributeName]->setValue(level);
  }
}

void BitBuddyStatusWidget::onAttributeUpdated(const BitBuddyAttribute &attribute) {
  std::cout << "BitBuddyWidget received an updated attribute: " <<
      BitBuddyAttributeName::toString(attribute.getAttributeName()) << " with value: " << attribute.getValue() <<
      std::endl;
  setAttributeLevel(attribute.getAttributeName(), attribute.getValue());
}

void BitBuddyStatusWidget::updateDarkMode(bool isDarkMode) {
  if (isDarkMode) {
    this->setStyleSheet("QLabel { color: white; }");
  } else {
    this->setStyleSheet("QLabel { color: black; }");
  }
}