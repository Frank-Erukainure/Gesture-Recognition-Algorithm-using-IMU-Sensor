#include "imu.h"

#define NUM_SAMPLES 30
#define NUM_AXES 3
// sometimes you may get "spikes" in the readings
// set a sensible value to truncate too large values
#define TRUNCATE_AT 20

double features[NUM_SAMPLES * NUM_AXES];

void setup() {
    Serial.begin(115200);
    imu_setup();
}

void loop() {
    float ax, ay, az;

    imu_read(&ax, &ay, &az);

    ax = constrain(ax, -TRUNCATE_AT, TRUNCATE_AT);
    ay = constrain(ay, -TRUNCATE_AT, TRUNCATE_AT);
    az = constrain(az, -TRUNCATE_AT, TRUNCATE_AT);

    Serial.print(ax);
    Serial.print('\t');
    Serial.print(ay);
    Serial.print('\t');
    Serial.println(az);
    
    delay(500);
}
