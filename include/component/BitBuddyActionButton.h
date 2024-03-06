//
// Created by Annabel Irani on 2024-03-04.
//

#ifndef BITBUDDY_BITBUDDYACTIONBUTTON_H
#define BITBUDDY_BITBUDDYACTIONBUTTON_H


#include <QPushButton>
#include <QIcon>

class BitBuddyActionButton: public QPushButton{
    Q_OBJECT

    //BitBuddyActionButton(QIcon icon, const QString &text, BitBuddyAttributeName::UniqueName name, QWidget *pWidget);

public:
    explicit BitBuddyActionButton(const QIcon &icon, const QString &text,BitBuddyAttributeName::UniqueName attribute, QWidget *parent = nullptr);

private slots:
    void handleButtonClicked();

private:
    BitBuddyAttributeName::UniqueName attribute;

};


#endif //BITBUDDY_BITBUDDYACTIONBUTTON_H
