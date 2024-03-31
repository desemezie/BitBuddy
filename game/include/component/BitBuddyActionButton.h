//
// Created by Annabel Irani on 2024-03-04.
//

#ifndef BITBUDDY_BITBUDDYACTIONBUTTON_H
#define BITBUDDY_BITBUDDYACTIONBUTTON_H

#include <QIcon>
#include <QPushButton>

#include "model/BitBuddyAttributeName.h"

/**
 * @class BitBuddyActionButton
 * @brief Inherits from QPushButton
 */

class BitBuddyActionButton : public QPushButton {
  Q_OBJECT


 public:
  /**
   * Constructor for the BitBuddyActionButton
   * @param icon Icon for the button
   * @param text Text for the button
   * @param attribute Attribute the button belongs to
   * @param parent The Parent of the button, parent widget
   */
  explicit BitBuddyActionButton(const QIcon &icon, const QString &text, BitBuddyAttributeName::UniqueName attribute,
                                QWidget *parent = nullptr);

  /**
   * setButtonStyle()
   * Function will set the stylesheet for the button
   */
  void setButtonStyle();

 private slots:
  /**
   * Function will be called to handle the button clicked
   */
  void handleButtonClicked();

 private:
  /**
   * Attribute that the button belongs to
   */
  BitBuddyAttributeName::UniqueName attribute;
};

#endif  // BITBUDDY_BITBUDDYACTIONBUTTON_H