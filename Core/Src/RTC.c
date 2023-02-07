//
// Created by SMhd3 on 2/8/2023.
//

#include "main.h"
#include "RTC.h"
#include "stm32f3xx_hal.h"

extern RTC_HandleTypeDef hrtc;

void RTC_Init() {
  RTC_TimeTypeDef time = {.Hours = 18, .Minutes = 0, .Seconds = 0};
  HAL_RTC_SetTime(&hrtc, &time, RTC_FORMAT_BIN);

  RTC_DateTypeDef date = {.Year = 23, .Month = 2, .Date = 0};
  HAL_RTC_SetDate(&hrtc, &date, RTC_FORMAT_BIN);
}

RTC_DateTypeDef RTC_GetCurrentDate() {
  RTC_DateTypeDef date;
  HAL_RTC_GetDate(&hrtc, &date, RTC_FORMAT_BIN);

  return date;
}

RTC_TimeTypeDef RTC_GetCurrentTime() {
  RTC_TimeTypeDef time;
  HAL_RTC_GetTime(&hrtc, &time, RTC_FORMAT_BIN);

  return time;
}