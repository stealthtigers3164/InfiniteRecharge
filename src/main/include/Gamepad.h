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

        enum triggers{
            LEFT,
            RIGHT
        };

        //takes a controller enum value as input
        //returns the value of the button that is passed as input
        bool button(controller button){
            switch (button){
                case controller::A:
                    return this->ButtonA();
                    break;
                case controller::B:
                    return this->ButtonB();
                    break;
               case controller::X:
                   return this->ButtonX();
                    break;
                case controller::Y:
                    return this->ButtonY();
                    break;
                case controller::LBUMPER:
                    return this->LeftBumper();
                    break;
                case controller::RBUMPER:
                    return this->RightBumper();
                    break;
                case controller::BACK:
                    return this->ButtonBack();
                    break;
                case controller::START:
                    return this->ButtonStart();
                    break;
                case controller::UDPAD:
                    if (this->DPad()[1] == 1){
                        return true;
                    } else {
                        return false;
                    }
                    break;
                case controller::DDPAD:
                    if (this->DPad()[1] == -1){
                        return true;
                    } else {
                        return false;
                    }
                    break;
                case controller::LDPAD:
                    if (this->DPad()[0] == -1){
                        return true;
                    } else {
                        return false;
                    }
                    break;
                case controller::RDPAD:
                    if (this->DPad()[0] == 1){
                        return true;
                    } else {
                        return false;
                    }
                    break;
                case controller::LTRIG:
                    return this->LeftTriggerPressed();
                    break;
                case controller::RTRIG:
                    return this->RightTriggerPressed();
                    break;
                case controller::LJOY:
                    return this->ButtonLeftJoy();
                    break;
                case controller::RJOY:
                    return this->ButtonRightJoy();
                    break;
                default:
                    return false;
                    break;
            }
        }

        //takes a triggers enum value as input
        //returns the value of the trigger that is passed as input
        float trigger(triggers hand){
            switch (hand){
                case triggers::LEFT:
                    return this->LeftTriggerValue();
                    break;
                case triggers::RIGHT:
                    return this->RightTriggerValue();
                    break;
                default:
                    return 0.0f;
                    break;
            }
        }

        //returns true when the button is first pressed
        //must be called every telop period to be accurate
        bool getButtonDown(controller bttn){
            //current vaule of button
            this->current[bttn] = this->button(bttn);
            //evals to true when button is first pressed
            bool down = ( this->current[bttn] && !(this->previous[bttn]) );
            //set previous value after eval
            this->previous[bttn] = this->current[bttn];
            return down;
        }

        //returns true when the button is first let up
        //must be called every telop period to be accurate
        bool getButtonUp(controller bttn){
            //current value of button
            this->current[bttn] = this->button(bttn);
            //evals to true when button is first let up
            bool up = ( !(this->current[bttn]) && this->previous[bttn] );
            //set previous value after eval
            this->previous[bttn] = this->current[bttn];
            return up;
        }

        //current button values
        std::map<controller, bool> current;
        //previous button values
        std::map<controller, bool> previous;

    private:

        Joystick* _gamepad;
        float LJoyAxes[2] = {0.0f, 0.0f};
        float RJoyAxes[2] = {0.0f, 0.0f};
        const double PI = 3.14159265;
        int DPadAxes[2] = {0, 0};

};