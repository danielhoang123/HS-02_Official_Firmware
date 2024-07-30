#include "Controller_GY_HMC588L.h"
// #include "debugkxn.h"

Controller_GY_HMC588L_Data::Controller_GY_HMC588L_Data()
{
    this->nameDevice = "HMC588L";
    this->timeInterval = 250;
    // this->valueDevice = "No device";
    this->Add_AddressList(0x68);
    // this->Add_HsCode(194);
    // Add your code here
}

Controller_GY_HMC588L_Data::~Controller_GY_HMC588L_Data()
{
}

bool Controller_GY_HMC588L_Data::getData()
{
    // Add your code here
    this->valueDevice = "";
    this->valueDevice1 = "";
    this->valueDevice2 = "";

    // this->nameDevice = "QMC5883L";
    // this->compass_qmc->read();

    // int x = this->compass_qmc->getX();
    // int y = this->compass_qmc->getY();
    // int z = this->compass_qmc->getZ();

    // this->valueDevice += "X: " + String(x);
    // this->valueDevice1 += "Y: " + String(y);
    // this->valueDevice2 += "Z: " + String(z);

    // if (x == 0 && y == 0 && z == 0)
    // {
    //     this->nameDevice = "HMC5883L";

    //     MagnetometerRaw raw = this->compass_hmc->readRawAxis();

    //     this->valueDevice += "X: " + String(raw.XAxis);
    //     this->valueDevice1 += "Y: " + String(raw.YAxis);
    //     this->valueDevice2 += "Z: " + String(raw.ZAxis);
    // }
    if (this->compass_qmc != nullptr)
    {
        this->nameDevice = "QMC5883L";
        this->compass_qmc->read();

        int x = this->compass_qmc->getX();
        int y = this->compass_qmc->getY();
        int z = this->compass_qmc->getZ();

        this->valueDevice += "X: " + String(x);
        this->valueDevice1 += "Y: " + String(y);
        this->valueDevice2 += "Z: " + String(z);
    }
    else
    {
        this->nameDevice = "HMC5883L";

        MagnetometerRaw raw = this->compass_hmc->readRawAxis();

        this->valueDevice += "X: " + String(raw.XAxis);
        this->valueDevice1 += "Y: " + String(raw.YAxis);
        this->valueDevice2 += "Z: " + String(raw.ZAxis);
    }
    // this->valueDevice1 += "x: " + String(x) + " ; " + "y: " + String(y) + " ; " + "z: " + String(z);
    // int a;

    // // Read compass values
    // compass.read();

    // // Return Azimuth reading
    // a = compass.getAzimuth();

    // Serial.print("A: ");
    // Serial.print(a);
    // Serial.println();
    // this->valueDevice1 += String(a);

    return true;
}

bool Controller_GY_HMC588L_Data::init()
{
    deInit();
    // Add your code here
    this->accelgyro = new MPU6050;
    this->compass_qmc = new QMC5883LCompass;
    Wire.begin();

    this->accelgyro->setI2CMasterModeEnabled(false);
    this->accelgyro->setI2CBypassEnabled(true);
    this->accelgyro->setSleepEnabled(false);

    this->compass_qmc->init();

    this->compass_qmc->read();

    int x = this->compass_qmc->getX();
    int y = this->compass_qmc->getY();
    int z = this->compass_qmc->getZ();

    if (x == 0 && y == 0 && z == 0)
    {
        delete compass_qmc;
        compass_qmc = nullptr;
        this->compass_hmc = new HMC5883L;
        error = this->compass_hmc->setAverageSamples(4); // Set the amount of samples of the compass.
        if (error != 0)
        { // If there is an error, print it out.
            // Serial.println(compass.getErrorText(error));
            this->valueDevice = "Error Step1";
        }

        Serial.println("Setting scale to +/- 1.3 Ga");
        error = this->compass_hmc->setScale(1.3); // Set the scale of the compass.
        if (error != 0)
        { // If there is an error, print it out.
            // Serial.println(compass.getErrorText(error));
            this->valueDevice = "Error Step2";
        }

        Serial.println("Setting measurement mode to continous.");
        error = this->compass_hmc->setMeasurementMode(MEASUREMENT_CONTINUOUS); // Set the measurement mode to Continuous
        if (error != 0)
        { // If there is an error, print it out.
            // Serial.println(this->compass_hmc->getErrorText(error));
            this->valueDevice = "Error Step3";
        }
    }

    return 1;
}

bool Controller_GY_HMC588L_Data::deInit()
{
    // Add your code here
    delete accelgyro;
    accelgyro = nullptr;
    delete compass_qmc;
    compass_qmc = nullptr;
    delete compass_hmc;
    compass_hmc = nullptr;
    return 1;
}

Controller_GY_HMC588L_Data device_Controller_GY_HMC588L;