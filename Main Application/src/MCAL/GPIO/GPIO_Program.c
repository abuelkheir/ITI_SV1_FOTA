/*
 * GPIO_Program.c
 *
 *  Created on: 7/9/2023 12 BM
 *      Author: omara
 */

// MODULE FEATURES :
/*
1-
2-
3-

*/

// STANDER TYPES
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/bit_macros.h"

// MCAL COMPONENTS
#include "GPIO_Private.h"
#include "GPIO_Interface.h"
#include "GPIO_Config.h"

void MGPIO_voidSetPinMode(u8 Copy_8uPortName, u8 Copy_u8PinNum, u8 Copy_u8Mode)
{
    if (Copy_u8PinNum < 16)
    {
        switch (Copy_8uPortName)
        {
        case MGPIOA_PORT:
            MGPIOA->MODER |= (u32)(Copy_u8Mode << (2U * Copy_u8PinNum));
            break;
        case MGPIOB_PORT:
            MGPIOB->MODER |= (u32)(Copy_u8Mode << (2U * Copy_u8PinNum));
            break;

            //!       #if STM_MODEL STM32F401CC
        case MGPIOC_PORT:
            if (12 < Copy_u8PinNum)
            {
                MGPIOC->MODER |= (u32)(Copy_u8Mode << (2U * Copy_u8PinNum));
            }
            else
            {
                // report error port c pin numper of boundry
            }
            break;

            //!     #elif STM_MODEL

            /*
            case MGPIOCD_PORT:
                 MGPIOD->MODER |= (u32)(Copy_u8Mode << (2U * Copy_u8PinNum));
                break;
            case MGPIOE_PORT:
                 MGPIOE->MODER |= (u32)(Copy_u8Mode << (2U * Copy_u8PinNum));
                break;
            case MGPIOH_PORT:
                 MGPIOH->MODER |= (u32)(Copy_u8Mode << (2U * Copy_u8PinNum));
                break;
            */
            //!    #ENDIF
        default:
            break; // REPORT EEROR PORT NAME ERROR
        }
    }
    else
    {
        // REPORT ERROR PIN NUMBER OUT OF BOUNDRY
    }
}

void MGPIO_voidSetPortMode(u8 Copy_8uPortName, u32 Copy_u32Mode)
{
    switch (Copy_8uPortName)
    {
    case MGPIOA_PORT:
        MGPIOA->MODER |= Copy_u32Mode;
        break;
    case MGPIOB_PORT:
        MGPIOB->MODER |= Copy_u32Mode;
        break;
    case MGPIOC_PORT:
        MGPIOC->MODER |= (Copy_u32Mode & 0XFC00);
        break;
    default:
        break; // REPORT EEROR PORT NAME ERROR
    }
}

void MGPIO_voidSetOutPutMode(u8 Copy_8uPortName, u8 Copy_u8PinNum, u8 Copy_u8OutPutMode)
{
    if (Copy_u8PinNum < 16)
    {
        switch (Copy_8uPortName)
        {
        case MGPIOA_PORT:
            MGPIOA->OTYPER |= (u32)(Copy_u8OutPutMode << (Copy_u8PinNum));
            break;
        case MGPIOB_PORT:
            MGPIOB->OTYPER |= (u32)(Copy_u8OutPutMode << (Copy_u8PinNum));
            break;
        case MGPIOC_PORT:
            MGPIOC->OTYPER |= (u32)(Copy_u8OutPutMode << (Copy_u8PinNum));
            break;
        default:
            break; // EEROR
        }
    }
    else
    {
    	// #ERROR
    }
}

void MGPIO_voidSetOutPutSpeed(u8 Copy_8uPortName, u8 Copy_u8PinNum, u8 Copy_u8OutPutSpeed)
{
    if (Copy_u8PinNum < 16)
    {
        switch (Copy_8uPortName)
        {
        case MGPIOA_PORT:
            MGPIOA->OSPEEDR |= (u32)(Copy_u8OutPutSpeed << (2U * Copy_u8PinNum));
            break;
        case MGPIOB_PORT:
            MGPIOB->OSPEEDR |= (u32)(Copy_u8OutPutSpeed << (2U * Copy_u8PinNum));
            break;

            //!       #if STM_MODEL STM32F401CC
        case MGPIOC_PORT:
            if (12 < Copy_u8PinNum)
            {
                MGPIOC->OSPEEDR |= (u32)(Copy_u8OutPutSpeed << (2U * Copy_u8PinNum));
            }
            else
            {
                // report error port c pin numper of boundry
            }
            break;
        default:
            break; // REPORT EEROR PORT NAME ERROR
        }
    }
    else
    {
        // REPORT ERROR PIN NUMBER OUT OF BOUNDRY
    }
}

