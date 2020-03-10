/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

#include <input.h>

#include "cameraserver/CameraServer.h"

#include <Dashboard.h>

#include <indexer.h>




Robot::Robot(){
  humani = new input();
  
}

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
  // Creates UsbCamera and MjpegServer [1] and connects them
  frc::CameraServer::GetInstance()->StartAutomaticCapture();
  // Creates the CvSink and connects it to the UsbCamera
  cs::CvSink cvSink = frc::CameraServer::GetInstance()->GetVideo();
  DashInit();
  
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {
  humani->update();
  DashCheck();
}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  std::cout << "Auto selected: " << m_autoSelected << std::endl;

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
  //timer = new Timer();
  //timer->Start();
  /*fly = new shooter(6);
  //indexer
  indx = new indexer(4,2, 0);
  driver = new drive(5, 8, 0, 1);*/
}
void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
  //add limelight!
  /*if(timer->Get() <= 5){
      indx->update(0.3);
      fly->flyyWheel(1);
  }else{
      indx->update(0);
      fly->flyyWheel(0);
  }
  if(timer->Get() >= 6){
      driver->update(0.5, 0.5);
  }else{
      driver->update(0,0);
  }*/
}

void Robot::TeleopInit() {
    //timer->Stop();
}

void Robot::TeleopPeriodic() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
