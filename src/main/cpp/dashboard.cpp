#include <dashboard.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/smartdashboard/SmartDashboard.h>


shuffle::shuffle(){

    m_PrevDriverSelected = "Default";

    oneA.button = Gamepad::controller::A;
    oneA.controller = driver::ONE;
    oneB.button = Gamepad::controller::A;
    oneB.controller = driver::ONE;
    oneX.button = Gamepad::controller::A;
    oneX.controller = driver::ONE;
    oneY.button = Gamepad::controller::A;
    oneY.controller = driver::ONE;
    oneLBUMPER.button = Gamepad::controller::LBUMPER;
    oneLBUMPER.controller = driver::ONE;
    oneUDPAD.button = Gamepad::controller::UDPAD;
    oneUDPAD.controller = driver::ONE;
    oneDDPAD.button = Gamepad::controller::DDPAD;
    oneDDPAD.controller = driver::ONE;
    oneLDPAD.button = Gamepad::controller::LDPAD;
    oneLDPAD.controller = driver::ONE;
    oneRDPAD.button = Gamepad::controller::RDPAD;
    oneRDPAD.controller = driver::ONE;
    oneLTRIG.button = Gamepad::controller::LTRIG;
    oneLTRIG.controller = driver::ONE;
    oneRTRIG.button = Gamepad::controller::RTRIG;
    oneRTRIG.controller = driver::ONE;
    oneLJOY.button = Gamepad::controller::LJOY;
    oneLJOY.controller = driver::ONE;
    oneRJOY.button = Gamepad::controller::RJOY;
    oneRJOY.controller = driver::ONE;
    oneSTART.button = Gamepad::controller::START;
    oneSTART.controller = driver::ONE;
    oneBACK.button = Gamepad::controller::BACK;
    oneBACK.controller = driver::ONE;
    twoA.button = Gamepad::controller::A;
    twoA.controller = driver::TWO;
    twoB.button = Gamepad::controller::B;
    twoB.controller = driver::TWO;
    twoX.button = Gamepad::controller::X;
    twoX.controller = driver::TWO;
    twoY.button = Gamepad::controller::Y;
    twoY.controller = driver::TWO;
    twoLBUMPER.button = Gamepad::controller::LBUMPER;
    twoLBUMPER.controller = driver::TWO;
    twoRBUMPER.button = Gamepad::controller::RBUMPER;
    twoRBUMPER.controller = driver::TWO;
    twoUDPAD.button = Gamepad::controller::UDPAD;
    twoUDPAD.controller = driver::TWO;
    twoDDPAD.button = Gamepad::controller::DDPAD;
    twoDDPAD.controller = driver::TWO;
    twoLDPAD.button = Gamepad::controller::LDPAD;
    twoLDPAD.controller = driver::TWO;
    twoRDPAD.button = Gamepad::controller::RDPAD;
    twoRDPAD.controller = driver::TWO;
    twoLTRIG.button = Gamepad::controller::LTRIG;
    twoLTRIG.controller = driver::TWO;
    twoRTRIG.button = Gamepad::controller::RTRIG;
    twoRTRIG.controller = driver::TWO;
    twoLJOY.button = Gamepad::controller::LJOY;
    twoLJOY.controller = driver::TWO;
    oneRJOY.button = Gamepad::controller::RJOY;
    oneRJOY.controller = driver::TWO;
    none.button = Gamepad::controller::NONE;
    none.controller = driver::NONE;
    twoSTART.button = Gamepad::controller::START;
    twoSTART.controller = driver::TWO;
    twoBACK.button = Gamepad::controller::BACK;
    twoBACK.controller = driver::TWO;

    for (int i=0; i<33; i++){
        m_ColourWheel.AddOption(names[i], buttonsList[i]);
        m_LimeAutoAlignment.AddOption(names[i], buttonsList[i]);
        m_Shooter.AddOption(names[i], buttonsList[i]);
    }

    m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
    m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
    frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

    m_ColourWheel.SetDefaultOption("X 1", oneX);
    frc::SmartDashboard::PutData("Colour Wheel", &m_ColourWheel);

    m_LimeAutoAlignment.SetDefaultOption("A 1", oneA);
    frc::SmartDashboard::PutData("Limelight", &m_LimeAutoAlignment);

    m_Shooter.SetDefaultOption("Right Bumper 1", oneRBUMPER);
    frc::SmartDashboard::PutData("Shooter", &m_Shooter);
    
    m_Driver.AddOption("Default", "Default");
    m_Driver.AddOption("Driver1", "Driver1");
    m_Driver.AddOption("Driver2", "Driver2");
    m_Driver.AddOption("Driver3", "Driver3");
    m_Driver.SetDefaultOption("Default", "Default");
    frc::SmartDashboard::PutData("Driver", &m_Driver);
}