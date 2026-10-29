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

void turn(int power, int direction) {
    drive(power * direction, -power * direction) // direction: 1 for right, -1 for left
}

void turnTicks(int ticks, int power, int direction) {
    encoderReset(leftEncoder);
    encoderReset(rightEncoder);
    while ((abs(encoderGet(leftEncoder)) + abs(encoderGet(rightEncoder))) / 2 < ticks) {
        turn(power, direction);
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

void sweepBulls() {
    
}

void driveSweep() {
    driveUntilLine(DRIVE_POWER);
    sweepBulls();
}

void driveTurn(int direction) {
    driveUntilClose(DISTANCE_THRESHOLD);
    turnTicks(TURN_TICKS, DRIVE_POWER, direction);
}

void ringSweep(int direction) {
    driveSweep();
    driveTurn(direction);
    driveSweep();
    driveSweep();
    driveTurn(direction);
    driveSweep();
    driveTurn(direction);
    turnTicks(TURN_TICKS, DRIVE_POWER, direction);
}

int direction = 1;

void autonomous() {
    // First run to get calf rope
    driveSweep();
    driveTurn(direction);
    driveSweep();
    // calf rope stuff
    driveSweep();
    driveTurn(direction);
    driveSweep();
    driveTurn(direction);
    turnTicks(TURN_TICKS, DRIVE_POWER, direction);
    direction *= -1;

    while (true) {
        ringSweep(direction)
        direction *= -1;
    }
}