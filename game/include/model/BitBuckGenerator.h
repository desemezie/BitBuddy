//
// Created by Ryan Hecht  on 2024-03-24.
//

#ifndef BITBUDDY_GAME_SRC_BITBUCKGENERATOR_H_
#define BITBUDDY_GAME_SRC_BITBUCKGENERATOR_H_

#include <QObject>
#include <QTimer>

constexpr int BIT_BUCK_GENERATION_INTERVAL_MS = 1000; // 1000 milliseconds = 1 second
constexpr int MIN_BIT_BUCKS_GENERATED_PER_TIME_INTERVAL = 1;

class BitBuckGenerator : public QObject {
 Q_OBJECT

 public:
  explicit BitBuckGenerator(int bitBucketsGeneratedPerTimeInterval = MIN_BIT_BUCKS_GENERATED_PER_TIME_INTERVAL,
                            QObject *parent = nullptr);

  BitBuckGenerator(const BitBuckGenerator &) = delete;
  BitBuckGenerator &operator=(const BitBuckGenerator &) = delete;
  BitBuckGenerator(BitBuckGenerator &&) = delete;
  BitBuckGenerator &operator=(BitBuckGenerator &&) = delete;

  [[nodiscard]] int getBitBucksGeneratedPerTimeInterval() const;

  void setBitBucksGeneratedPerTimeInterval(int bitBucksGeneratedPerTimeInterval);

  [[nodiscard]] QJsonObject toJson() const;

  static BitBuckGenerator *fromJson(const QJsonObject &bitBuckGeneratorJson);

 signals:
  void bitBucksGenerated(int bitBucks);

 private:
  int bitBucksGeneratedPerTimeInterval;
  QTimer generationTimer;

 private slots:
  void generateBitBucks();

};

#endif //BITBUDDY_GAME_SRC_BITBUCKGENERATOR_H_
