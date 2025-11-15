#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"resistor_color.h"



int main() {
    // Array to hold 4 color bands (max 12 chars each + '\0')
    char bands[4][13];

    printf("Input 4 resistor bands (Band1 Band2 Multiplier Tolerance):\n");

    // Read 4 color bands
    for (int i = 0; i < 4; i++) {
        printf("Band %d: ", i + 1);
        scanf("%12s", bands[i]); // safe input, max 12 chars
    }

    // Convert first 3 bands to numeric values
    int v1 = band_value(bands[0]);
    int v2 = band_value(bands[1]);
    int multiplier_power = band_value(bands[2]); // 3rd band is multiplier (power of 10)
    double tol = tolerance_value(bands[3]);      // 4th band is tolerance

    // Check for invalid inputs
    if (v1 == -1 || v2 == -1 || multiplier_power == -1 || tol < 0) {
        printf("Invalid color entered.\n");
        return 1;
    }

    // Calculate resistance
    int resistance = calculate_resistance(v1, v2, multiplier_power);

    // Display result
    printf("Resistance: %d ohms ±%.1f%%\n", resistance, tol);

    return 0;
}

// ------------------------
// Map first 3 bands to digits
int band_value(const char* color) {
    if (strcmp(color, "black") == 0) return 0;
    if (strcmp(color, "brown") == 0) return 1;
    if (strcmp(color, "red") == 0) return 2;
    if (strcmp(color, "orange") == 0) return 3;
    if (strcmp(color, "yellow") == 0) return 4;
    if (strcmp(color, "green") == 0) return 5;
    if (strcmp(color, "blue") == 0) return 6;
    if (strcmp(color, "violet") == 0) return 7;
    if (strcmp(color, "grey") == 0) return 8;
    if (strcmp(color, "white") == 0) return 9;

    return -1; // Invalid color
}

// ------------------------
// Map tolerance band to percentage
double tolerance_value(const char* color) {
    if (strcmp(color, "brown") == 0) return 1.0;
    if (strcmp(color, "red") == 0) return 2.0;
    if (strcmp(color, "green") == 0) return 0.5;
    if (strcmp(color, "blue") == 0) return 0.25;
    if (strcmp(color, "violet") == 0) return 0.1;
    if (strcmp(color, "grey") == 0) return 0.05;
    if (strcmp(color, "gold") == 0) return 5.0;
    if (strcmp(color, "silver") == 0) return 10.0;

    return -1; // Invalid tolerance
}

// ------------------------
// Calculate resistance from band values
int calculate_resistance(int v1, int v2, int multiplier_power) {
    int multiplier = 1;  // 10^0 is 1
    for (int i = 0; i < multiplier_power; i++) {
        multiplier *= 10;
    }
    return (v1 * 10 + v2) * multiplier;
}
