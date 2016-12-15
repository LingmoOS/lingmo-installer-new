// Copyright (c) 2016 Deepin Ltd. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef INSTALLER_UI_WIDGETS_TOOLTIP_CONTAINER_H
#define INSTALLER_UI_WIDGETS_TOOLTIP_CONTAINER_H

#include <QFrame>
class QKeyEvent;
class QListView;
class QPaintEvent;
class QStringListModel;

namespace installer {

// Used to display popup menu with sharp corner at middle of bottom edge.
class PopupMenu : public QFrame{
  Q_OBJECT

 public:
  explicit PopupMenu(QWidget* parent = nullptr);

  // Returns the list used by menu_model to store menu items.
  QStringList stringList() const;

 signals:
  // Emitted when window is hidden.
  void onHide();

  // Emitted when a menu item at |index| is activated.
  void menuActivated(int index);

 public slots:
  // Show tooltip container at |pos| and grab keyboard focus.
  void popup(const QPoint& pos);

  // Set menu models's internal list to |strings|.
  void setStringList(const QStringList& strings);

 protected:
  // Release keyboard focus when window is hidden.
  void hideEvent(QHideEvent* event) override;

  // Hide window when Escape button is pressed.
  void keyPressEvent(QKeyEvent* event) override;

  void paintEvent(QPaintEvent* event) override;

 private:
  void initConnections();
  void initUI();

  QListView* menu_view_ = nullptr;
  QStringListModel* menu_model_ = nullptr;

 private slots:
  void onMenuViewActivated(const QModelIndex& index);
};

}  // namespace installer

#endif  // INSTALLER_UI_WIDGETS_TOOLTIP_CONTAINER_H