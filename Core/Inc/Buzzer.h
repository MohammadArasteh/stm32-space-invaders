//
// Created by Mew on 2/9/2023.
//

#ifndef SPACEINVADERS_BUZZER_H
#define SPACEINVADERS_BUZZER_H

#include "main.h"

typedef struct
{
    uint16_t frequency;
    uint16_t duration;
} Tone;

void BuzzerInit();
void PWM_Change_Tone(uint16_t pwm_freq, uint16_t volume);
void Change_Melody(const Tone *melody, uint16_t tone_count);
void Update_Melody();

#endif //SPACEINVADERS_BUZZER_H
