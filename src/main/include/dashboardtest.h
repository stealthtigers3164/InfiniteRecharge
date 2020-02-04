#pragma once
#include <frc/smartdashboard/Smartdashboard.h>
#include <frc/SendableChooser.h>

enum Pos { LEFT, CENTER, RIGHT };

frc::SendableChooser<Pos> controller1;

// In RobotInit()
controller1.AddOption("Left", Pos::LEFT);
controller1.AddOption("Right", Pos::RIGHT);
controller1.SetDefaultOption("Center", Pos::CENTER);

// AutomousInit()
Pos startPosition = controller1.GetSelected();

switch (startPosition) {
  case LEFT:
    // Start the left-side auto
  case RIGHT:
    // etc...
}

enum Color { red, green, blue };
Color r = red;
switch(r)
{
    case red  : std::cout << "red\n";   break;
    case green: std::cout << "green\n"; break;
    case blue : std::cout << "blue\n";  break;
}