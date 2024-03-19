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

#include "ui/delegates/install_slide_frame_util.h"

#include "third_party/googletest/include/gtest/gtest.h"

namespace installer {
namespace {

TEST(InstallSlideFrameUtil, GetSlideDir) {
  EXPECT_TRUE(GetSlideDir("zh_CN").endsWith("zh_CN"));
  EXPECT_TRUE(GetSlideDir("ru_RU").endsWith("default"));
}

TEST(InstallSlideFrameUtil, GetSlideFiles) {
  EXPECT_FALSE(GetSlideFiles("en_US").isEmpty());
  EXPECT_FALSE(GetSlideFiles("zh_CN").isEmpty());
}

}  // namespace
}  // namespace installer