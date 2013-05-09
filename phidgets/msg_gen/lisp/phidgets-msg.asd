
(cl:in-package :asdf)

(defsystem "phidgets-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "accelerometer_params" :depends-on ("_package_accelerometer_params"))
    (:file "_package_accelerometer_params" :depends-on ("_package"))
    (:file "encoder_params" :depends-on ("_package_encoder_params"))
    (:file "_package_encoder_params" :depends-on ("_package"))
    (:file "interface_kit_params" :depends-on ("_package_interface_kit_params"))
    (:file "_package_interface_kit_params" :depends-on ("_package"))
    (:file "ir_params" :depends-on ("_package_ir_params"))
    (:file "_package_ir_params" :depends-on ("_package"))
    (:file "joystick_params" :depends-on ("_package_joystick_params"))
    (:file "_package_joystick_params" :depends-on ("_package"))
    (:file "led_params" :depends-on ("_package_led_params"))
    (:file "_package_led_params" :depends-on ("_package"))
    (:file "manager_params" :depends-on ("_package_manager_params"))
    (:file "_package_manager_params" :depends-on ("_package"))
    (:file "motor_params" :depends-on ("_package_motor_params"))
    (:file "_package_motor_params" :depends-on ("_package"))
    (:file "phsensor_params" :depends-on ("_package_phsensor_params"))
    (:file "_package_phsensor_params" :depends-on ("_package"))
    (:file "pid_params" :depends-on ("_package_pid_params"))
    (:file "_package_pid_params" :depends-on ("_package"))
    (:file "rfid_params" :depends-on ("_package_rfid_params"))
    (:file "_package_rfid_params" :depends-on ("_package"))
    (:file "servo_params" :depends-on ("_package_servo_params"))
    (:file "_package_servo_params" :depends-on ("_package"))
    (:file "spatial_params" :depends-on ("_package_spatial_params"))
    (:file "_package_spatial_params" :depends-on ("_package"))
    (:file "stepper_params" :depends-on ("_package_stepper_params"))
    (:file "_package_stepper_params" :depends-on ("_package"))
    (:file "textlcd_params" :depends-on ("_package_textlcd_params"))
    (:file "_package_textlcd_params" :depends-on ("_package"))
  ))