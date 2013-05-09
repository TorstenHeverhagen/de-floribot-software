; Auto-generated. Do not edit!


(cl:in-package phidgets-msg)


;//! \htmlinclude led_params.msg.html

(cl:defclass <led_params> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (brightness
    :reader brightness
    :initarg :brightness
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass led_params (<led_params>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <led_params>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'led_params)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name phidgets-msg:<led_params> is deprecated: use phidgets-msg:led_params instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <led_params>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-msg:header-val is deprecated.  Use phidgets-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'brightness-val :lambda-list '(m))
(cl:defmethod brightness-val ((m <led_params>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-msg:brightness-val is deprecated.  Use phidgets-msg:brightness instead.")
  (brightness m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <led_params>) ostream)
  "Serializes a message object of type '<led_params>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'brightness))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'brightness))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <led_params>) istream)
  "Deserializes a message object of type '<led_params>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'brightness) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'brightness)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<led_params>)))
  "Returns string type for a message object of type '<led_params>"
  "phidgets/led_params")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'led_params)))
  "Returns string type for a message object of type 'led_params"
  "phidgets/led_params")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<led_params>)))
  "Returns md5sum for a message object of type '<led_params>"
  "96e6783756aededccc7bc0f33d16d7bf")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'led_params)))
  "Returns md5sum for a message object of type 'led_params"
  "96e6783756aededccc7bc0f33d16d7bf")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<led_params>)))
  "Returns full string definition for message of type '<led_params>"
  (cl:format cl:nil "Header header~%byte[] brightness~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'led_params)))
  "Returns full string definition for message of type 'led_params"
  (cl:format cl:nil "Header header~%byte[] brightness~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <led_params>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'brightness) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <led_params>))
  "Converts a ROS message object to a list"
  (cl:list 'led_params
    (cl:cons ':header (header msg))
    (cl:cons ':brightness (brightness msg))
))
