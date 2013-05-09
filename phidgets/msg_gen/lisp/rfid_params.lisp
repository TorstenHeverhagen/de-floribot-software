; Auto-generated. Do not edit!


(cl:in-package phidgets-msg)


;//! \htmlinclude rfid_params.msg.html

(cl:defclass <rfid_params> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (gained
    :reader gained
    :initarg :gained
    :type cl:boolean
    :initform cl:nil)
   (tag
    :reader tag
    :initarg :tag
    :type cl:string
    :initform ""))
)

(cl:defclass rfid_params (<rfid_params>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <rfid_params>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'rfid_params)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name phidgets-msg:<rfid_params> is deprecated: use phidgets-msg:rfid_params instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <rfid_params>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-msg:header-val is deprecated.  Use phidgets-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'gained-val :lambda-list '(m))
(cl:defmethod gained-val ((m <rfid_params>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-msg:gained-val is deprecated.  Use phidgets-msg:gained instead.")
  (gained m))

(cl:ensure-generic-function 'tag-val :lambda-list '(m))
(cl:defmethod tag-val ((m <rfid_params>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-msg:tag-val is deprecated.  Use phidgets-msg:tag instead.")
  (tag m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <rfid_params>) ostream)
  "Serializes a message object of type '<rfid_params>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'gained) 1 0)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'tag))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'tag))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <rfid_params>) istream)
  "Deserializes a message object of type '<rfid_params>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:slot-value msg 'gained) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'tag) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'tag) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<rfid_params>)))
  "Returns string type for a message object of type '<rfid_params>"
  "phidgets/rfid_params")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'rfid_params)))
  "Returns string type for a message object of type 'rfid_params"
  "phidgets/rfid_params")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<rfid_params>)))
  "Returns md5sum for a message object of type '<rfid_params>"
  "6943b5800eeeaa3d7f682dd30fe8108e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'rfid_params)))
  "Returns md5sum for a message object of type 'rfid_params"
  "6943b5800eeeaa3d7f682dd30fe8108e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<rfid_params>)))
  "Returns full string definition for message of type '<rfid_params>"
  (cl:format cl:nil "Header header~%bool gained~%string tag~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'rfid_params)))
  "Returns full string definition for message of type 'rfid_params"
  (cl:format cl:nil "Header header~%bool gained~%string tag~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <rfid_params>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
     4 (cl:length (cl:slot-value msg 'tag))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <rfid_params>))
  "Converts a ROS message object to a list"
  (cl:list 'rfid_params
    (cl:cons ':header (header msg))
    (cl:cons ':gained (gained msg))
    (cl:cons ':tag (tag msg))
))
