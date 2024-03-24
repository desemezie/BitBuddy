//
// Created by Ryan Hecht  on 2024-03-24.
//

#ifndef SHOPWINDOW_H
#define SHOPWINDOW_H

#include <QLabel>
#include <QListWidget>
#include <QPushButton>
#include <QWidget>

class ShopWindow final : public QWidget {
  Q_OBJECT

 public:
  explicit ShopWindow(QWidget *parent = nullptr);

 private slots:
  void onBuyButtonClicked();

 private:
  QListWidget *gameListWidget;
  QPushButton *buyButton;
  QLabel *titleLabel;
};

#endif  // SHOPWINDOW_H
