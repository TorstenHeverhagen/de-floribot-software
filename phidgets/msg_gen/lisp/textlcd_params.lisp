; Auto-generated. Do not edit!


(cl:in-package phidgets-msg)


;//! \htmlinclude textlcd_params.msg.html

(cl:defclass <textlcd_params> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (row
    :reader row
    :initarg :row
    :type (cl:vector cl:string)
   :initform (cl:make-array 0 :element-type 'cl:string :initial-element ""))
   (contrast
    :reader contrast
    :initarg :contrast
    :type cl:integer
    :initform 0)
   (cursor
    :reader cursor
    :initarg :cursor
    :type cl:boolean
    :initform cl:nil)
   (blink
    :reader blink
    :initarg :blink
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass textlcd_params (<textlcd_params>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <textlcd_params>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'textlcd_params)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name phidgets-msg:<textlcd_params> is deprecated: use phidgets-msg:textlcd_params instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <textlcd_params>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-msg:header-val is deprecated.  Use phidgets-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'row-val :lambda-list '(m))
(cl:defmethod row-val ((m <textlcd_params>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-msg:row-val is deprecated.  Use phidgets-msg:row instead.")
  (row m))

(cl:ensure-generic-function 'contrast-val :lambda-list '(m))
(cl:defmethod contrast-val ((m <textlcd_params>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-msg:contrast-val is deprecated.  Use phidgets-msg:contrast instead.")
  (contrast m))

(cl:ensure-generic-function 'cursor-val :lambda-list '(m))
(cl:defmethod cursor-val ((m <textlcd_params>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-msg:cursor-val is deprecated.  Use phidgets-msg:cursor instead.")
  (cursor m))

(cl:ensure-generic-function 'blink-val :lambda-list '(m))
(cl:defmethod blink-val ((m <textlcd_params>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-msg:blink-val is deprecated.  Use phidgets-msg:blink instead.")
  (blink m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <textlcd_params>) ostream)
  "Serializes a message object of type '<textlcd_params>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'row))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((__ros_str_len (cl:length ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) ele))
   (cl:slot-value msg 'row))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'contrast)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'cursor) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'blink) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <textlcd_params>) istream)
  "Deserializes a message object of type '<textlcd_params>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'row) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'row)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:aref vals i) __ros_str_idx) (cl:code-char (cl:read-byte istream))))))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'contrast)) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'cursor) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'blink) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<textlcd_params>)))
  "Returns string type for a message object of type '<textlcd_params>"
  "phidgets/textlcd_params")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'textlcd_params)))
  "Returns string type for a message object of type 'textlcd_params"
  "phidgets/textlcd_params")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<textlcd_params>)))
  "Returns md5sum for a message object of type '<textlcd_params>"
  "59746e91d84bf92a93f3c739052658f0")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'textlcd_params)))
  "Returns md5sum for a message object of type 'textlcd_params"
  "59746e91d84bf92a93f3c739052658f0")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<textlcd_params>)))
  "Returns full string definition for message of type '<textlcd_params>"
  (cl:format cl:nil "Header header~%string[] row~%byte contrast~%bool cursor~%bool blink~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'textlcd_params)))
  "Returns full string definition for message of type 'textlcd_params"
  (cl:format cl:nil "Header header~%string[] row~%byte contrast~%bool cursor~%bool blink~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <textlcd_params>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'row) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4 (cl:length ele))))
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <textlcd_params>))
  "Converts a ROS message object to a list"
  (cl:list 'textlcd_params
    (cl:cons ':header (header msg))
    (cl:cons ':row (row msg))
    (cl:cons ':contrast (contrast msg))
    (cl:cons ':cursor (cursor msg))
    (cl:cons ':blink (blink msg))
))
