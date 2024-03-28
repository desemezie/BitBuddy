//
// Created by Annabel Irani on 2024-03-10.
//

/**
 * @class LauncherWindow
 * @author Annabel Irani
 * @brief LauncherWindow class is responsible for the initial landing page of the application
 */
#ifndef BITBUDDY_GROUP17_SRC_LAUNCHERWINDOW_H_
#define BITBUDDY_GROUP17_SRC_LAUNCHERWINDOW_H_

#include <QWidget>
#include <QPushButton>

class LauncherWindow : public QWidget{
  Q_OBJECT

 public:
  /**
   * @class LauncherWindow
   * @param parent - parent widget
   * @brief Constructor to launch the LauncherWindow instance
   */
  explicit LauncherWindow(QWidget *parent = nullptr);

  /**
   * @brief function to insert the image pattern
   */
  void addImages();
};

#endif //BITBUDDY_GROUP17_SRC_LAUNCHERWINDOW_H_
