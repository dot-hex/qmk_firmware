/* Copyright 2021 QMK
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <hal.h>
<<<<<<< HEAD
#include "usb_util.h"

void usb_disconnect(void) {
    usbStop(&USBD1);
}

bool usb_connected_state(void) {
    return usbGetDriverStateI(&USBD1) == USB_ACTIVE;
=======
#include "usb_main.h"
#include "usb_util.h"

void usb_disconnect(void) {
    usbDisconnectBus(&USB_DRIVER);
    usbStop(&USB_DRIVER);
}

bool usb_connected_state(void) {
    return usbGetDriverStateI(&USB_DRIVER) == USB_ACTIVE;
>>>>>>> upstream/master
}
