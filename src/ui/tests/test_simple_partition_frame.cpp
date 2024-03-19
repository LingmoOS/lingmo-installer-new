/*
 * Copyright (C) 2017 ~ 2018 Lingmo Technology Co., Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <QApplication>
#include <QFrame>

#include "ui/delegates/simple_partition_delegate.h"
#include "ui/frames/inner/simple_partition_frame.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  QFrame window;
  installer::SimplePartitionDelegate delegate;
  installer::SimplePartitionFrame frame(&delegate, &window);
  delegate.scanDevices();
  window.resize(640, 480);
  window.show();
  window.setStyleSheet("background: transparent;");

  return app.exec();
}