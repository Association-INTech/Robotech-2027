#include <Servo.h>
#include "Pince.h"
#include <Arduino.h>

Pince::Pince(int broche, int attente) {
    _broche = broche ;
    _ouverte = true ;
    _position_initiale = 180 ;
    _attente = attente;
}

void Pince::begin() {
    _servo.write(_position_initiale);
    _servo.attach(_broche);
}


void Pince::ouvrir() {
    for (int i = 0 ;i <= 180 ; i++ ) {
        _servo.write(i);
        delay(_attente);
    }
    _ouverte = true ;
}



void Pince::fermer() {
    for (int i = 180 ;i >=0 ; i-- ) {
        _servo.write(i);
        delay(_attente);
    }
    _ouverte = false;
}

bool Pince::estOuverte() {
    return _ouverte
}

