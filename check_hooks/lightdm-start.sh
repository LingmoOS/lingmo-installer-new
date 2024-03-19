#!/bin/bash

# SI = System Integrity

. "/lingmo-installer/basic_utils.sh"
. "/usr/share/lingmo-installer/hooks/basic_utils.sh"

if [ -d "/lingmo-installer/before_check/" ];then
    for i in /lingmo-installer/before_check/*; do
        chmod +x $i
        $i
        if [ $? != 0 ]; then
            echo "Check Mode faild: $i" >> /var/log/lingmo-installer.log
            touch /boot/efi/SI_FAILED
            setNetworkBoot
            reboot
        fi
    done
fi

# wait for lightdm
sleep 5
