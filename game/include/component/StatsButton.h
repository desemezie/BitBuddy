//
// Created by Shaylan Pratt on 2024-03-22.
//

#ifndef BITBUDDY_INCLUDE_COMPONENT_STATSBUTTON_H_
#define BITBUDDY_INCLUDE_COMPONENT_STATSBUTTON_H_

#include <QPushButton>
#include <QIcon>

/**
 * @class StatsButton
 * @brief The StatsButton class extends QPushButton to provide a button specifically for showing statistics.
 * @author Shaylan Pratt
 *
 * This button is designed to trigger the display of statistics or information relevant to the application's context.
 * It can be customized with an image representing its function and is intended to interact with other parts of the application
 * to display statistical data when clicked.
 */
class StatsButton: public QPushButton{
 Q_OBJECT

 public:

  /**
 * @brief Construct a new Stats Button object.
 *
 * Initializes the button with default styling and connects the click event to the slot handling the statistics display.
 *
 * @param parent The parent widget of this button. Default is nullptr.
 */
  explicit StatsButton(QWidget *parent = nullptr );


 private slots:

  /**
 * @brief Slot that handles the button's click event for showing statistics.
 *
 * When clicked, this slot triggers the necessary actions to display the relevant statistical data.
 */
  void statsClicked();


 private:

  /**
 * @brief Sets the button's image.
 *
 * This method allows for the customization of the button's appearance by setting an image indicative of its purpose.
 *
 * @param imagePath The path to the image file to be displayed on the button.
 */

  void setImage(QString);

  /**
 * @brief Updates the button's appearance or state.
 *
 * This method can be used to refresh the button's visual appearance or to perform any necessary updates to its state.
 */
  void update();


 signals:

  /**
 * @brief Signal emitted to indicate that statistics should be displayed.
 *
 * This signal should be connected to the appropriate slot in the application that handles the display of statistical data.
 */
  void showStats();




};

#endif //BITBUDDY_INCLUDE_COMPONENT_STATSBUTTON_H_