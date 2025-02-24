// Copyright 2023 Stefan Kerkmann
// Copyright 2020-2021 Ryan (@fauxpark)
// Copyright 2020 Nick Brassel (@tzarc)
// Copyright 2020 a-chol
// Copyright 2020 xyzz
// Copyright 2020 Joel Challis (@zvecr)
// Copyright 2020 George (@goshdarnharris)
// Copyright 2018 James Laird-Wah
// Copyright 2018 Drashna Jaelre (@drashna)
// Copyright 2016 Fredizzimo
// Copyright 2016 Giovanni Di Sirio
// SPDX-License-Identifier: GPL-3.0-or-later OR Apache-2.0

#include <ch.h>
#include <hal.h>
#include <string.h>

#include "usb_main.h"
#include "usb_report_handling.h"

#include "host.h"
#include "suspend.h"
#include "timer.h"
#ifdef SLEEP_LED_ENABLE
#    include "sleep_led.h"
#    include "led.h"
#endif
#include "wait.h"
<<<<<<< HEAD
=======
#include "usb_endpoints.h"
>>>>>>> upstream/master
#include "usb_device_state.h"
#include "usb_descriptor.h"
#include "usb_driver.h"
#include "usb_types.h"

#ifdef NKRO_ENABLE
#    include "keycode_config.h"

extern keymap_config_t keymap_config;
#endif

/* ---------------------------------------------------------
 *       Global interface variables and declarations
 * ---------------------------------------------------------
 */

#ifndef usb_lld_connect_bus
#    define usb_lld_connect_bus(usbp)
#endif

#ifndef usb_lld_disconnect_bus
#    define usb_lld_disconnect_bus(usbp)
#endif

<<<<<<< HEAD
uint8_t                keyboard_idle __attribute__((aligned(2)))     = 0;
uint8_t                keyboard_protocol __attribute__((aligned(2))) = 1;
uint8_t                keyboard_led_state                            = 0;
volatile uint16_t      keyboard_idle_count                           = 0;
static virtual_timer_t keyboard_idle_timer;

#if CH_KERNEL_MAJOR >= 7
static void keyboard_idle_timer_cb(struct ch_virtual_timer *, void *arg);
#elif CH_KERNEL_MAJOR <= 6
static void keyboard_idle_timer_cb(void *arg);
#endif
=======
extern usb_endpoint_in_t  usb_endpoints_in[USB_ENDPOINT_IN_COUNT];
extern usb_endpoint_out_t usb_endpoints_out[USB_ENDPOINT_OUT_COUNT];
>>>>>>> upstream/master

static bool __attribute__((__unused__)) send_report_buffered(usb_endpoint_in_lut_t endpoint, void *report, size_t size);
static void __attribute__((__unused__)) flush_report_buffered(usb_endpoint_in_lut_t endpoint, bool padded);
static bool __attribute__((__unused__)) receive_report(usb_endpoint_out_lut_t endpoint, void *report, size_t size);

/* ---------------------------------------------------------
 *            Descriptors and USB driver objects
 * ---------------------------------------------------------
 */

/* USB Low Level driver specific endpoint fields */
#if !defined(usb_lld_endpoint_fields)
#    define usb_lld_endpoint_fields   \
        2,        /* IN multiplier */ \
            NULL, /* SETUP buffer (not a SETUP endpoint) */
#endif

/*
 * Handles the GET_DESCRIPTOR callback
 *
 * Returns the proper descriptor
 */
