#ifndef MAIN_H_
#define MAIN_H_
#include <API.h>
#ifdef __cplusplus
extern "C" {
#endif

void autonomous();
void initializeIO();
void initialize();
void operatorControl();

// Motor ports 
#define LEFT_DRIVE_MOTOR 0
#define RIGHT_DRIVE_MOTOR 0
#define SWEEP_MOTOR 0

// Analog ports 
#define FRONT_DISTANCE_SENSOR 0
#define LINE_SENSOR 0

// Digital ports
#define LEFT_ENCODER_TOP 0
#define LEFT_ENCODER_BOTTOM 0
#define RIGHT_ENCODER_TOP 0
#define RIGHT_ENCODER_BOTTOM 0

// Sensors
extern Encoder leftEncoder;
extern Encoder rightEncoder;

// Autonomous constants
#define LINE_THRESHOLD 0
#define DISTANCE_THRESHOLD 0
#define DRIVE_POWER 0
#define TURN_TICKS 0

// Autonomous helpers
void drive(int leftPower, int rightPower);
void stopDrive();
void driveTicks(int ticks, int power);
void turn(int power, int direction);
void turnTicks(int ticks, int power, int direction)
int readDistance();
void driveUntilClose(int threshold, int power);
int onLine();
void driveUntilLine(int power);
void sweepBulls();
void driveSweep();
void driveTurn(int direction);
void ringSweep(int direction);

#ifdef __cplusplus
}
#endif

#endif