#!/bin/bash

# Absolute path to config file.
# Do not read from/write to this file, call installer_get/installer_set instead.
CONF_FILE=/etc/lingmo-installer.conf

installer_get() {
    local key="$1"
    [ -z "${CONF_FILE}" ] && exit "CONF_FILE is not defined"
    which lingmo-installer-settings 1>/dev/null || \
    exit "lingmo-installer-settings not found!"
    lingmo-installer-settings get "${CONF_FILE}" "${key}"
}

# Set value in conf file. Section name is ignored.
installer_set() {
    local key="$1"
    local value="$2"
    [ -z "${CONF_FILE}" ] && exit "CONF_FILE is not defined"
    which lingmo-installer-settings 1>/dev/null || \
    exit "lingmo-installer-settings not found!"
    lingmo-installer-settings set "${CONF_FILE}" "${key}" "${value}"
}

DI_SI_USER=$(installer_get "DI_SI_USER")
DI_SI_PASSWORD=$(installer_get "DI_SI_PASSWORD")

setNetworkBoot() {
    NETWORK_EFI=$(efibootmgr |grep -i network |awk -F'*' '{print $1}' |sed 's#Boot##')
    echo ${DI_SI_PASSWORD}|sudo -S efibootmgr -n ${NETWORK_EFI}
}
