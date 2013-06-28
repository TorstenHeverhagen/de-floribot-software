; Auto-generated. Do not edit!


(cl:in-package phidgets-srv)


;//! \htmlinclude pid-request.msg.html

(cl:defclass <pid-request> (roslisp-msg-protocol:ros-message)
  ((index
    :reader index
    :initarg :index
    :type cl:integer
    :initform 0)
   (mode
    :reader mode
    :initarg :mode
    :type cl:integer
    :initform 0)
   (direction
    :reader direction
    :initarg :direction
    :type cl:integer
    :initform 0)
   (target_position
    :reader target_position
    :initarg :target_position
    :type cl:integer
    :initform 0)
   (target_velocity
    :reader target_velocity
    :initarg :target_velocity
    :type cl:float
    :initform 0.0)
   (p_gain
    :reader p_gain
    :initarg :p_gain
    :type cl:float
    :initform 0.0)
   (i_gain
    :reader i_gain
    :initarg :i_gain
    :type cl:float
    :initform 0.0)
   (d_gain
    :reader d_gain
    :initarg :d_gain
    :type cl:float
    :initform 0.0)
   (acc_ff
    :reader acc_ff
    :initarg :acc_ff
    :type cl:float
    :initform 0.0)
   (fri_ff
    :reader fri_ff
    :initarg :fri_ff
    :type cl:float
    :initform 0.0)
   (vel_ff
    :reader vel_ff
    :initarg :vel_ff
    :type cl:float
    :initform 0.0)
   (hold
    :reader hold
    :initarg :hold
    :type cl:float
    :initform 0.0)
   (bias
    :reader bias
    :initarg :bias
    :type cl:float
    :initform 0.0)
   (accel
    :reader accel
    :initarg :accel
    :type cl:float
    :initform 0.0)
   (trans
    :reader trans
    :initarg :trans
    :type cl:float
    :initform 0.0)
   (lag
    :reader lag
    :initarg :lag
    :type cl:float
    :initform 0.0)
   (min
    :reader min
    :initarg :min
    :type cl:float
    :initform 0.0)
   (max
    :reader max
    :initarg :max
    :type cl:float
    :initform 0.0)
   (slew
    :reader slew
    :initarg :slew
    :type cl:float
    :initform 0.0))
)

