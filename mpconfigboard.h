/*
 * The MIT License (MIT)
 * Copyright (c) 2022 Myth
 */

#define MICROPY_HW_BOARD_NAME "WEACT_H750VBT6"
#define MICROPY_HW_MCU_NAME "STM32H750VBT6"
#define MICROPY_HW_FLASH_FS_LABEL "WEACT_H750VBT6"

#define MICROPY_FATFS_EXFAT (1)
#define MICROPY_HW_ENABLE_RTC (1)
#define MICROPY_HW_HAS_LCD (1)
#define MICROPY_HW_ENABLE_RNG (1)
#define MICROPY_HW_ENABLE_ADC (1)
#define MICROPY_HW_ENABLE_DAC (1)
#define MICROPY_HW_ENABLE_USB (1)
#define MICROPY_HW_HAS_SWITCH (1)
#define MICROPY_HW_HAS_FLASH (1)
#define MICROPY_HW_ENABLE_SERVO (1)
#define MICROPY_HW_ENABLE_TIMER (1)
#define MICROPY_HW_ENABLE_SDCARD (1)
#define MICROPY_HW_ENABLE_MMCARD (0)

// Flash storage config
#define MICROPY_HW_SPIFLASH_ENABLE_CACHE (1)
#define MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE (0)

#define MICROPY_BOARD_EARLY_INIT WEACT_H750VBT6_board_early_init
void WEACT_H750VBT6_board_early_init(void);

// Clock config
#define MICROPY_HW_CLK_PLLM (5)
#define MICROPY_HW_CLK_PLLN (192)
#define MICROPY_HW_CLK_PLLP (2)
#define MICROPY_HW_CLK_PLLQ (2)
#define MICROPY_HW_CLK_PLLR (2)
#define MICROPY_HW_CLK_PLLVCI (RCC_PLL1VCIRANGE_1)
#define MICROPY_HW_CLK_PLLVCO (RCC_PLL1VCOWIDE)
#define MICROPY_HW_CLK_PLLFRAC (0)

#define MICROPY_HW_CLK_PLL3M (5)
#define MICROPY_HW_CLK_PLL3N (96)
#define MICROPY_HW_CLK_PLL3P (2)
#define MICROPY_HW_CLK_PLL3Q (10)
#define MICROPY_HW_CLK_PLL3R (8)
#define MICROPY_HW_CLK_PLL3VCI (RCC_PLL3VCIRANGE_1)
#define MICROPY_HW_CLK_PLL3VCO (RCC_PLL3VCOWIDE)
#define MICROPY_HW_CLK_PLL3FRAC (0)

// 32kHz crystal for RTC
#define MICROPY_HW_RTC_USE_LSE (1)
#define MICROPY_HW_RTC_USE_US (0)

#if (MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE == 0)
// W25Q64 for storage
#define MICROPY_HW_QSPI_PRESCALER (2) // 100MHz
#define MICROPY_HW_QSPIFLASH_SIZE_BITS_LOG2 (26)
#define MICROPY_HW_SPIFLASH_SIZE_BITS (64 * 1024 * 1024)
#define MICROPY_HW_QSPIFLASH_CS (pin_B6)
#define MICROPY_HW_QSPIFLASH_SCK (pin_B2)
#define MICROPY_HW_QSPIFLASH_IO0 (pin_D11)
#define MICROPY_HW_QSPIFLASH_IO1 (pin_D12)
#define MICROPY_HW_QSPIFLASH_IO2 (pin_E2)
#define MICROPY_HW_QSPIFLASH_IO3 (pin_D13)

// SPI flash, block device config
extern const struct _mp_spiflash_config_t spiflash_config;
extern struct _spi_bdev_t spi_bdev;
#define MICROPY_HW_BDEV_IOCTL(op, arg) (                                                                                                                                           \
    (op) == BDEV_IOCTL_NUM_BLOCKS ? (MICROPY_HW_SPIFLASH_SIZE_BITS / 8 / FLASH_BLOCK_SIZE) : (op) == BDEV_IOCTL_INIT ? spi_bdev_ioctl(&spi_bdev, (op), (uint32_t)&spiflash_config) \
                                                                                                                     : spi_bdev_ioctl(&spi_bdev, (op), (arg)))
#define MICROPY_HW_BDEV_READBLOCKS(dest, bl, n) spi_bdev_readblocks(&spi_bdev, (dest), (bl), (n))
#define MICROPY_HW_BDEV_WRITEBLOCKS(src, bl, n) spi_bdev_writeblocks(&spi_bdev, (src), (bl), (n))
#define MICROPY_HW_BDEV_SPIFLASH_EXTENDED (&spi_bdev)
#endif

// 4 wait states
#define MICROPY_HW_FLASH_LATENCY FLASH_LATENCY_2

// UART
// NOTE: You can enable more UARTs here.
#define MICROPY_HW_UART1_TX (pin_A9)
#define MICROPY_HW_UART1_RX (pin_A10)

#define MICROPY_HW_UART2_TX (pin_A2)
#define MICROPY_HW_UART2_RX (pin_A3)

// I2C busses
// NOTE: You can enable more I2C busses here.
#define MICROPY_HW_I2C1_SCL (pin_B8)
#define MICROPY_HW_I2C1_SDA (pin_B9)

#define MICROPY_HW_I2C2_SCL (pin_B10)
#define MICROPY_HW_I2C2_SDA (pin_B11)

// SPI busses
// NOTE: You can enable more SPI busses here.
#define MICROPY_HW_SPI1_NSS (pin_A4)
#define MICROPY_HW_SPI1_SCK (pin_A5)
#define MICROPY_HW_SPI1_MISO (pin_A6)
#define MICROPY_HW_SPI1_MOSI (pin_A7)

#define MICROPY_HW_SPI2_NSS (pin_B12)
#define MICROPY_HW_SPI2_SCK (pin_B13)
#define MICROPY_HW_SPI2_MISO (pin_B14)
#define MICROPY_HW_SPI2_MOSI (pin_B15)

// CAN busses
// NOTE: You can enable more CAN busses here.
#define MICROPY_HW_CAN1_TX (pin_B9)
#define MICROPY_HW_CAN1_RX (pin_B8)

// USRSW
#define MICROPY_HW_USRSW_PIN (pin_C13) // K1 on the board.
#define MICROPY_HW_USRSW_PULL (GPIO_NOPULL)
#define MICROPY_HW_USRSW_EXTI_MODE (GPIO_MODE_IT_FALLING)
#define MICROPY_HW_USRSW_PRESSED (0)

// LEDs
#define MICROPY_HW_LED1 (pin_E3) // BLUE_LED, the only controlable LED on the board.
#define MICROPY_HW_LED_ON(pin) (mp_hal_pin_low(pin))
#define MICROPY_HW_LED_OFF(pin) (mp_hal_pin_high(pin))

// SD Card SDMMC
#define MICROPY_HW_SDCARD_SDMMC (1)
#define MICROPY_HW_SDCARD_CK (pin_C12)
#define MICROPY_HW_SDCARD_CMD (pin_D2)
#define MICROPY_HW_SDCARD_D0 (pin_C8)
#define MICROPY_HW_SDCARD_D1 (pin_C9)
#define MICROPY_HW_SDCARD_D2 (pin_C10)
#define MICROPY_HW_SDCARD_D3 (pin_C11)

// USB config
#define MICROPY_HW_USB_FS (1)
