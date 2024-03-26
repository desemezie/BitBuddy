//
// Created by Ryan Hecht  on 2024-03-04.
//

#ifndef BITBUDDY_SRC_COMPONENT_BITBUDDY_H_
#define BITBUDDY_SRC_COMPONENT_BITBUDDY_H_

#include <QObject>
#include <map>
#include "model/BitBuddyAttribute.h"
#include "model/Event.h"
#include "BitBuckGenerator.h"
#include <QUuid>

constexpr int IN_GAME_YEAR_LENGTH_IN_MINUTES = 1; // 1 minute represents 1 in-game year

/**
 * Bit Buddy!
 */
class BitBuddy : public QObject {
    Q_OBJECT

 public:
    /**
     * Constructor for the BitBuddy. Initializes the attribute maps.
     *
     * @param name The name of the BitBuddy
     * @param parent The parent widget of the BitBuddy, typically the MainWindow.
     */
    explicit BitBuddy(std::string name);

    /**
     * Constructor for the BitBuddy that takes all of BitBuddy's attributes as parameters.
     *
     * @param name The name of the BitBuddy
     * @param parent The parent widget of the BitBuddy, typically the MainWindow.
     * @param attributes A map of the BitBuddy's attributes where the key is the attribute's unique name and the value is the attribute
     * @param creationTime The time the BitBuddy was created
     * @param dead Whether the BitBuddy is dead
     * @param id The unique identifier of the BitBuddy
     * @param bitBuckGenerator The BitBuckGenerator that generates BitBucks for the BitBuddy
     */
    BitBuddy(std::string name, const std::map<BitBuddyAttributeName::UniqueName, BitBuddyAttribute> &attributes,
             std::chrono::system_clock::time_point creationTime, bool dead, QUuid id,
             BitBuckGenerator *bitBuckGenerator);

    /**
     * Destructor for the BitBuddy
     */
    ~BitBuddy() override;

    BitBuddy(const BitBuddy &) = delete;
    BitBuddy &operator=(const BitBuddy &) = delete;
    BitBuddy(BitBuddy &&) = delete;
    BitBuddy &operator=(BitBuddy &&) = delete;
    void addItemPurchased(const std::string &itemName);

    std::vector<std::string> thingsPurchased;
    [[nodiscard]] const std::vector<std::string>& getPurchasedItems() const;

    /**
     * Converts the BitBuddy to a JSON object
     *
     * @return The BitBuddy as a JSON object
     */
    [[nodiscard]] QJsonObject toJson() const;

    /**
     * Converts a JSON object to a BitBuddy
     *
     * @param json The JSON object to convert
     * @return The BitBuddy
     */
    static BitBuddy *fromJson(const QJsonObject &json);

    /**
     * Gets the attribute value for the given attribute name
     *
     * @param attributeName The name of the attribute to get the value for
     * @return The value of the attribute
     */
    [[nodiscard]] int getAttributeValue(BitBuddyAttributeName::UniqueName attributeName) const;

    /**
     * Increments the value of the attribute with the given value
     *
     * @param attribute
     * @param value
     */
    void incrementAttribute(BitBuddyAttributeName::UniqueName attribute, int value);

    /**
     * Gets the age of the BitBuddy represented in 'in-game-years'
     *
     * @return The age of the BitBuddy in 'in-game-years'
     */
    [[nodiscard]] long getAgeInGameYears() const;

    /**
     * @brief Gets the name of the BitBuddy
     *
     * @return The name of the BitBuddy
     */
    [[nodiscard]] std::string getName() const;

    /**
     * @brief Sets the name of the BitBuddy
     */
    void setName(std::string name);

    std::string currentSprite;

    /**
    * @brief Gets the bitbuddys current sprite
    * @return The bitbuddy sprite
    */
    [[nodiscard]] std::string getSprite() const;

    void setCurrentSprite(std::string name);
  signals:
    /**
     * Signal emitted when an attribute is updated
     *
     * @param attribute The attribute that was updated
     */
    void attributeUpdated(const BitBuddyAttribute &attribute);

    /**
     * Signal emitted when the BitBuddy dies
     *
     * @paragraph attribute The attribute that caused the BitBuddy to die
     */
    void died(const BitBuddyAttribute &attribute);

  public slots:
    /**
     * Slot that listens for Events from the event dispatch service and updates the BitBuddy's attributes.
     *
     * @param event The event to process
     */
    void onEvent(const Event &event);

  private:
    QUuid id;
    std::map<BitBuddyAttributeName::UniqueName, BitBuddyAttribute> attributes;
    std::chrono::system_clock::time_point creationTime;
    std::string name;
    bool dead;
    BitBuckGenerator *bitBuckGenerator;


    /**
     * Connects the signals to the slots
     */
    void connectSignals() const;

    /**
     * Kills the BitBuddy
     *
     * @param attribute The attribute that caused the BitBuddy to die
     */
    void die(const BitBuddyAttribute &attribute);

  const std::vector<std::string> &getItemsPurchased() const;
};

#endif //BITBUDDY_SRC_COMPONENT_BITBUDDY_H_