# ImuBno055
Program pembacaan Sensor BNO055 dengan arduino. pengiriman data hasil pembacaan sensor BNO055 ke ROS 
# Camaik
pengiriman hasil baca sensor dibagi menjadi 2 publisher dengan msgs geometry_msgs/Vector3.h 
<br>
topic 1 : "/Imu/linear" <br>
isinya : 
- float64 x --> linear_acceleration.x
- float64 y --> linear_acceleration.y
- float64 z --> linear_acceleration.z <br>
topic 2 : "/Imu/euler" <br>
isinya : 
- float64 x --> angular_velocity.x
- float64 y --> angular_velocity.y
- float64 z --> angular_velocity.z
# Camaik2
pengiriman hasil baca sensor dibagi menjadi 1 publisher saja dengan msgs sensor_msgs/Imu.h
