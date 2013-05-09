; Auto-generated. Do not edit!


(cl:in-package phidgets-srv)


;//! \htmlinclude stepper-request.msg.html

(cl:defclass <stepper-request> (roslisp-msg-protocol:ros-message)
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
   (velocity
    :reader velocity
    :initarg :velocity
    :type cl:float
    :initform 0.0)
   (acceleration
    :reader acceleration
    :initarg :acceleration
    :type cl:float
    :initform 0.0)
   (position
    :reader position
    :initarg :position
    :type cl:integer
    :initform 0)
   (reset_position
    :reader reset_position
    :initarg :reset_position
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass stepper-request (<stepper-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <stepper-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'stepper-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name phidgets-srv:<stepper-request> is deprecated: use phidgets-srv:stepper-request instead.")))

(cl:ensure-generic-function 'index-val :lambda-list '(m))
(cl:defmethod index-val ((m <stepper-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:index-val is deprecated.  Use phidgets-srv:index instead.")
  (index m))

(cl:ensure-generic-function 'engage-val :lambda-list '(m))
(cl:defmethod engage-val ((m <stepper-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:engage-val is deprecated.  Use phidgets-srv:engage instead.")
  (engage m))

(cl:ensure-generic-function 'velocity-val :lambda-list '(m))
(cl:defmethod velocity-val ((m <stepper-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:velocity-val is deprecated.  Use phidgets-srv:velocity instead.")
  (velocity m))

(cl:ensure-generic-function 'acceleration-val :lambda-list '(m))
(cl:defmethod acceleration-val ((m <stepper-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:acceleration-val is deprecated.  Use phidgets-srv:acceleration instead.")
  (acceleration m))

(cl:ensure-generic-function 'position-val :lambda-list '(m))
(cl:defmethod position-val ((m <stepper-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:position-val is deprecated.  Use phidgets-srv:position instead.")
  (position m))

(cl:ensure-generic-function 'reset_position-val :lambda-list '(m))
(cl:defmethod reset_position-val ((m <stepper-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:reset_position-val is deprecated.  Use phidgets-srv:reset_position instead.")
  (reset_position m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <stepper-request>) ostream)
  "Serializes a message object of type '<stepper-request>"
  (cl:let* ((signed (cl:slot-value msg 'index)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'engage) 1 0)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'velocity))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'acceleration))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'position)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'reset_position) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <stepper-request>) istream)
  "Deserializes a message object of type '<stepper-request>"
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
    (cl:setf (cl:slot-value msg 'velocity) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'acceleration) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'position) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:setf (cl:slot-value msg 'reset_position) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<stepper-request>)))
  "Returns string type for a service object of type '<stepper-request>"
  "phidgets/stepperRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'stepper-request)))
  "Returns string type for a service object of type 'stepper-request"
  "phidgets/stepperRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<stepper-request>)))
  "Returns md5sum for a message object of type '<stepper-request>"
  "4072c02b1e0ebcc1552d02f11a06dcf5")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'stepper-request)))
  "Returns md5sum for a message object of type 'stepper-request"
  "4072c02b1e0ebcc1552d02f11a06dcf5")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<stepper-request>)))
  "Returns full string definition for message of type '<stepper-request>"
  (cl:format cl:nil "int32 index~%bool engage~%float32 velocity~%float32 acceleration~%int64 position~%bool reset_position~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'stepper-request)))
  "Returns full string definition for message of type 'stepper-request"
  (cl:format cl:nil "int32 index~%bool engage~%float32 velocity~%float32 acceleration~%int64 position~%bool reset_position~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <stepper-request>))
  (cl:+ 0
     4
     1
     4
     4
     8
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <stepper-request>))
  "Converts a ROS message object to a list"
  (cl:list 'stepper-request
    (cl:cons ':index (index msg))
    (cl:cons ':engage (engage msg))
    (cl:cons ':velocity (velocity msg))
    (cl:cons ':acceleration (acceleration msg))
    (cl:cons ':position (position msg))
    (cl:cons ':reset_position (reset_position msg))
))
;//! \htmlinclude stepper-response.msg.html

(cl:defclass <stepper-response> (roslisp-msg-protocol:ros-message)
  ((ack
    :reader ack
    :initarg :ack
    :type cl:integer
    :initform 0))
)

(cl:defclass stepper-response (<stepper-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <stepper-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'stepper-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name phidgets-srv:<stepper-response> is deprecated: use phidgets-srv:stepper-response instead.")))

(cl:ensure-generic-function 'ack-val :lambda-list '(m))
(cl:defmethod ack-val ((m <stepper-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:ack-val is deprecated.  Use phidgets-srv:ack instead.")
  (ack m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <stepper-response>) ostream)
  "Serializes a message object of type '<stepper-response>"
  (cl:let* ((signed (cl:slot-value msg 'ack)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <stepper-response>) istream)
  "Deserializes a message object of type '<stepper-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ack) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<stepper-response>)))
  "Returns string type for a service object of type '<stepper-response>"
  "phidgets/stepperResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'stepper-response)))
  "Returns string type for a service object of type 'stepper-response"
  "phidgets/stepperResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<stepper-response>)))
  "Returns md5sum for a message object of type '<stepper-response>"
  "4072c02b1e0ebcc1552d02f11a06dcf5")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'stepper-response)))
  "Returns md5sum for a message object of type 'stepper-response"
  "4072c02b1e0ebcc1552d02f11a06dcf5")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<stepper-response>)))
  "Returns full string definition for message of type '<stepper-response>"
  (cl:format cl:nil "int32 ack~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'stepper-response)))
  "Returns full string definition for message of type 'stepper-response"
  (cl:format cl:nil "int32 ack~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <stepper-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <stepper-response>))
  "Converts a ROS message object to a list"
  (cl:list 'stepper-response
    (cl:cons ':ack (ack msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'stepper)))
  'stepper-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'stepper)))
  'stepper-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'stepper)))
  "Returns string type for a service object of type '<stepper>"
  "phidgets/stepper")