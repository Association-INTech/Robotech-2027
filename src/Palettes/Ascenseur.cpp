#include "Ascenseur.hpp"


Ascenseur::Ascenseur(int step_pin, int dir_pin, int m0_pin, int m1_pin, int m2_pin)
    : m_step_pin(step_pin),
    m_dir_pin(dir_pin),
    m_m0_pin(m0_pin),
    m_m1_pin(m1_pin),
    m_m2_pin(m2_pin),
    m_stepsPerRevolution(200),
    m_microStepSetting(1),
    m_motor(AccelStepper::DRIVER, step_pin, dir_pin),
    m_min_height(-1),
    m_max_height(-1)
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
    //rail.setMaxSpeed(Max_Speed_StepsPerSec);
    
    float AccelRPMperSec = 3000; // Set acceleration in rpm/sec
    float Accel_StepsPerSec2 = m_microStepSetting * m_stepsPerRevolution * AccelRPMperSec / 60;
    m_motor.setAcceleration(Accel_StepsPerSec2);

    m_motor.setCurrentPosition(0);
}

Ascenseur::Ascenseur(int step_pin, int dir_pin, int m0_pin, int m1_pin, int m2_pin, int min_height, int max_height) 
    : m_step_pin(step_pin),
    m_dir_pin(dir_pin),
    m_m0_pin(m0_pin),
    m_m1_pin(m1_pin),
    m_m2_pin(m2_pin),
    m_stepsPerRevolution(200),
    m_microStepSetting(1),
    m_motor(AccelStepper::DRIVER, step_pin, dir_pin),
    m_min_height(min_height),
    m_max_height(max_height)
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

    m_motor.setCurrentPosition(m_min_height);
}


bool Ascenseur::go_down(int height){
    if(height < 0){
        return false;
    }

    if (m_motor.currentPosition() - height < m_min_height && m_min_height > 0){
        m_motor.move(height);

        while (m_motor.distanceToGo() != 0) {
            m_motor.run();
        }

        return false;
    }

    m_motor.move(- height);
    while (m_motor.distanceToGo() != 0) {
        m_motor.run();
    }

    return true;
}

bool Ascenseur::go_up(int height){
    if(height < 0){
        return false;
    }

    if (m_motor.currentPosition() + height > m_max_height && m_max_height > 0){
        m_motor.move(height);

        while (m_motor.distanceToGo() != 0) {
            m_motor.run();
        }

        return false;
    }

    m_motor.move(height);
    while (m_motor.distanceToGo() != 0) {
        m_motor.run();
    }

    return true;
}

