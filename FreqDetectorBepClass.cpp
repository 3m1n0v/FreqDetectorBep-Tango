/*----- PROTECTED REGION ID(FreqDetectorBepClass.cpp) ENABLED START -----*/
//=============================================================================
//
// file :        FreqDetectorBepClass.cpp
//
// description : C++ source for the FreqDetectorBepClass.
//               A singleton class derived from DeviceClass.
//               It implements the command and attribute list
//               and all properties and methods required
//               by the FreqDetectorBep once per process.
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


#include <FreqDetectorBepClass.h>

/*----- PROTECTED REGION END -----*/	//	FreqDetectorBepClass.cpp

//-------------------------------------------------------------------
/**
 *	Create FreqDetectorBepClass singleton and
 *	return it in a C function for Python usage
 */
//-------------------------------------------------------------------
extern "C" {
#ifdef _TG_WINDOWS_

__declspec(dllexport)

#endif

	Tango::DeviceClass *_create_FreqDetectorBep_class(const char *name) {
		return FreqDetectorBep_ns::FreqDetectorBepClass::init(name);
	}
}

namespace FreqDetectorBep_ns
{
//===================================================================
//	Initialize pointer for singleton pattern
//===================================================================
FreqDetectorBepClass *FreqDetectorBepClass::_instance = NULL;

//--------------------------------------------------------
/**
 * method : 		FreqDetectorBepClass::FreqDetectorBepClass(string &s)
 * description : 	constructor for the FreqDetectorBepClass
 *
 * @param s	The class name
 */
//--------------------------------------------------------
FreqDetectorBepClass::FreqDetectorBepClass(string &s):Tango::DeviceClass(s)
{
	cout2 << "Entering FreqDetectorBepClass constructor" << endl;
	set_default_property();
	write_class_property();

	/*----- PROTECTED REGION ID(FreqDetectorBepClass::constructor) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	FreqDetectorBepClass::constructor

	cout2 << "Leaving FreqDetectorBepClass constructor" << endl;
}

//--------------------------------------------------------
/**
 * method : 		FreqDetectorBepClass::~FreqDetectorBepClass()
 * description : 	destructor for the FreqDetectorBepClass
 */
//--------------------------------------------------------
FreqDetectorBepClass::~FreqDetectorBepClass()
{
	/*----- PROTECTED REGION ID(FreqDetectorBepClass::destructor) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	FreqDetectorBepClass::destructor

	_instance = NULL;
}


//--------------------------------------------------------
/**
 * method : 		FreqDetectorBepClass::init
 * description : 	Create the object if not already done.
 *                  Otherwise, just return a pointer to the object
 *
 * @param	name	The class name
 */
//--------------------------------------------------------
FreqDetectorBepClass *FreqDetectorBepClass::init(const char *name)
{
	if (_instance == NULL)
	{
		try
		{
			string s(name);
			_instance = new FreqDetectorBepClass(s);
		}
		catch (bad_alloc &)
		{
			throw;
		}
	}
	return _instance;
}

//--------------------------------------------------------
/**
 * method : 		FreqDetectorBepClass::instance
 * description : 	Check if object already created,
 *                  and return a pointer to the object
 */
//--------------------------------------------------------
FreqDetectorBepClass *FreqDetectorBepClass::instance()
{
	if (_instance == NULL)
	{
		cerr << "Class is not initialised !!" << endl;
		exit(-1);
	}
	return _instance;
}



//===================================================================
//	Command execution method calls
//===================================================================
//--------------------------------------------------------
/**
 * method : 		OnTimerClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *OnTimerClass::execute(Tango::DeviceImpl *device, TANGO_UNUSED(const CORBA::Any &in_any))
{
	cout2 << "OnTimerClass::execute(): arrived" << endl;
	((static_cast<FreqDetectorBep *>(device))->on_timer());
	return new CORBA::Any();
}


//===================================================================
//	Properties management
//===================================================================
//--------------------------------------------------------
/**
 *	Method      : FreqDetectorBepClass::get_class_property()
 *	Description : Get the class property for specified name.
 */
//--------------------------------------------------------
Tango::DbDatum FreqDetectorBepClass::get_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_prop.size() ; i++)
		if (cl_prop[i].name == prop_name)
			return cl_prop[i];
	//	if not found, returns  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : FreqDetectorBepClass::get_default_device_property()
 *	Description : Return the default value for device property.
 */
//--------------------------------------------------------
Tango::DbDatum FreqDetectorBepClass::get_default_device_property(string &prop_name)
{
	for (unsigned int i=0 ; i<dev_def_prop.size() ; i++)
		if (dev_def_prop[i].name == prop_name)
			return dev_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : FreqDetectorBepClass::get_default_class_property()
 *	Description : Return the default value for class property.
 */
//--------------------------------------------------------
Tango::DbDatum FreqDetectorBepClass::get_default_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_def_prop.size() ; i++)
		if (cl_def_prop[i].name == prop_name)
			return cl_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}


//--------------------------------------------------------
/**
 *	Method      : FreqDetectorBepClass::set_default_property()
 *	Description : Set default property (class and device) for wizard.
 *                For each property, add to wizard property name and description.
 *                If default value has been set, add it to wizard property and
 *                store it in a DbDatum.
 */
//--------------------------------------------------------
void FreqDetectorBepClass::set_default_property()
{
	string	prop_name;
	string	prop_desc;
	string	prop_def;
	vector<string>	vect_data;

	//	Set Default Class Properties

	//	Set Default device Properties
	prop_name = "CanPort";
	prop_desc = "Name of CANBus port. (can0, vcan1, mxcan2 etc.)";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "CanAddr";
	prop_desc = "8 bit address ( 0xf4 )";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "PollSettings";
	prop_desc = "Set poll all attributes or not";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
}

//--------------------------------------------------------
/**
 *	Method      : FreqDetectorBepClass::write_class_property()
 *	Description : Set class description fields as property in database
 */
//--------------------------------------------------------
void FreqDetectorBepClass::write_class_property()
{
	//	First time, check if database used
	if (Tango::Util::_UseDb == false)
		return;

	Tango::DbData	data;
	string	classname = get_name();
	string	header;
	string::size_type	start, end;

	//	Put title
	Tango::DbDatum	title("ProjectTitle");
	string	str_title("");
	title << str_title;
	data.push_back(title);

	//	Put Description
	Tango::DbDatum	description("Description");
	vector<string>	str_desc;
	str_desc.push_back("");
	description << str_desc;
	data.push_back(description);

	//  Put inheritance
	Tango::DbDatum	inher_datum("InheritedFrom");
	vector<string> inheritance;
	inheritance.push_back("TANGO_BASE_CLASS");
	inher_datum << inheritance;
	data.push_back(inher_datum);

	//	Call database and and values
	get_db_class()->put_property(data);
}

//===================================================================
//	Factory methods
//===================================================================

//--------------------------------------------------------
/**
 *	Method      : FreqDetectorBepClass::device_factory()
 *	Description : Create the device object(s)
 *                and store them in the device list
 */
//--------------------------------------------------------
void FreqDetectorBepClass::device_factory(const Tango::DevVarStringArray *devlist_ptr)
{
	/*----- PROTECTED REGION ID(FreqDetectorBepClass::device_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	FreqDetectorBepClass::device_factory_before

	//	Create devices and add it into the device list
	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		cout4 << "Device name : " << (*devlist_ptr)[i].in() << endl;
		device_list.push_back(new FreqDetectorBep(this, (*devlist_ptr)[i]));
	}

	//	Manage dynamic attributes if any
	erase_dynamic_attributes(devlist_ptr, get_class_attr()->get_attr_list());

	//	Export devices to the outside world
	for (unsigned long i=1 ; i<=devlist_ptr->length() ; i++)
	{
		//	Add dynamic attributes if any
		FreqDetectorBep *dev = static_cast<FreqDetectorBep *>(device_list[device_list.size()-i]);
		dev->add_dynamic_attributes();

		//	Check before if database used.
		if ((Tango::Util::_UseDb == true) && (Tango::Util::_FileDb == false))
			export_device(dev);
		else
			export_device(dev, dev->get_name().c_str());
	}

	/*----- PROTECTED REGION ID(FreqDetectorBepClass::device_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	FreqDetectorBepClass::device_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : FreqDetectorBepClass::attribute_factory()
 *	Description : Create the attribute object(s)
 *                and store them in the attribute list
 */
//--------------------------------------------------------
void FreqDetectorBepClass::attribute_factory(vector<Tango::Attr *> &att_list)
{
	/*----- PROTECTED REGION ID(FreqDetectorBepClass::attribute_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	FreqDetectorBepClass::attribute_factory_before
	//	Attribute : freq
	freqAttrib	*freq = new freqAttrib();
	Tango::UserDefaultAttrProp	freq_prop;
	//	description	not set for freq
	//	label	not set for freq
	freq_prop.set_unit("MHz");
	//	standard_unit	not set for freq
	//	display_unit	not set for freq
	//	format	not set for freq
	freq_prop.set_max_value("13434");
	freq_prop.set_min_value("13400");
	//	max_alarm	not set for freq
	//	min_alarm	not set for freq
	//	max_warning	not set for freq
	//	min_warning	not set for freq
	//	delta_t	not set for freq
	//	delta_val	not set for freq
	
	freq->set_default_properties(freq_prop);
	//	Not Polled
	freq->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	freq->set_change_event(true, true);
	att_list.push_back(freq);


	//	Create a list of static attributes
	create_static_attribute_list(get_class_attr()->get_attr_list());
	/*----- PROTECTED REGION ID(FreqDetectorBepClass::attribute_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	FreqDetectorBepClass::attribute_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : FreqDetectorBepClass::pipe_factory()
 *	Description : Create the pipe object(s)
 *                and store them in the pipe list
 */
//--------------------------------------------------------
void FreqDetectorBepClass::pipe_factory()
{
	/*----- PROTECTED REGION ID(FreqDetectorBepClass::pipe_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	FreqDetectorBepClass::pipe_factory_before
	/*----- PROTECTED REGION ID(FreqDetectorBepClass::pipe_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	FreqDetectorBepClass::pipe_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : FreqDetectorBepClass::command_factory()
 *	Description : Create the command object(s)
 *                and store them in the command list
 */
//--------------------------------------------------------
void FreqDetectorBepClass::command_factory()
{
	/*----- PROTECTED REGION ID(FreqDetectorBepClass::command_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	FreqDetectorBepClass::command_factory_before


	//	Command OnTimer
	OnTimerClass	*pOnTimerCmd =
		new OnTimerClass("OnTimer",
			Tango::DEV_VOID, Tango::DEV_VOID,
			"",
			"",
			Tango::EXPERT);
	pOnTimerCmd->set_polling_period(1000);
	command_list.push_back(pOnTimerCmd);

	/*----- PROTECTED REGION ID(FreqDetectorBepClass::command_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	FreqDetectorBepClass::command_factory_after
}

//===================================================================
//	Dynamic attributes related methods
//===================================================================

//--------------------------------------------------------
/**
 * method : 		FreqDetectorBepClass::create_static_attribute_list
 * description : 	Create the a list of static attributes
 *
 * @param	att_list	the ceated attribute list
 */
//--------------------------------------------------------
void FreqDetectorBepClass::create_static_attribute_list(vector<Tango::Attr *> &att_list)
{
	for (unsigned long i=0 ; i<att_list.size() ; i++)
	{
		string att_name(att_list[i]->get_name());
		transform(att_name.begin(), att_name.end(), att_name.begin(), ::tolower);
		defaultAttList.push_back(att_name);
	}

	cout2 << defaultAttList.size() << " attributes in default list" << endl;

	/*----- PROTECTED REGION ID(FreqDetectorBepClass::create_static_att_list) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	FreqDetectorBepClass::create_static_att_list
}


//--------------------------------------------------------
/**
 * method : 		FreqDetectorBepClass::erase_dynamic_attributes
 * description : 	delete the dynamic attributes if any.
 *
 * @param	devlist_ptr	the device list pointer
 * @param	list of all attributes
 */
//--------------------------------------------------------
void FreqDetectorBepClass::erase_dynamic_attributes(const Tango::DevVarStringArray *devlist_ptr, vector<Tango::Attr *> &att_list)
{
	Tango::Util *tg = Tango::Util::instance();

	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		Tango::DeviceImpl *dev_impl = tg->get_device_by_name(((string)(*devlist_ptr)[i]).c_str());
		FreqDetectorBep *dev = static_cast<FreqDetectorBep *> (dev_impl);

		vector<Tango::Attribute *> &dev_att_list = dev->get_device_attr()->get_attribute_list();
		vector<Tango::Attribute *>::iterator ite_att;
		for (ite_att=dev_att_list.begin() ; ite_att != dev_att_list.end() ; ++ite_att)
		{
			string att_name((*ite_att)->get_name_lower());
			if ((att_name == "state") || (att_name == "status"))
				continue;
			vector<string>::iterator ite_str = find(defaultAttList.begin(), defaultAttList.end(), att_name);
			if (ite_str == defaultAttList.end())
			{
				cout2 << att_name << " is a UNWANTED dynamic attribute for device " << (*devlist_ptr)[i] << endl;
				Tango::Attribute &att = dev->get_device_attr()->get_attr_by_name(att_name.c_str());
				dev->remove_attribute(att_list[att.get_attr_idx()], true, false);
				--ite_att;
			}
		}
	}
	/*----- PROTECTED REGION ID(FreqDetectorBepClass::erase_dynamic_attributes) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	FreqDetectorBepClass::erase_dynamic_attributes
}

//--------------------------------------------------------
/**
 *	Method      : FreqDetectorBepClass::get_attr_by_name()
 *	Description : returns Tango::Attr * object found by name
 */
//--------------------------------------------------------
Tango::Attr *FreqDetectorBepClass::get_attr_object_by_name(vector<Tango::Attr *> &att_list, string attname)
{
	vector<Tango::Attr *>::iterator it;
	for (it=att_list.begin() ; it<att_list.end() ; ++it)
		if ((*it)->get_name()==attname)
			return (*it);
	//	Attr does not exist
	return NULL;
}


/*----- PROTECTED REGION ID(FreqDetectorBepClass::Additional Methods) ENABLED START -----*/

/*----- PROTECTED REGION END -----*/	//	FreqDetectorBepClass::Additional Methods
} //	namespace
