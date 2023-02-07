//
// Created by SMhd3 on 2/8/2023.
//

#include <stdio.h>
#include "main.h"
#include "AboutScreen.h"
#include "LiquidCrystal.h"
#include "types.h"
#include "RTC.h"

char *firstRowText2 = "     SMhd Asadi     ";
char *secondRowText2 = "     Mew Samurai    ";
extern ScreenType currentScreen;

char *monthArray[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

void AboutScreen_OnEverySecond() {
  char message[21];
  setCursor(0, 0);
  print(firstRowText2);

  setCursor(0, 1);
  print(secondRowText2);

  RTC_DateTypeDef date = RTC_GetCurrentDate();
  sprintf(message, "Date: %2d-%s-%2d     ", date.Year, monthArray[date.Month], date.Date);
  setCursor(0, 2);
  print(message);

  RTC_TimeTypeDef time = RTC_GetCurrentTime();
  setCursor(0, 3);
  sprintf(message, "Time: %2d:%2d:%2d      ", time.Hours, time.Minutes, time.Seconds);
  print(message);
}

void AboutScreen_OnKeyPress() {
  currentScreen = SCREEN_MENU;
}