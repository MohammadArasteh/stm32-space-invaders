//
// Created by Mew on 2/9/2023.
//
#include "main.h"
#include "Buzzer.h"
#include "types.h"
#include "Constants.h"

extern TIM_HandleTypeDef htim8;
TIM_HandleTypeDef *pwm_timer = &htim8;	// Point to PWM Timer configured in CubeMX
uint32_t pwm_channel = TIM_CHANNEL_3;   // Select configured PWM channel number

const Tone *volatile melody_ptr;
volatile uint16_t melody_tone_count;
volatile uint16_t current_tone_number;
volatile uint32_t current_tone_end;
volatile uint16_t volume = 50;          // (0 - 1000)
extern ScreenType currentScreen;

Tone super_mario_bros[] = {
        {2637,306}, // E7 x2
        {   0,153}, // x3 <-- Silence
        {2637,153}, // E7
        {   0,153}, // x3
        {2093,153}, // C7
        {2637,153}, // E7
        {   0,153}, // x3
        {3136,153}, // G7
        {   0,459}, // x3
        {1586,153}, // G6
        {   0,459}, // x3

        {2093,153}, // C7
        {   0,306}, // x2
        {1586,153}, // G6
        {   0,306}, // x2
        {1319,153}, // E6
        {   0,306}, // x2
        {1760,153}, // A6
        {   0,153}, // x1
        {1976,153}, // B6
        {   0,153}, // x1
        {1865,153}, // AS6
        {1760,153}, // A6
        {   0,153}, // x1

        {1586,204}, // G6
        {2637,204}, // E7
        {3136,204}, // G7
        {3520,153}, // A7
        {   0,153}, // x1
        {2794,153}, // F7
        {3136,153}, // G7
        {   0,153}, // x1
        {2637,153}, // E7
        {   0,153}, // x1
        {2093,153}, // C7
        {2349,153}, // D7
        {1976,153}, // B6
        {   0,306}, // x2

        {2093,153}, // C7
        {   0,306}, // x2
        {1586,153}, // G6
        {   0,306}, // x2
        {1319,153}, // E6
        {   0,306}, // x2
        {1760,153}, // A6
        {   0,153}, // x1
        {1976,153}, // B6
        {   0,153}, // x1
        {1865,153}, // AS6
        {1760,153}, // A6
        {   0,153}, // x1

        {1586,204}, // G6
        {2637,204}, // E7
        {3136,204}, // G7
        {3520,153}, // A7
        {   0,153}, // x1
        {2794,153}, // F7
        {3136,153}, // G7
        {   0,153}, // x1
        {2637,153}, // E7
        {   0,153}, // x1
        {2093,153}, // C7
        {2349,153}, // D7
        {1976,153}, // B6

        {   0,  0}	// <-- Disable PWM
};

Tone mute[] = {{0, 0}};

Tone user_shoot[] = {
        {2093,153},
        {0, 0}
};
Tone user_target[] = {
        {2093,153}, // C7
        {   0,306}, // x2
        {0, 0}, // G6
};
Tone enemy_shoot[] = {
        {1586,204},
        {0, 0}
};
Tone enemy_target[] = {
        {1586,204}, // G6
        {2637,204}, // E7
        {0, 0}, // G7
};

void BuzzerInit()
{
    HAL_TIM_PWM_Start(pwm_timer, pwm_channel);
    Change_Melody(super_mario_bros, ARRAY_LENGTH(super_mario_bros));
}

void PWM_Change_Tone(uint16_t pwm_freq, uint16_t v) // pwm_freq (1 - 20000), volume (0 - 1000)
{
    if (pwm_freq == 0 || pwm_freq > 20000)
    {
        __HAL_TIM_SET_COMPARE(pwm_timer, pwm_channel, 0);
    }
    else
    {
        const uint32_t internal_clock_freq = HAL_RCC_GetSysClockFreq();
        const uint16_t prescaler = 1 + internal_clock_freq / pwm_freq / 60000;
        const uint32_t timer_clock = internal_clock_freq / prescaler;
        const uint32_t period_cycles = timer_clock / pwm_freq;
        const uint32_t pulse_width = v * period_cycles / 1000 / 2;

        pwm_timer->Instance->PSC = prescaler - 1;
        pwm_timer->Instance->ARR = period_cycles - 1;
        pwm_timer->Instance->EGR = TIM_EGR_UG;
        __HAL_TIM_SET_COMPARE(pwm_timer, pwm_channel, pulse_width); // pwm_timer->Instance->CCR2 = pulse_width;
    }
}

void Change_Melody(const Tone *melody, uint16_t tone_count)
{
    melody_ptr = melody;
    melody_tone_count = tone_count;
    current_tone_number = 0;
}

void Update_Melody()
{
    if ((HAL_GetTick() > current_tone_end) && (current_tone_number < melody_tone_count))
    {
        const Tone active_tone = *(melody_ptr + current_tone_number);
        PWM_Change_Tone(active_tone.frequency, volume);
        current_tone_end = HAL_GetTick() + active_tone.duration;
        current_tone_number++;
    } else if(current_tone_number >= melody_tone_count)
        if(currentScreen != SCREEN_GAME) current_tone_number = 0;
}
