#include <input.h>
#include <limelight.h>
#include <drive.h>

//constructor
input::input(){
    controller = new Gamepad(1);
    aligner = new limelight();
}

input::update(){
    
    //limelight alignment set to A button
    if (joystick->ButtonA()){
        double adjustment = std::static_cast<double>(aligner->update());
        double left = controller->LeftJoystick()[1] + adjustment;
        double right = controller->RightJoystick()[1] - adjustment;
        drive::update(right, left);
    } else {
        double left = controller->LeftJoystick()[1];
        double right = controller->RightJoystick()[1];
        drive::update(right, left);
    }
}