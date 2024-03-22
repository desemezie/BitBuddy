//
// Created by Shaylan Pratt on 2024-03-22.
//

#ifndef BITBUDDY_INCLUDE_COMPONENT_STATSBUTTON_H_
#define BITBUDDY_INCLUDE_COMPONENT_STATSBUTTON_H_

#include <QPushButton>
#include <QIcon>

class StatsButton: public QPushButton{
 Q_OBJECT

 public:
  explicit StatsButton(QWidget *parent = nullptr);


 private slots:
  void statsClicked();


 private:
  void setImage(QString);
  void update();


 signals:
  void showStats();




};

#endif //BITBUDDY_INCLUDE_COMPONENT_STATSBUTTON_H_
