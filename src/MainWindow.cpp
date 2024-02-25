//
// Created by Ryan Hecht  on 2024-02-25.
//

#include <QApplication>
#include "MainWindow.h"

/**
 * @brief Constructor of the MainWindow.
 *
 * @param parent The parent widget of the MainWindow, typically the desktop.
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    auto *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
}

/**
 * @brief Destructor of the MainWindow.
 */
MainWindow::~MainWindow() = default;
