#include <EEPROM.h>

#define HALL_SENSOR_PIN 2 // Hall sensor input pin
#define ESC_PIN 9 // ESC output pin
#define SERIAL_BAUD 115200 // Serial communication baud rate

volatile unsigned long lastTick = 0;
volatile unsigned long rpm = 0;
volatile bool dtReady = false;
unsigned long lastEEPROMWrite = 0;

// Initialize PWM value
int pwmValue = 0;
int tractionControlThreshold = 100; // Arbitrary threshold for traction control

void setup() {
    Serial.begin(SERIAL_BAUD);
    pinMode(HALL_SENSOR_PIN, INPUT);
    pinMode(ESC_PIN, OUTPUT);
    
    // Load configuration from EEPROM
    EEPROM.get(0, tractionControlThreshold);

    // Initialize ESC
    analogWrite(ESC_PIN, 0);
    delay(1000);
    analogWrite(ESC_PIN, pwmValue); // Start the ESC
}

void loop() {
    // Dummy main control logic
    if (dtReady) {
        controlPwm();
        dtReady = false;
    }

    // Regular checks and updates
    if (millis() - lastEEPROMWrite > 60000) { // Every minute
        EEPROM.put(0, tractionControlThreshold);
        lastEEPROMWrite = millis();
    }

    // RPM measurement (this should be in an ISR, simplified here)
    rpmMeasurement();
}

void controlPwm() {
    // Implement traction control logic
    if (rpm > tractionControlThreshold) {
        pwmValue = constrain(pwmValue - 10, 0, 255); // Decrease PWM to prevent wheelie
    } else {
        pwmValue = constrain(pwmValue + 10, 0, 255); // Increase PWM otherwise
    }
    analogWrite(ESC_PIN, pwmValue);
}

void rpmMeasurement() {
    // Placeholder for future implementation
    // This function should be called in an ISR triggered by the hall sensor
    // Calculate rpm and set dtReady flag accordingly
    unsigned long now = millis();
    unsigned long dt = now - lastTick;

    if (dt > 0) {
        rpm = (60000 / dt); // Calculate RPM
        lastTick = now;
        dtReady = true;
        
        Serial.println(rpm);
    }
}

void hallSensorISR() {
    // Triggered on hall sensor input
    rpmMeasurement();
}