//
// Created by Ryan Hecht  on 2024-02-25.
//

#ifndef BITBUDDY_MAINWINDOW_H
#define BITBUDDY_MAINWINDOW_H


#include <QMainWindow>


class MainWindow : public QMainWindow {
Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

    MainWindow(const MainWindow &) = delete;

    MainWindow &operator=(const MainWindow &) = delete;

    MainWindow(MainWindow &&) = delete;

    MainWindow &operator=(MainWindow &&) = delete;


};


#endif //BITBUDDY_MAINWINDOW_H
