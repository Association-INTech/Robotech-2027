#pragma once
#include <Servo.h>

class Pince {
    public:
        Pince(int broche, int attente);
        void ouvrir();
        void fermer();
        bool estOuverte();
        void begin();

    private:
        Servo _servo ;
        bool _ouverte;
        int _broche;
        int _position_initiale ;
        int _attente ;
};