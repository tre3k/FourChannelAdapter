/*----- PROTECTED REGION ID(FourChannelAdapterClass.h) ENABLED START -----*/
//=============================================================================
//
// file :        FourChannelAdapterClass.h
//
// description : Include for the FourChannelAdapter root class.
//               This class is the singleton class for
//                the FourChannelAdapter device class.
//               It contains all properties and methods which the 
//               FourChannelAdapter requires only once e.g. the commands.
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


#ifndef FourChannelAdapterClass_H
#define FourChannelAdapterClass_H

#include <tango.h>
#include <FourChannelAdapter.h>


/*----- PROTECTED REGION END -----*/	//	FourChannelAdapterClass.h


namespace FourChannelAdapter_ns
{
/*----- PROTECTED REGION ID(FourChannelAdapterClass::classes for dynamic creation) ENABLED START -----*/

static SP::SerialPort *sPort;

/*----- PROTECTED REGION END -----*/	//	FourChannelAdapterClass::classes for dynamic creation

//=========================================
//	Define classes for attributes
//=========================================
//	Attribute Position class definition
class PositionAttrib: public Tango::Attr
{
public:
	PositionAttrib():Attr("Position",
			Tango::DEV_DOUBLE, Tango::READ_WRITE) {};
	~PositionAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<FourChannelAdapter *>(dev))->read_Position(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<FourChannelAdapter *>(dev))->write_Position(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<FourChannelAdapter *>(dev))->is_Position_allowed(ty);}
};

//	Attribute ZeroPosition class definition
class ZeroPositionAttrib: public Tango::Attr
{
public:
	ZeroPositionAttrib():Attr("ZeroPosition",
			Tango::DEV_DOUBLE, Tango::READ_WRITE) {};
	~ZeroPositionAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<FourChannelAdapter *>(dev))->read_ZeroPosition(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<FourChannelAdapter *>(dev))->write_ZeroPosition(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<FourChannelAdapter *>(dev))->is_ZeroPosition_allowed(ty);}
};

//	Attribute LeftEnd class definition
class LeftEndAttrib: public Tango::Attr
{
public:
	LeftEndAttrib():Attr("LeftEnd",
			Tango::DEV_BOOLEAN, Tango::READ) {};
	~LeftEndAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<FourChannelAdapter *>(dev))->read_LeftEnd(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<FourChannelAdapter *>(dev))->is_LeftEnd_allowed(ty);}
};

//	Attribute RightEnd class definition
class RightEndAttrib: public Tango::Attr
{
public:
	RightEndAttrib():Attr("RightEnd",
			Tango::DEV_BOOLEAN, Tango::READ) {};
	~RightEndAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<FourChannelAdapter *>(dev))->read_RightEnd(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<FourChannelAdapter *>(dev))->is_RightEnd_allowed(ty);}
};

//	Attribute rPosition class definition
class rPositionAttrib: public Tango::Attr
{
public:
	rPositionAttrib():Attr("rPosition",
			Tango::DEV_DOUBLE, Tango::READ_WRITE) {};
	~rPositionAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<FourChannelAdapter *>(dev))->read_rPosition(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<FourChannelAdapter *>(dev))->write_rPosition(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<FourChannelAdapter *>(dev))->is_rPosition_allowed(ty);}
};


//=========================================
//	Define classes for commands
//=========================================
//	Command StopMove class definition
class StopMoveClass : public Tango::Command
{
public:
	StopMoveClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	StopMoveClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~StopMoveClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<FourChannelAdapter *>(dev))->is_StopMove_allowed(any);}
};

//	Command MoveToLeftSteps class definition
class MoveToLeftStepsClass : public Tango::Command
{
public:
	MoveToLeftStepsClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	MoveToLeftStepsClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~MoveToLeftStepsClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<FourChannelAdapter *>(dev))->is_MoveToLeftSteps_allowed(any);}
};

//	Command MoveToRightSteps class definition
class MoveToRightStepsClass : public Tango::Command
{
public:
	MoveToRightStepsClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	MoveToRightStepsClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~MoveToRightStepsClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<FourChannelAdapter *>(dev))->is_MoveToRightSteps_allowed(any);}
};

//	Command SetCurrentPosAsZero class definition
class SetCurrentPosAsZeroClass : public Tango::Command
{
public:
	SetCurrentPosAsZeroClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	SetCurrentPosAsZeroClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~SetCurrentPosAsZeroClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<FourChannelAdapter *>(dev))->is_SetCurrentPosAsZero_allowed(any);}
};


/**
 *	The FourChannelAdapterClass singleton definition
 */

#ifdef _TG_WINDOWS_
class __declspec(dllexport)  FourChannelAdapterClass : public Tango::DeviceClass
#else
class FourChannelAdapterClass : public Tango::DeviceClass
#endif
{
	/*----- PROTECTED REGION ID(FourChannelAdapterClass::Additionnal DServer data members) ENABLED START -----*/

	public:
		//static SP::SerialPort *sP = sPort;
		SP::SerialPort *sP;
	
	/*----- PROTECTED REGION END -----*/	//	FourChannelAdapterClass::Additionnal DServer data members

	//	Class properties data members
	public:
		//	DevicePath:	Path to the device file for the MOXA RS485
		string	devicePath;
		//	ControllerNumber:	Number of controller
		Tango::DevShort	controllerNumber;
	public:
		//	write class properties data members
		Tango::DbData	cl_prop;
		Tango::DbData	cl_def_prop;
		Tango::DbData	dev_def_prop;
	
		//	Method prototypes
		static FourChannelAdapterClass *init(const char *);
		static FourChannelAdapterClass *instance();
		~FourChannelAdapterClass();
		Tango::DbDatum	get_class_property(string &);
		Tango::DbDatum	get_default_device_property(string &);
		Tango::DbDatum	get_default_class_property(string &);
	
	protected:
		FourChannelAdapterClass(string &);
		static FourChannelAdapterClass *_instance;
		void command_factory();
		void attribute_factory(vector<Tango::Attr *> &);
		void pipe_factory();
		void write_class_property();
		void set_default_property();
		void get_class_property();
		string get_cvstag();
		string get_cvsroot();
	
	private:
		void device_factory(const Tango::DevVarStringArray *);
		void create_static_attribute_list(vector<Tango::Attr *> &);
		void erase_dynamic_attributes(const Tango::DevVarStringArray *,vector<Tango::Attr *> &);
		vector<string>	defaultAttList;
		Tango::Attr *get_attr_object_by_name(vector<Tango::Attr *> &att_list, string attname);
};

}	//	End of namespace

#endif   //	FourChannelAdapter_H
