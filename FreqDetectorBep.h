/*----- PROTECTED REGION ID(FreqDetectorBep.h) ENABLED START -----*/
//=============================================================================
//
// file :        FreqDetectorBep.h
//
// description : Include file for the FreqDetectorBep class
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


#ifndef FreqDetectorBep_H
#define FreqDetectorBep_H

#include <tango.h>
#include <slio24.h>

/*----- PROTECTED REGION END -----*/	//	FreqDetectorBep.h

/**
 *  FreqDetectorBep class description:
 *    
 */

namespace FreqDetectorBep_ns
{
/*----- PROTECTED REGION ID(FreqDetectorBep::Additional Class Declarations) ENABLED START -----*/

//	Additional Class Declarations

/*----- PROTECTED REGION END -----*/	//	FreqDetectorBep::Additional Class Declarations

class FreqDetectorBep : public TANGO_BASE_CLASS
{

/*----- PROTECTED REGION ID(FreqDetectorBep::Data Members) ENABLED START -----*/

//	Add your own data members
	std::unique_ptr<SLIO24::Device> dev;

/*----- PROTECTED REGION END -----*/	//	FreqDetectorBep::Data Members

//	Device property data members
public:
	//	CanPort:	Name of CANBus port. (can0, vcan1, mxcan2 etc.)
	string	canPort;
	//	CanAddr:	8 bit address ( 0xf4 )
	string	canAddr;
	//	PollSettings:	Set poll all attributes or not
	Tango::DevBoolean	pollSettings;

	bool	mandatoryNotDefined;

//	Attribute data members
public:
	Tango::DevFloat	*attr_freq_read;

//	Constructors and destructors
public:
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	FreqDetectorBep(Tango::DeviceClass *cl,string &s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	FreqDetectorBep(Tango::DeviceClass *cl,const char *s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device name
	 *	@param d	Device description.
	 */
	FreqDetectorBep(Tango::DeviceClass *cl,const char *s,const char *d);
	/**
	 * The device object destructor.
	 */
	~FreqDetectorBep() {delete_device();};


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

	/*
	 *	Check if mandatory property has been set
	 */
	 void check_mandatory_property(Tango::DbDatum &class_prop, Tango::DbDatum &dev_prop);

//	Attribute methods
public:
	//--------------------------------------------------------
	/*
	 *	Method      : FreqDetectorBep::read_attr_hardware()
	 *	Description : Hardware acquisition for attributes.
	 */
	//--------------------------------------------------------
	virtual void read_attr_hardware(vector<long> &attr_list);
	//--------------------------------------------------------
	/*
	 *	Method      : FreqDetectorBep::write_attr_hardware()
	 *	Description : Hardware writing for attributes.
	 */
	//--------------------------------------------------------
	virtual void write_attr_hardware(vector<long> &attr_list);

/**
 *	Attribute freq related methods
 *	Description: 
 *
 *	Data type:	Tango::DevFloat
 *	Attr type:	Scalar
 */
	virtual void read_freq(Tango::Attribute &attr);
	virtual void write_freq(Tango::WAttribute &attr);
	virtual bool is_freq_allowed(Tango::AttReqType type);


	//--------------------------------------------------------
	/**
	 *	Method      : FreqDetectorBep::add_dynamic_attributes()
	 *	Description : Add dynamic attributes if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_attributes();




//	Command related methods
public:
	/**
	 *	Command OnTimer related method
	 *	Description: 
	 *
	 */
	virtual void on_timer();
	virtual bool is_OnTimer_allowed(const CORBA::Any &any);


	//--------------------------------------------------------
	/**
	 *	Method      : FreqDetectorBep::add_dynamic_commands()
	 *	Description : Add dynamic commands if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_commands();

/*----- PROTECTED REGION ID(FreqDetectorBep::Additional Method prototypes) ENABLED START -----*/

//	Additional Method prototypes
	void on_dev_state(SLIO24::Device& dev, SLIO24::Device::State state);
	void on_dev_event(SLIO24::Device& dev, SLIO24::Device::Event event);
/*----- PROTECTED REGION END -----*/	//	FreqDetectorBep::Additional Method prototypes
};

/*----- PROTECTED REGION ID(FreqDetectorBep::Additional Classes Definitions) ENABLED START -----*/

//	Additional Classes Definitions

/*----- PROTECTED REGION END -----*/	//	FreqDetectorBep::Additional Classes Definitions

}	//	End of namespace

#endif   //	FreqDetectorBep_H
