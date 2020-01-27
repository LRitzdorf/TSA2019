using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor conveyorMotor;
extern motor liftMotor;
extern motor huggerMotor;
extern motor leftFrontDrive;
extern motor rightFrontDrive;
extern motor leftRearDrive;
extern motor rightRearDrive;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );