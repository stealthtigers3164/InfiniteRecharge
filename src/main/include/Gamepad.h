/* ------------------------------------------------------------------------ */
/* Gamepad wrapper for the frc Joystick class.                              */
/* WPILIB documentation found at:                                           */
/* https://wpilib.screenstepslive.com/s/currentCS/m/java/l/599723-joysticks */
/* ------------------------------------------------------------------------ */

#pragma once

#include <frc/Joystick.h>
#include <iostream>
#include <math.h>
#include <map>

using namespace frc;

class Gamepad{
    
    public:

        Gamepad(){
            //create error
            //todo
        }

        Gamepad(int port){
            _gamepad =  new Joystick(port);

            //initialize all std::map current values to false
            current[controller::A] = false;
            current[controller::B] = false;
            current[controller::X] = false;
            current[controller::Y] = false;
            current[controller::LBUMPER] = false;
            current[controller::RBUMPER] = false;
            current[controller::BACK] = false;
            current[controller::START] = false;
            current[controller::UDPAD] = false;
            current[controller::DDPAD] = false;
            current[controller::LDPAD] = false;
            current[controller::RDPAD] = false;
            current[controller::LTRIG] = false;
            current[controller::RTRIG] = false;
            current[controller::LJOY] = false;
            current[controller::RJOY] = false;
            //initialize all std::map previous values to false
            previous[controller::A] = false;
            previous[controller::B] = false;
            previous[controller::X] = false;
            previous[controller::Y] = false;
            previous[controller::LBUMPER] = false;
            previous[controller::RBUMPER] = false;
            previous[controller::BACK] = false;
            previous[controller::START] = false;
            previous[controller::UDPAD] = false;
            previous[controller::DDPAD] = false;
            previous[controller::LDPAD] = false;
            previous[controller::RDPAD] = false;
            previous[controller::LTRIG] = false;
            previous[controller::RTRIG] = false;
            previous[controller::LJOY] = false;
            previous[controller::RJOY] = false;

        }

        //button numbers subject to change
        //testing to be done in the future
        bool ButtonA(){
            return _gamepad->GetRawButton(1);
        }
        bool ButtonB(){
            return _gamepad->GetRawButton(2);
        }
        bool ButtonX(){
            return _gamepad->GetRawButton(3);
        }
        bool ButtonY(){
            return _gamepad->GetRawButton(4);
        }
        bool LeftBumper(){
            return _gamepad->GetRawButton(5);
        }
        bool RightBumper(){
            return _gamepad->GetRawButton(6);
        }
        bool ButtonBack(){
            return _gamepad->GetRawButton(7);
        }
        bool ButtonStart(){
            return _gamepad->GetRawButton(8);
        }
        bool ButtonLeftJoy(){
            return _gamepad->GetRawButton(9);
        }
        bool ButtonRightJoy(){
            return _gamepad->GetRawButton(10);
        }
        
        //returns true if trigger is pressed past the deadzone
        //default deadzone is 0.25
        bool LeftTriggerPressed(float deadzone = 0.25f){
            if (_gamepad->GetRawAxis(2) > deadzone){
                return true;
            } else {
                return false;
            }
        }
        bool RightTriggerPressed(float deadzone = 0.25f){
            if (_gamepad->GetRawAxis(3) > deadzone){
                return true;
            } else {
                return false;
            }
        }

        //returns the value of the trigger if pressed beyond deadzone
        //default deadzone is 0.1
        float LeftTriggerValue(float deadzone = 0.1f){
            if (_gamepad->GetRawAxis(2) > deadzone){
                return _gamepad->GetRawAxis(2);
            } else {
                return 0.0f;
            }
        }
        float RightTriggerValue(float deadzone = 0.1f){
            if (_gamepad->GetRawAxis(3) > deadzone){
                return _gamepad->GetRawAxis(3);
            } else {
                return 0.0f;
            }
        }

        //returns a float vector (x, y) for the left joystick
        float* LeftJoystick(){
            LJoyAxes[0] = _gamepad->GetRawAxis(0);
            LJoyAxes[1] = _gamepad->GetRawAxis(1);
            //static float axes[2] = {xAxis, yAxis};
            return LJoyAxes;
        }

        //returns a float vector (x, y) for the right joystick
        float* RightJoystick(){
            RJoyAxes[0] = _gamepad->GetRawAxis(4);
            RJoyAxes[1] = _gamepad->GetRawAxis(5);
            //static float axes[2] = {xAxis, yAxis};
            return RJoyAxes;
        }

        //dpad logic
        //returns a float vector (x, y) for the dpad state
        int* DPad(){
            float degrees = _gamepad->GetPOV();
            //returns the value of the dpad direction
            //rounded to the nearest integer value (-1, 0, 1)
            //x axis
            DPadAxes[0] = static_cast<int>(round(cos(degrees * PI/180)));
            //y axis
            DPadAxes[1] = static_cast<int>(round(sin(degrees * PI/180)));
            //axes[1] = {vecx, vecy};
            return DPadAxes;
        }

        enum controller{
            A,
            B,
            X,
            Y,
            LBUMPER,
            RBUMPER,
            BACK,
            START,
            UDPAD,
            DDPAD,
            LDPAD,
            RDPAD,
            LTRIG,
            RTRIG,
            LJOY,
            RJOY,
            NONE
        };

        //current button values
        std::map<controller, bool> current;
        //previous button values
        std::map<controller, bool> previous;

    private:

        const double PI = 3.14159265;
        Joystick* _gamepad;
        float LJoyAxes[2] = {0.0f, 0.0f};
        float RJoyAxes[2] = {0.0f, 0.0f};
        int DPadAxes[2] = {0, 0};

};

bool button(Gamepad::controller button, Gamepad *gpad){
    switch (button){
        case Gamepad::controller::A:
            return gpad->ButtonA();
            break;
        case Gamepad::controller::B:
            return gpad->ButtonB();
            break;
        case Gamepad::controller::X:
           return gpad->ButtonX();
            break;
        case Gamepad::controller::Y:
            return gpad->ButtonY();
            break;
        case Gamepad::controller::LBUMPER:
            return gpad->LeftBumper();
            break;
        case Gamepad::controller::RBUMPER:
            return gpad->RightBumper();
            break;
        case Gamepad::controller::BACK:
            return gpad->ButtonBack();
            break;
        case Gamepad::controller::START:
            return gpad->ButtonStart();
            break;
        case Gamepad::controller::UDPAD:
            if (gpad->DPad()[1] == 1){
                return true;
            } else {
                return false;
            }
            break;
        case Gamepad::controller::DDPAD:
            if (gpad->DPad()[1] == -1){
                return true;
            } else {
                return false;
            }
            break;
        case Gamepad::controller::LDPAD:
            if (gpad->DPad()[0] == -1){
                return true;
            } else {
                return false;
            }
            break;
        case Gamepad::controller::RDPAD:
            if (gpad->DPad()[0] == 1){
                return true;
            } else {
                return false;
            }
            break;
        case Gamepad::controller::LTRIG:
            return gpad->LeftTriggerPressed();
            break;
        case Gamepad::controller::RTRIG:
            return gpad->RightTriggerPressed();
            break;
        case Gamepad::controller::LJOY:
            return gpad->ButtonLeftJoy();
            break;
        case Gamepad::controller::RJOY:
            return gpad->ButtonRightJoy();
            break;
        default:
            return false;
            break;
    }
}

//returns true when the button is first pressed
//must be called every telop period to be accurate
bool getButtonDown(Gamepad::controller bttn, Gamepad *gpad){
    //current vaule of button
    gpad->current[bttn] = button(bttn, gpad);
    //evals to true when button is first pressed
    bool down = ( gpad->current[bttn] && !(gpad->previous[bttn]) );
    //set previous value after eval
    gpad->previous[bttn] = gpad->current[bttn];
    return down;
}

//returns true when the button is first let up
//must be called every telop period to be accurate
bool getButtonUp(Gamepad::controller bttn, Gamepad *gpad){
    //current value of button
    gpad->current[bttn] = button(bttn, gpad);
    //evals to true when button is first let up
    bool up = ( !(gpad->current[bttn]) && gpad->previous[bttn] );
    //set previous value after eval
    gpad->previous[bttn] = gpad->current[bttn];
    return up;
}