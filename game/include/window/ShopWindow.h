//
// Created by Ryan Hecht  on 2024-03-24.
//

#ifndef SHOPWINDOW_H
#define SHOPWINDOW_H

#include <QLabel>
#include <QListWidget>
#include <QPushButton>
#include <QWidget>
#include "model/BitBuddy.h"

class ShopWindow final : public QWidget {
  Q_OBJECT
  void setBitBuddy(BitBuddy *bitBuddy);

  BitBuddy *bitBuddy;

 public:
  explicit ShopWindow(QWidget *parent = nullptr);

 private slots:
  void onBuyButtonClicked();

 private:
  QListWidget *gameListWidget;
  QPushButton *buyButton;
  QLabel *titleLabel;

  void addListItem(QString *name, QListWidget *parentWidget, QString &icon);
  void addItem(const QString &name, const QString &iconPath);
  void showItemsPurchased();
};

#endif  // SHOPWINDOW_H
