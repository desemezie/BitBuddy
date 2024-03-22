//
// Created by Shaylan Pratt on 2024-03-22.
//

#ifndef BITBUDDY_INCLUDE_STATSWINDOW_H_
#define BITBUDDY_INCLUDE_STATSWINDOW_H_

#include <QDialog>
#include <QLabel>

class StatsWindow : public QDialog {
 Q_OBJECT

 public:
  explicit StatsWindow(const QString &name, QWidget *parent = nullptr);
  ~StatsWindow();

 private:
  QLabel *nameLabel;
  QLabel *ageLabel;
  QString name;
  void setupUi();
};

#endif //BITBUDDY_INCLUDE_STATSWINDOW_H_
