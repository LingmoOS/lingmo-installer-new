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

#ifndef INSTALLER_SETTINGS_MANAGER_H
#define INSTALLER_SETTINGS_MANAGER_H

#include <QDir>
#include <QString>
#include <QStringList>
#include <QVariant>

namespace installer {

// Get absolute path to oem/ folder. Note that oem folder may not exist.
QDir GetOemDir();

// Read settings value from ini file.

// Get boolean option value from settings file.
// If |key| does not exist, returns false.
bool GetSettingsBool(const QString& key);

// Get integer option value from settings file.
// If |key| does not exist, return 0.
int GetSettingsInt(const QString& key);

// Get string option value from settings file.
// If |key| does not exist, returns an empty string.
QString GetSettingsString(const QString& key);

// Get string list option value form settings file.
// Items in value are separated by ;
// If |key| does not exist, returns an empty string list.
QStringList GetSettingsStringList(const QString& key);

// Get variant option value from settings file.
QVariant GetSettingsValue(const QString& key);

// Returns absolute path to oem/auto_part.sh
QString GetAutoPartFile();

// Get all available avatars in avatar folder.
QStringList GetAvatars();

// Get default user avatar, is specified. Or else returns a random avatar.
QString GetDefaultAvatar();

// Get absolute path to oem hooks folder.
QString GetOemHooksDir();

// Get absolute path to oem check_hooks foler.
QString GetOemCheckHooksDir();

// Returns absolute path to reserved_usernames file.
QString GetReservedUsernameFile();

// Get vendor logo.
QString GetVendorLogo();

// Get image path of installer window background.
// First try to find installer background image in oem folder.
// If not found, use the fallback image.
QString GetWindowBackground();

// Append settings in |conf_file| into default conf file.
bool AppendConfigFile(const QString& conf_file);

// Operations of /etc/lingmo-installer.conf
bool DeleteConfigFile();

// Setup uefi mode or not.
void WriteUEFI(bool is_efi);
//void WriteInstallerMode(bool is_simple_mode);

// Get current locale.
QString ReadLocale();

QString GetUIDefaultFont();

void WriteAvatar(const QString& avatar);
void WriteHostname(const QString& hostname);
// Write keyboard model, layout and layout variant name.
void WriteKeyboard(const QString& model,
                   const QString& layout,
                   const QString& variant);
void WriteLocale(const QString& locale);
void WritePassword(const QString& password);
void WriteTimezone(const QString& timezone);
void WriteUsername(const QString& username);
void WriteFullDiskDeivce(const QString &deviceName);
void WriteFullDiskEncryptPassword(const QString &password);
void WritePasswordStrong(bool storePassword);
void WriteDisplayPort(const QString &display);
void WriteGrubPassword(const QString &password);

// Write disk info.
//  * |root_disk|, device path to install system into, like /dev/sda;
//  * |root_partition|, partition path to install system into;
//  * |boot_partition|, partition path to install grub into;
//  * |mount_point|, a list of partition path and mount-point info,
//    items are separated by ';'
void WritePartitionInfo(const QString& root_disk,
                        const QString& root_partition,
                        const QString& boot_partition,
                        const QString& mount_points);

// Whether swap file is required. Swap file is created in before_chroot/.
void WriteRequiringSwapFile(bool is_required);

// Save current settings to /etc/lingmo-installer.conf
// Other settings will be updated later.
void AddConfigFile();

// Save swap size for FullDiskInstall
void WriteSwapPartitionSize(const uint size);

}  // namespace installer

#endif  // INSTALLER_SETTINGS_MANAGER_H
