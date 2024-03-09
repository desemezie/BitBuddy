//
// Created by Ryan Hecht  on 2024-02-25.
//

#include <QApplication>
#include <QGridLayout>
#include "MainWindow.h"
#include "model/BitBuddyAttributeName.h"
#include "component/BitBuddyStatusWidget.h"
#include "component/BitBuddyWidget.h"
#include "component/BitBuddyActionButton.h"
#include "service/EventDispatcherService.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    auto *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    resize(1280, 720);

    // Grid layout for the central widget
    auto *layout = new QGridLayout(centralWidget);
    centralWidget->setLayout(layout);

    // connect spriteHandler to bitbuddy
    spriteLabel = new QLabel(centralWidget);
    spriteHandler = new BitBuddySpriteHandler(spriteLabel, this);


    auto *bitBuddyWidget = new BitBuddyWidget("BitBuddy", this);

    auto *statusWidget = new BitBuddyStatusWidget(bitBuddyWidget, this);

    // Create spacers to push the status widget to the top-left corner
    auto *verticalSpacer = new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);
    //spriteLabel = new QLabel(centralWidget);
    QImage image("/Users/annabelirani/Desktop/3307repo/group17/assets/happy_bitbuddy.png");

    if (image.isNull()) {
        qDebug() << "Failed to load the image.";
    } else {

        QSize imageSize(400,400);

        QPixmap pixmap = QPixmap::fromImage(image.scaled(imageSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));

        if (!pixmap.isNull()) {
            //spriteLabel->setFixedSize(400,400);
            spriteLabel->setPixmap(pixmap);

            qDebug() << "Hooray!";
        } else {

            qDebug() << "Failed to create a pixmap from image.";
        }
    }


    layout->addWidget(statusWidget, 0, 0, Qt::AlignTop | Qt::AlignLeft);
    layout->addItem(verticalSpacer, 1, 0, 1, 2);

    // Setting button icon
    QIcon buttonIcon("./thumb.png");

    QHBoxLayout * rowLayout1 = new QHBoxLayout;
    QHBoxLayout * rowLayout2 = new QHBoxLayout;

    std::string buttonNames[8] = {"feed", "clean", "discipline", "play", "blah", "blah", "blah", "blah "};
    for (int i = 0; i < NUMBER_OF_ATTRIBUTES; i++) {
        auto attribute = static_cast<BitBuddyAttributeName::UniqueName>(i);
        auto *but = new BitBuddyActionButton(buttonIcon, QString::fromStdString(BitBuddyAttributeName::toString(attribute)), attribute, centralWidget);
        if (i < 4){
            rowLayout1->addWidget(but);
        } else{
            rowLayout2->addWidget(but);
        }



    }

    rowLayout1->setSpacing(0);
    rowLayout2->setSpacing(0);
    layout->addWidget(spriteLabel, 0, 0, 2, 2, Qt::AlignCenter);
    layout->addLayout(rowLayout1, 2, 0, 2, 2);
    layout->addLayout(rowLayout2, 4, 0, 2, 2);

    layout->setAlignment(Qt::AlignBottom);
    connect(&EventDispatcherService::getInstance(), &EventDispatcherService::eventDispatched,
            spriteHandler, &BitBuddySpriteHandler::handleEvent);


}

MainWindow::~MainWindow() = default;
