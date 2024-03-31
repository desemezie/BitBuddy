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
/**
 * @class ShowWindow
 * @brief Provides functionality to display a shop like window for the BitBuddy
 * @author Ryan Hecht, Annabel Irani
 *
 */
class ShopWindow final : public QWidget {
  Q_OBJECT
  /**
   * @brief Sets the unique bitbuddy for the ShowWindow
   * @param bitBuddy, sends in the BitBuddy instance
   */
  void setBitBuddy(BitBuddy *bitBuddy);

  BitBuddy *bitBuddy;

 public:

  /**
   * @class ShopWindow
   * @brief Constructor for the ShowWindow
   * @param parent, sends in the parent widget
   */
  explicit ShopWindow(QWidget *parent = nullptr);

 private slots:
  /**
   * @brief Function for functionality of "purchacing" and item
   */
  void onBuyButtonClicked();

  /**
   * private variables
   */
 private:
  QListWidget *gameListWidget;
  QPushButton *buyButton;
  QLabel *titleLabel;

  /**
   * @brief Used to add an item to the list
   * @param name - name of the object
   * @param parentWidget - parent widget is sent in
   * @param icon - icon path to set the icon
   */
  void addListItem(QString *name, QListWidget *parentWidget, QString &icon);
  /**
  * @brief Used to add an item to the list
  * @param name - name of the object
  * @param icon - icon path to set the icon
  */
  void addItem(const QString &name, const QString &iconPath);
  /**
   * @brief Function to display the bitbuddy's already purchased items
   */
  void showItemsPurchased();
};

#endif  // SHOPWINDOW_H
