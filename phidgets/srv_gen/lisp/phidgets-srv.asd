
(cl:in-package :asdf)

(defsystem "phidgets-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "interface_kit" :depends-on ("_package_interface_kit"))
    (:file "_package_interface_kit" :depends-on ("_package"))
    (:file "lidar_control" :depends-on ("_package_lidar_control"))
    (:file "_package_lidar_control" :depends-on ("_package"))
    (:file "pid" :depends-on ("_package_pid"))
    (:file "_package_pid" :depends-on ("_package"))
    (:file "servo_reference" :depends-on ("_package_servo_reference"))
    (:file "_package_servo_reference" :depends-on ("_package"))
    (:file "stepper" :depends-on ("_package_stepper"))
    (:file "_package_stepper" :depends-on ("_package"))
  ))