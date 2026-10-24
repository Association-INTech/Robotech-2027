#include <Arduino.h>
#include "Pince.hpp"
#include "Ascenseur.hpp"

#ifndef PALETTE
#define PALETTE


class Palette{

private:
    // Wether the pince is opened or not
    bool m_open;
    // wether the lift is in high or low position
    bool m_high;

    // the height of the plates when they are lifted to move the boxs
    int m_lifted_height;

    // the distance to move the plates of to grab the boxs
    int m_grab_dist;

    Ascenseur m_lift;
    Pince m_pince;

public:
    Palette(int dir_pin_lift, int step_pin_lift, int m2_pin_lift, int m1_pin_lift, int m0_pin_lift,
            int dir_pin_pince, int step_pin_pince, int m2_pin_pince, int m1_pin_pince, int m0_pin_pince);

    void grab_box();
    void release_box();

};

#endif