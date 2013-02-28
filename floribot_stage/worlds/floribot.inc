define pantilt actuator
(
  control_mode "position"
  actuator_type "rotational"

  # generic model properties
  color "black"
  size [ 0.3 0.05 0.05 ] # dimensions

)

define hokuyo_laser ranger
(

  sensor(
    range [ 0 30 ]
    fov 140.0
    samples 800
  )
	

  # generic model properties
  color "blue"
  size [ 0.07 0.07 0.07 ] # dimensions
  
)

define hokuyo_body hokuyo_laser
(
   block(
	points 4
  	point[0] [ 0 0 ]
  	point[1] [ 0 1 ]
  	point[2] [ 1 1 ]
  	point[3] [ 1 0 ]
  	z [0 0.035 ]
   )
)

define floribot position
(
	
   size [0.55 0.4 0.4]
   block(
	points 4
  	point[0] [ 0 0 ]
  	point[1] [ 0 1 ]
  	point[2] [ 1 1 ]
  	point[3] [ 1 0 ]
	z [0 0.2]
   )
	
  	gui_nose 1
	mass 25.0
	drive "diff"
	localization "odom" # gps für fehlerfreie Odometrie
	odom_error [0.03 0.03 0.00 0.05]

	hokuyo_body(pose [0.3 0 -0.3 0])
	pantilt(pose [0.3 0 -0.1 0])
)