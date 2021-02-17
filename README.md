# ImuBno055
Program pembacaan Sensor BNO055 dengan arduino. pengiriman data hasil pembacaan sensor BNO055 ke ROS 
# Camaik
pengiriman hasil baca sensor dibagi menjadi 2 publisher dengan msgs geometry_msgs/Vector3.h 
<br>
topic 1 : "/Imu/linear" <br>
isinya : 
- float64 x --> VECTOR_LINEARACCEL.x
- float64 y --> VECTOR_LINEARACCEL.y
- float64 z --> VECTOR_LINEARACCEL.z <br>

topic 2 : "/Imu/euler" <br>
isinya : 
- float64 x --> VECTOR_EULER.x
- float64 y --> VECTOR_EULER.y
- float64 z --> VECTOR_EULER.z
# Camaik2
pengiriman hasil baca sensor dibagi menjadi 1 publisher saja dengan msgs sensor_msgs/Imu.h <br>
topic : "IMU" <br>
isinya : 
- header :
  - stamp --> nh.now()
- orientation :
  - float64 x --> quat.x
  - float64 y --> quat.y
  - float64 z --> quat.z
  - float64 w --> quat.w
- angular_velocity:
  - float64 x --> VECTOR_EULER.x  
  - float64 y --> VECTOR_EULER.y
  - float64 z --> VECTOR_EULER.z
- linear_acceleration:
  - float64 x --> VECTOR_EULER.x
  - float64 y --> VECTOR_EULER.y
  - float64 z --> VECTOR_EULER.z

# PENTING
- DEKLARASIKAN #DEFINE USE_USBCON di arduino IDE sebelum Deklarasi include library, hal ini diperlukan untuk beberapa mikon yang menggunakan sam3x atau sejenis yang mengalami error : <br>
Unable to sync with device; possible link problem or link software version mismatch such as hydro rosserial_python with groovy Arduino <br>
pada saat menjalan rosrun rosserial_python serial_node.py
