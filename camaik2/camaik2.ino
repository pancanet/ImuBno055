#define USE_USBCON 
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

#include <ros.h>
#include <geometry_msgs/Vector3.h>
#include <sensor_msgs/Imu.h>

ros::NodeHandle nh;

//geometry_msgs::Vector3 lineac;
//geometry_msgs::Vector3 euler;
//ros::Publisher pubacc("Imu/linear", &lineac);
//ros::Publisher pubeul("Imu/euler", &euler);
sensor_msgs::Imu rawimu;
ros::Publisher pub("IMU",&rawimu);
Adafruit_BNO055 bno = Adafruit_BNO055(-1, 0x28);

void setup() {
  // put your setup code here, to run once:
//  Serial.begin(115200);
//  pinMode(LED_BUILTIN,OUTPUT);
  nh.getHardware()->setBaud(57600);
  nh.initNode();
//  nh.advertise(pubacc);
//  nh.advertise(pubeul);
  nh.advertise(pub);
  if(!bno.begin()){
//    digitalWrite(LED_BUILTIN,HIGH);
//    delay(100);
//    digitalWrite(LED_BUILTIN,LOW);
//    delay(100);
  }
  bno.setExtCrystalUse(true);
}

void loop() {
  // put your main code here, to run repeatedly:
  imu::Vector<3> aeuler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  imu::Vector<3> alineac = bno.getVector(Adafruit_BNO055::VECTOR_LINEARACCEL);
  imu::Quaternion quat = bno.getQuat();
  rawimu.header.stamp = nh.now();
  rawimu.orientation.x = quat.x();
  rawimu.orientation.y = quat.y();
  rawimu.orientation.z = quat.z();
  rawimu.orientation.w = quat.w();
  rawimu.angular_velocity.x = aeuler.x();
  rawimu.angular_velocity.y = aeuler.y();
  rawimu.angular_velocity.z = aeuler.z();
  rawimu.linear_acceleration.x = alineac.x();
  rawimu.linear_acceleration.y = alineac.y();
  rawimu.linear_acceleration.z = alineac.z();
//  euler.x = aeuler.x();
//  euler.y = aeuler.y();
//  euler.z = aeuler.z();
//  lineac.x = alineac.x();
//  lineac.y = alineac.y();
//  lineac.z = alineac.z();
//  pubacc.publish(&lineac);
//  pubeul.publish(&euler);
  pub.publish(&rawimu);
  nh.spinOnce();
}
