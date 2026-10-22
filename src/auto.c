#include "main.h"

void drive(int leftPower, int rightPower) {
    motorSet(LEFT_DRIVE_MOTOR, leftPower);
    motorSet(RIGHT_DRIVE_MOTOR, -rightPower);  
}

void stopDrive() {
    drive(0, 0);
}

void driveTicks(int ticks, int power) {
    encoderReset(leftEncoder);
    encoderReset(rightEncoder);
    while ((abs(encoderGet(leftEncoder)) + abs(encoderGet(rightEncoder))) / 2 < ticks) {
        drive(power, power);
        delay(20);
    }
    stopDrive();
}

int readDistance() {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += analogRead(FRONT_DISTANCE_SENSOR);
        delay(2);
    }
    return sum / 5;
}

void driveUntilClose(int threshold, int power) {
    while (readDistance() < threshold) {
        drive(power, power);
        delay(20);
    }
    stopDrive();
}

void onLine() {
    return analogRead(LINE_SENSOR) > LINE_THRESHOLD;
}

void driveUntilLine(int power) {
    while (!onLine()) {
        drive(power, power);
        delay(20);
    }
    stopDrive();
}

void autonomous() {
    
}