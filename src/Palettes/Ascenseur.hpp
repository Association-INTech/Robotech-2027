#include <Arduino.h>
#include <AccelStepper.h>

#ifndef ASCENSEUR
#define ASCENSEUR


class Ascenseur{

public:
    Ascenseur(int step_pin, int dir_pin, int m0_pin, int m1_pin, int m2_pin);
    Ascenseur(int step_pin, int dir_pin, int m0_pin, int m1_pin, int m2_pin, int min_height, int max_height);

    bool go_down(int height);
    bool go_up(int height);

    
private:
    const int m_step_pin;
    const int m_dir_pin;
    
    const int m_m0_pin;
    const int m_m1_pin;
    const int m_m2_pin;
    
    // the consts which are the stepper's properties
    const float m_stepsPerRevolution;
    const int m_microStepSetting;

    // the stepper motor object, to be able to make it go up or down
    AccelStepper m_motor;

    // if these values are set at -1, the feature is disabled
    int m_min_height;
    int m_max_height;

};

#endif