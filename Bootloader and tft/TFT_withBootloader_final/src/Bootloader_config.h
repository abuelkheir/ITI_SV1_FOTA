/**
 * @file Bootloader_config.h
 *
 * @brief Configuration file for the bootloader.
 *
 * This file defines constants related to the bootloader, such as flash addresses and vector table offsets.
 *
 * @version 1.0
 * @date Nov 10, 2023
 * @author Basel Ibrahim
 */

#ifndef BOOTLOADER_CONFIG_H_
#define BOOTLOADER_CONFIG_H_

/**
 * @brief First flash address for the backup application.
 */
#define FIRST_FLASH_ADDRESS_BACKUP  0x08000000

/**
 * @brief First flash address for the main application.
 */
#define FIRST_FLASH_ADDRESS_MAIN    0x08020000

/**
 * @brief Vector table offset for sector 5.
 */
#define VECTOR_TABLE_OFFSET_SECTOR1 0x08020000

/**
 * @brief Vector table offset for sector 3.
 */
#define VECTOR_TABLE_OFFSET_SECTOR2 0x0800C000

#endif /* BOOTLOADER_CONFIG_H_ */
