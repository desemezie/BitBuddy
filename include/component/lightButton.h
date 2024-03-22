//
// Created by Shaylan Pratt on 2024-03-21.
//

#ifndef BITBUDDY_INCLUDE_COMPONENT_LIGHTBUTTON_H_
#define BITBUDDY_INCLUDE_COMPONENT_LIGHTBUTTON_H_

#include <QPushButton>
#include <QIcon>

class lightButton: public QPushButton{
  Q_OBJECT

  public:
  explicit lightButton(QWidget *parent = nullptr);


private slots:
  void lightClicked();


 private:
  void setImage(QString);
  void update();
  bool isLightOn;

  signals:
   void themeChange(const QString& newStyle);
   void textChange(bool isDarkMode);



};

#endif //BITBUDDY_INCLUDE_COMPONENT_LIGHTBUTTON_H_
