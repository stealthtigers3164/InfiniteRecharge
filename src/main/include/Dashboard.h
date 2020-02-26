  /*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>

#include <input.h>
#include <frc/Spark.h>

#include <Gamepad.h>

  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
  std::string m_PrevDriverSelected = "Default";
  std::string m_DriverSelected;
  frc::SendableChooser<std::string> m_ColourWheel;
  frc::SendableChooser<std::string> m_LimeAutoAlignment;
  frc::SendableChooser<std::string> m_Shooter;
  frc::SendableChooser<std::string> m_Driver;
  frc::SendableChooser<std::string> m_PrevDriver;
void DashInit(){
    m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
    m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
    frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

    m_ColourWheel.AddOption("A", "A");
    m_ColourWheel.AddOption("B", "B");
    m_ColourWheel.AddOption("X", "X");
    m_ColourWheel.AddOption("Y", "Y");
    m_ColourWheel.SetDefaultOption("A", "A");
    frc::SmartDashboard::PutData("Colour Wheel", &m_ColourWheel);
    
    m_LimeAutoAlignment.AddOption("A", "A");
    m_LimeAutoAlignment.AddOption("B", "B");
    m_LimeAutoAlignment.AddOption("X", "X");
    m_LimeAutoAlignment.AddOption("Y", "Y");
    m_LimeAutoAlignment.SetDefaultOption("B", "B");
    frc::SmartDashboard::PutData("Limelight", &m_LimeAutoAlignment); 

    m_Shooter.AddOption("A", "A");
    m_Shooter.AddOption("B", "B");
    m_Shooter.AddOption("X", "X");
    m_Shooter.AddOption("Y", "Y");
    m_Shooter.SetDefaultOption("X", "X");
    frc::SmartDashboard::PutData("Shooter", &m_Shooter);

    m_Driver.AddOption("Default", "Default");
    m_Driver.AddOption("Driver1", "Driver1");
    m_Driver.AddOption("Driver2", "Driver2");
    m_Driver.AddOption("Driver3", "Driver3");
    m_Driver.SetDefaultOption("Default", "Default");
    frc::SmartDashboard::PutData("Driver", &m_Driver);
}

void DashCheck(){
    m_DriverSelected = m_Driver.GetSelected();
  if(m_PrevDriverSelected != m_DriverSelected){
    if(m_DriverSelected ==  "Driver1"){
      m_Shooter.SetDefaultOption("Y", "Y");
      frc::SmartDashboard::PutData("Shooter", &m_Shooter);
    } else if(m_DriverSelected ==  "Driver2"){
      m_Shooter.SetDefaultOption("X", "X");
      frc::SmartDashboard::PutData("Shooter", &m_Shooter);
    }
  }
  m_PrevDriverSelected = m_DriverSelected;
}

/*
enum driver{
  ONE,
  TWO
};

struct input{
  Gamepad::controller button;
  driver controller;
} buttonAcontrollerOne;

void example(){
  buttonAcontrollerOne.button = Gamepad::controller::A;
  buttonAcontrollerOne.controller = driver::ONE;
}

bool limelight(input controls){
  switch (controls.controller)
  {
  case driver::ONE:
    return controllerOne->button(controls.button);
    break;
  
  default:
    break;
  }
}*/