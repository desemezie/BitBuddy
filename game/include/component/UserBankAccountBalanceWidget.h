//
// Created by Ryan Hecht  on 2024-03-24.
//

#ifndef BITBUDDY_GAME_INCLUDE_COMPONENT_USERBANKACCOUNTBALANCEWIDGET_H_
#define BITBUDDY_GAME_INCLUDE_COMPONENT_USERBANKACCOUNTBALANCEWIDGET_H_

#include <QWidget>
#include <QLabel>

class UserBankAccountBalanceWidget : public QWidget {
 Q_OBJECT

 public:
  explicit UserBankAccountBalanceWidget(QWidget *parent = nullptr);

 private slots:
  void updateBalanceDisplay(int newBalance);

 private:
  QLabel *balanceLabel;
};

#endif //BITBUDDY_GAME_INCLUDE_COMPONENT_USERBANKACCOUNTBALANCEWIDGET_H_
