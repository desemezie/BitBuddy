//
// Created by Shaylan Pratt on 2024-03-21.
//

#ifndef BITBUDDY_INCLUDE_COMPONENT_LIGHTBUTTON_H_
#define BITBUDDY_INCLUDE_COMPONENT_LIGHTBUTTON_H_

#include <QPushButton>

/**
 * @class LightButton
 * @brief The LightButton class extends QPushButton to provide a light-themed toggle button.
 * @author Shaylan Pratt
 *
 * This button is designed to toggle between two states, typically representing light and dark modes or turning a light-themed feature on and off.
 * It emits signals upon changing themes or text modes, allowing for broader application-level changes in response to its state.
 */

class LightButton : public QPushButton {
 Q_OBJECT

 public:

  /**
 * @brief Construct a new Light Button object.
 *
 * Initializes the button with default styling and connects the click signal to the slot handling the toggle logic.
 *
 * @param parent The parent widget of this button. Default is nullptr.
 */
  explicit LightButton(QWidget *parent = nullptr);

 private slots:

  /**
 * @brief Slot that handles the button's click event.
 *
 * Toggles the light state and updates the button's appearance and emitted signals accordingly.
 */
  void lightClicked();

 private:

  /**
 * @brief Sets the button's image based on the current state.
 *
 * @param imagePath The path to the image file that should be displayed on the button.
 */
  void setImage(QString);

  /**
 * @brief Updates the button's appearance and state.
 *
 * This method is called to refresh the button's visual appearance based on the current state and to emit appropriate signals.
 */

  void update();

  bool isLightOn; ///< Indicates whether the light mode is currently enabled.

 signals:

  /**
 * @brief Signal emitted when the theme should be changed.
 *
 * @param newStyle The new style or theme to be applied, typically "light" or "dark".
 */
  void themeChange(const QString &newStyle);

  /**
 * @brief Signal emitted to indicate a change in text mode, useful for adjusting text colors in dark/light modes.
 *
 * @param isDarkMode Indicates whether the text should be optimized for dark mode (true) or light mode (false).
 */
  void textChange(bool isDarkMode);


};

#endif //BITBUDDY_INCLUDE_COMPONENT_LIGHTBUTTON_H_