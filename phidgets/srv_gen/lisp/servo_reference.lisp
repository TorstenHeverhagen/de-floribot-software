; Auto-generated. Do not edit!


(cl:in-package phidgets-srv)


;//! \htmlinclude servo_reference-request.msg.html

(cl:defclass <servo_reference-request> (roslisp-msg-protocol:ros-message)
  ((index
    :reader index
    :initarg :index
    :type cl:integer
    :initform 0)
   (engage
    :reader engage
    :initarg :engage
    :type cl:boolean
    :initform cl:nil)
   (position
    :reader position
    :initarg :position
    :type cl:float
    :initform 0.0)
   (speed
    :reader speed
    :initarg :speed
    :type cl:float
    :initform 0.0)
   (acceleration
    :reader acceleration
    :initarg :acceleration
    :type cl:float
    :initform 0.0))
)

(cl:defclass servo_reference-request (<servo_reference-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <servo_reference-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'servo_reference-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name phidgets-srv:<servo_reference-request> is deprecated: use phidgets-srv:servo_reference-request instead.")))

(cl:ensure-generic-function 'index-val :lambda-list '(m))
(cl:defmethod index-val ((m <servo_reference-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:index-val is deprecated.  Use phidgets-srv:index instead.")
  (index m))

(cl:ensure-generic-function 'engage-val :lambda-list '(m))
(cl:defmethod engage-val ((m <servo_reference-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:engage-val is deprecated.  Use phidgets-srv:engage instead.")
  (engage m))

(cl:ensure-generic-function 'position-val :lambda-list '(m))
(cl:defmethod position-val ((m <servo_reference-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:position-val is deprecated.  Use phidgets-srv:position instead.")
  (position m))

(cl:ensure-generic-function 'speed-val :lambda-list '(m))
(cl:defmethod speed-val ((m <servo_reference-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:speed-val is deprecated.  Use phidgets-srv:speed instead.")
  (speed m))

(cl:ensure-generic-function 'acceleration-val :lambda-list '(m))
(cl:defmethod acceleration-val ((m <servo_reference-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:acceleration-val is deprecated.  Use phidgets-srv:acceleration instead.")
  (acceleration m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <servo_reference-request>) ostream)
  "Serializes a message object of type '<servo_reference-request>"
  (cl:let* ((signed (cl:slot-value msg 'index)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'engage) 1 0)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'position))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'speed))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'acceleration))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <servo_reference-request>) istream)
  "Deserializes a message object of type '<servo_reference-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'index) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:setf (cl:slot-value msg 'engage) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'position) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'speed) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'acceleration) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<servo_reference-request>)))
  "Returns string type for a service object of type '<servo_reference-request>"
  "phidgets/servo_referenceRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'servo_reference-request)))
  "Returns string type for a service object of type 'servo_reference-request"
  "phidgets/servo_referenceRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<servo_reference-request>)))
  "Returns md5sum for a message object of type '<servo_reference-request>"
  "e147971107721d067998f603de281d62")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'servo_reference-request)))
  "Returns md5sum for a message object of type 'servo_reference-request"
  "e147971107721d067998f603de281d62")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<servo_reference-request>)))
  "Returns full string definition for message of type '<servo_reference-request>"
  (cl:format cl:nil "int32 index~%bool engage~%float32 position~%float32 speed~%float32 acceleration~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'servo_reference-request)))
  "Returns full string definition for message of type 'servo_reference-request"
  (cl:format cl:nil "int32 index~%bool engage~%float32 position~%float32 speed~%float32 acceleration~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <servo_reference-request>))
  (cl:+ 0
     4
     1
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <servo_reference-request>))
  "Converts a ROS message object to a list"
  (cl:list 'servo_reference-request
    (cl:cons ':index (index msg))
    (cl:cons ':engage (engage msg))
    (cl:cons ':position (position msg))
    (cl:cons ':speed (speed msg))
    (cl:cons ':acceleration (acceleration msg))
))
;//! \htmlinclude servo_reference-response.msg.html

(cl:defclass <servo_reference-response> (roslisp-msg-protocol:ros-message)
  ((ack
    :reader ack
    :initarg :ack
    :type cl:integer
    :initform 0))
)

(cl:defclass servo_reference-response (<servo_reference-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <servo_reference-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'servo_reference-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name phidgets-srv:<servo_reference-response> is deprecated: use phidgets-srv:servo_reference-response instead.")))

(cl:ensure-generic-function 'ack-val :lambda-list '(m))
(cl:defmethod ack-val ((m <servo_reference-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:ack-val is deprecated.  Use phidgets-srv:ack instead.")
  (ack m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <servo_reference-response>) ostream)
  "Serializes a message object of type '<servo_reference-response>"
  (cl:let* ((signed (cl:slot-value msg 'ack)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <servo_reference-response>) istream)
  "Deserializes a message object of type '<servo_reference-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ack) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<servo_reference-response>)))
  "Returns string type for a service object of type '<servo_reference-response>"
  "phidgets/servo_referenceResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'servo_reference-response)))
  "Returns string type for a service object of type 'servo_reference-response"
  "phidgets/servo_referenceResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<servo_reference-response>)))
  "Returns md5sum for a message object of type '<servo_reference-response>"
  "e147971107721d067998f603de281d62")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'servo_reference-response)))
  "Returns md5sum for a message object of type 'servo_reference-response"
  "e147971107721d067998f603de281d62")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<servo_reference-response>)))
  "Returns full string definition for message of type '<servo_reference-response>"
  (cl:format cl:nil "int32 ack~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'servo_reference-response)))
  "Returns full string definition for message of type 'servo_reference-response"
  (cl:format cl:nil "int32 ack~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <servo_reference-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <servo_reference-response>))
  "Converts a ROS message object to a list"
  (cl:list 'servo_reference-response
    (cl:cons ':ack (ack msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'servo_reference)))
  'servo_reference-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'servo_reference)))
  'servo_reference-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'servo_reference)))
  "Returns string type for a service object of type '<servo_reference>"
  "phidgets/servo_reference")