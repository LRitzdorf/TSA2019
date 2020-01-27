/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Lucas Ritzdorf                                   */
/*    Created:      Fri Dec 06 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// conveyorMotor        motor         5               
// liftMotor            motor         6               
// huggerMotor          motor         7               
// leftFrontDrive       motor         1               
// rightFrontDrive      motor         2               
// leftRearDrive        motor         3               
// rightRearDrive       motor         4               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // Define variables here for easier behavior modification
  // Motor speeds (in RPM)
  const double conveyorSpeed = 30;
  const double liftSpeed = 60;
  const double huggerSpeed = 15;

  while(true) {
    // Driving control (currently tank style)
    // Left side
    if (Controller1.Axis3.position(pct) != 0) {
      leftFrontDrive.setVelocity(Controller1.Axis3.position(pct), pct);
      leftRearDrive.setVelocity(Controller1.Axis3.position(pct), pct);
    }
    // Right side
    if (Controller1.Axis2.position(pct) != 0) {
      rightFrontDrive.setVelocity(Controller1.Axis2.position(pct), pct);
      rightRearDrive.setVelocity(Controller1.Axis2.position(pct), pct);
    }

    // Manipulator control
    // NOTE: If the first condition is met, it takes priority over the second
    // Conveyor
    if (Controller1.ButtonA.pressing()) {
      conveyorMotor.setVelocity(conveyorSpeed, rpm);
    } else if (Controller1.ButtonB.pressing()) {
      conveyorMotor.setVelocity(conveyorSpeed, rpm);
    }
    // Lift
    if (Controller1.ButtonR1.pressing()) {
      liftMotor.setVelocity(liftSpeed, rpm);
    } else if (Controller1.ButtonR2.pressing()) {
      liftMotor.setVelocity(-liftSpeed, rpm);
    } else {
      liftMotor.setVelocity(0, rpm);
    }
    // Hugger
    if (Controller1.ButtonL1.pressing()) {
      huggerMotor.setVelocity(huggerSpeed, rpm);
    } else if (Controller1.ButtonL2.pressing()) {
      huggerMotor.setVelocity(-huggerSpeed, rpm);
    } else {
      huggerMotor.setVelocity(0, rpm);
    }
  }
}
