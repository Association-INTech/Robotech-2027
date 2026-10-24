#include "Pince.hpp"

Pince::Pince(int step_pin, int dir_pin, int m0_pin, int m1_pin, int m2_pin, int dist_of_closing, int dist_of_opening) : 
    m_step_pin(step_pin),
    m_dir_pin(dir_pin),
    m_m0_pin(m0_pin),
    m_m1_pin(m1_pin),
    m_m2_pin(m2_pin),
    m_stepsPerRevolution(200),
    m_microStepSetting(1),
    m_motor(AccelStepper::DRIVER, step_pin, dir_pin),
    m_closed_pos(dist_of_closing),
    m_open_pos(dist_of_opening)
{
    
    // Set microstepping pins as outputs
    pinMode(m_m0_pin, OUTPUT);
    pinMode(m_m1_pin, OUTPUT);
    pinMode(m_m2_pin, OUTPUT);

    // Set microstepping mode (adjust as needed: HIGH or LOW)
    digitalWrite(m_m0_pin, LOW);  // Adjust microstepping settings as needed
    digitalWrite(m_m1_pin, LOW);
    digitalWrite(m_m2_pin, LOW);

    // Set the max speed and acceleration
    float MaxRPM = 300; // Set max speed in rpm (revolutions per minute)
    float Max_Speed_StepsPerSec = m_microStepSetting * m_stepsPerRevolution * MaxRPM / 60; // Specify max speed in steps/sec (converted from RPM)
    m_motor.setMaxSpeed(Max_Speed_StepsPerSec);
    
    float AccelRPMperSec = 3000; // Set acceleration in rpm/sec
    float Accel_StepsPerSec2 = m_microStepSetting * m_stepsPerRevolution * AccelRPMperSec / 60;
    m_motor.setAcceleration(Accel_StepsPerSec2);

    m_motor.setCurrentPosition(0);
}


void Pince::close() {
    m_motor.moveTo(-m_closed_pos);
    while (m_motor.distanceToGo() != 0) {
        m_motor.run();
    }
}
bool Pince::is_closed() {
    return m_motor.currentPosition() == long(m_closed_pos);
}

void Pince::open() {
    m_motor.moveTo(m_open_pos);
    while (m_motor.distanceToGo() != 0) {
        m_motor.run();
    }
}

void Pince::open_of(int length) {
    m_motor.move(length);
    while (m_motor.distanceToGo() != 0) {
        m_motor.run();
    }
}

void Pince::close_of(int length) {
    m_motor.move(-length);
    while (m_motor.distanceToGo() != 0) {
        m_motor.run();
    }
}