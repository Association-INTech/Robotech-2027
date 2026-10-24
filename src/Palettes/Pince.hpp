#include <Arduino.h>
#include "AccelStepper.h"

#ifndef PINCE
#define PINCE


class Pince{
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

    // dist between the two plates when the pincers are closed
    int m_closed_pos;
    // dist between the two plates when the pincers are open
    int m_open_pos;

public:
    Pince(int step_pin, int dir_pin, int m0_pin, int m1_pin, int m2_pin, int dist_of_closing = 0, int dist_of_opening = 4);

    // open and close from the preset values
    void close();
    void open();

    // opens and close of length value.
    // Length corresponds to the distance the two plates are getting closer the one from the other
    void open_of(int length);
    void close_of(int length);

    bool is_closed();


};


#endif