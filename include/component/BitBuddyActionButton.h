//
// Created by Annabel Irani on 2024-03-04.
//

#ifndef BITBUDDY_BITBUDDYACTIONBUTTON_H
#define BITBUDDY_BITBUDDYACTIONBUTTON_H


#include <QPushButton>
#include <QIcon>

class BitBuddyActionButton: public QPushButton{
    Q_OBJECT
public:
    BitBuddyActionButton(const QIcon &icon, const QString &text, QWidget *parent = nullptr);


};


#endif //BITBUDDY_BITBUDDYACTIONBUTTON_H
