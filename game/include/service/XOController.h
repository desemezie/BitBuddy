//
// Created by razvan on 31/03/24.
//

#ifndef BITBUDDY_XOCONTROLLER_H
#define BITBUDDY_XOCONTROLLER_H
// My Stuff
#include "window/BoardWindow.h"
#include "model/board.h"
#include "window/TieWindow.h"
#include "window/BuddyWindow.h"


#include <QApplication>
#include <cmath>
#include <unistd.h>
#include <QTimer>

class XOController
{
 public:
  XOController();
  int run();
};

#endif  // BITBUDDY_XOCONTROLLER_H
