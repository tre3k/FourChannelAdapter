/*----- PROTECTED REGION ID(FourChannelAdapterStateMachine.cpp) ENABLED START -----*/
//=============================================================================
//
// file :        FourChannelAdapterStateMachine.cpp
//
// description : State machine file for the FourChannelAdapter class
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

#include <FourChannelAdapter.h>

/*----- PROTECTED REGION END -----*/	//	FourChannelAdapter::FourChannelAdapterStateMachine.cpp

//================================================================
//  States  |  Description
//================================================================
//  ON      |  
//  FAULT   |  
//  MOVING  |  


namespace FourChannelAdapter_ns
{
//=================================================
//		Attributes Allowed Methods
//=================================================

//--------------------------------------------------------
/**
 *	Method      : FourChannelAdapter::is_Position_allowed()
 *	Description : Execution allowed for Position attribute
 */
//--------------------------------------------------------
bool FourChannelAdapter::is_Position_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for Position attribute in Write access.
	/*----- PROTECTED REGION ID(FourChannelAdapter::PositionStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	FourChannelAdapter::PositionStateAllowed_WRITE

	//	Not any excluded states for Position attribute in read access.
	/*----- PROTECTED REGION ID(FourChannelAdapter::PositionStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	FourChannelAdapter::PositionStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : FourChannelAdapter::is_ZeroPosition_allowed()
 *	Description : Execution allowed for ZeroPosition attribute
 */
//--------------------------------------------------------
bool FourChannelAdapter::is_ZeroPosition_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for ZeroPosition attribute in Write access.
	/*----- PROTECTED REGION ID(FourChannelAdapter::ZeroPositionStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	FourChannelAdapter::ZeroPositionStateAllowed_WRITE

	//	Not any excluded states for ZeroPosition attribute in read access.
	/*----- PROTECTED REGION ID(FourChannelAdapter::ZeroPositionStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	FourChannelAdapter::ZeroPositionStateAllowed_READ
	return true;
}


//=================================================
//		Commands Allowed Methods
//=================================================

//--------------------------------------------------------
/**
 *	Method      : FourChannelAdapter::is_StopMove_allowed()
 *	Description : Execution allowed for StopMove attribute
 */
//--------------------------------------------------------
bool FourChannelAdapter::is_StopMove_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for StopMove command.
	/*----- PROTECTED REGION ID(FourChannelAdapter::StopMoveStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	FourChannelAdapter::StopMoveStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : FourChannelAdapter::is_ResetMotor_allowed()
 *	Description : Execution allowed for ResetMotor attribute
 */
//--------------------------------------------------------
bool FourChannelAdapter::is_ResetMotor_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for ResetMotor command.
	/*----- PROTECTED REGION ID(FourChannelAdapter::ResetMotorStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	FourChannelAdapter::ResetMotorStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : FourChannelAdapter::is_Calibrate_allowed()
 *	Description : Execution allowed for Calibrate attribute
 */
//--------------------------------------------------------
bool FourChannelAdapter::is_Calibrate_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for Calibrate command.
	/*----- PROTECTED REGION ID(FourChannelAdapter::CalibrateStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	FourChannelAdapter::CalibrateStateAllowed
	return true;
}


/*----- PROTECTED REGION ID(FourChannelAdapter::FourChannelAdapterStateAllowed.AdditionalMethods) ENABLED START -----*/

//	Additional Methods

/*----- PROTECTED REGION END -----*/	//	FourChannelAdapter::FourChannelAdapterStateAllowed.AdditionalMethods

}	//	End of namespace
