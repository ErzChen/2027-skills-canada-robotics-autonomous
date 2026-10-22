#include "main.h"

Encoder leftEncoder;
Encoder rightEncoder;

void initializeIO() {
    
}

void initialize() {
    leftEncoder  = encoderInit(LEFT_ENCODER_TOP, LEFT_ENCODER_BOTTOM, false);
    rightEncoder = encoderInit(RIGHT_ENCODER_TOP, RIGHT_ENCODER_BOTTOM, true);
}