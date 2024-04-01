//
// Created by Ryan Hecht  on 2024-03-24.
//

#ifndef BITBUDDY_GAME_INCLUDE_COMPONENT_USERBANKACCOUNTBALANCEWIDGET_H_
#define BITBUDDY_GAME_INCLUDE_COMPONENT_USERBANKACCOUNTBALANCEWIDGET_H_

#include <QLabel>
#include <QWidget>

/**
 * @class UserBankAccountBalanceWidget
 * @brief Provides functionality to display the user's bank account balance
 * @author Ryan Hecht
 *
 * This widget displays the user's bank account balance in the game with a special arcade font.
 */
class UserBankAccountBalanceWidget final : public QWidget {
  Q_OBJECT

 public:
  /**
   * @brief Constructor for the UserBankAccountBalanceWidget
   *
   * @param parent The parent widget of the UserBankAccountBalanceWidget
   */
  explicit UserBankAccountBalanceWidget(QWidget *parent = nullptr);

 private slots:
  /**
   * @brief Updates the balance display with the new balance
   *
   * @param newBalance The new balance to display
   */
  void updateBalanceDisplay(int newBalance);

 private:
  QLabel *balanceLabel;
};

#endif  // BITBUDDY_GAME_INCLUDE_COMPONENT_USERBANKACCOUNTBALANCEWIDGET_H_
