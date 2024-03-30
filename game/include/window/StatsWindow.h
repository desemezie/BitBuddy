//
// Created by Shaylan Pratt on 2024-03-22.
//

#ifndef BITBUDDY_INCLUDE_STATSWINDOW_H_
#define BITBUDDY_INCLUDE_STATSWINDOW_H_

#include <QDialog>
#include <QLabel>


/**
 * @class StatsWindow
 * @brief The StatsWindow class provides a dialog to display statistics or information.
 * @author Shaylan Pratt
 *
 * This dialog is designed to show specific details, such as name and age, which can be expanded
 * to include more statistics as required.
 */
class StatsWindow : public QDialog {
 Q_OBJECT

 public:
  /**
  * @brief Construct a new Stats Window object.
  *
  * Initializes the dialog with the given name and sets up the UI elements.
  *
  * @param thename The name to be displayed in this stats window.
  * @param parent The parent widget of this dialog. Default is nullptr.
  */
  explicit StatsWindow(const QString &thename, QWidget *parent = nullptr);
  /**
    * @brief Destroy the Stats Window object.
    *
    * Ensures that resources are cleaned up properly.
    */
  ~StatsWindow();

 private:
  QLabel *nameLabel; ///< Label for displaying the name.
  QLabel *ageLabel; ///< Label for displaying the age
  QString name;  ///< Stores the name to be displayed.
  /**
   * @brief Sets up the user interface of the stats window.
   *
   * This method initializes all UI components, including labels for name and age, and positions them
   * within the window.
   */
  void setupUi();

};

#endif //BITBUDDY_INCLUDE_STATSWINDOW_H_