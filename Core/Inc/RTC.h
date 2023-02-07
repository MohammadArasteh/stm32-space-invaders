//
// Created by SMhd3 on 2/8/2023.
//

#ifndef SPACEINVADERS_RTC_H
#define SPACEINVADERS_RTC_H

#include "stm32f3xx_hal_rtc.h"

void RTC_Init();
RTC_DateTypeDef RTC_GetCurrentDate();
RTC_TimeTypeDef RTC_GetCurrentTime();

#endif //SPACEINVADERS_RTC_H
