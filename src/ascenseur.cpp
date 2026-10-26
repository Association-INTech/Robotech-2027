#include <Servo.h>
#include "Ascenseur.h"
#include <Arduino.h>

Ascenseur::Ascenseur(int broche, int attente) {
    _broche = broche ;
    _enHaut = false ;
    _position_initiale = 0 ;
    _attente = attente;
}

void Ascenseur::begin() {
    _servo.write(_position_initiale);
    _servo.attach(_broche);
}


void Ascenseur::monter() {
    for (int i = 0 ;i <= 180 ; i++ ) {
        _servo.write(i);
        delay(_attente);
    }
    _enHaut = true ;
}



void Ascenseur::descendre() {
    for (int i = 180 ;i >=0 ; i-- ) {
        _servo.write(i);
        delay(_attente);
    }
    _enHaut = false;
}

bool Ascenseur::estEnHaut() {
    return _enHaut
}

