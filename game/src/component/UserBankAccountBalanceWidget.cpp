//
// Created by Ryan Hecht  on 2024-03-24.
//

#include "component/UserBankAccountBalanceWidget.h"
#include "model/UserBankAccount.h"
#include "service/UserBankAccountService.h"
#include <QVBoxLayout>
#include <QFontDatabase>

const QString LABEL_FONT = ":/assets/fonts/ARCADECLASSIC.TTF";

UserBankAccountBalanceWidget::UserBankAccountBalanceWidget(QWidget *parent)
    : QWidget(parent), balanceLabel(new QLabel(this)) {

  int id = QFontDatabase::addApplicationFont(LABEL_FONT);
  QStringList fontFamilies = QFontDatabase::applicationFontFamilies(id);
  if (fontFamilies.isEmpty()) {
    qWarning() << "Failed to load font from" << LABEL_FONT;
  } else {
    const QString &family = fontFamilies.at(0);
    QFont retroFont(family, 32, QFont::Bold);
    balanceLabel->setFont(retroFont);
  }

  QVBoxLayout *layout = new QVBoxLayout(this);
  layout->addWidget(balanceLabel);
  setLayout(layout);

  // Attempt to connect to the UserBankAccount signal
  try {
    connect(&UserBankAccountService::getUserBankAccount(),
            &UserBankAccount::bankAccountUpdated,
            this,
            &UserBankAccountBalanceWidget::updateBalanceDisplay);

    // Initialize the display with the current balance
    updateBalanceDisplay(UserBankAccountService::getUserBankAccount().getBalance());
  } catch (const std::runtime_error &e) {
    balanceLabel->setText("Account not available");
  }
}

void UserBankAccountBalanceWidget::updateBalanceDisplay(int newBalance) {
  balanceLabel->setText(QString("Balance: %1").arg(newBalance));
}