(cl:defclass pid-request (<pid-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <pid-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'pid-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name phidgets-srv:<pid-request> is deprecated: use phidgets-srv:pid-request instead.")))

(cl:ensure-generic-function 'index-val :lambda-list '(m))
(cl:defmethod index-val ((m <pid-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:index-val is deprecated.  Use phidgets-srv:index instead.")
  (index m))

(cl:ensure-generic-function 'mode-val :lambda-list '(m))
(cl:defmethod mode-val ((m <pid-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:mode-val is deprecated.  Use phidgets-srv:mode instead.")
  (mode m))

(cl:ensure-generic-function 'direction-val :lambda-list '(m))
(cl:defmethod direction-val ((m <pid-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:direction-val is deprecated.  Use phidgets-srv:direction instead.")
  (direction m))

(cl:ensure-generic-function 'target_position-val :lambda-list '(m))
(cl:defmethod target_position-val ((m <pid-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:target_position-val is deprecated.  Use phidgets-srv:target_position instead.")
  (target_position m))

(cl:ensure-generic-function 'target_velocity-val :lambda-list '(m))
(cl:defmethod target_velocity-val ((m <pid-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:target_velocity-val is deprecated.  Use phidgets-srv:target_velocity instead.")
  (target_velocity m))

(cl:ensure-generic-function 'p_gain-val :lambda-list '(m))
(cl:defmethod p_gain-val ((m <pid-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:p_gain-val is deprecated.  Use phidgets-srv:p_gain instead.")
  (p_gain m))

(cl:ensure-generic-function 'i_gain-val :lambda-list '(m))
(cl:defmethod i_gain-val ((m <pid-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:i_gain-val is deprecated.  Use phidgets-srv:i_gain instead.")
  (i_gain m))

(cl:ensure-generic-function 'd_gain-val :lambda-list '(m))
(cl:defmethod d_gain-val ((m <pid-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:d_gain-val is deprecated.  Use phidgets-srv:d_gain instead.")
  (d_gain m))

(cl:ensure-generic-function 'acc_ff-val :lambda-list '(m))
(cl:defmethod acc_ff-val ((m <pid-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:acc_ff-val is deprecated.  Use phidgets-srv:acc_ff instead.")
  (acc_ff m))

(cl:ensure-generic-function 'fri_ff-val :lambda-list '(m))
(cl:defmethod fri_ff-val ((m <pid-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:fri_ff-val is deprecated.  Use phidgets-srv:fri_ff instead.")
  (fri_ff m))

(cl:ensure-generic-function 'vel_ff-val :lambda-list '(m))
(cl:defmethod vel_ff-val ((m <pid-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:vel_ff-val is deprecated.  Use phidgets-srv:vel_ff instead.")
  (vel_ff m))

(cl:ensure-generic-function 'hold-val :lambda-list '(m))
(cl:defmethod hold-val ((m <pid-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:hold-val is deprecated.  Use phidgets-srv:hold instead.")
  (hold m))

(cl:ensure-generic-function 'bias-val :lambda-list '(m))
(cl:defmethod bias-val ((m <pid-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:bias-val is deprecated.  Use phidgets-srv:bias instead.")
  (bias m))

(cl:ensure-generic-function 'accel-val :lambda-list '(m))
(cl:defmethod accel-val ((m <pid-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:accel-val is deprecated.  Use phidgets-srv:accel instead.")
  (accel m))

(cl:ensure-generic-function 'trans-val :lambda-list '(m))
(cl:defmethod trans-val ((m <pid-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:trans-val is deprecated.  Use phidgets-srv:trans instead.")
  (trans m))

(cl:ensure-generic-function 'lag-val :lambda-list '(m))
(cl:defmethod lag-val ((m <pid-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:lag-val is deprecated.  Use phidgets-srv:lag instead.")
  (lag m))

(cl:ensure-generic-function 'min-val :lambda-list '(m))
(cl:defmethod min-val ((m <pid-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:min-val is deprecated.  Use phidgets-srv:min instead.")
  (min m))

(cl:ensure-generic-function 'max-val :lambda-list '(m))
(cl:defmethod max-val ((m <pid-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:max-val is deprecated.  Use phidgets-srv:max instead.")
  (max m))

(cl:ensure-generic-function 'slew-val :lambda-list '(m))
(cl:defmethod slew-val ((m <pid-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:slew-val is deprecated.  Use phidgets-srv:slew instead.")
  (slew m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <pid-request>) ostream)
  "Serializes a message object of type '<pid-request>"
  (cl:let* ((signed (cl:slot-value msg 'index)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'mode)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'direction)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'target_position)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'target_velocity))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'p_gain))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'i_gain))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'd_gain))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'acc_ff))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'fri_ff))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'vel_ff))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'hold))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'bias))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'accel))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'trans))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'lag))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'min))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'max))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'slew))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <pid-request>) istream)
  "Deserializes a message object of type '<pid-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'index) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'mode) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'direction) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'target_position) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'target_velocity) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'p_gain) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'i_gain) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'd_gain) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'acc_ff) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'fri_ff) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vel_ff) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'hold) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'bias) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'accel) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'trans) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'lag) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'min) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'max) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'slew) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<pid-request>)))
  "Returns string type for a service object of type '<pid-request>"
  "phidgets/pidRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'pid-request)))
  "Returns string type for a service object of type 'pid-request"
  "phidgets/pidRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<pid-request>)))
  "Returns md5sum for a message object of type '<pid-request>"
  "095b14b7e37aa3b1f86557d3dcc10fde")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'pid-request)))
  "Returns md5sum for a message object of type 'pid-request"
  "095b14b7e37aa3b1f86557d3dcc10fde")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<pid-request>)))
  "Returns full string definition for message of type '<pid-request>"
  (cl:format cl:nil "int32 index~%int32 mode~%int32 direction~%int32 target_position~%float32 target_velocity~%float32 p_gain~%float32 i_gain~%float32 d_gain~%float32 acc_ff~%float32 fri_ff~%float32 vel_ff~%float32 hold~%float32 bias~%float32 accel~%float32 trans~%float32 lag~%float32 min~%float32 max~%float32 slew~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'pid-request)))
  "Returns full string definition for message of type 'pid-request"
  (cl:format cl:nil "int32 index~%int32 mode~%int32 direction~%int32 target_position~%float32 target_velocity~%float32 p_gain~%float32 i_gain~%float32 d_gain~%float32 acc_ff~%float32 fri_ff~%float32 vel_ff~%float32 hold~%float32 bias~%float32 accel~%float32 trans~%float32 lag~%float32 min~%float32 max~%float32 slew~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <pid-request>))
  (cl:+ 0
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <pid-request>))
  "Converts a ROS message object to a list"
  (cl:list 'pid-request
    (cl:cons ':index (index msg))
    (cl:cons ':mode (mode msg))
    (cl:cons ':direction (direction msg))
    (cl:cons ':target_position (target_position msg))
    (cl:cons ':target_velocity (target_velocity msg))
    (cl:cons ':p_gain (p_gain msg))
    (cl:cons ':i_gain (i_gain msg))
    (cl:cons ':d_gain (d_gain msg))
    (cl:cons ':acc_ff (acc_ff msg))
    (cl:cons ':fri_ff (fri_ff msg))
    (cl:cons ':vel_ff (vel_ff msg))
    (cl:cons ':hold (hold msg))
    (cl:cons ':bias (bias msg))
    (cl:cons ':accel (accel msg))
    (cl:cons ':trans (trans msg))
    (cl:cons ':lag (lag msg))
    (cl:cons ':min (min msg))
    (cl:cons ':max (max msg))
    (cl:cons ':slew (slew msg))
))
;//! \htmlinclude pid-response.msg.html

(cl:defclass <pid-response> (roslisp-msg-protocol:ros-message)
  ((ack
    :reader ack
    :initarg :ack
    :type cl:integer
    :initform 0))
)

(cl:defclass pid-response (<pid-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <pid-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'pid-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name phidgets-srv:<pid-response> is deprecated: use phidgets-srv:pid-response instead.")))

(cl:ensure-generic-function 'ack-val :lambda-list '(m))
(cl:defmethod ack-val ((m <pid-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader phidgets-srv:ack-val is deprecated.  Use phidgets-srv:ack instead.")
  (ack m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <pid-response>) ostream)
  "Serializes a message object of type '<pid-response>"
  (cl:let* ((signed (cl:slot-value msg 'ack)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <pid-response>) istream)
  "Deserializes a message object of type '<pid-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ack) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<pid-response>)))
  "Returns string type for a service object of type '<pid-response>"
  "phidgets/pidResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'pid-response)))
  "Returns string type for a service object of type 'pid-response"
  "phidgets/pidResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<pid-response>)))
  "Returns md5sum for a message object of type '<pid-response>"
  "095b14b7e37aa3b1f86557d3dcc10fde")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'pid-response)))
  "Returns md5sum for a message object of type 'pid-response"
  "095b14b7e37aa3b1f86557d3dcc10fde")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<pid-response>)))
  "Returns full string definition for message of type '<pid-response>"
  (cl:format cl:nil "int32 ack~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'pid-response)))
  "Returns full string definition for message of type 'pid-response"
  (cl:format cl:nil "int32 ack~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <pid-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <pid-response>))
  "Converts a ROS message object to a list"
  (cl:list 'pid-response
    (cl:cons ':ack (ack msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'pid)))
  'pid-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'pid)))
  'pid-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'pid)))
  "Returns string type for a service object of type '<pid>"
  "phidgets/pid")