static const USBDescriptor *usb_get_descriptor_cb(USBDriver *usbp, uint8_t dtype, uint8_t dindex, uint16_t wIndex) {
    usb_control_request_t *setup = (usb_control_request_t *)usbp->setup;

<<<<<<< HEAD
#if STM32_USB_USE_OTG1
typedef struct {
    size_t              queue_capacity_in;
    size_t              queue_capacity_out;
    USBInEndpointState  in_ep_state;
    USBOutEndpointState out_ep_state;
    USBInEndpointState  int_ep_state;
    USBEndpointConfig   inout_ep_config;
    USBEndpointConfig   int_ep_config;
    const QMKUSBConfig  config;
    QMKUSBDriver        driver;
} usb_driver_config_t;
#else
typedef struct {
    size_t              queue_capacity_in;
    size_t              queue_capacity_out;
    USBInEndpointState  in_ep_state;
    USBOutEndpointState out_ep_state;
    USBInEndpointState  int_ep_state;
    USBEndpointConfig   in_ep_config;
    USBEndpointConfig   out_ep_config;
    USBEndpointConfig   int_ep_config;
    const QMKUSBConfig  config;
    QMKUSBDriver        driver;
} usb_driver_config_t;
#endif

#if STM32_USB_USE_OTG1
/* Reusable initialization structure - see USBEndpointConfig comment at top of file */
#    define QMK_USB_DRIVER_CONFIG(stream, notification, fixedsize)                                                              \
        {                                                                                                                       \
            .queue_capacity_in = stream##_IN_CAPACITY, .queue_capacity_out = stream##_OUT_CAPACITY,                             \
            .inout_ep_config =                                                                                                  \
                {                                                                                                               \
                    stream##_IN_MODE,      /* Interrupt EP */                                                                   \
                    NULL,                  /* SETUP packet notification callback */                                             \
                    qmkusbDataTransmitted, /* IN notification callback */                                                       \
                    qmkusbDataReceived,    /* OUT notification callback */                                                      \
                    stream##_EPSIZE,       /* IN maximum packet size */                                                         \
                    stream##_EPSIZE,       /* OUT maximum packet size */                                                        \
                    NULL,                  /* IN Endpoint state */                                                              \
                    NULL,                  /* OUT endpoint state */                                                             \
                    2,                     /* IN multiplier */                                                                  \
                    NULL                   /* SETUP buffer (not a SETUP endpoint) */                                            \
                },                                                                                                              \
            .int_ep_config =                                                                                                    \
                {                                                                                                               \
                    USB_EP_MODE_TYPE_INTR,      /* Interrupt EP */                                                              \
                    NULL,                       /* SETUP packet notification callback */                                        \
                    qmkusbInterruptTransmitted, /* IN notification callback */                                                  \
                    NULL,                       /* OUT notification callback */                                                 \
                    CDC_NOTIFICATION_EPSIZE,    /* IN maximum packet size */                                                    \
                    0,                          /* OUT maximum packet size */                                                   \
                    NULL,                       /* IN Endpoint state */                                                         \
                    NULL,                       /* OUT endpoint state */                                                        \
                    2,                          /* IN multiplier */                                                             \
                    NULL,                       /* SETUP buffer (not a SETUP endpoint) */                                       \
                },                                                                                                              \
            .config = {                                                                                                         \
                .usbp        = &USB_DRIVER,                                                                                     \
                .bulk_in     = stream##_IN_EPNUM,                                                                               \
                .bulk_out    = stream##_OUT_EPNUM,                                                                              \
                .int_in      = notification,                                                                                    \
                .in_buffers  = stream##_IN_CAPACITY,                                                                            \
                .out_buffers = stream##_OUT_CAPACITY,                                                                           \
                .in_size     = stream##_EPSIZE,                                                                                 \
                .out_size    = stream##_EPSIZE,                                                                                 \
                .fixed_size  = fixedsize,                                                                                       \
                .ib          = (__attribute__((aligned(4))) uint8_t[BQ_BUFFER_SIZE(stream##_IN_CAPACITY, stream##_EPSIZE)]){},  \
                .ob          = (__attribute__((aligned(4))) uint8_t[BQ_BUFFER_SIZE(stream##_OUT_CAPACITY, stream##_EPSIZE)]){}, \
            }                                                                                                                   \
        }
#else
/* Reusable initialization structure - see USBEndpointConfig comment at top of file */
#    define QMK_USB_DRIVER_CONFIG(stream, notification, fixedsize)                                                              \
        {                                                                                                                       \
            .queue_capacity_in = stream##_IN_CAPACITY, .queue_capacity_out = stream##_OUT_CAPACITY,                             \
            .in_ep_config =                                                                                                     \
                {                                                                                                               \
                    stream##_IN_MODE,      /* Interrupt EP */                                                                   \
                    NULL,                  /* SETUP packet notification callback */                                             \
                    qmkusbDataTransmitted, /* IN notification callback */                                                       \
                    NULL,                  /* OUT notification callback */                                                      \
                    stream##_EPSIZE,       /* IN maximum packet size */                                                         \
                    0,                     /* OUT maximum packet size */                                                        \
                    NULL,                  /* IN Endpoint state */                                                              \
                    NULL,                  /* OUT endpoint state */                                                             \
                    2,                     /* IN multiplier */                                                                  \
                    NULL                   /* SETUP buffer (not a SETUP endpoint) */                                            \
                },                                                                                                              \
            .out_ep_config =                                                                                                    \
                {                                                                                                               \
                    stream##_OUT_MODE,  /* Interrupt EP */                                                                      \
                    NULL,               /* SETUP packet notification callback */                                                \
                    NULL,               /* IN notification callback */                                                          \
                    qmkusbDataReceived, /* OUT notification callback */                                                         \
                    0,                  /* IN maximum packet size */                                                            \
                    stream##_EPSIZE,    /* OUT maximum packet size */                                                           \
                    NULL,               /* IN Endpoint state */                                                                 \
                    NULL,               /* OUT endpoint state */                                                                \
                    2,                  /* IN multiplier */                                                                     \
                    NULL,               /* SETUP buffer (not a SETUP endpoint) */                                               \
                },                                                                                                              \
            .int_ep_config =                                                                                                    \
                {                                                                                                               \
                    USB_EP_MODE_TYPE_INTR,      /* Interrupt EP */                                                              \
                    NULL,                       /* SETUP packet notification callback */                                        \
                    qmkusbInterruptTransmitted, /* IN notification callback */                                                  \
                    NULL,                       /* OUT notification callback */                                                 \
                    CDC_NOTIFICATION_EPSIZE,    /* IN maximum packet size */                                                    \
                    0,                          /* OUT maximum packet size */                                                   \
                    NULL,                       /* IN Endpoint state */                                                         \
                    NULL,                       /* OUT endpoint state */                                                        \
                    2,                          /* IN multiplier */                                                             \
                    NULL,                       /* SETUP buffer (not a SETUP endpoint) */                                       \
                },                                                                                                              \
            .config = {                                                                                                         \
                .usbp        = &USB_DRIVER,                                                                                     \
                .bulk_in     = stream##_IN_EPNUM,                                                                               \
                .bulk_out    = stream##_OUT_EPNUM,                                                                              \
                .int_in      = notification,                                                                                    \
                .in_buffers  = stream##_IN_CAPACITY,                                                                            \
                .out_buffers = stream##_OUT_CAPACITY,                                                                           \
                .in_size     = stream##_EPSIZE,                                                                                 \
                .out_size    = stream##_EPSIZE,                                                                                 \
                .fixed_size  = fixedsize,                                                                                       \
                .ib          = (__attribute__((aligned(4))) uint8_t[BQ_BUFFER_SIZE(stream##_IN_CAPACITY, stream##_EPSIZE)]){},  \
                .ob          = (__attribute__((aligned(4))) uint8_t[BQ_BUFFER_SIZE(stream##_OUT_CAPACITY, stream##_EPSIZE)]){}, \
            }                                                                                                                   \
        }
#endif

typedef struct {
    union {
        struct {
#ifdef CONSOLE_ENABLE
            usb_driver_config_t console_driver;
#endif
#ifdef RAW_ENABLE
            usb_driver_config_t raw_driver;
#endif
#ifdef MIDI_ENABLE
            usb_driver_config_t midi_driver;
#endif
#ifdef VIRTSER_ENABLE
            usb_driver_config_t serial_driver;
#endif
#ifdef JOYSTICK_ENABLE
            usb_driver_config_t joystick_driver;
#endif
#if defined(DIGITIZER_ENABLE) && !defined(DIGITIZER_SHARED_EP)
            usb_driver_config_t digitizer_driver;
#endif
        };
        usb_driver_config_t array[0];
    };
} usb_driver_configs_t;

static usb_driver_configs_t drivers = {
#ifdef CONSOLE_ENABLE
#    define CONSOLE_IN_CAPACITY 4
#    define CONSOLE_OUT_CAPACITY 4
#    define CONSOLE_IN_MODE USB_EP_MODE_TYPE_INTR
#    define CONSOLE_OUT_MODE USB_EP_MODE_TYPE_INTR
    .console_driver = QMK_USB_DRIVER_CONFIG(CONSOLE, 0, true),
#endif
#ifdef RAW_ENABLE
#    define RAW_IN_CAPACITY 4
#    define RAW_OUT_CAPACITY 4
#    define RAW_IN_MODE USB_EP_MODE_TYPE_INTR
#    define RAW_OUT_MODE USB_EP_MODE_TYPE_INTR
    .raw_driver = QMK_USB_DRIVER_CONFIG(RAW, 0, false),
#endif

#ifdef MIDI_ENABLE
#    define MIDI_STREAM_IN_CAPACITY 4
#    define MIDI_STREAM_OUT_CAPACITY 4
#    define MIDI_STREAM_IN_MODE USB_EP_MODE_TYPE_BULK
#    define MIDI_STREAM_OUT_MODE USB_EP_MODE_TYPE_BULK
    .midi_driver = QMK_USB_DRIVER_CONFIG(MIDI_STREAM, 0, false),
#endif

#ifdef VIRTSER_ENABLE
#    define CDC_IN_CAPACITY 4
#    define CDC_OUT_CAPACITY 4
#    define CDC_IN_MODE USB_EP_MODE_TYPE_BULK
#    define CDC_OUT_MODE USB_EP_MODE_TYPE_BULK
    .serial_driver = QMK_USB_DRIVER_CONFIG(CDC, CDC_NOTIFICATION_EPNUM, false),
#endif

#ifdef JOYSTICK_ENABLE
#    define JOYSTICK_IN_CAPACITY 4
#    define JOYSTICK_OUT_CAPACITY 4
#    define JOYSTICK_IN_MODE USB_EP_MODE_TYPE_BULK
#    define JOYSTICK_OUT_MODE USB_EP_MODE_TYPE_BULK
    .joystick_driver = QMK_USB_DRIVER_CONFIG(JOYSTICK, 0, false),
#endif

#if defined(DIGITIZER_ENABLE) && !defined(DIGITIZER_SHARED_EP)
#    define DIGITIZER_IN_CAPACITY 4
#    define DIGITIZER_OUT_CAPACITY 4
#    define DIGITIZER_IN_MODE USB_EP_MODE_TYPE_BULK
#    define DIGITIZER_OUT_MODE USB_EP_MODE_TYPE_BULK
    .digitizer_driver = QMK_USB_DRIVER_CONFIG(DIGITIZER, 0, false),
#endif
};
=======
    static USBDescriptor descriptor;
    descriptor.ud_string = NULL;
    descriptor.ud_size   = get_usb_descriptor(setup->wValue.word, setup->wIndex, setup->wLength, (const void **const) & descriptor.ud_string);

    if (descriptor.ud_string == NULL) {
        return NULL;
    }
>>>>>>> upstream/master

    return &descriptor;
}

/* ---------------------------------------------------------
 *                  USB driver functions
 * ---------------------------------------------------------
 */

#define USB_EVENT_QUEUE_SIZE 16
usbevent_t event_queue[USB_EVENT_QUEUE_SIZE];
uint8_t    event_queue_head;
uint8_t    event_queue_tail;

void usb_event_queue_init(void) {
    // Initialise the event queue
    memset(&event_queue, 0, sizeof(event_queue));
    event_queue_head = 0;
    event_queue_tail = 0;
}

static inline bool usb_event_queue_enqueue(usbevent_t event) {
    uint8_t next = (event_queue_head + 1) % USB_EVENT_QUEUE_SIZE;
    if (next == event_queue_tail) {
        return false;
    }
    event_queue[event_queue_head] = event;
    event_queue_head              = next;
    return true;
}

static inline bool usb_event_queue_dequeue(usbevent_t *event) {
    if (event_queue_head == event_queue_tail) {
        return false;
    }
    *event           = event_queue[event_queue_tail];
    event_queue_tail = (event_queue_tail + 1) % USB_EVENT_QUEUE_SIZE;
    return true;
}

static inline void usb_event_suspend_handler(void) {
    usb_device_state_set_suspend(USB_DRIVER.configuration != 0, USB_DRIVER.configuration);
#ifdef SLEEP_LED_ENABLE
    sleep_led_enable();
#endif /* SLEEP_LED_ENABLE */
}

static inline void usb_event_wakeup_handler(void) {
    suspend_wakeup_init();
    usb_device_state_set_resume(USB_DRIVER.configuration != 0, USB_DRIVER.configuration);
#ifdef SLEEP_LED_ENABLE
    sleep_led_disable();
    // NOTE: converters may not accept this
    led_set(host_keyboard_leds());
#endif /* SLEEP_LED_ENABLE */
}

bool last_suspend_state = false;

void usb_event_queue_task(void) {
    usbevent_t event;
    while (usb_event_queue_dequeue(&event)) {
        switch (event) {
            case USB_EVENT_SUSPEND:
                last_suspend_state = true;
                usb_event_suspend_handler();
                break;
            case USB_EVENT_WAKEUP:
                last_suspend_state = false;
                usb_event_wakeup_handler();
                break;
            case USB_EVENT_CONFIGURED:
                usb_device_state_set_configuration(USB_DRIVER.configuration != 0, USB_DRIVER.configuration);
                break;
            case USB_EVENT_UNCONFIGURED:
                usb_device_state_set_configuration(false, 0);
                break;
            case USB_EVENT_RESET:
                usb_device_state_set_reset();
<<<<<<< HEAD
=======
                usb_device_state_set_protocol(USB_PROTOCOL_REPORT);
>>>>>>> upstream/master
                break;
            default:
                // Nothing to do, we don't handle it.
                break;
        }
    }
}

/* Handles the USB driver global events. */
static void usb_event_cb(USBDriver *usbp, usbevent_t event) {
    switch (event) {
        case USB_EVENT_ADDRESS:
            return;

        case USB_EVENT_CONFIGURED:
            osalSysLockFromISR();
            for (int i = 0; i < USB_ENDPOINT_IN_COUNT; i++) {
                usb_endpoint_in_configure_cb(&usb_endpoints_in[i]);
            }
            for (int i = 0; i < USB_ENDPOINT_OUT_COUNT; i++) {
                usb_endpoint_out_configure_cb(&usb_endpoints_out[i]);
            }
            osalSysUnlockFromISR();
            if (last_suspend_state) {
                usb_event_queue_enqueue(USB_EVENT_WAKEUP);
            }
            usb_event_queue_enqueue(USB_EVENT_CONFIGURED);
            return;
        case USB_EVENT_SUSPEND:
            /* Falls into.*/
        case USB_EVENT_UNCONFIGURED:
            /* Falls into.*/
        case USB_EVENT_RESET:
            usb_event_queue_enqueue(event);
<<<<<<< HEAD
            for (int i = 0; i < NUM_USB_DRIVERS; i++) {
                chSysLockFromISR();
                /* Disconnection event on suspend.*/
                qmkusbSuspendHookI(&drivers.array[i].driver);
                chSysUnlockFromISR();
=======
            chSysLockFromISR();
            for (int i = 0; i < USB_ENDPOINT_IN_COUNT; i++) {
                usb_endpoint_in_suspend_cb(&usb_endpoints_in[i]);
            }
            for (int i = 0; i < USB_ENDPOINT_OUT_COUNT; i++) {
                usb_endpoint_out_suspend_cb(&usb_endpoints_out[i]);
>>>>>>> upstream/master
            }
            chSysUnlockFromISR();
            return;

        case USB_EVENT_WAKEUP:
            chSysLockFromISR();
            for (int i = 0; i < USB_ENDPOINT_IN_COUNT; i++) {
                usb_endpoint_in_wakeup_cb(&usb_endpoints_in[i]);
            }
            for (int i = 0; i < USB_ENDPOINT_OUT_COUNT; i++) {
                usb_endpoint_out_wakeup_cb(&usb_endpoints_out[i]);
            }
            chSysUnlockFromISR();
            usb_event_queue_enqueue(USB_EVENT_WAKEUP);
            return;

        case USB_EVENT_STALLED:
            return;
    }
}

/*
 * Appendix G: HID Request Support Requirements
 *
 * The following table enumerates the requests that need to be supported by various types of HID class devices.
 * Device type     GetReport   SetReport   GetIdle     SetIdle     GetProtocol SetProtocol
 * ------------------------------------------------------------------------------------------
 * Boot Mouse      Required    Optional    Optional    Optional    Required    Required
 * Non-Boot Mouse  Required    Optional    Optional    Optional    Optional    Optional
 * Boot Keyboard   Required    Optional    Required    Required    Required    Required
 * Non-Boot Keybrd Required    Optional    Required    Required    Optional    Optional
 * Other Device    Required    Optional    Optional    Optional    Optional    Optional
 */

<<<<<<< HEAD
static uint8_t set_report_buf[2] __attribute__((aligned(4)));
static void    set_led_transfer_cb(USBDriver *usbp) {
    if (usbp->setup[6] == 2) { /* LSB(wLength) */
=======
static uint8_t _Alignas(4) set_report_buf[2];

static void set_led_transfer_cb(USBDriver *usbp) {
    usb_control_request_t *setup = (usb_control_request_t *)usbp->setup;

    if (setup->wLength == 2) {
>>>>>>> upstream/master
        uint8_t report_id = set_report_buf[0];
        if ((report_id == REPORT_ID_KEYBOARD) || (report_id == REPORT_ID_NKRO)) {
            usb_device_state_set_leds(set_report_buf[1]);
        }
    } else {
        usb_device_state_set_leds(set_report_buf[0]);
    }
}

static bool usb_requests_hook_cb(USBDriver *usbp) {
    usb_control_request_t *setup = (usb_control_request_t *)usbp->setup;

    /* Handle HID class specific requests */
    if ((setup->bmRequestType & (USB_RTYPE_TYPE_MASK | USB_RTYPE_RECIPIENT_MASK)) == (USB_RTYPE_TYPE_CLASS | USB_RTYPE_RECIPIENT_INTERFACE)) {
        switch (setup->bmRequestType & USB_RTYPE_DIR_MASK) {
            case USB_RTYPE_DIR_DEV2HOST:
                switch (setup->bRequest) {
                    case HID_REQ_GetReport:
                        return usb_get_report_cb(usbp);
                    case HID_REQ_GetProtocol:
                        if (setup->wIndex == KEYBOARD_INTERFACE) {
                            static uint8_t keyboard_protocol;
                            keyboard_protocol = usb_device_state_get_protocol();
                            usbSetupTransfer(usbp, &keyboard_protocol, sizeof(keyboard_protocol), NULL);
                            return true;
                        }
                        break;

                    case HID_REQ_GetIdle:
                        return usb_get_idle_cb(usbp);
                }

            case USB_RTYPE_DIR_HOST2DEV:
                switch (setup->bRequest) {
                    case HID_REQ_SetReport:
                        switch (setup->wIndex) {
                            case KEYBOARD_INTERFACE:
#if defined(SHARED_EP_ENABLE) && !defined(KEYBOARD_SHARED_EP)
                            case SHARED_INTERFACE:
#endif
                                usbSetupTransfer(usbp, set_report_buf, sizeof(set_report_buf), set_led_transfer_cb);
                                return true;
                        }
                        break;
                    case HID_REQ_SetProtocol:
                        if (setup->wIndex == KEYBOARD_INTERFACE) {
                            usb_device_state_set_protocol(setup->wValue.lbyte);
                        }
                        usbSetupTransfer(usbp, NULL, 0, NULL);
                        return true;
                    case HID_REQ_SetIdle:
                        usb_device_state_set_idle_rate(setup->wValue.hbyte);
                        return usb_set_idle_cb(usbp);
                }
                break;
        }
    }

    /* Handle the Get_Descriptor Request for HID class, which is not handled by
     * the ChibiOS USB driver */
    if (((setup->bmRequestType & (USB_RTYPE_DIR_MASK | USB_RTYPE_RECIPIENT_MASK)) == (USB_RTYPE_DIR_DEV2HOST | USB_RTYPE_RECIPIENT_INTERFACE)) && (setup->bRequest == USB_REQ_GET_DESCRIPTOR)) {
        const USBDescriptor *descriptor = usbp->config->get_descriptor_cb(usbp, setup->wValue.lbyte, setup->wValue.hbyte, setup->wIndex);
        if (descriptor == NULL) {
            return false;
        }
        usbSetupTransfer(usbp, (uint8_t *)descriptor->ud_string, descriptor->ud_size, NULL);
        return true;
    }

    for (int i = 0; i < USB_ENDPOINT_IN_COUNT; i++) {
        if (usb_endpoints_in[i].usb_requests_cb != NULL) {
            if (usb_endpoints_in[i].usb_requests_cb(usbp)) {
                return true;
            }
        }
    }

    return false;
}

static __attribute__((unused)) void dummy_cb(USBDriver *usbp) {
    (void)usbp;
}

static const USBConfig usbcfg = {
    usb_event_cb,          /* USB events callback */
    usb_get_descriptor_cb, /* Device GET_DESCRIPTOR request callback */
    usb_requests_hook_cb,  /* Requests hook callback */
#if STM32_USB_USE_OTG1 == TRUE || STM32_USB_USE_OTG2 == TRUE
    dummy_cb, /* Workaround for OTG Peripherals not servicing new interrupts
    after resuming from suspend. */
#endif
};

void init_usb_driver(USBDriver *usbp) {
    for (int i = 0; i < USB_ENDPOINT_IN_COUNT; i++) {
        usb_endpoint_in_init(&usb_endpoints_in[i]);
        usb_endpoint_in_start(&usb_endpoints_in[i]);
    }

    for (int i = 0; i < USB_ENDPOINT_OUT_COUNT; i++) {
        usb_endpoint_out_init(&usb_endpoints_out[i]);
        usb_endpoint_out_start(&usb_endpoints_out[i]);
    }

    /*
     * Activates the USB driver and then the USB bus pull-up on D+.
     * Note, a delay is inserted in order to not have to disconnect the cable
     * after a reset.
     */
    usbDisconnectBus(usbp);
<<<<<<< HEAD
=======
    usbStop(usbp);
>>>>>>> upstream/master
    wait_ms(50);
    usbStart(usbp, &usbcfg);
    usbConnectBus(usbp);
}

__attribute__((weak)) void restart_usb_driver(USBDriver *usbp) {
<<<<<<< HEAD
    usbStop(usbp);
=======
>>>>>>> upstream/master
    usbDisconnectBus(usbp);
    usbStop(usbp);

    for (int i = 0; i < USB_ENDPOINT_IN_COUNT; i++) {
        usb_endpoint_in_stop(&usb_endpoints_in[i]);
    }

    for (int i = 0; i < USB_ENDPOINT_OUT_COUNT; i++) {
        usb_endpoint_out_stop(&usb_endpoints_out[i]);
    }

    wait_ms(50);

    for (int i = 0; i < USB_ENDPOINT_IN_COUNT; i++) {
        usb_endpoint_in_init(&usb_endpoints_in[i]);
        usb_endpoint_in_start(&usb_endpoints_in[i]);
    }

    for (int i = 0; i < USB_ENDPOINT_OUT_COUNT; i++) {
        usb_endpoint_out_init(&usb_endpoints_out[i]);
        usb_endpoint_out_start(&usb_endpoints_out[i]);
    }

    usbStart(usbp, &usbcfg);
    usbConnectBus(usbp);
}

/* ---------------------------------------------------------
 *                  Keyboard functions
 * ---------------------------------------------------------
 */
<<<<<<< HEAD
/* keyboard IN callback hander (a kbd report has made it IN) */
#ifndef KEYBOARD_SHARED_EP
void kbd_in_cb(USBDriver *usbp, usbep_t ep) {
    /* STUB */
    (void)usbp;
    (void)ep;
}
#endif

/* start-of-frame handler
 * TODO: i guess it would be better to re-implement using timers,
 *  so that this is not going to have to be checked every 1ms */
void kbd_sof_cb(USBDriver *usbp) {
    (void)usbp;
}

/* Idle requests timer code
 * callback (called from ISR, unlocked state) */
#if CH_KERNEL_MAJOR >= 7
static void keyboard_idle_timer_cb(struct ch_virtual_timer *timer, void *arg) {
    (void)timer;
#elif CH_KERNEL_MAJOR <= 6
static void keyboard_idle_timer_cb(void *arg) {
#endif
    USBDriver *usbp = (USBDriver *)arg;

    osalSysLockFromISR();

    /* check that the states of things are as they're supposed to */
    if (usbGetDriverStateI(usbp) != USB_ACTIVE) {
        /* do not rearm the timer, should be enabled on IDLE request */
        osalSysUnlockFromISR();
        return;
    }
=======

/**
 * @brief Send a report to the host, the report is enqueued into an output
 * queue and send once the USB endpoint becomes empty.
 *
 * @param endpoint USB IN endpoint to send the report from
 * @param report pointer to the report
 * @param size size of the report
 * @return true Success
 * @return false Failure
 */
bool send_report(usb_endpoint_in_lut_t endpoint, void *report, size_t size) {
    return usb_endpoint_in_send(&usb_endpoints_in[endpoint], (uint8_t *)report, size, TIME_MS2I(100), false);
}
>>>>>>> upstream/master

/**
 * @brief Send a report to the host, but delay the sending until the size of
 * endpoint report is reached or the incompletely filled buffer is flushed with
 * a call to `flush_report_buffered`. This is useful if the report is being
 * updated frequently. The complete report is then enqueued into an output
 * queue and send once the USB endpoint becomes empty.
 *
 * @param endpoint USB IN endpoint to send the report from
 * @param report pointer to the report
 * @param size size of the report
 * @return true Success
 * @return false Failure
 */
static bool send_report_buffered(usb_endpoint_in_lut_t endpoint, void *report, size_t size) {
    return usb_endpoint_in_send(&usb_endpoints_in[endpoint], (uint8_t *)report, size, TIME_MS2I(100), true);
}

/** @brief Flush all buffered reports which were enqueued with a call to
 * `send_report_buffered` that haven't been send. If necessary the buffered
 * report can be padded with zeros up to the endpoints maximum size.
 *
 * @param endpoint USB IN endpoint to flush the reports from
 * @param padded Pad the buffered report with zeros up to the endpoints maximum size
 */
static void flush_report_buffered(usb_endpoint_in_lut_t endpoint, bool padded) {
    usb_endpoint_in_flush(&usb_endpoints_in[endpoint], padded);
}

<<<<<<< HEAD
/* LED status */
uint8_t keyboard_leds(void) {
    return keyboard_led_state;
=======
/**
 * @brief Receive a report from the host.
 *
 * @param endpoint USB OUT endpoint to receive the report from
 * @param report pointer to the report
 * @param size size of the report
 * @return true Success
 * @return false Failure
 */
static bool receive_report(usb_endpoint_out_lut_t endpoint, void *report, size_t size) {
    return usb_endpoint_out_receive(&usb_endpoints_out[endpoint], (uint8_t *)report, size, TIME_IMMEDIATE);
>>>>>>> upstream/master
}

void send_keyboard(report_keyboard_t *report) {
    /* If we're in Boot Protocol, don't send any report ID or other funky fields */
    if (usb_device_state_get_protocol() == USB_PROTOCOL_BOOT) {
        send_report(USB_ENDPOINT_IN_KEYBOARD, &report->mods, 8);
    } else {
        send_report(USB_ENDPOINT_IN_KEYBOARD, report, KEYBOARD_REPORT_SIZE);
    }
}

void send_nkro(report_nkro_t *report) {
#ifdef NKRO_ENABLE
    send_report(USB_ENDPOINT_IN_SHARED, report, sizeof(report_nkro_t));
#endif
}

/* ---------------------------------------------------------
 *                     Mouse functions
 * ---------------------------------------------------------
 */

void send_mouse(report_mouse_t *report) {
<<<<<<< HEAD
    osalSysLock();
    if (usbGetDriverStateI(&USB_DRIVER) != USB_ACTIVE) {
        osalSysUnlock();
        return;
    }

    if (usbGetTransmitStatusI(&USB_DRIVER, MOUSE_IN_EPNUM)) {
        /* Need to either suspend, or loop and call unlock/lock during
         * every iteration - otherwise the system will remain locked,
         * no interrupts served, so USB not going through as well.
         * Note: for suspend, need USB_USE_WAIT == TRUE in halconf.h */
        if (osalThreadSuspendTimeoutS(&(&USB_DRIVER)->epc[MOUSE_IN_EPNUM]->in_state->thread, TIME_MS2I(10)) == MSG_TIMEOUT) {
            osalSysUnlock();
            return;
        }
    }
    usbStartTransmitI(&USB_DRIVER, MOUSE_IN_EPNUM, (uint8_t *)report, sizeof(report_mouse_t));
    osalSysUnlock();
}

#else  /* MOUSE_ENABLE */
void send_mouse(report_mouse_t *report) {
    (void)report;
}
#endif /* MOUSE_ENABLE */

/* ---------------------------------------------------------
 *                   Shared EP functions
 * ---------------------------------------------------------
 */
#ifdef SHARED_EP_ENABLE
/* shared IN callback hander */
void shared_in_cb(USBDriver *usbp, usbep_t ep) {
    /* STUB */
    (void)usbp;
    (void)ep;
}
=======
#ifdef MOUSE_ENABLE
    send_report(USB_ENDPOINT_IN_MOUSE, report, sizeof(report_mouse_t));
>>>>>>> upstream/master
#endif
}

/* ---------------------------------------------------------
 *                   Extrakey functions
 * ---------------------------------------------------------
 */

void send_extra(report_extra_t *report) {
#ifdef EXTRAKEY_ENABLE
<<<<<<< HEAD
static void send_extra(uint8_t report_id, uint16_t data) {
    osalSysLock();
    if (usbGetDriverStateI(&USB_DRIVER) != USB_ACTIVE) {
        osalSysUnlock();
        return;
    }

    if (usbGetTransmitStatusI(&USB_DRIVER, SHARED_IN_EPNUM)) {
        /* Need to either suspend, or loop and call unlock/lock during
         * every iteration - otherwise the system will remain locked,
         * no interrupts served, so USB not going through as well.
         * Note: for suspend, need USB_USE_WAIT == TRUE in halconf.h */
        if (osalThreadSuspendTimeoutS(&(&USB_DRIVER)->epc[SHARED_IN_EPNUM]->in_state->thread, TIME_MS2I(10)) == MSG_TIMEOUT) {
            osalSysUnlock();
            return;
        }
    }

    static report_extra_t report;
    report = (report_extra_t){.report_id = report_id, .usage = data};

    usbStartTransmitI(&USB_DRIVER, SHARED_IN_EPNUM, (uint8_t *)&report, sizeof(report_extra_t));
    osalSysUnlock();
=======
    send_report(USB_ENDPOINT_IN_SHARED, report, sizeof(report_extra_t));
#endif
>>>>>>> upstream/master
}

void send_programmable_button(report_programmable_button_t *report) {
#ifdef PROGRAMMABLE_BUTTON_ENABLE
    send_report(USB_ENDPOINT_IN_SHARED, report, sizeof(report_programmable_button_t));
#endif
}

void send_joystick(report_joystick_t *report) {
#ifdef JOYSTICK_ENABLE
    send_report(USB_ENDPOINT_IN_JOYSTICK, report, sizeof(report_joystick_t));
#endif
}

void send_digitizer(report_digitizer_t *report) {
#ifdef DIGITIZER_ENABLE
    send_report(USB_ENDPOINT_IN_DIGITIZER, report, sizeof(report_digitizer_t));
#endif
}

void send_programmable_button(uint32_t data) {
#ifdef PROGRAMMABLE_BUTTON_ENABLE
    osalSysLock();
    if (usbGetDriverStateI(&USB_DRIVER) != USB_ACTIVE) {
        osalSysUnlock();
        return;
    }

    if (usbGetTransmitStatusI(&USB_DRIVER, SHARED_IN_EPNUM)) {
        /* Need to either suspend, or loop and call unlock/lock during
         * every iteration - otherwise the system will remain locked,
         * no interrupts served, so USB not going through as well.
         * Note: for suspend, need USB_USE_WAIT == TRUE in halconf.h */
        if (osalThreadSuspendTimeoutS(&(&USB_DRIVER)->epc[SHARED_IN_EPNUM]->in_state->thread, TIME_MS2I(10)) == MSG_TIMEOUT) {
            osalSysUnlock();
            return;
        }
    }
    static report_programmable_button_t report = {
        .report_id = REPORT_ID_PROGRAMMABLE_BUTTON,
    };

    report.usage = data;

    usbStartTransmitI(&USB_DRIVER, SHARED_IN_EPNUM, (uint8_t *)&report, sizeof(report));
    osalSysUnlock();
#endif
}

void send_digitizer(report_digitizer_t *report) {
#ifdef DIGITIZER_ENABLE
#    ifdef DIGITIZER_SHARED_EP
    osalSysLock();
    if (usbGetDriverStateI(&USB_DRIVER) != USB_ACTIVE) {
        osalSysUnlock();
        return;
    }

    usbStartTransmitI(&USB_DRIVER, DIGITIZER_IN_EPNUM, (uint8_t *)report, sizeof(report_digitizer_t));
    osalSysUnlock();
#    else
    chnWrite(&drivers.digitizer_driver.driver, (uint8_t *)report, sizeof(report_digitizer_t));
#    endif
#endif
}

/* ---------------------------------------------------------
 *                   Console functions
 * ---------------------------------------------------------
 */

#ifdef CONSOLE_ENABLE

int8_t sendchar(uint8_t c) {
<<<<<<< HEAD
    static bool timed_out = false;
    /* The `timed_out` state is an approximation of the ideal `is_listener_disconnected?` state.
     *
     * When a 5ms timeout write has timed out, hid_listen is most likely not running, or not
     * listening to this keyboard, so we go into the timed_out state. In this state we assume
     * that hid_listen is most likely not gonna be connected to us any time soon, so it would
     * be wasteful to write follow-up characters with a 5ms timeout, it would all add up and
     * unncecessarily slow down the firmware. However instead of just dropping the characters,
     * we write them with a TIME_IMMEDIATE timeout, which is a zero timeout,
     * and this will succeed only if hid_listen gets connected again. When a write with
     * TIME_IMMEDIATE timeout succeeds, we know that hid_listen is listening to us again, and
     * we can go back to the timed_out = false state, and following writes will be executed
     * with a 5ms timeout. The reason we don't just send all characters with the TIME_IMMEDIATE
     * timeout is that this could cause bytes to be lost even if hid_listen is running, if there
     * is a lot of data being sent over the console.
     *
     * This logic will work correctly as long as hid_listen is able to receive at least 200
     * bytes per second. On a heavily overloaded machine that's so overloaded that it's
     * unusable, and constantly swapping, hid_listen might have trouble receiving 200 bytes per
     * second, so some bytes might be lost on the console.
     */

    const sysinterval_t timeout = timed_out ? TIME_IMMEDIATE : TIME_MS2I(5);
    const size_t        result  = chnWriteTimeout(&drivers.console_driver.driver, &c, 1, timeout);
    timed_out                   = (result == 0);
    return result;
}

// Just a dummy function for now, this could be exposed as a weak function
// Or connected to the actual QMK console
static void console_receive(uint8_t *data, uint8_t length) {
    (void)data;
    (void)length;
=======
    return (int8_t)send_report_buffered(USB_ENDPOINT_IN_CONSOLE, &c, sizeof(uint8_t));
>>>>>>> upstream/master
}

void console_task(void) {
    flush_report_buffered(USB_ENDPOINT_IN_CONSOLE, true);
}

#endif /* CONSOLE_ENABLE */

#ifdef RAW_ENABLE
void raw_hid_send(uint8_t *data, uint8_t length) {
    if (length != RAW_EPSIZE) {
        return;
    }
    send_report(USB_ENDPOINT_IN_RAW, data, length);
}

__attribute__((weak)) void raw_hid_receive(uint8_t *data, uint8_t length) {
    // Users should #include "raw_hid.h" in their own code
    // and implement this function there. Leave this as weak linkage
    // so users can opt to not handle data coming in.
}

void raw_hid_task(void) {
    uint8_t buffer[RAW_EPSIZE];
    while (receive_report(USB_ENDPOINT_OUT_RAW, buffer, sizeof(buffer))) {
        raw_hid_receive(buffer, sizeof(buffer));
    }
}

#endif

#ifdef MIDI_ENABLE

void send_midi_packet(MIDI_EventPacket_t *event) {
<<<<<<< HEAD
    chnWrite(&drivers.midi_driver.driver, (uint8_t *)event, sizeof(MIDI_EventPacket_t));
=======
    send_report(USB_ENDPOINT_IN_MIDI, (uint8_t *)event, sizeof(MIDI_EventPacket_t));
>>>>>>> upstream/master
}

bool recv_midi_packet(MIDI_EventPacket_t *const event) {
    return receive_report(USB_ENDPOINT_OUT_MIDI, (uint8_t *)event, sizeof(MIDI_EventPacket_t));
}

#endif

#ifdef VIRTSER_ENABLE

<<<<<<< HEAD
void virtser_init(void) {}

void virtser_send(const uint8_t byte) {
    chnWrite(&drivers.serial_driver.driver, &byte, 1);
=======
#    include "hal_usb_cdc.h"
/**
 * @brief CDC serial driver configuration structure. Set to 9600 baud, 1 stop bit, no parity, 8 data bits.
 */
static cdc_linecoding_t linecoding = {{0x00, 0x96, 0x00, 0x00}, LC_STOP_1, LC_PARITY_NONE, 8};

bool virtser_usb_request_cb(USBDriver *usbp) {
    if ((usbp->setup[0] & USB_RTYPE_TYPE_MASK) == USB_RTYPE_TYPE_CLASS) { /* bmRequestType */
        if (usbp->setup[4] == CCI_INTERFACE) {                            /* wIndex (LSB) */
            switch (usbp->setup[1]) {                                     /* bRequest */
                case CDC_GET_LINE_CODING:
                    usbSetupTransfer(usbp, (uint8_t *)&linecoding, sizeof(linecoding), NULL);
                    return true;
                case CDC_SET_LINE_CODING:
                    usbSetupTransfer(usbp, (uint8_t *)&linecoding, sizeof(linecoding), NULL);
                    return true;
                case CDC_SET_CONTROL_LINE_STATE:
                    /* Nothing to do, there are no control lines.*/
                    usbSetupTransfer(usbp, NULL, 0, NULL);
                    return true;
                default:
                    return false;
            }
        }
    }

    return false;
}

void virtser_init(void) {}

void virtser_send(const uint8_t byte) {
    send_report_buffered(USB_ENDPOINT_IN_CDC_DATA, (void *)&byte, sizeof(byte));
>>>>>>> upstream/master
}

__attribute__((weak)) void virtser_recv(uint8_t c) {
    // Ignore by default
}

void virtser_task(void) {
    uint8_t buffer[CDC_EPSIZE];
    while (receive_report(USB_ENDPOINT_OUT_CDC_DATA, buffer, sizeof(buffer))) {
        for (int i = 0; i < sizeof(buffer); i++) {
            virtser_recv(buffer[i]);
        }
<<<<<<< HEAD
    } while (numBytesReceived > 0);
}

#endif

#ifdef JOYSTICK_ENABLE

void send_joystick_packet(joystick_t *joystick) {
    static joystick_report_t rep;
    rep = (joystick_report_t) {
#    if JOYSTICK_AXES_COUNT > 0
        .axes =
        { joystick->axes[0],

#        if JOYSTICK_AXES_COUNT >= 2
          joystick->axes[1],
#        endif
#        if JOYSTICK_AXES_COUNT >= 3
          joystick->axes[2],
#        endif
#        if JOYSTICK_AXES_COUNT >= 4
          joystick->axes[3],
#        endif
#        if JOYSTICK_AXES_COUNT >= 5
          joystick->axes[4],
#        endif
#        if JOYSTICK_AXES_COUNT >= 6
          joystick->axes[5],
#        endif
        },
#    endif // JOYSTICK_AXES_COUNT>0

#    if JOYSTICK_BUTTON_COUNT > 0
        .buttons = {
            joystick->buttons[0],

#        if JOYSTICK_BUTTON_COUNT > 8
            joystick->buttons[1],
#        endif
#        if JOYSTICK_BUTTON_COUNT > 16
            joystick->buttons[2],
#        endif
#        if JOYSTICK_BUTTON_COUNT > 24
            joystick->buttons[3],
#        endif
        }
#    endif // JOYSTICK_BUTTON_COUNT>0
    };

    // chnWrite(&drivers.joystick_driver.driver, (uint8_t *)&rep, sizeof(rep));
    osalSysLock();
    if (usbGetDriverStateI(&USB_DRIVER) != USB_ACTIVE) {
        osalSysUnlock();
        return;
=======
>>>>>>> upstream/master
    }

    flush_report_buffered(USB_ENDPOINT_IN_CDC_DATA, false);
}

#endif
