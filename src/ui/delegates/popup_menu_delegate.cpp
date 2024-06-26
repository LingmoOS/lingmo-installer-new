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

#include "ui/delegates/popup_menu_delegate.h"

#include <QPainter>

namespace installer {

namespace {

const int kBorderRadius = 5;
const int kBorderDiameter = kBorderRadius * 2;

}  // namespace

PopupMenuDelegate::PopupMenuDelegate(QWidget* parent)
    : QStyledItemDelegate(parent) {
  this->setObjectName("popup_menu_delegate");
}

void PopupMenuDelegate::paint(QPainter* painter,
                              const QStyleOptionViewItem& option,
                              const QModelIndex& index) const {
  painter->save();

  const QRect& rect(option.rect);

  if (option.state & QStyle::State_MouseOver) {
    // Draw background color of selected item, no matter it is active or not.
    // #2ca7f8
    const QColor selected_color = QColor::fromRgb(44, 167, 248);
    painter->fillRect(rect, QBrush(selected_color));
  }

  // Draw text. Default color is #303030.
  QColor text_color = QColor::fromRgb(48, 48, 48);
  if (option.state & QStyle::State_MouseOver) {
    // Change text color to white on mouse hover.
    text_color = Qt::white;
  }
  painter->setPen(QPen(text_color));
  const QString text = index.model()->data(index, Qt::DisplayRole).toString();

  // Text alignment is center.
  painter->drawText(rect, Qt::AlignHCenter | Qt::AlignVCenter, text);

  painter->restore();
}

}  // namespace installer