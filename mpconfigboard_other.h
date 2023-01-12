#define MICROPY_HW_BOARD_NAME       "WEACT_H750"
#define MICROPY_HW_MCU_NAME         "STM32H750"
#define MICROPY_HW_FLASH_FS_LABEL   "WEACTH750"

#define MICROPY_HW_ENABLE_RTC       (1)
#define MICROPY_HW_ENABLE_RNG       (1)
#define MICROPY_HW_ENABLE_ADC       (1)
#define MICROPY_HW_ENABLE_DAC       (1)
#define MICROPY_HW_ENABLE_USB       (1)
#define MICROPY_HW_ENABLE_SDCARD    (0) // it has a sd scard, but no detect pin
#define MICROPY_HW_HAS_SWITCH       (1) // has 2 buttons K1, K2
#define MICROPY_HW_HAS_FLASH        (1)

// The board has a 25MHz HSE, the following gives 480MHz CPU speed
#define MICROPY_HW_CLK_PLLM (5)
#define MICROPY_HW_CLK_PLLN (192)
#define MICROPY_HW_CLK_PLLP (2)
#define MICROPY_HW_CLK_PLLQ (2)
#define MICROPY_HW_CLK_PLLR (2)

// The USB clock is set using PLL3
#define MICROPY_HW_CLK_PLL3M (5)
#define MICROPY_HW_CLK_PLL3N (96)
#define MICROPY_HW_CLK_PLL3P (2)
#define MICROPY_HW_CLK_PLL3Q (10)
#define MICROPY_HW_CLK_PLL3R (8)

// RTC
#define MICROPY_HW_RTC_USE_LSE      (1)
#define MICROPY_HW_RTC_USE_US       (0)
// #define MICROPY_HW_RTC_USE_CALOUT   (1)  // turn on/off PC13 512Hz output

// 4 wait states
#define MICROPY_HW_FLASH_LATENCY    FLASH_LATENCY_4

// UARTs
#define MICROPY_HW_UART1_TX         (pin_A9)
#define MICROPY_HW_UART1_RX         (pin_A10)
#define MICROPY_HW_UART2_TX         (pin_A2)
#define MICROPY_HW_UART2_RX         (pin_A3)
#define MICROPY_HW_UART3_TX         (pin_D8)
#define MICROPY_HW_UART3_RX         (pin_D9)
#define MICROPY_HW_UART4_TX         (pin_A0)
#define MICROPY_HW_UART4_RX         (pin_A1)
#define MICROPY_HW_UART5_TX         (pin_C12)
#define MICROPY_HW_UART5_RX         (pin_D2)
#define MICROPY_HW_UART6_TX         (pin_C6)
#define MICROPY_HW_UART6_RX         (pin_C7)
#define MICROPY_HW_UART7_TX         (pin_E8)
#define MICROPY_HW_UART7_RX         (pin_E7)
#define MICROPY_HW_UART8_TX         (pin_E1)
#define MICROPY_HW_UART8_RX         (pin_E0)

// I2C
#define MICROPY_HW_I2C1_SCL         (pin_B8)
#define MICROPY_HW_I2C1_SDA         (pin_B9)
#define MICROPY_HW_I2C2_SCL         (pin_B10)
#define MICROPY_HW_I2C2_SDA         (pin_B11)
#define MICROPY_HW_I2C3_SCL         (pin_A8)
#define MICROPY_HW_I2C3_SDA         (pin_C9)
#define MICROPY_HW_I2C4_SCL         (pin_B6)
#define MICROPY_HW_I2C4_SDA         (pin_B7)

// SPI
#define MICROPY_HW_SPI1_NSS         (pin_A4)
#define MICROPY_HW_SPI1_SCK         (pin_A5)
#define MICROPY_HW_SPI1_MISO        (pin_A6)
#define MICROPY_HW_SPI1_MOSI        (pin_A7)
#define MICROPY_HW_SPI2_NSS         (pin_B12)
#define MICROPY_HW_SPI2_SCK         (pin_B13)
#define MICROPY_HW_SPI2_MISO        (pin_B14)
#define MICROPY_HW_SPI2_MOSI        (pin_B15)
#define MICROPY_HW_SPI3_NSS         (pin_A15)
#define MICROPY_HW_SPI3_SCK         (pin_B3)
#define MICROPY_HW_SPI3_MISO        (pin_B4)
#define MICROPY_HW_SPI3_MOSI        (pin_B2)
#define MICROPY_HW_SPI4_NSS         (pin_E4)
#define MICROPY_HW_SPI4_SCK         (pin_E2)
#define MICROPY_HW_SPI4_MISO        (pin_E5)
#define MICROPY_HW_SPI4_MOSI        (pin_E6)
#define MICROPY_HW_SPI6_NSS         (pin_A4)
#define MICROPY_HW_SPI6_SCK         (pin_A5)
#define MICROPY_HW_SPI6_MISO        (pin_A6)
#define MICROPY_HW_SPI6_MOSI        (pin_A7)

// K0 has no pullup or pulldown; Pressing the button makes the input go low.
#define MICROPY_HW_USRSW_PIN        (pin_E3)
#define MICROPY_HW_USRSW_PULL       (GPIO_PULLUP)
#define MICROPY_HW_USRSW_EXTI_MODE  (GPIO_MODE_IT_FALLING)
#define MICROPY_HW_USRSW_PRESSED    (0)

// LEDs
// LED D1 is the power LED and always on
#define MICROPY_HW_LED1             (pin_A1)  // LED D2
#define MICROPY_HW_LED_ON(pin)      (mp_hal_pin_low(pin))
#define MICROPY_HW_LED_OFF(pin)     (mp_hal_pin_high(pin))

// USB config
#define MICROPY_HW_USB_FS              (1)
#define MICROPY_HW_USB_HS              (0)

// FDCAN bus
#define MICROPY_HW_CAN1_NAME  "FDCAN1"
#define MICROPY_HW_CAN1_TX    (pin_D1)
#define MICROPY_HW_CAN1_RX    (pin_D0)

