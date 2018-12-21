/*----- PROTECTED REGION ID(FourChannelAdapter.h) ENABLED START -----*/
//=============================================================================
//
// file :        FourChannelAdapter.h
//
// description : Include file for the FourChannelAdapter class
//
// project :     
//
// This file is part of Tango device class.
// 
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
// 
//
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#ifndef FourChannelAdapter_H
#define FourChannelAdapter_H

#include <tango.h>

#include "SerialPort.h"
#include "MotorClass.h"

#define DEBUG_MESSAGE

/*----- PROTECTED REGION END -----*/	//	FourChannelAdapter.h

/**
 *  FourChannelAdapter class description:
 *    
 */

namespace FourChannelAdapter_ns
{
/*----- PROTECTED REGION ID(FourChannelAdapter::Additional Class Declarations) ENABLED START -----*/

//	Additional Class Declarations

/*----- PROTECTED REGION END -----*/	//	FourChannelAdapter::Additional Class Declarations

class FourChannelAdapter : public TANGO_BASE_CLASS
{

/*----- PROTECTED REGION ID(FourChannelAdapter::Data Members) ENABLED START -----*/

private:
	//int fd = 0;							// device file Descriptor
	boost::asio::serial_port *sp;

	double currentrPosition;
	double currentPosition;
	double setrPosition;
	double  setCurrentPosition;

	double oldRPosition=0.0;

	bool leftEnd, rightEnd;

	Motor::MotorClass *mc;

/*----- PROTECTED REGION END -----*/	//	FourChannelAdapter::Data Members

//	Device property data members
public:
	//	Speed:	Speed int Hz
	Tango::DevULong	speed;
	//	Channel:	channel of the motor
	Tango::DevUShort	channel;
	//	ZeroPosition:	
	Tango::DevDouble	zeroPosition;
	//	encoderCoeffToUnit:	Coeff for convert encoder value to units
	Tango::DevDouble	encoderCoeffToUnit;
	//	Stepping:	
	Tango::DevUShort	stepping;
	//	Accelerate:	8
	Tango::DevUShort	accelerate;
	//	stepsCoeffToUnit:	convert motor step to physical unit
	Tango::DevDouble	stepsCoeffToUnit;

//	Attribute data members
public:
	Tango::DevDouble	*attr_Position_read;
	Tango::DevDouble	*attr_ZeroPosition_read;
	Tango::DevBoolean	*attr_LeftEnd_read;
	Tango::DevBoolean	*attr_RightEnd_read;
	Tango::DevDouble	*attr_rPosition_read;

//	Constructors and destructors
public:
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	FourChannelAdapter(Tango::DeviceClass *cl,string &s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	FourChannelAdapter(Tango::DeviceClass *cl,const char *s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device name
	 *	@param d	Device description.
	 */
	FourChannelAdapter(Tango::DeviceClass *cl,const char *s,const char *d);
	/**
	 * The device object destructor.
	 */
	~FourChannelAdapter() {delete_device();};


//	Miscellaneous methods
public:
	/*
	 *	will be called at device destruction or at init command.
	 */
	void delete_device();
	/*
	 *	Initialize the device
	 */
	virtual void init_device();
	/*
	 *	Read the device properties from database
	 */
	void get_device_property();
	/*
	 *	Always executed method before execution command method.
	 */
	virtual void always_executed_hook();


//	Attribute methods
public:
	//--------------------------------------------------------
	/*
	 *	Method      : FourChannelAdapter::read_attr_hardware()
	 *	Description : Hardware acquisition for attributes.
	 */
	//--------------------------------------------------------
	virtual void read_attr_hardware(vector<long> &attr_list);
	//--------------------------------------------------------
	/*
	 *	Method      : FourChannelAdapter::write_attr_hardware()
	 *	Description : Hardware writing for attributes.
	 */
	//--------------------------------------------------------
	virtual void write_attr_hardware(vector<long> &attr_list);

/**
 *	Attribute Position related methods
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_Position(Tango::Attribute &attr);
	virtual void write_Position(Tango::WAttribute &attr);
	virtual bool is_Position_allowed(Tango::AttReqType type);
/**
 *	Attribute ZeroPosition related methods
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_ZeroPosition(Tango::Attribute &attr);
	virtual void write_ZeroPosition(Tango::WAttribute &attr);
	virtual bool is_ZeroPosition_allowed(Tango::AttReqType type);
/**
 *	Attribute LeftEnd related methods
 *	Description: 
 *
 *	Data type:	Tango::DevBoolean
 *	Attr type:	Scalar
 */
	virtual void read_LeftEnd(Tango::Attribute &attr);
	virtual bool is_LeftEnd_allowed(Tango::AttReqType type);
/**
 *	Attribute RightEnd related methods
 *	Description: 
 *
 *	Data type:	Tango::DevBoolean
 *	Attr type:	Scalar
 */
	virtual void read_RightEnd(Tango::Attribute &attr);
	virtual bool is_RightEnd_allowed(Tango::AttReqType type);
/**
 *	Attribute rPosition related methods
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_rPosition(Tango::Attribute &attr);
	virtual void write_rPosition(Tango::WAttribute &attr);
	virtual bool is_rPosition_allowed(Tango::AttReqType type);


	//--------------------------------------------------------
	/**
	 *	Method      : FourChannelAdapter::add_dynamic_attributes()
	 *	Description : Add dynamic attributes if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_attributes();




//	Command related methods
public:
	/**
	 *	Command StopMove related method
	 *	Description: 
	 *
	 */
	virtual void stop_move();
	virtual bool is_StopMove_allowed(const CORBA::Any &any);
	/**
	 *	Command MoveToLeftSteps related method
	 *	Description: 
	 *
	 *	@param argin 
	 */
	virtual void move_to_left_steps(Tango::DevLong argin);
	virtual bool is_MoveToLeftSteps_allowed(const CORBA::Any &any);
	/**
	 *	Command MoveToRightSteps related method
	 *	Description: 
	 *
	 *	@param argin 
	 */
	virtual void move_to_right_steps(Tango::DevLong argin);
	virtual bool is_MoveToRightSteps_allowed(const CORBA::Any &any);
	/**
	 *	Command SetCurrentPosAsZero related method
	 *	Description: 
	 *
	 */
	virtual void set_current_pos_as_zero();
	virtual bool is_SetCurrentPosAsZero_allowed(const CORBA::Any &any);


	//--------------------------------------------------------
	/**
	 *	Method      : FourChannelAdapter::add_dynamic_commands()
	 *	Description : Add dynamic commands if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_commands();

/*----- PROTECTED REGION ID(FourChannelAdapter::Additional Method prototypes) ENABLED START -----*/

    char getMotorState();

/*----- PROTECTED REGION END -----*/	//	FourChannelAdapter::Additional Method prototypes
};

/*----- PROTECTED REGION ID(FourChannelAdapter::Additional Classes Definitions) ENABLED START -----*/

//	Additional Classes Definitions

/*----- PROTECTED REGION END -----*/	//	FourChannelAdapter::Additional Classes Definitions

}	//	End of namespace

#endif   //	FourChannelAdapter_H
