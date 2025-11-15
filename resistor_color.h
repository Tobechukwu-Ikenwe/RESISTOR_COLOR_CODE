#pragma once

#ifndef RESISTOR_COLOR_H
#define RESISTOR_COLOR_H

//fucntion doesnt know bands so make a prototype first using color
int band_value(const char* color);            // Returns digit for first 3 bands
double tolerance_value(const char* color);    // Returns tolerance percentage
int calculate_resistance(int v1, int v2, int multiplier_power);



#endif 


