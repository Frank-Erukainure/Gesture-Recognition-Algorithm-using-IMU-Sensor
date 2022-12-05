#include "imu.h"

#include "Window.h"
#include "Classifier.h"

Window window;
Eloquent::ML::Port::Classifier clf;

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
    
    float sample[] = {ax, ay, az};
    // feed data to the window and wait until the window is full
    if (!window.transform(sample))
      return;

    // predict gesture
    Serial.print("Gesture: ");
    Serial.println(clf.predictLabel(window.features));
    
    delay(1000);
}
