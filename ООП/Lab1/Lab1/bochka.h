#pragma once

class Bochka {

    double m_size;
    double m_concentration;

public:

    Bochka() {};
    Bochka(double size, double concentration) { m_size = size; m_concentration = concentration; };

    double Get—oncentration() const { return m_concentration; };
    void Pereliv(Bochka& barrel, double sizeOfCap);

};