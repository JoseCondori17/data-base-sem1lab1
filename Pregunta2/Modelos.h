
#ifndef UNTITLED5_MODELS_H
#define UNTITLED5_MODELS_H

#include "headers.h"

struct Alumno {
    std::string Nombre;
    std::string Apellidos;
    std::string Carrera;
    float mensualidad;

    Alumno() = default;
    virtual ~Alumno(){}
    Alumno(std::string nombre, std::string apellidos, std::string carrera, float mensualidad)
            : Nombre(move(nombre)), Apellidos(move(apellidos)), Carrera(move(carrera)), mensualidad(mensualidad) {}


    void showDataLine() const {
        std::cout << std::setw(15) << std::left << this->Nombre
             << std::setw(20) << std::left << this->Apellidos
             << std::setw(15) << std::left << this->Carrera
             << std::setw(10) << std::left << this->mensualidad << std::endl;
    }
};

#endif //UNTITLED5_MODELS_H
