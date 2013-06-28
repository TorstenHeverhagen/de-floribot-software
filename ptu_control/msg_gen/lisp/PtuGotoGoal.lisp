; Auto-generated. Do not edit!


(cl:in-package ptu_control-msg)


;//! \htmlinclude PtuGotoGoal.msg.html

(cl:defclass <PtuGotoGoal> (roslisp-msg-protocol:ros-message)
  ((pan
    :reader pan
    :initarg :pan
    :type cl:float
    :initform 0.0)
   (tilt
    :reader tilt
    :initarg :tilt
    :type cl:float
    :initform 0.0)
   (pan_vel
    :reader pan_vel
    :initarg :pan_vel
    :type cl:float
    :initform 0.0)
   (tilt_vel
    :reader tilt_vel
    :initarg :tilt_vel
    :type cl:float
    :initform 0.0))
)

(cl:defclass PtuGotoGoal (<PtuGotoGoal>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PtuGotoGoal>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PtuGotoGoal)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ptu_control-msg:<PtuGotoGoal> is deprecated: use ptu_control-msg:PtuGotoGoal instead.")))

(cl:ensure-generic-function 'pan-val :lambda-list '(m))
(cl:defmethod pan-val ((m <PtuGotoGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ptu_control-msg:pan-val is deprecated.  Use ptu_control-msg:pan instead.")
  (pan m))

(cl:ensure-generic-function 'tilt-val :lambda-list '(m))
(cl:defmethod tilt-val ((m <PtuGotoGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ptu_control-msg:tilt-val is deprecated.  Use ptu_control-msg:tilt instead.")
  (tilt m))

(cl:ensure-generic-function 'pan_vel-val :lambda-list '(m))
(cl:defmethod pan_vel-val ((m <PtuGotoGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ptu_control-msg:pan_vel-val is deprecated.  Use ptu_control-msg:pan_vel instead.")
  (pan_vel m))

(cl:ensure-generic-function 'tilt_vel-val :lambda-list '(m))
(cl:defmethod tilt_vel-val ((m <PtuGotoGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ptu_control-msg:tilt_vel-val is deprecated.  Use ptu_control-msg:tilt_vel instead.")
  (tilt_vel m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PtuGotoGoal>) ostream)
  "Serializes a message object of type '<PtuGotoGoal>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'pan))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'tilt))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'pan_vel))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'tilt_vel))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PtuGotoGoal>) istream)
  "Deserializes a message object of type '<PtuGotoGoal>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'pan) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'tilt) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'pan_vel) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'tilt_vel) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PtuGotoGoal>)))
  "Returns string type for a message object of type '<PtuGotoGoal>"
  "ptu_control/PtuGotoGoal")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PtuGotoGoal)))
  "Returns string type for a message object of type 'PtuGotoGoal"
  "ptu_control/PtuGotoGoal")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PtuGotoGoal>)))
  "Returns md5sum for a message object of type '<PtuGotoGoal>"
  "3081c5893ca658a36b6caa436091a00d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PtuGotoGoal)))
  "Returns md5sum for a message object of type 'PtuGotoGoal"
  "3081c5893ca658a36b6caa436091a00d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PtuGotoGoal>)))
  "Returns full string definition for message of type '<PtuGotoGoal>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%# goal~%float32 pan~%float32 tilt~%float32 pan_vel~%float32 tilt_vel~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PtuGotoGoal)))
  "Returns full string definition for message of type 'PtuGotoGoal"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%# goal~%float32 pan~%float32 tilt~%float32 pan_vel~%float32 tilt_vel~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PtuGotoGoal>))
  (cl:+ 0
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PtuGotoGoal>))
  "Converts a ROS message object to a list"
  (cl:list 'PtuGotoGoal
    (cl:cons ':pan (pan msg))
    (cl:cons ':tilt (tilt msg))
    (cl:cons ':pan_vel (pan_vel msg))
    (cl:cons ':tilt_vel (tilt_vel msg))
))
