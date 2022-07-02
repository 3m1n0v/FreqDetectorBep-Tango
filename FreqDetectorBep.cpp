/*----- PROTECTED REGION ID(FreqDetectorBep.cpp) ENABLED START -----*/
//=============================================================================
//
// file :        FreqDetectorBep.cpp
//
// description : C++ source for the FreqDetectorBep class and its commands.
//               The class is derived from Device. It represents the
//               CORBA servant object which will be accessed from the
//               network. All commands which can be executed on the
//               FreqDetectorBep are implemented in this file.
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


#include <FreqDetectorBep.h>
#include <FreqDetectorBepClass.h>

/*----- PROTECTED REGION END -----*/	//	FreqDetectorBep.cpp

/**
 *  FreqDetectorBep class description:
 *    
 */

//================================================================
//  The following table gives the correspondence
//  between command and method names.
//
//  Command name  |  Method name
//================================================================
//  State         |  Inherited (no method)
//  Status        |  Inherited (no method)
//  OnTimer       |  on_timer
//================================================================

//================================================================
//  Attributes managed is:
//================================================================
//  freq  |  Tango::DevFloat	Scalar
//================================================================

namespace FreqDetectorBep_ns
{
/*----- PROTECTED REGION ID(FreqDetectorBep::namespace_starting) ENABLED START -----*/

//	static initializations
using namespace CAN;
/*----- PROTECTED REGION END -----*/	//	FreqDetectorBep::namespace_starting

//--------------------------------------------------------
/**
 *	Method      : FreqDetectorBep::FreqDetectorBep()
 *	Description : Constructors for a Tango device
 *                implementing the classFreqDetectorBep
 */
//--------------------------------------------------------
FreqDetectorBep::FreqDetectorBep(Tango::DeviceClass *cl, string &s)
 : TANGO_BASE_CLASS(cl, s.c_str())
{
	/*----- PROTECTED REGION ID(FreqDetectorBep::constructor_1) ENABLED START -----*/
	init_device();
	
	/*----- PROTECTED REGION END -----*/	//	FreqDetectorBep::constructor_1
}
//--------------------------------------------------------
FreqDetectorBep::FreqDetectorBep(Tango::DeviceClass *cl, const char *s)
 : TANGO_BASE_CLASS(cl, s)
{
	/*----- PROTECTED REGION ID(FreqDetectorBep::constructor_2) ENABLED START -----*/
	init_device();
	
	/*----- PROTECTED REGION END -----*/	//	FreqDetectorBep::constructor_2
}
//--------------------------------------------------------
FreqDetectorBep::FreqDetectorBep(Tango::DeviceClass *cl, const char *s, const char *d)
 : TANGO_BASE_CLASS(cl, s, d)
{
	/*----- PROTECTED REGION ID(FreqDetectorBep::constructor_3) ENABLED START -----*/
	init_device();
	
	/*----- PROTECTED REGION END -----*/	//	FreqDetectorBep::constructor_3
}

//--------------------------------------------------------
/**
 *	Method      : FreqDetectorBep::delete_device()
 *	Description : will be called at device destruction or at init command
 */
//--------------------------------------------------------
void FreqDetectorBep::delete_device()
{
	DEBUG_STREAM << "FreqDetectorBep::delete_device() " << device_name << endl;
	/*----- PROTECTED REGION ID(FreqDetectorBep::delete_device) ENABLED START -----*/
	
	//	Delete device allocated objects
	dev.reset();
	/*----- PROTECTED REGION END -----*/	//	FreqDetectorBep::delete_device
	delete[] attr_freq_read;
}

//--------------------------------------------------------
/**
 *	Method      : FreqDetectorBep::init_device()
 *	Description : will be called at device initialization.
 */
//--------------------------------------------------------
void FreqDetectorBep::init_device()
{
	DEBUG_STREAM << "FreqDetectorBep::init_device() create device " << device_name << endl;
	/*----- PROTECTED REGION ID(FreqDetectorBep::init_device_before) ENABLED START -----*/
	
	//	Initialization before get_device_property() call
	
	/*----- PROTECTED REGION END -----*/	//	FreqDetectorBep::init_device_before
	

	//	Get the device properties from database
	get_device_property();
	
	attr_freq_read = new Tango::DevFloat[1];
	//	No longer if mandatory property not set. 
	if (mandatoryNotDefined)
		return;

	/*----- PROTECTED REGION ID(FreqDetectorBep::init_device) ENABLED START -----*/
	
	//	Initialize device
	try
	{
		set_state(Tango::INIT);
		set_status("Device is initializing");

		CANInterface* iface = CANBus::instance().interface(canPort);
		unsigned short addr = std::stoi(canAddr, 0, 0);
		dev = std::unique_ptr<SLIO24::Device>(new SLIO24::Device(iface,addr));

		dev->poll_settings(pollSettings, 0);
	}
	catch(CANException& ex)
	{
		set_state(Tango::FAULT);
		set_status("Error on initializing device - CAN exception");
		ERROR_STREAM << "FreqDetectorBep::init_device() - CAN exception in " << device_name << endl
					 << ex.what() << endl;
	}
	/*----- PROTECTED REGION END -----*/	//	FreqDetectorBep::init_device
}

//--------------------------------------------------------
/**
 *	Method      : FreqDetectorBep::get_device_property()
 *	Description : Read database to initialize property data members.
 */
//--------------------------------------------------------
void FreqDetectorBep::get_device_property()
{
	/*----- PROTECTED REGION ID(FreqDetectorBep::get_device_property_before) ENABLED START -----*/
	
	//	Initialize property data members
	
	/*----- PROTECTED REGION END -----*/	//	FreqDetectorBep::get_device_property_before

	mandatoryNotDefined = false;

	//	Read device properties from database.
	Tango::DbData	dev_prop;
	dev_prop.push_back(Tango::DbDatum("CanPort"));
	dev_prop.push_back(Tango::DbDatum("CanAddr"));
	dev_prop.push_back(Tango::DbDatum("PollSettings"));

	//	is there at least one property to be read ?
	if (dev_prop.size()>0)
	{
		//	Call database and extract values
		if (Tango::Util::instance()->_UseDb==true)
			get_db_device()->get_property(dev_prop);
	
		//	get instance on FreqDetectorBepClass to get class property
		Tango::DbDatum	def_prop, cl_prop;
		FreqDetectorBepClass	*ds_class =
			(static_cast<FreqDetectorBepClass *>(get_device_class()));
		int	i = -1;

		//	Try to initialize CanPort from class property
		cl_prop = ds_class->get_class_property(dev_prop[++i].name);
		if (cl_prop.is_empty()==false)	cl_prop  >>  canPort;
		else {
			//	Try to initialize CanPort from default device value
			def_prop = ds_class->get_default_device_property(dev_prop[i].name);
			if (def_prop.is_empty()==false)	def_prop  >>  canPort;
		}
		//	And try to extract CanPort value from database
		if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  canPort;
		//	Property StartDsPath is mandatory, check if has been defined in database.
		check_mandatory_property(cl_prop, dev_prop[i]);

		//	Try to initialize CanAddr from class property
		cl_prop = ds_class->get_class_property(dev_prop[++i].name);
		if (cl_prop.is_empty()==false)	cl_prop  >>  canAddr;
		else {
			//	Try to initialize CanAddr from default device value
			def_prop = ds_class->get_default_device_property(dev_prop[i].name);
			if (def_prop.is_empty()==false)	def_prop  >>  canAddr;
		}
		//	And try to extract CanAddr value from database
		if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  canAddr;
		//	Property StartDsPath is mandatory, check if has been defined in database.
		check_mandatory_property(cl_prop, dev_prop[i]);

		//	Try to initialize PollSettings from class property
		cl_prop = ds_class->get_class_property(dev_prop[++i].name);
		if (cl_prop.is_empty()==false)	cl_prop  >>  pollSettings;
		else {
			//	Try to initialize PollSettings from default device value
			def_prop = ds_class->get_default_device_property(dev_prop[i].name);
			if (def_prop.is_empty()==false)	def_prop  >>  pollSettings;
		}
		//	And try to extract PollSettings value from database
		if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  pollSettings;
		//	Property StartDsPath is mandatory, check if has been defined in database.
		check_mandatory_property(cl_prop, dev_prop[i]);

	}

	/*----- PROTECTED REGION ID(FreqDetectorBep::get_device_property_after) ENABLED START -----*/
	
	//	Check device property data members init
	
	/*----- PROTECTED REGION END -----*/	//	FreqDetectorBep::get_device_property_after
}
//--------------------------------------------------------
/**
 *	Method      : FreqDetectorBep::check_mandatory_property()
 *	Description : For mandatory properties check if defined in database.
 */
//--------------------------------------------------------
void FreqDetectorBep::check_mandatory_property(Tango::DbDatum &class_prop, Tango::DbDatum &dev_prop)
{
	//	Check if all properties are empty
	if (class_prop.is_empty() && dev_prop.is_empty())
	{
		TangoSys_OMemStream	tms;
		tms << endl <<"Property \'" << dev_prop.name;
		if (Tango::Util::instance()->_UseDb==true)
			tms << "\' is mandatory but not defined in database";
		else
			tms << "\' is mandatory but cannot be defined without database";
		string	status(get_status());
		status += tms.str();
		set_status(status);
		mandatoryNotDefined = true;
		/*----- PROTECTED REGION ID(FreqDetectorBep::check_mandatory_property) ENABLED START -----*/
		cerr << tms.str() << " for " << device_name << endl;
		
		/*----- PROTECTED REGION END -----*/	//	FreqDetectorBep::check_mandatory_property
	}
}


//--------------------------------------------------------
/**
 *	Method      : FreqDetectorBep::always_executed_hook()
 *	Description : method always executed before any command is executed
 */
//--------------------------------------------------------
void FreqDetectorBep::always_executed_hook()
{
	DEBUG_STREAM << "FreqDetectorBep::always_executed_hook()  " << device_name << endl;
	if (mandatoryNotDefined)
	{
		string	status(get_status());
		Tango::Except::throw_exception(
					(const char *)"PROPERTY_NOT_SET",
					status.c_str(),
					(const char *)"FreqDetectorBep::always_executed_hook()");
	}
	/*----- PROTECTED REGION ID(FreqDetectorBep::always_executed_hook) ENABLED START -----*/
	
	//	code always executed before all requests
	
	/*----- PROTECTED REGION END -----*/	//	FreqDetectorBep::always_executed_hook
}

//--------------------------------------------------------
/**
 *	Method      : FreqDetectorBep::read_attr_hardware()
 *	Description : Hardware acquisition for attributes
 */
//--------------------------------------------------------
void FreqDetectorBep::read_attr_hardware(TANGO_UNUSED(vector<long> &attr_list))
{
	DEBUG_STREAM << "FreqDetectorBep::read_attr_hardware(vector<long> &attr_list) entering... " << endl;
	/*----- PROTECTED REGION ID(FreqDetectorBep::read_attr_hardware) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	FreqDetectorBep::read_attr_hardware
}
//--------------------------------------------------------
/**
 *	Method      : FreqDetectorBep::write_attr_hardware()
 *	Description : Hardware writing for attributes
 */
//--------------------------------------------------------
void FreqDetectorBep::write_attr_hardware(TANGO_UNUSED(vector<long> &attr_list))
{
	DEBUG_STREAM << "FreqDetectorBep::write_attr_hardware(vector<long> &attr_list) entering... " << endl;
	/*----- PROTECTED REGION ID(FreqDetectorBep::write_attr_hardware) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	FreqDetectorBep::write_attr_hardware
}

//--------------------------------------------------------
/**
 *	Read attribute freq related method
 *	Description: 
 *
 *	Data type:	Tango::DevFloat
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void FreqDetectorBep::read_freq(Tango::Attribute &attr)
{
	DEBUG_STREAM << "FreqDetectorBep::read_freq(Tango::Attribute &attr) entering... " << endl;
	/*----- PROTECTED REGION ID(FreqDetectorBep::read_freq) ENABLED START -----*/
	//	Set the attribute value
	SLIO24::Data data = dev->get_data();
	*attr_freq_read = 14999.455 - data.value / 2560;
	attr.set_value_date_quality(attr_freq_read, data.timestamp, Tango::ATTR_VALID);
	
	/*----- PROTECTED REGION END -----*/	//	FreqDetectorBep::read_freq
}
//--------------------------------------------------------
/**
 *	Write attribute freq related method
 *	Description: 
 *
 *	Data type:	Tango::DevFloat
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void FreqDetectorBep::write_freq(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "FreqDetectorBep::write_freq(Tango::WAttribute &attr) entering... " << endl;
	//	Retrieve write value
	Tango::DevFloat	w_val;
	attr.get_write_value(w_val);
	/*----- PROTECTED REGION ID(FreqDetectorBep::write_freq) ENABLED START -----*/
	SLIO24::Data data;
	data.value = (14999.455 - w_val) * 2560;
	dev->write_data(data);
	
	/*----- PROTECTED REGION END -----*/	//	FreqDetectorBep::write_freq
}

//--------------------------------------------------------
/**
 *	Method      : FreqDetectorBep::add_dynamic_attributes()
 *	Description : Create the dynamic attributes if any
 *                for specified device.
 */
//--------------------------------------------------------
void FreqDetectorBep::add_dynamic_attributes()
{
	/*----- PROTECTED REGION ID(FreqDetectorBep::add_dynamic_attributes) ENABLED START -----*/
	
	//	Add your own code to create and add dynamic attributes if any
	
	/*----- PROTECTED REGION END -----*/	//	FreqDetectorBep::add_dynamic_attributes
}

//--------------------------------------------------------
/**
 *	Command OnTimer related method
 *	Description: 
 *
 */
//--------------------------------------------------------
void FreqDetectorBep::on_timer()
{
	DEBUG_STREAM << "FreqDetectorBep::OnTimer()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(FreqDetectorBep::on_timer) ENABLED START -----*/
	
	//	Add your own code
	dev->poll();

	/*----- PROTECTED REGION END -----*/	//	FreqDetectorBep::on_timer
}
//--------------------------------------------------------
/**
 *	Method      : FreqDetectorBep::add_dynamic_commands()
 *	Description : Create the dynamic commands if any
 *                for specified device.
 */
//--------------------------------------------------------
void FreqDetectorBep::add_dynamic_commands()
{
	/*----- PROTECTED REGION ID(FreqDetectorBep::add_dynamic_commands) ENABLED START -----*/
	
	//	Add your own code to create and add dynamic commands if any
	
	/*----- PROTECTED REGION END -----*/	//	FreqDetectorBep::add_dynamic_commands
}

/*----- PROTECTED REGION ID(FreqDetectorBep::namespace_ending) ENABLED START -----*/

//	Additional Methods
void FreqDetectorBep::on_dev_state(SLIO24::Device& dev, SLIO24::Device::State state)
{
	if(state == SLIO24::Device::State::UNKNOWN)
	{
		set_state(Tango::UNKNOWN);
		set_status("Device is not responding");
	}
	else if(state == SLIO24::Device::State::INIT)
	{
		set_state(Tango::ON);
		set_status("Device online");
	}
}
void FreqDetectorBep::on_dev_event(SLIO24::Device& dev, SLIO24::Device::Event event)
{
	if(event == SLIO24::Device::Event::HW_RESTART)
	{
		set_status("Device was restarted");
		ERROR_STREAM << device_name << "was restarted" << endl;
	}
	else if(event == SLIO24::Device::Event::BUSOFF_REC)
	{
		set_status("Device connection was restored");
		ERROR_STREAM << device_name << "connection was restored" << endl;
	}
	else if(event == SLIO24::Device::Event::TIMEOUT)
	{
		set_status("OnTimer command was timeouted");
		ERROR_STREAM << device_name << "polling command was timeouted" << endl;
	}
	else if(event == SLIO24::Device::Event::NACK)
	{
		set_status("Acknowledgement not received from bus on data read/write");
		ERROR_STREAM << device_name << "acknowledgement not received from bus on data read/write" << endl;
	}
	else if(event == SLIO24::Device::Event::RECEIVED_DATA)
	{
		SLIO24::Data data = this->dev->get_data();
		*attr_freq_read = 14999.455 - data.value / 2560;

		try
		{
			push_change_event("freq", attr_freq_read, data.timestamp, Tango::ATTR_VALID);
		}
	 	catch(Tango::DevFailed &e)
		{
			Tango::Except::print_exception(e);
		}
	}
}
/*----- PROTECTED REGION END -----*/	//	FreqDetectorBep::namespace_ending
} //	namespace