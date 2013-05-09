; Auto-generated. Do not edit!


(cl:in-package phidgets-msg)


;//! \htmlinclude phsensor_params.msg.html

(cl:defclass <phsensor_params> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (value
    :reader value
    :initarg :value
    :type cl:float
    :initform 0.0)
   (potential
    :reader potential
    :initarg :potential
    :type cl:float
    :initform 0.0))
)

(cl:defclass phsensor_params (<phsensor_params>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <phsensor_params>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'phsensor_params)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name phidgets-msg:<phsensor_params> is deprecated: use phidgets-msg:phsensor_params instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <phsensor_params>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-msg:header-val is deprecated.  Use phidgets-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'value-val :lambda-list '(m))
(cl:defmethod value-val ((m <phsensor_params>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-msg:value-val is deprecated.  Use phidgets-msg:value instead.")
  (value m))

(cl:ensure-generic-function 'potential-val :lambda-list '(m))
(cl:defmethod potential-val ((m <phsensor_params>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-msg:potential-val is deprecated.  Use phidgets-msg:potential instead.")
  (potential m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <phsensor_params>) ostream)
  "Serializes a message object of type '<phsensor_params>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'value))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'potential))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <phsensor_params>) istream)
  "Deserializes a message object of type '<phsensor_params>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'value) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'potential) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<phsensor_params>)))
  "Returns string type for a message object of type '<phsensor_params>"
  "phidgets/phsensor_params")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'phsensor_params)))
  "Returns string type for a message object of type 'phsensor_params"
  "phidgets/phsensor_params")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<phsensor_params>)))
  "Returns md5sum for a message object of type '<phsensor_params>"
  "446c7325052f4b06c5d23c921a285e1e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'phsensor_params)))
  "Returns md5sum for a message object of type 'phsensor_params"
  "446c7325052f4b06c5d23c921a285e1e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<phsensor_params>)))
  "Returns full string definition for message of type '<phsensor_params>"
  (cl:format cl:nil "Header header~%float32 value~%float32 potential~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'phsensor_params)))
  "Returns full string definition for message of type 'phsensor_params"
  (cl:format cl:nil "Header header~%float32 value~%float32 potential~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <phsensor_params>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <phsensor_params>))
  "Converts a ROS message object to a list"
  (cl:list 'phsensor_params
    (cl:cons ':header (header msg))
    (cl:cons ':value (value msg))
    (cl:cons ':potential (potential msg))
))
