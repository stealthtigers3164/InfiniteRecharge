#include <controls.h>
// https://github.com/yhirose/cpp-httplib
#include <httplib.h>
// https://github.com/dropbox/json11
#include <json11.hpp>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <string>
#include <fstream>
#include <streambuf>

controls::controls(){

    m_PrevDriverSelected = "Default";

    m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
    m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
    frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

    m_Driver.AddOption("Default", "Default");
    m_Driver.AddOption("Driver1", "Driver1");
    m_Driver.AddOption("Driver2", "Driver2");
    m_Driver.AddOption("Driver3", "Driver3");
    m_Driver.SetDefaultOption("Default", "Default");
    frc::SmartDashboard::PutData("Driver", &m_Driver);

    frc::SmartDashboard::PutString("Host", "172.20.10.2");
    frc::SmartDashboard::PutString("Mech", "limelight");
    frc::SmartDashboard::PutNumber("Controller", 1);
    frc::SmartDashboard::PutString("Button", "A");

    try{
        httplib::Client client(frc::SmartDashboard::GetString("Host", "172.20.10.2"), 5802);

        httplib::Client client("172.20.10.2", 5802);
    } catch (...){
        std::string err = "parse failed";
        std::ifstream t("/home/lvuser/defaults.json");
        const std::string file((std::istreambuf_iterator<char>(t)),std::istreambuf_iterator<char>());
        json = json11::Json::parse(file, err);
    }
}

controls::keybind controls::getControl(std::string mech){
    keybind result;
    result.controller = 0;
    result.button = "none";
    try{
        char* buttonRequest = "/?driver=Default&req=limelight&mode=0";
        // char* buttonRequest = "/?driver=";
        // buttonRequest += reinterpret_cast<char>(frc::SmartDashboard::GetData("Driver"));
        // buttonRequest += (char)"&req=";
        // buttonRequest += (char)(mech).c_str();
        // buttonRequest += (char)"&mode=0";
        char* controllerRequest = "/?driver=Default&req=limelight&mode=1";
        // char* controllerRequest = "/?driver=";
        // controllerRequest += reinterpret_cast<char>(frc::SmartDashboard::GetData("Driver"));
        // controllerRequest += (char)"&req=";
        // controllerRequest += (char)(mech).c_str();
        // controllerRequest += (char)"&mode=1";
        auto buttonResponse = client.Get(buttonRequest);
        auto controllerResponse = client.Get(controllerRequest);
        if(buttonResponse && buttonResponse->status == 200){
            result.button = buttonResponse->body;
        }
        if(controllerResponse && controllerResponse->status == 200){
            result.controller = std::stoi(controllerResponse->body);
        }
        std::cout << "Controller: " << result.controller << std::endl;
        std::cout << "Button: " << result.button << std::endl;
    } catch (...){
        char* driver = "Default";
        // char* driver reinterpret_cast<char>(frc::SmartDashboard::GetData("Driver"));
        result.button = json["limelight"]["button"].string_value();
        result.controller = json["limelight"]["button"].int_value();
        // result.button = json[mech]["button"];
        // result.controller = json[mech]["controller"];
    }
    return result;
}
