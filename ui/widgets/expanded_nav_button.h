// Copyright (c) 2016 Deepin Ltd. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef DEEPIN_INSTALLER_REBORN_UI_WIDGETS_EXPANDED_NAV_BUTTON_H
#define DEEPIN_INSTALLER_REBORN_UI_WIDGETS_EXPANDED_NAV_BUTTON_H

#include "ui/widgets/flat_button.h"

namespace ui {

// Resizable NavButton.
class ExpandedNavButton : public FlatButton {
  Q_OBJECT

 public:
  ExpandedNavButton(const QString& text, QWidget* parent = nullptr);
};

}  // namespace ui

#endif  // DEEPIN_INSTALLER_REBORN_UI_WIDGETS_EXPANDED_NAV_BUTTON_H