void MGPIO_voidSetPullState(u8 Copy_8uPortName, u8 Copy_u8PinNum, u8 Copy_u8PullState)
{
    if (Copy_u8PinNum < 16)
    {
        switch (Copy_8uPortName)
        {
        case MGPIOA_PORT:
            MGPIOA->PUPDR |= (u32)(Copy_u8PullState << (2U * Copy_u8PinNum));
            break;
        case MGPIOB_PORT:
            MGPIOB->PUPDR |= (u32)(Copy_u8PullState << (2U * Copy_u8PinNum));
            break;

            //!       #if STM_MODEL STM32F401CC
        case MGPIOC_PORT:
            if (12 < Copy_u8PinNum)
            {
                MGPIOC->PUPDR |= (u32)(Copy_u8PullState << (2U * Copy_u8PinNum));
            }
            else
            {
                // report error port c pin numper of boundry
            }
            break;
        default:
            break; // REPORT EEROR PORT NAME ERROR
        }
    }
    else
    {
        // REPORT ERROR PIN NUMBER OUT OF BOUNDRY
    }
}

u8 MGPIO_u8GetPinVal(u8 Copy_8uPortName, u8 Copy_u8PinNum)
{
    u8 L_u8_pinValue=0;
    switch (Copy_8uPortName)
    {
    case MGPIOA_PORT:
        L_u8_pinValue = GET_BIT(MGPIOA->IDR, Copy_u8PinNum);
        break;
    case MGPIOB_PORT:
        L_u8_pinValue = GET_BIT(MGPIOB->IDR, Copy_u8PinNum);
        break;
    case MGPIOC_PORT:
        L_u8_pinValue = GET_BIT(MGPIOC->IDR, Copy_u8PinNum);
        break;
    default:
        break; // EEROR
    }
    return L_u8_pinValue;
}

void MGPIO_voidSetPinVal(u8 Copy_8uPortName, u8 Copy_u8PinNum, u8 Copy_u8PinVal)
{
    if (Copy_u8PinNum < 16)
    {
        if (Copy_u8PinVal == MGPIO_HIGH)
        {
            switch (Copy_8uPortName)
            {
            case MGPIOA_PORT:
                SET_BIT(MGPIOA->ODR, Copy_u8PinNum);
                break;
            case MGPIOB_PORT:
                SET_BIT(MGPIOB->ODR, Copy_u8PinNum);
                break;
            case MGPIOC_PORT:
                if (Copy_u8PinNum > 12)
                {
                    SET_BIT(MGPIOC->ODR, Copy_u8PinNum);
                }
                else
                {
                    // ERROR
                }
                break;
            default:
                break;
            } // SWITCH

        } // IF HIGH
        else if (Copy_u8PinVal == MGPIO_LOW)
        {
            switch (Copy_8uPortName)
            {
            case MGPIOA_PORT:
                CLR_BIT(MGPIOA->ODR, Copy_u8PinNum);
                break;
            case MGPIOB_PORT:
                CLR_BIT(MGPIOB->ODR, Copy_u8PinNum);
                break;
            case MGPIOC_PORT:
                if (Copy_u8PinNum > 12)
                {
                    CLR_BIT(MGPIOC->ODR, Copy_u8PinNum);
                }
                else
                {
                    // ERROR
                }
                break;
            default:
                break;
            } // SWITCH

        } // ELSE IF LOW

    } // IF 16
    else if (Copy_u8PinNum > 15)
    {
        // ERROR
    }
}

