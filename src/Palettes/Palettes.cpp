#include "Palettes.hpp"

Palette::Palette(int dir_pin_lift, int step_pin_lift, int m2_pin_lift, int m1_pin_lift, int m0_pin_lift,
            int dir_pin_pince, int step_pin_pince, int m2_pin_pince, int m1_pin_pince, int m0_pin_pince)
    : m_open(false),
      m_high(false),
      m_grab_dist(150), // TODO : adapt this value
      m_lifted_height(200), // TODO : adapt this value,
      m_lift(step_pin_lift, dir_pin_lift, m0_pin_lift, m1_pin_lift, m2_pin_lift),
      m_pince(step_pin_pince, dir_pin_pince, m0_pin_pince, m1_pin_pince, m2_pin_pince, 0, m_grab_dist)
{
}

void Palette::grab_box() {
    // Lower the lift to the ground
    Serial.println("Debut down");
    m_lift.go_down(m_lifted_height);
    Serial.println("Fin down");

    delay(100);

    // Close the pince to grab the box
    Serial.println("début close");
    m_pince.close();
    Serial.println("Fin close");

    delay(100);

    // Lift the box to the lifted height
    Serial.println("Début up");
    m_lift.go_up(m_lifted_height);
    Serial.println("Fin up");
}

void Palette::release_box() {
    // Lower the lift to the ground
    Serial.println("Debut down");
    m_lift.go_down(m_lifted_height);
    Serial.println("Fin down");

    delay(100);

    // Close the pince to grab the box
    Serial.println("début open");
    m_pince.open();
    Serial.println("Fin open");

    delay(100);

    // Lift the box to the lifted height
    Serial.println("Début up");
    m_lift.go_up(m_lifted_height);
    Serial.println("Fin up");
}