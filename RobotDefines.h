//******************************************************************************
//
// File: RobotDefines.h
//
// Description: Defines for all inputs and motors
//
//******************************************************************************
#ifndef RobotDefines_h
#define RobotDefines_h

//#define ROBOT2012
#define ROBOT2013

#ifdef ROBOT2013
// PWMs
#define PWM_LEFT_DRIVE_MOTOR       (2)
#define PWM_RIGHT_DRIVE_MOTOR      (1)
#define PWM_THROWER_MOTOR          (3)
#define PWM_CLIMBER_MOTOR          (4)
#define PWM_FEEDER_MOTOR           (6)

// Relays
#define RELAY_FEEDER_MOTOR         (1)

// Solenoids
#define SOL_ARM_BRAKE              (1)
#define SOL_WINCH_BRAKE            (2)


// Digital IO
#define DIG_MOD1                   (1)

#define DIG_IN_SHOOTER_RPM         (1)
#define DIG_IN_FEED_LEVER_BACK     (2)
#define DIG_IN_FEED_LEVER_FWD      (3)
#define DIG_IN_FEEDER_EMPTY        (4)
#define DIG_IN_HOOK1_ON_BAR        (5)
#define DIG_IN_HOOK2_ON_BAR        (6)
#define DIG_IN_HOOK3_ON_BAR        (7)
#define DIG_IN_HOOK4_ON_BAR        (8)
#define DIG_IN_LIFT_CLOSED         (9)
#define DIG_IN_FAR_LIMIT           (10)
#define DIG_IN_NEAR_LIMIT          (11)


// Joysticks
#define PORT_DRIVER_JOYSTICK       (1)
#define PORT_THROWER_JOYSTICK      (2)


// Joystick Buttons

// Joystick 1
#define BTN_J1_SHOOT               (1)
#define BTN_J1_CLIMBER             (4)

// Joystick 2
#define BTN_J2_WINCH_ENABLE        (6)
#define BTN_J2_WINCH_BRAKE         (7)

#define THROTTLE_J2_SPEED          (1)

#endif

#ifdef ROBOT2012

//TODO: Set robot 2012 defines.

// PWMs
#define PWM_LEFT_DRIVE_MOTOR       (1)
#define PWM_RIGHT_DRIVE_MOTOR      (2)
#define PWM_THROWER_MOTOR          (8)
#define PWM_CLIMBER_MOTOR1         (4)
#define PWM_CLIMBER_MOTOR2         (5)
#define PWM_FEEDER_MOTOR           (6)
#define PWM_ELEVATOR_MOTOR         (7)

// Relays
#define RELAY_FEEDER_MOTOR		   (1)



// Digital IO
#define DIG_MOD1                   (1)

#define DIG_IN_SHOOTER_RPM         (7)
#define DIG_IN_FEED_LEVER_BACK     (2)
#define DIG_IN_FEED_LEVER_FWD      (8)
#define DIG_IN_FEEDER_EMPTY        (4)
#define DIG_IN_HOOK1_ON_BAR        (5)
#define DIG_IN_HOOK2_ON_BAR        (6)
#define DIG_IN_HOOK3_ON_BAR        (7)
#define DIG_IN_HOOK4_ON_BAR        (8)
#define DIG_IN_LIFT_CLOSED         (9)


// Joysticks
#define PORT_DRIVER_JOYSTICK       (1)
#define PORT_THROWER_JOYSTICK      (2)


// Joystick Buttons

// Joystick 1
#define BTN_J1_SHOOT               (1)
#define BTN_J1_CLIMBER             (4)

// Joystick 2
#define BTN_J2_SPEED_1             (4)
#define BTN_J2_SPEED_2             (3)
#define BTN_J2_SPEED_3             (5)


#define THROTTLE_J2_SPEED          (1)

#endif

#endif





