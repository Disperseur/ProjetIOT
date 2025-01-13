/*****************************************************************************
 * Copyright (c) 2024 Renesas Electronics Corporation
 * All Rights Reserved.
 * 
 * This code is proprietary to Renesas, and is license pursuant to the terms and
 * conditions that may be accessed at:
 * https://www.renesas.com/eu/en/document/msc/renesas-software-license-terms-gas-sensor-software
 *****************************************************************************/

/**
 * @file    zmod4xxx_cleaning.h
 * @brief   This file contains the cleaning function definition for ZMOD4xxx.
 * @version 2.8.0
 * @author  Renesas Electronics Corporation
 * @details The library contains the function that starts the cleaning procedure.
 *          **The procedure takes 1 minute.** After successful cleaning,
 *          the function returns 0. **The procedure can be run only once.**
 */

#ifndef _ZMOD4XXX_CLEANING_H_
#define _ZMOD4XXX_CLEANING_H_

#include "zmod4xxx.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Perform cleaning in a blocking function
 * This function starts the cleaning procedure and returns after cleaning has
 * finished. If cleaning needs to be performed, the function requires 
 * approximately one minute to complete. If cleaning has been performed before,
 * the error code ERROR_CLEANING is returned immediately.
 * @param [in] dev pointer to the device
 * @return Error code
 * @retval 0 Success
 * @retval "!= 0" Error
 */
int8_t zmod4xxx_cleaning_run(zmod4xxx_dev_t *dev);

/**
 * @brief Start a cleaning procedure
 * This function starts the cleaning procedure and returns immediatly, allowing
 * the MCU to perfom other tasks. If cleaning has been performed before the
 * error code ERROR_CLEANING is returned. If this function succeeds, the
 * function zmod4xxx_cleaning_finalize must be called after >1min to finalize
 * the cleaning.
 * @note: No other ZMOD4xxx API functions must be called for the device being
 *        cleaned while the cleaning procedure is ongoing!
 * @param [in] dev pointer to the device
 * @return Error code
 * @retval 0 Success
 * @retval "!= 0" Error
 */
int8_t zmod4xxx_cleaning_start(zmod4xxx_dev_t* dev);

/**
 * @brief Finalize the cleaning procedure
 * This function verifies that the cleaning has been completed successfully and
 * udpates the ZMOD4xxx.
 * @param [in] dev pointer to the device
 * @return Error code
 * @retval 0 Success
 * @retval "!= 0" Error
 */
int8_t zmod4xxx_cleaning_finalize(zmod4xxx_dev_t* dev);

#ifdef __cplusplus
}
#endif

#endif /* _ZMOD4XXX_CLEANING_H_ */
