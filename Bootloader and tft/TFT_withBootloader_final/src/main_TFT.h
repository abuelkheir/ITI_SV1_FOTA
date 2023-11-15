/**
 * @file main_TFT.h
 *
 * @brief Header file for TFT functions in the bootloader application.
 *
 * This file contains function prototypes for various TFT-related functions used in the bootloader.
 * These functions handle displaying information, error messages, and application switching on the TFT screen.
 *
 * @version 1.0
 * @date Nov 9, 2023
 * @author Basel
 */

#ifndef MAIN_TFT_H_
#define MAIN_TFT_H_

/**
 * @brief Write bootloader mode on TFT display.
 *
 * This function writes the bootloader mode on the TFT display.
 *
 * @param None
 * @return None
 */
void writeBootLoaderModeInTFT(void);

/**
 * @brief Write flashing mode on TFT display.
 *
 * This function writes the flashing mode on the TFT display.
 *
 * @param None
 * @return None
 */
void writeFLASHINGModeInTFT(void);

/**
 * @brief Write flashing done on TFT display.
 *
 * This function writes the flashing done status on the TFT display.
 *
 * @param None
 * @return None
 */
void writeFLASHING_DONE(void);

/**
 * @brief Switch to the main application on TFT display.
 *
 * This function switches the TFT display to show the main application.
 *
 * @param None
 * @return None
 */
void Switch_To_Main_APP(void);

/**
 * @brief Switch to the backup application on TFT display.
 *
 * This function switches the TFT display to show the backup application.
 *
 * @param None
 * @return None
 */
void Switch_To_Backup_APP(void);

/**
 * @brief Display error message in hexadecimal on TFT.
 *
 * This function displays an error message in hexadecimal on the TFT display.
 *
 * @param None
 * @return None
 */
void ErrorInHex(void);

#endif /* MAIN_TFT_H_ */
