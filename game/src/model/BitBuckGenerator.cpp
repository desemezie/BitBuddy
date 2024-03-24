//
// Created by Ryan Hecht  on 2024-03-24.
//

#include <QJsonObject>
#include "model/BitBuckGenerator.h"
#include "service/TransactionService.h"

BitBuckGenerator::BitBuckGenerator(int bitBucketsGeneratedPerTimeInterval, QObject *parent) : QObject(parent) {
  setBitBucksGeneratedPerTimeInterval(bitBucketsGeneratedPerTimeInterval);

  connect(&generationTimer, &QTimer::timeout, this, &BitBuckGenerator::generateBitBucks);
  connect(this,
          &BitBuckGenerator::bitBucksGenerated,
          &TransactionService::getInstance(),
          &TransactionService::payUserBitBucks);

  generationTimer.start(BIT_BUCK_GENERATION_INTERVAL_MS);;
}

int BitBuckGenerator::getBitBucksGeneratedPerTimeInterval() const {
  return bitBucksGeneratedPerTimeInterval;
}

void BitBuckGenerator::setBitBucksGeneratedPerTimeInterval(int bitBucksGeneratedPerTimeInterval) {
  qWarning() << "Setting bitBucksGeneratedPerTimeInterval to:" << bitBucksGeneratedPerTimeInterval;
  this->bitBucksGeneratedPerTimeInterval =
      std::max(bitBucksGeneratedPerTimeInterval, MIN_BIT_BUCKS_GENERATED_PER_TIME_INTERVAL);
}

QJsonObject BitBuckGenerator::toJson() const {
  QJsonObject bitBuckGeneratorObject;
  bitBuckGeneratorObject["bitBucksGeneratedPerTimeInterval"] = bitBucksGeneratedPerTimeInterval;
  return bitBuckGeneratorObject;
}

BitBuckGenerator *BitBuckGenerator::fromJson(const QJsonObject &bitBuckGeneratorJson) {
  try {
    return new BitBuckGenerator(bitBuckGeneratorJson["bitBucksGeneratedPerTimeInterval"].toInt());
  } catch (std::exception &error) {
    qWarning() << "Could not create BitBuckGenerator from JSON:" << error.what();

    return new BitBuckGenerator(MIN_BIT_BUCKS_GENERATED_PER_TIME_INTERVAL);
  }
}

void BitBuckGenerator::generateBitBucks() {
  emit bitBucksGenerated(bitBucksGeneratedPerTimeInterval);
}
