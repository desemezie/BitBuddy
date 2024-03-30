//
// Created by Ryan Hecht  on 2024-03-24.
//

#ifndef BITBUDDY_GAME_SRC_BITBUCKGENERATOR_H_
#define BITBUDDY_GAME_SRC_BITBUCKGENERATOR_H_

#include <QObject>
#include <QTimer>

constexpr int BIT_BUCK_GENERATION_INTERVAL_MS = 1000;  // 1000 milliseconds = 1 second
constexpr int MIN_BIT_BUCKS_GENERATED_PER_TIME_INTERVAL = 1;

/**
 * @class BitBuckGenerator
 * @brief Generates BitBucks at a set interval and emits a signal when they are generated
 * @author Ryan Hecht
 *
 * A BitBuckGenerator generates BitBucks at a set interval and emits a signal when they are generated. The number of
 * BitBucks generated and the interval at which they are generated can be set ('upgrade'), but have default constants
 * that they start at. The BitBuckGenerator can be paused and started and is paused by default.
 */
class BitBuckGenerator final : public QObject {
  Q_OBJECT

 public:
  /**
   * @brief Constructor for the BitBuckGenerator
   *
   * @param bitBucketsGeneratedPerTimeInterval The number of BitBucks generated per time interval
   * @param parent The parent object of the BitBuckGenerator
   */
  explicit BitBuckGenerator(int bitBucketsGeneratedPerTimeInterval = MIN_BIT_BUCKS_GENERATED_PER_TIME_INTERVAL,
                            QObject *parent = nullptr);

  BitBuckGenerator(const BitBuckGenerator &) = delete;
  BitBuckGenerator &operator=(const BitBuckGenerator &) = delete;
  BitBuckGenerator(BitBuckGenerator &&) = delete;
  BitBuckGenerator &operator=(BitBuckGenerator &&) = delete;

  /**
   * @brief Gets the number of BitBucks generated per time interval
   *
   * @return The number of BitBucks generated per time interval
   */
  [[nodiscard]] int getBitBucksGeneratedPerTimeInterval() const;

  /**
   * @brief Sets the number of BitBucks generated per time interval
   *
   * @param bitBucksGeneratedPerTimeInterval The number of BitBucks generated per time interval
   */
  void setBitBucksGeneratedPerTimeInterval(int bitBucksGeneratedPerTimeInterval);

  /**
   * @brief Pauses the generation of BitBucks
   */
  void pauseGeneration();

  /**
   * @brief Starts the generation of BitBucks
   */
  void startGeneration();

  /**
   * @brief Converts the BitBuckGenerator to a JSON object
   * @details Converts the BitBuckGenerator to a JSON object that can be saved to a file. The JSON object contains the
   * number of BitBucks generated per time interval.
   *
   * @return The BitBuckGenerator as a JSON object
   */
  [[nodiscard]] QJsonObject toJson() const;

  /**
   * @brief Converts a JSON object to a BitBuckGenerator
   * @details Converts a JSON object to a BitBuckGenerator. The JSON object should contain the number of BitBucks
   * generated per time interval.
   *
   * @param bitBuckGeneratorJson The JSON object to convert to a BitBuckGenerator
   * @return The BitBuckGenerator created from the JSON object
   */
  [[nodiscard]] static BitBuckGenerator *fromJson(const QJsonObject &bitBuckGeneratorJson);

 signals:
  /**
   * @brief Signal emitted when BitBucks are generated
   *
   * @param bitBucks The number of BitBucks generated
   */
  void bitBucksGenerated(int bitBucks);

 private:
  int bitBucksGeneratedPerTimeInterval;
  QTimer generationTimer;

 private slots:
  /**
   * @brief Generates the BitBucks and emits the bitBucksGenerated signal
   */
  void generateBitBucks();
};

#endif  // BITBUDDY_GAME_SRC_BITBUCKGENERATOR_H_
