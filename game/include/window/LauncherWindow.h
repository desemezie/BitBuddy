//
// Created by Annabel Irani on 2024-03-10.
//

#ifndef BITBUDDY_GROUP17_SRC_LAUNCHERWINDOW_H_
#define BITBUDDY_GROUP17_SRC_LAUNCHERWINDOW_H_

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

class LauncherWindow : public QWidget{
  Q_OBJECT

 public:
  explicit LauncherWindow(QWidget *parent = nullptr);

  void addImages();

 private:
  QLineEdit *nameLineEdit;
};

#endif //BITBUDDY_GROUP17_SRC_LAUNCHERWINDOW_H_