void MGPIO_voidDirectSetReset(u8 Copy_8uPortName, u8 Copy_u8PinNum, u8 Copy_u8SetResetState)
{
    if (Copy_u8SetResetState == MGPIO_HIGH)
    {
        switch (Copy_8uPortName)
        {
        case MGPIOA_PORT:
            MGPIOA->BSRR = (Copy_u8SetResetState << Copy_u8PinNum);
            break;
        case MGPIOB_PORT:
            MGPIOB->BSRR = (Copy_u8SetResetState << Copy_u8PinNum);
            break;
        case MGPIOC_PORT:
            MGPIOC->BSRR = (Copy_u8SetResetState << Copy_u8PinNum);
            break;

        default:
            break;
        }
    }
    else if (Copy_u8SetResetState == MGPIO_LOW)
    {
        Copy_u8PinNum += 16;

        switch (Copy_8uPortName)
        {
        case MGPIOA_PORT:
            MGPIOA->BSRR = (1U << Copy_u8PinNum);
            break;
        case MGPIOB_PORT:
            MGPIOB->BSRR = (1U << Copy_u8PinNum);
            break;
        case MGPIOC_PORT:
            MGPIOC->BSRR = (1U << Copy_u8PinNum);
            break;
        default:
            break;
        }
    }
}

void MGPIO_voidSetPortVal(u8 Copy_8uPortName, u16 Copy_u16OutPutVal)
{
    switch (Copy_8uPortName)
    {
    case MGPIOA_PORT:
        MGPIOA->ODR = Copy_u16OutPutVal;
        break;
    case MGPIOB_PORT:
        MGPIOB->ODR = Copy_u16OutPutVal;
        break;
    case MGPIOC_PORT:
        MGPIOC->ODR |= (Copy_u16OutPutVal & 0XE000);
        break;
    default:
        break;
    }
}

void MGPIO_voidSetPinLock(u8 Copy_8uPortName, u8 Copy_u8PinNum)
{
    if (Copy_u8PinNum < 16)
    {
        switch (Copy_8uPortName)
        {
        case MGPIOA_PORT:
            SET_BIT(MGPIOA->LCKR, Copy_u8PinNum);
            break;
        case MGPIOB_PORT:
            SET_BIT(MGPIOB->LCKR, Copy_u8PinNum);
            break;
            //!       #if STM_MODEL STM32F401CC
        case MGPIOC_PORT:
            if (12 < Copy_u8PinNum)
            {
                SET_BIT(MGPIOC->LCKR, Copy_u8PinNum);
            }
            else
            {
                // report error port c pin numper of boundry
            }
            break;
        default:
            break; // REPORT EEROR PORT NAME ERROR
        }
    }
    else if (Copy_u8PinNum == 17)
    {
        //PIN 17 MAKE SOMETHING
    }   
    else
    {
        // REPORT ERROR PIN NUMBER OUT OF BOUNDRY
    }
}

void MGPIO_voidSetAltFun(u8 Copy_8uPortName, u8 Copy_u8PinNum, u8 Copy_u8AltFun)
    {
        if (Copy_u8PinNum <= 7u)
        {
            switch (Copy_8uPortName)
            {
            case MGPIOA_PORT:
                MGPIOA->AFRL |= (Copy_u8AltFun << 4U * (Copy_u8PinNum));
                break;
            case MGPIOB_PORT:
                MGPIOB->AFRL |= (Copy_u8AltFun << 4U * (Copy_u8PinNum));
                break;
            case MGPIOC_PORT:
                MGPIOC->AFRL |= (Copy_u8AltFun << 4U * (Copy_u8PinNum));
                break;
            default:
                break;
            }
        }
        else if (Copy_u8PinNum <= 15u)
        {
            switch (Copy_8uPortName)
            {

            case MGPIOA_PORT:
                MGPIOA->AFRH |= (Copy_u8AltFun << 4U * (Copy_u8PinNum-8));
                break;
            case MGPIOB_PORT:
                MGPIOB->AFRH |= (Copy_u8AltFun << 4U * (Copy_u8PinNum-8));
                break;
            case MGPIOC_PORT:
                MGPIOC->AFRH |= (Copy_u8AltFun << 4U * (Copy_u8PinNum-8));
                break;
            default:
                break;
            }
        }
    }
