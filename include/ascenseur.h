#pragma once
#include <Servo.h>

class Ascenseur {
    public:
        Ascenseur(int broche, int attente);
        void monter();
        void descendre();
        bool estEnHaut();
        void begin();

    private:
        Servo _servo ;
        bool _enHaut;
        int _broche;
        int _position_initiale ;
        int _attente ;
};