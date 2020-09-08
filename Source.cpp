#include<iostream>
#include<fstream>
using namespace std;
class Helper
{
public:
	static int StringLenght(char* str)
	{
		if (str != nullptr)
		{
			int len = 0;
			for (int i = 0; str[i] != '\0'; i++)
			{
				len++;
			}
			return len;
		}
		else
		{
			return 0;
		}
		// This function should return lenght of str

	}
	static char* GetStringFromBuffer(char* str)
	{
		if (str != nullptr)
		{
			int length = StringLenght(str) + 1;
			char* arr = new char[length];
			for (int i = 0; i < length - 1; i++)
			{
				arr[i] = str[i];
			}
			arr[length - 1] = '\0';
			return arr;
		}
		else
		{
			return nullptr;
		}
		//This function should allocate required memory on heap, 
		//copy string in this memory and return newly created cstring.

	}
};
class Name
{
private:
	char* fName;
	char* lName;
public:
	Name();
	Name(char* fN, char* lN);
	Name(const Name& copy);
	char* getfName();
	char* getlName();
	void setfName(char* fN);
	void setlName(char* lN);
	friend ostream& operator<<(ostream& out, const Name & display);
	~Name();
};
Name::Name()
{
	fName = nullptr;
	lName = nullptr;
}
Name::Name(char* fN, char* lN)
{
	fName = Helper::GetStringFromBuffer(fN);
	lName = Helper::GetStringFromBuffer(lN);
}
Name::Name(const Name& copy)
{
	if (copy.fName != nullptr)
	{
		fName = Helper::GetStringFromBuffer(copy.fName);
	}
	else
	{
		fName = nullptr;
	}
	if (copy.lName != nullptr)
	{
		lName = Helper::GetStringFromBuffer(copy.lName);
	}
	else
	{
		lName = nullptr;
	}
}
char* Name::getfName()
{
	return fName;
}
char* Name::getlName()
{
	return lName;
}
void Name::setfName(char* fN)
{
	if (fName != nullptr)
	{
		delete[]fName;
		fName = Helper::GetStringFromBuffer(fN);
	}
	else
	{
		fName = Helper::GetStringFromBuffer(fN);
	}
}
void Name::setlName(char* lN)
{
	if (lName != nullptr)
	{
		delete[]lName;
		lName = Helper::GetStringFromBuffer(lN);
	}
	else
	{
		lName = Helper::GetStringFromBuffer(lN);
	}
}
ostream& operator<<(ostream& out, const Name & display)
{
	out << display.fName << " " << display.lName << endl;
	return out;
}
Name::~Name()
{
	if (fName != nullptr)
	{
		delete[]fName;
		fName = nullptr;
	}
	if (lName != nullptr)
	{
		delete[]lName;
		lName = nullptr;
	}
}
class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(int _day, int _month, int _year);
	Date(const Date& copy);
	int getday();
	int getmonth();
	int getyear();
	void setday(int _day);
	void setmonth(int _month);
	void setyear(int _year);
	friend ostream& operator<<(ostream& out, const Date & display);
};
Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}
Date::Date(int _day, int _month, int _year)
{
	day = _day;
	month = _month;
	year = _year;
}
Date::Date(const Date& copy)
{
	day = copy.day;
	month = copy.month;
	year = copy.year;
}
int Date::getday()
{
	return day;
}
int Date::getmonth()
{
	return month;
}
int Date::getyear()
{
	return year;
}
void Date::setday(int _day)
{
	day = _day;
}
void Date::setmonth(int _month)
{
	month = _month;
}
void Date::setyear(int _year)
{
	year = _year;
}
ostream& operator<<(ostream& out, const Date & display)
{
	out << display.day << " / " << display.month << " / " << display.year << endl;
	return out;
}
class mTime
{
private:
	int hour;
	int min;
	int sec;
public:
	mTime();
	mTime(int _hour, int _min, int _sec);
	mTime(const mTime& copy);
	int gethour();
	int getmin();
	int getsec();
	void sethour(int _hour);
	void setmin(int _min);
	void setsec(int _sec);
	friend ostream& operator<<(ostream& out, const mTime& display);
};
mTime::mTime()
{
	hour = 0;
	min = 0;
	sec = 0;
}
mTime::mTime(int _hour, int _min, int _sec)
{
	hour = _hour;
	min = _min;
	sec = _sec;
}
mTime::mTime(const mTime& copy)
{

	hour = copy.hour;
	min = copy.min;
	sec = copy.sec;
}
int mTime::gethour()
{
	return hour;
}
int mTime::getmin()
{
	return min;
}
int mTime::getsec()
{
	return sec;
}
void mTime::sethour(int _hour)
{
	hour = _hour;
}
void mTime::setmin(int _min)
{
	min = _min;
}
void mTime::setsec(int _sec)
{
	sec = _sec;
}
ostream& operator<<(ostream& out, const mTime& display)
{
	out << display.hour << " : " << display.min << " : " << display.sec << endl;
	return out;
}
class Person
{
private:
	Name pName;
	Date DOB;
	int Age;
	int Nid;
public:
	Person();
	Person(char* _fName, char* _lName, int _day, int _month, int _year, int _Age, int _Nid);
	Person(const Person& copy);
	Name getpName();
	Date getDOB();
	int getAge();
	int getNid();
	void setpName(char* _fName, char* _lName);
	void setDOB(int _day, int _month, int _year);
	void setAge(int _Age);
	void setNid(int _Nid);
	friend ostream& operator<<(ostream& out, const Person& display);
};
Person::Person()
{
	pName.setfName(nullptr);
	pName.setlName(nullptr);
	DOB.setday(0);
	DOB.setmonth(0);
	DOB.setyear(0);
	Age = 0;
	Nid = 0;
}
Person::Person(char* _fName, char* _lName, int _day, int _month, int _year, int _Age, int _Nid)
{
	pName.setfName(Helper::GetStringFromBuffer(_fName));
	pName.setlName(Helper::GetStringFromBuffer(_lName));
	DOB.setday(_day);
	DOB.setmonth(_month);
	DOB.setyear(_year);
	Age = _Age;
	Nid = _Nid;
}
Person::Person(const Person& copy)
{
	Name temp(copy.pName);
	char *f = Helper::GetStringFromBuffer(temp.getfName());
	char *l = Helper::GetStringFromBuffer(temp.getlName());
	Date temp1(copy.DOB);
	pName.setfName(f);
	pName.setlName(l);
	DOB.setday(temp1.getday());
	DOB.setmonth(temp1.getmonth());
	DOB.setyear(temp1.getyear());
	Age = copy.Age;
	Nid = copy.Nid;
}
Name Person::getpName()
{
	return pName;
}
Date Person::getDOB()
{
	return DOB;
}
int Person::getAge()
{
	return Age;
}
int Person::getNid()
{
	return Nid;
}
void Person::setpName(char * _fName, char* _lName)
{
	pName.setfName(_fName);
	pName.setlName(_lName);
}
void Person::setDOB(int _day, int _month, int _year)
{
	DOB.setday(_day);
	DOB.setmonth(_month);
	DOB.setyear(_year);
}
void Person::setAge(int _Age)
{
	Age = _Age;
}
void Person::setNid(int _Nid)
{
	Nid = _Nid;
}
ostream& operator<<(ostream& out, const Person& display)
{
	out << display.pName;
	out << display.DOB;
	out << display.Age << endl;
	out << display.Nid << endl;
	return out;
}
class pRecord
{
private:
	char* DiseaseType;
	Date visDate;
	mTime visTime;
	int AssignedDoc;
	float feepaid;
public:
	pRecord();
	pRecord(char* _DiseaseType, int _day, int _month, int _year, int _hour, int _min, int _sec, int _AssignedDoc, float _feepaid);
	pRecord(const pRecord& copy);
	char* getDiseaseType();
	Date getDate();
	mTime getTime();
	int getAssignedDoc();
	float getfeepaid();
	void setDiseaseType(char* _DiseaseType);
	void setDate(int _day, int _month, int _year);
	void setTime(int _hour, int _min, int _sec);
	void setAssignedDoc(int _AssignedDoc);
	void setfeepaid(float _feepaid);
	friend ostream& operator<<(ostream& out, const pRecord& display);
	~pRecord();
};
pRecord::pRecord()
{
	DiseaseType = nullptr;
	visDate.setday(0);
	visDate.setmonth(0);
	visDate.setyear(0);
	visTime.sethour(0);
	visTime.setmin(0);
	visTime.setsec(0);
	AssignedDoc = 0;
	feepaid = 0;

}
pRecord::pRecord(char* _DiseaseType, int _day, int _month, int _year, int _hour, int _min, int _sec, int _AssignedDoc, float _feepaid)
{
	DiseaseType = Helper::GetStringFromBuffer(_DiseaseType);
	visDate.setday(_day);
	visDate.setmonth(_month);
	visDate.setyear(_year);
	visTime.sethour(_hour);
	visTime.setmin(_min);
	visTime.setsec(_sec);
	AssignedDoc = _AssignedDoc;
	feepaid = _feepaid;
}
pRecord::pRecord(const pRecord& copy)
{
	DiseaseType = Helper::GetStringFromBuffer(copy.DiseaseType);
	Date temp(copy.visDate);
	mTime temp1(copy.visTime);
	visDate.setday(temp.getday());
	visDate.setmonth(temp.getmonth());
	visDate.setyear(temp.getyear());
	visTime.sethour(temp1.gethour());
	visTime.setmin(temp1.getmin());
	visTime.setsec(temp1.getsec());
	AssignedDoc = copy.AssignedDoc;
	feepaid = copy.feepaid;
}
char* pRecord::getDiseaseType()
{
	return DiseaseType;
}
Date pRecord::getDate()
{
	return visDate;
}
mTime pRecord::getTime()
{
	return visTime;
}
int pRecord::getAssignedDoc()
{
	return AssignedDoc;
}
float pRecord::getfeepaid()
{
	return feepaid;
}
void pRecord::setDiseaseType(char* _DiseaseType)
{
	if (DiseaseType != nullptr)
	{
		delete[]DiseaseType;
		DiseaseType = Helper::GetStringFromBuffer(_DiseaseType);
	}
	else
	{
		DiseaseType = Helper::GetStringFromBuffer(_DiseaseType);
	}
}
void pRecord::setDate(int _day, int _month, int _year)
{
	visDate.setday(_day);
	visDate.setmonth(_month);
	visDate.setyear(_year);
}
void pRecord::setTime(int _hour, int _min, int _sec)
{
	visTime.sethour(_hour);
	visTime.setmin(_min);
	visTime.setsec(_sec);
}
void pRecord::setAssignedDoc(int _AssignedDoc)
{
	AssignedDoc = _AssignedDoc;
}
void pRecord::setfeepaid(float _feepaid)
{
	feepaid = _feepaid;
}
ostream& operator<<(ostream& out, const pRecord& display)
{
	out << "Disease: " << display.DiseaseType << endl;
	out << "Date: " << display.visDate;
	out << "Time: " << display.visTime;
	out << "Assigned Doc: " << display.AssignedDoc << endl;
	out << "Fee: " << display.feepaid << endl;
	return out;
}
pRecord::~pRecord()
{
	if (DiseaseType != nullptr)
	{
		delete[]DiseaseType;
		DiseaseType = nullptr;
	}
	else
	{
		DiseaseType = nullptr;
	}
}
class Patient :public Person
{
private:
	int Pid;
	pRecord** history;
	int size;
public:
	Patient();
	Patient(char* _fName, char* _lName, int dday, int dmonth, int dyear, int _Age, int _Nid, int _Pid, char* _DiseaseType, int _day, int _month, int _year, int _hour, int _min, int _sec, int _AssignedDoc, float _feepaid);
	Patient(Patient& copy);
	int getPid();
	pRecord** gethistory();
	int getsize();
	void setPid(int _Pid);
	void addinhistory(char* _DiseaseType, int _day, int _month, int _year, int _hour, int _min, int _sec, int _AssignedDoc, float _feepaid);
	friend ostream& operator<<(ostream& out, Patient& display);
	~Patient();
};
Patient::Patient() :Person()
{
	Pid = 0;
	history = nullptr;
	size = 0;
}
Patient::Patient(char* _fName, char* _lName, int dday, int dmonth, int dyear, int _Age, int _Nid, int _Pid, char* _DiseaseType, int _day, int _month, int _year, int _hour, int _min, int _sec, int _AssignedDoc, float _feepaid)
{
	setpName(_fName, _lName);
	setDOB(dday, dmonth, dyear);
	setAge(_Age);
	setNid(_Nid);
	Pid = _Pid;
	if (_DiseaseType != nullptr)
	{
		history = new pRecord*;
		history[0] = new pRecord(_DiseaseType, _day, _month, _year, _hour, _min, _sec, _AssignedDoc, _feepaid);
		size = 1;
	}
	else
		size = 0;
}
Patient::Patient(Patient& copy)
{
	Name temp(copy.getpName());
	setpName(temp.getfName(), temp.getlName());
	Date temp1(copy.getDOB());
	setDOB(temp1.getday(), temp1.getmonth(), temp1.getyear());
	setAge(copy.getAge());
	setNid(copy.getNid());
	Pid = copy.Pid;
	size = copy.size;
	if (copy.history != nullptr)
	{
		history = new pRecord*[size];
		for (int i = 0; i < size; i++)
		{
			history[i] = new pRecord(*(copy.history[i]));
		}
	}
	else
	{
		history = nullptr;
	}
}
int Patient::getPid()
{
	return Pid;
}
pRecord** Patient::gethistory()
{
	return history;
}
int Patient::getsize()
{
	return size;
}
void Patient::setPid(int _Pid)
{
	Pid = _Pid;
}
void Patient::addinhistory(char* _DiseaseType, int _day, int _month, int _year, int _hour, int _min, int _sec, int _AssignedDoc, float _feepaid)
{
	pRecord **temphistory;
	temphistory = new pRecord*[size + 1];
	for (int i = 0; i < size; i++)
	{
		temphistory[i] = new pRecord(*(history[i]));
	}
	temphistory[size] = new pRecord(_DiseaseType, _day, _month, _year, _hour, _min, _sec, _AssignedDoc, _feepaid);
	size = size + 1;
	for (int i = 0; i < size - 1; i++)
	{
		delete history[i];
	}
	history = temphistory;
}
ostream& operator<<(ostream& out, Patient& display)
{
	out << "PID: " << display.Pid << endl;
	out << "Name: " << display.getpName();
	out << "DOB: " << display.getDOB();
	out << "Age: " << display.getAge() << endl;
	out << "NID: " << display.getNid() << endl;
	out << "Patient History: ";
	if (display.size == 0)
		cout << "No History." << endl;
	else
	{
		cout << endl;
		for (int i = 0; i < display.size; i++)
		{
			out << i + 1 << "." << endl;
			cout << *display.history[i] << endl;
		}
	}
	return out;
}
Patient::~Patient()
{
	if (history != nullptr)
	{
		for (int i = 0; i < size; i++)
		{
			delete history[i];
		}
		history = nullptr;
	}
	else
	{
		history = nullptr;
	}

}
class Doctor :public Person
{
private:
	int Did;
	char *specialization;
	int *patientsvisited;
	int size;
public:
	Doctor();
	Doctor(char* _fName, char* _lName, int dday, int dmonth, int dyear, int _Age, int _Nid, int _Did, char *_specializtion, int _patientid);
	Doctor(Doctor& copy);
	int getDid();
	char* getspecialization();
	int* getpatientsvisited();
	int getsize();
	void setDid(int _Did);
	void setspecialization(char* _specialization);
	void addpatientsvisited(int _Pid);
	friend ostream& operator<<(ostream& out, Doctor& display);
	~Doctor();
};
Doctor::Doctor() :Person()
{
	size = 0;
	Did = 0;
	specialization = nullptr;
	patientsvisited = nullptr;
}
Doctor::Doctor(char* _fName, char* _lName, int dday, int dmonth, int dyear, int _Age, int _Nid, int _Did, char *_specializtion, int _patientid)
{
	setpName(_fName, _lName);
	setDOB(dday, dmonth, dyear);
	setAge(_Age);
	setNid(_Nid);
	setDid(_Did);
	specialization = Helper::GetStringFromBuffer(_specializtion);
	if (_patientid != -111)
	{
		patientsvisited = new int(_patientid);
		size = 1;
	}
	else
		size = 0;
}
Doctor::Doctor(Doctor& copy)
{
	Name temp(copy.getpName());
	setpName(temp.getfName(), temp.getlName());
	Date temp1(copy.getDOB());
	setDOB(temp1.getday(), temp1.getmonth(), temp1.getyear());
	setAge(copy.getAge());
	setNid(copy.getNid());
	setDid(copy.getDid());
	specialization = Helper::GetStringFromBuffer(copy.specialization);
	if (copy.patientsvisited != nullptr)
	{
		patientsvisited = new int[copy.size];
		size = copy.size;
		for (int i = 0; i < size; i++)
		{
			patientsvisited[i] = copy.patientsvisited[i];
		}
	}
	else
	{
		patientsvisited = nullptr;
	}


}
int Doctor::getDid()
{
	return Did;
}
char* Doctor::getspecialization()
{
	return specialization;
}
int* Doctor::getpatientsvisited()
{
	return patientsvisited;
}
int Doctor::getsize()
{
	return size;
}
void Doctor::setDid(int _Did)
{
	Did = _Did;
}
void Doctor::setspecialization(char* _specialization)
{
	specialization = Helper::GetStringFromBuffer(_specialization);
}
void Doctor::addpatientsvisited(int _Pid)
{
	int *temp = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = patientsvisited[i];
	}
	temp[size] = _Pid;
	size = size + 1;
	delete[]patientsvisited;
	patientsvisited = temp;

}
ostream& operator<<(ostream& out, Doctor& display)
{
	out << "DID: " << display.Did << endl;
	out << "NID: " << display.getNid() << endl;
	out << "Name: " << display.getpName();
	out << "DOB: " << display.getDOB();
	out << "Age: " << display.getAge() << endl;
	out << "Specialization: " << display.specialization << endl;
	out << "Patients Visited (ID): ";
	if (display.size == 0)
	{
		cout << "None." << endl;
	}
	else
	{
		cout << endl;
		for (int i = 0; i < display.size; i++)
		{
			out << i + 1 << ". " << display.patientsvisited[i] << endl;
		}
	}
	cout << endl;
	return out;
}
Doctor::~Doctor()
{
	if (patientsvisited != nullptr)
	{
		delete[]patientsvisited;
		patientsvisited = nullptr;
	}
	else
	{
		patientsvisited = nullptr;
	}
	if (specialization != nullptr)
	{
		delete[]specialization;
		specialization = nullptr;
	}
	else
	{
		specialization = nullptr;
	}
}
class Appointment
{
private:
	char *DiseaseType;
	int Pid;
	int Did;
	Date appDate;
	mTime appTime;
	int token_Number;
	float fee;
	bool status;
public:
	Appointment();
	Appointment(char* _DiseaseType, int _Pid, int _Did, int _day, int _month, int _year, int _hour, int _min, int _sec, int _token_Number, float _fee, bool _status);
	Appointment(Appointment& copy);
	char *getDiseaseType();
	int getPid();
	int getDid();
	Date getappDate();
	mTime getappTime();
	int gettoken_Number();
	float getfee();
	bool getstatus();
	void setDiseaseType(char* _DiseaseType);
	void setPid(int _Pid);
	void setDid(int _Did);
	void setappDate(int _day, int _month, int _year);
	void setappTime(int _hour, int _min, int _sec);
	void settoken_Number(int _token_Number);
	void setfee(float _fee);
	void setstatus(bool _status);
	friend ostream& operator<<(ostream& out, const Appointment& display);
	~Appointment();
};
Appointment::Appointment()
{
	DiseaseType = nullptr;
	Did = 0;
	Did = 0;
	appDate.setday(0);
	appDate.setmonth(0);
	appDate.setyear(0);
	appTime.sethour(0);
	appTime.setmin(0);
	appTime.setsec(0);
	token_Number = 0;
	fee = 0;
	status = 0;
}
Appointment::Appointment(char* _DiseaseType, int _Pid, int _Did, int _day, int _month, int _year, int _hour, int _min, int _sec, int _token_Number, float _fee, bool _status)
{
	DiseaseType = Helper::GetStringFromBuffer(_DiseaseType);
	Pid = _Pid;
	Did = _Did;
	appDate.setday(_day);
	appDate.setmonth(_month);
	appDate.setyear(_year);
	appTime.sethour(_hour);
	appTime.setmin(_min);
	appTime.setsec(_sec);
	token_Number = _token_Number;
	fee = _fee;
	status = _status;
}
Appointment::Appointment(Appointment& copy)
{
	DiseaseType = Helper::GetStringFromBuffer(copy.getDiseaseType());
	Pid = copy.Pid;
	Did = copy.Did;
	Date temp(copy.getappDate());
	mTime temp1(copy.getappTime());
	appDate.setday(temp.getday());
	appDate.setmonth(temp.getmonth());
	appDate.setyear(temp.getyear());
	appTime.sethour(temp1.gethour());
	appTime.setmin(temp1.getmin());
	appTime.setsec(temp1.getsec());
	token_Number = copy.token_Number;
	fee = copy.fee;
	status = copy.status;
}
char* Appointment::getDiseaseType()
{
	return DiseaseType;
}
int Appointment::getPid()
{
	return Pid;
}
int Appointment::getDid()
{
	return Did;
}
Date Appointment::getappDate()
{
	return appDate;
}
mTime Appointment::getappTime()
{
	return appTime;
}
int Appointment::gettoken_Number()
{
	return token_Number;
}
float Appointment::getfee()
{
	return fee;
}
bool Appointment::getstatus()
{
	return status;
}
void Appointment::setDiseaseType(char* _DiseaseType)
{
	DiseaseType = Helper::GetStringFromBuffer(_DiseaseType);
}
void Appointment::setPid(int _Pid)
{
	Pid - _Pid;
}
void Appointment::setDid(int _Did)
{
	Did = _Did;
}
void Appointment::setappDate(int _day, int _month, int _year)
{
	appDate.setday(_day);
	appDate.setmonth(_month);
	appDate.setyear(_year);
}
void Appointment::setappTime(int _hour, int _min, int _sec)
{
	appTime.sethour(_hour);
	appTime.setmin(_min);
	appTime.setsec(_sec);
}
void Appointment::settoken_Number(int _token_Number)
{
	token_Number = _token_Number;
}
void Appointment::setfee(float _fee)
{
	fee = _fee;
}
void Appointment::setstatus(bool _status)
{
	status = _status;
}
ostream& operator<<(ostream& out, const Appointment& display)
{
	out << "Disease: " << display.DiseaseType << endl;
	out << "PID: " << display.Pid << endl;
	out << "DID: " << display.Did << endl;
	out << "Date: " << display.appDate;
	out << "Time: " << display.appTime;
	out << "Token: " << display.token_Number << endl;
	out << "Fee: " << display.fee << endl;
	out << "Status: ";
	if (display.status)
	{
		out << "Complete" << endl;
	}
	else
	{
		out << "Pending" << endl;
	}
	out << endl;
	return out;
}
Appointment::~Appointment()
{
	if (DiseaseType != nullptr)
	{
		delete[]DiseaseType;
		DiseaseType = nullptr;
	}
	else
	{
		DiseaseType = nullptr;
	}
}
class Clinic
{
private:
	Doctor * * Doc;
	int Docsize;
	Patient** sysPatient;
	int Patientsize;
	Appointment** sysAppointment;
	int Appointmentsize;
public:
	Clinic();
	Clinic(Doctor _Doc, Patient _sysPatient, Appointment _sysAppointment);
	Clinic(const Clinic& copy);
	Doctor** getDoc();
	Patient** getPatient();
	Appointment** getAppointment();
	void addDoc(Doctor _Doc);
	void addPatient(Patient _Patient);
	void addAppointment(Appointment _Appointment);
	void printDoc();
	void printPatient();
	void printAppointment();
	friend ostream& operator<<(ostream& out, Clinic& display);
	void getpatientfromfile();
	void addpatienthistoryfromfile();
	void getdoctorfromfile();
	void addpatientvisitedfromfile();
	void addappointmentsfromfile();
	void updateappointment(int token);
	void printpatientondate(int _day, int _month, int _year, int _did);
	void patientsamedoc(int _did);
	void appointmentpendingdate(int _day, int _month, int _year);
	void appointmentpendingdoc(int did);
	void printpatientid(int _pid);
	void printdoctorid(int _did);
	void savepatient();
	void savepatienthistory();
	void savedoc();
	void savepatientvisited();
	void saveappointments();
	~Clinic();
};
Clinic::Clinic()
{
	Doc = nullptr;
	sysPatient = nullptr;
	sysAppointment = nullptr;
	Docsize = 0;
	Patientsize = 0;
	Appointmentsize = 0;
}
Clinic::Clinic(Doctor _Doc, Patient _sysPatient, Appointment _sysAppointment)
{
	Doc = new Doctor*;
	Doc[0] = new Doctor(_Doc);
	sysPatient = new Patient*;
	sysPatient[0] = new Patient(_sysPatient);
	sysAppointment = new Appointment*;
	sysAppointment[0] = new Appointment(_sysAppointment);
	Docsize = 1;
	Patientsize = 1;
	Appointmentsize = 1;
}
Clinic::Clinic(const Clinic& copy)
{
	if (copy.Doc != nullptr)
	{
		Doc = new Doctor*[copy.Docsize];
		for (int i = 0; i < copy.Docsize; i++)
		{
			Doc[i] = new Doctor(*copy.Doc[i]);
		}
		Docsize = copy.Docsize;
	}
	else
	{
		Doc = nullptr;
		Docsize = 0;
	}
	if (copy.sysPatient != nullptr)
	{
		sysPatient = new Patient*[copy.Patientsize];
		for (int i = 0; i < copy.Patientsize; i++)
		{
			sysPatient[i] = new Patient(*copy.sysPatient[i]);
		}
		Patientsize = copy.Patientsize;
	}
	else
	{
		sysPatient = nullptr;
		Patientsize = 0;
	}
	if (copy.sysAppointment != nullptr)
	{
		sysAppointment = new Appointment*[copy.Appointmentsize];
		for (int i = 0; i < copy.Appointmentsize; i++)
		{
			sysAppointment[i] = new Appointment(*copy.sysAppointment[i]);
		}
		Appointmentsize = copy.Appointmentsize;
	}
	else
	{
		sysAppointment = nullptr;
		Appointmentsize = 0;
	}
}
Doctor** Clinic::getDoc()
{
	return Doc;
}
Patient** Clinic::getPatient()
{
	return sysPatient;
}
Appointment** Clinic::getAppointment()
{
	return sysAppointment;
}
void Clinic::addDoc(Doctor _Doc)
{
	Doctor** temp = new Doctor*[Docsize + 1];
	Docsize = Docsize + 1;
	for (int i = 0; i < Docsize - 1; i++)
	{
		temp[i] = new Doctor(*Doc[i]);
	}
	temp[Docsize - 1] = new Doctor(_Doc);
	for (int i = 0; i < Docsize - 1; i++)
	{
		delete Doc[i];
	}
	Doc = temp;
}
void Clinic::addPatient(Patient _Patient)
{
	Patient** temp = new Patient*[Patientsize + 1];
	Patientsize = Patientsize + 1;
	for (int i = 0; i < Patientsize - 1; i++)
	{
		temp[i] = new Patient(*sysPatient[i]);
	}
	temp[Patientsize - 1] = new Patient(_Patient);
	for (int i = 0; i < Patientsize - 1; i++)
	{
		delete sysPatient[i];
	}
	sysPatient = temp;
}
void Clinic::addAppointment(Appointment _Appointment)
{
	Appointment** temp = new Appointment*[Appointmentsize + 1];
	Appointmentsize = Appointmentsize + 1;
	for (int i = 0; i < Appointmentsize - 1; i++)
	{
		temp[i] = new Appointment(*sysAppointment[i]);
	}
	temp[Appointmentsize - 1] = new Appointment(_Appointment);
	for (int i = 0; i < Appointmentsize - 1; i++)
	{
		delete sysAppointment[i];
	}
	sysAppointment = temp;
}
void Clinic::printDoc()
{
	for (int i = 0; i < Docsize; i++)
	{
		if (i == 0)
			cout << "Doctors:" << endl;
		cout << i + 1 << "." << endl;
		cout << *Doc[i];
	}
	//cout << endl;
}
void Clinic::printPatient()
{

	for (int i = 0; i < Patientsize; i++)
	{
		if (i == 0)
			cout << "Patients:" << endl;
		cout << i + 1 << "." << endl;
		cout << *sysPatient[i];
		cout << endl;
	}
	//cout << endl;
}
void Clinic::printAppointment()
{
	int index = 1;
	for (int i = 0; i < Appointmentsize; i++)
	{
		if (i == 0)
			cout << "Appointments:" << endl;
		if (sysAppointment[i] != nullptr)
		{
			cout << index << "." << endl;
			cout << *sysAppointment[i];
			index++;
		}
	}
	//cout << endl;
}
ostream& operator<<(ostream& out, Clinic& display)
{
	display.printDoc();
	out << endl;
	display.printPatient();
	out << endl;
	display.printAppointment();
	out << endl;
	return out;
}
void Clinic::getpatientfromfile()
{
	int pid;
	char* fname = new char[20];
	char* lname = new char[20];
	int day;
	int month;
	int year;
	int age;
	int nid;
	int size;
	ifstream fin;
	fin.open("Patient.txt");
	while (!fin.eof())
	{
		fin >> pid;
		fin >> fname;
		fin >> lname;
		fin >> day;
		fin >> month;
		fin >> year;
		fin >> age;
		fin >> nid;
		fin >> size;
		//cout << pid << "  " << fname << "  " << lname << " " << nid << endl;
		Patient temp(fname, lname, day, month, year, age, nid, pid, nullptr, 0, 0, 0, 0, 0, 0, 0, 0);
		addPatient(temp);
	}
	fin.close();
}
void Clinic::addpatienthistoryfromfile()
{
	int size;
	int pid;
	char *disease = new char[40];
	int day;
	int month;
	int year;
	int hour;
	int min;
	int sec;
	int did;
	int fee;
	char ch;
	bool check;
	ifstream fin;
	fin.open("Patient - History.txt");
	while (!fin.eof())
	{
		//cout << Patientsize << endl;
		fin >> pid;
		//cout << pid << endl;
		for (int i = 0; i < Patientsize; i++)
		{

			if (pid == sysPatient[i]->getPid())
			{
				check = true;
				while (check == true)
				{
					fin >> disease;
					fin >> day;
					fin >> month;
					fin >> year;
					fin >> hour;
					fin >> min;
					fin >> sec;
					fin >> did;
					fin >> fee;
					sysPatient[i]->addinhistory(disease, day, month, year, hour, min, sec, did, fee);
					if (fin.eof())
						break;
					fin >> ch;
					if (fin.eof())
						break;
					//cout << ch << endl;
					fin.unget();
					if (ch >= 48 && ch <= 57)
						check = false;
				}
			}
		}
	}
	fin.close();
}
void Clinic::getdoctorfromfile()
{
	int did;
	char* fname = new char[20];
	char* lname = new char[20];
	int day;
	int month;
	int year;
	int age;
	int nid;
	char* spec = new char[40];
	ifstream fin;
	fin.open("Doctor.txt");
	while (!fin.eof())
	{
		fin >> did;
		//cout << did << endl;
		fin >> fname;
		fin >> lname;
		fin >> day;
		fin >> month;
		fin >> year;
		fin >> age;
		fin >> nid;
		fin >> spec;
		Doctor temp(fname, lname, day, month, year, age, nid, did, spec, -111);
		addDoc(temp);
		if (fin.eof())
			break;
	}
	fin.close();
}
void Clinic::addpatientvisitedfromfile()
{
	int did;
	int pid;
	char value;
	ifstream fin;
	fin.open("Patients visited.txt");
	//cout << Docsize << endl;
	int index = 0;
	while (!fin.eof())
	{
		fin >> did;
		value = 0;
		//cout << did << " ";
		while (value != '\n')
		{
			fin >> pid;
			//cout << pid << " ";
			for (int i = 0; i < Docsize; i++)
			{
				if (Doc[i]->getDid() == did)
					Doc[i]->addpatientsvisited(pid);
			}
			fin.get(value);
			//cout << value;
			if (fin.eof())
				break;
		}
		index++;
		//cout << endl;

	}
	fin.close();
}
void Clinic::addappointmentsfromfile()
{
	char* disease = new char[40];
	int pid, did, day, month, year, hour, min, sec, token, fee, status;
	ifstream fin;
	fin.open("Appointment.txt");
	while (!fin.eof())
	{
		fin >> disease >> pid >> did >> day >> month >> year >> hour >> min >> sec >> token >> fee >> status;
		Appointment temp(disease, pid, did, day, month, year, hour, min, sec, token, fee, status);
		addAppointment(temp);
	}
	fin.close();
}
void Clinic::updateappointment(int token)
{
	bool check = false;
	for (int i = 0; i < Appointmentsize; i++)
	{
		if (sysAppointment[i]->gettoken_Number() == token)
		{
			check = true;
			int pid = sysAppointment[i]->getPid();
			int did = sysAppointment[i]->getDid();
			for (int j = 0; j < Docsize; j++)
			{
				if (Doc[j]->getDid() == did)
					Doc[j]->addpatientsvisited(pid);
			}
			for (int k = 0; k < Patientsize; k++)
			{
				if (sysPatient[k]->getPid() == pid)
				{
					char *disease = sysAppointment[i]->getDiseaseType();
					Date temp(sysAppointment[i]->getappDate());
					mTime temp1(sysAppointment[i]->getappTime());
					sysPatient[k]->addinhistory(disease, temp.getday(), temp.getmonth(), temp.getyear(), temp1.gethour(), temp1.getmin(), temp1.getsec(), did, sysAppointment[i]->getfee());
				}
			}
			delete sysAppointment[i];
			sysAppointment[i] = nullptr;
		}
	}
	if (check == false)
		cout << "Token No Not Found." << endl;
	else
	{
		cout << "Appointments Updated." << endl;
	}
}
void Clinic::printpatientondate(int _day, int _month, int _year, int _did)
{
	int index = 0;
	bool check;
	for (int i = 0; i < Patientsize; i++)
	{
		check = false;
		pRecord **temp = sysPatient[i]->gethistory();
		int size = sysPatient[i]->getsize();
		for (int j = 0; j < size; j++)
		{
			Date temp1(temp[j]->getDate());
			if (_day == temp1.getday() && _month == temp1.getmonth() && _year == temp1.getyear() && temp[j]->getAssignedDoc() == _did)
			{
				check = true;
				index++;
			}
		}
		if (check)
			cout << *sysPatient[i];
	}
	if (index == 0)
	{
		cout << "None Found." << endl;
	}
}
void Clinic::patientsamedoc(int _did)
{
	int index = 0;
	int index1 = 1;
	bool check;
	for (int i = 0; i < Patientsize; i++)
	{
		check = false;
		pRecord **temp = sysPatient[i]->gethistory();
		int size = sysPatient[i]->getsize();
		for (int j = 0; j < size; j++)
		{
			if (temp[j]->getAssignedDoc() == _did)
			{
				check = true;
				index++;
			}
		}
		if (check)
		{
			cout << index1++ << "." << endl;
			cout << *sysPatient[i];
		}
	}
	if (index == 0)
	{
		cout << "None Found." << endl;
	}
}
void Clinic::appointmentpendingdate(int _day, int _month, int _year)
{
	int index = 0;
	int index1 = 1;
	for (int i = 0; i < Appointmentsize; i++)
	{
		Date temp(sysAppointment[i]->getappDate());
		if (_day == temp.getday() && _month == temp.getmonth() && _year == temp.getyear())
		{
			if (sysAppointment[i]->getstatus() == 0)
			{
				cout << index1 << "." << endl;
				cout << *sysAppointment[i];
				index++;
				index1++;
			}
		}
	}
	if (index == 0)
	{
		cout << "None Found." << endl;
	}
}
void Clinic::appointmentpendingdoc(int did)
{
	int index = 0;
	int index1 = 1;
	for (int i = 0; i < Appointmentsize; i++)
	{
		if (sysAppointment[i]->getDid() == did)
		{
			if (sysAppointment[i]->getstatus() == 0)
			{
				cout << index1 << "." << endl;
				cout << *sysAppointment[i];
				index1++;
				index++;
			}
		}
	}
	if (index == 0)
		cout << "None Found." << endl;
}
void Clinic::printpatientid(int _pid)
{
	bool check = false;
	for (int i = 0; i < Patientsize; i++)
	{
		if (sysPatient[i]->getPid() == _pid)
		{
			cout << *sysPatient[i];
			check = true;
		}
	}
	if (check == false)
		cout << "None Found." << endl;
}
void Clinic::printdoctorid(int _did)
{
	bool check = false;
	for (int i = 0; i < Docsize; i++)
	{
		if (Doc[i]->getDid() == _did)
		{
			cout << *Doc[i];
			check = true;
		}
	}
	if (check == false)
		cout << "None Found." << endl;
}
void Clinic::savepatient()
{
	ofstream ffout;
	ffout.open("Patient.txt");
	//remove("Patient.txt");
	for (int i = 0; i < Patientsize; i++)
	{
		//cout << Patientsize << endl;
		ffout << sysPatient[i]->getPid() << " ";
		Name temp(sysPatient[i]->getpName());
		ffout << temp.getfName() << " ";
		ffout << temp.getlName() << " ";
		Date temp1(sysPatient[i]->getDOB());
		ffout << temp1.getday() << " ";
		ffout << temp1.getmonth() << " ";
		ffout << temp1.getyear() << " ";
		ffout << sysPatient[i]->getAge() << " ";
		ffout << sysPatient[i]->getNid() << " ";
		if (sysPatient[i]->gethistory() == nullptr)
			ffout << "0";
		else
			ffout << "1";
		if (i != Patientsize - 1)
			ffout << endl;
	}
	ffout.close();
}
void Clinic::savepatienthistory()
{
	ofstream fout;
	fout.open("Patient - History.txt");
	//remove("Patient - History.txt");
	for (int i = 0; i < Patientsize; i++)
	{
		if (sysPatient[i]->getsize() != 0)
		{
			//cout <<"    "<< Patientsize << endl;
			fout << sysPatient[i]->getPid() << " ";
			pRecord **temp(sysPatient[i]->gethistory());
			for (int j = 0; j < sysPatient[i]->getsize(); j++)
			{
				fout << temp[j]->getDiseaseType() << " ";
				Date temp1(temp[j]->getDate());
				fout << temp1.getday() << " ";
				fout << temp1.getmonth() << " ";
				fout << temp1.getyear() << " ";
				mTime temp2(temp[j]->getTime());
				fout << temp2.gethour() << " ";
				fout << temp2.getmin() << " ";
				fout << temp2.getsec() << " ";
				fout << temp[j]->getAssignedDoc() << " ";
				fout << temp[j]->getfeepaid() << " ";
			}
			bool checkk = false;
			for (int k = i + 1; k < Patientsize; k++)
			{
				if (sysPatient[k]->gethistory() != nullptr)
					checkk = true;
			}
			if (checkk)
				fout << endl;
		}
	}
	fout.close();
}
void Clinic::savedoc()
{
	ofstream fout;
	fout.open("Doctor.txt");
	//remove("Doctor.txt");
	for (int i = 0; i < Docsize; i++)
	{
		//cout << Docsize << endl;
		fout << Doc[i]->getDid() << " ";
		Name temp(Doc[i]->getpName());
		fout << temp.getfName() << " ";
		fout << temp.getlName() << " ";
		Date temp1(Doc[i]->getDOB());
		fout << temp1.getday() << " ";
		fout << temp1.getmonth() << " ";
		fout << temp1.getyear() << " ";
		fout << Doc[i]->getAge() << " ";
		fout << Doc[i]->getNid() << " ";
		fout << Doc[i]->getspecialization();
		if (i != Docsize - 1)
			fout << endl;
	}
	fout.close();
}
void Clinic::savepatientvisited()
{
	ofstream fout;
	fout.open("Patients visited.txt");
	//remove("Patients visited.txt");
	for (int i = 0; i < Docsize; i++)
	{
		//cout << Docsize << endl;
		if (Doc[i]->getpatientsvisited() != nullptr)
		{
			fout << Doc[i]->getDid() << " ";
			int * temp = Doc[i]->getpatientsvisited();
			for (int j = 0; j < Doc[i]->getsize(); j++)
			{
				if (j == Doc[i]->getsize() - 1)
					fout << temp[j];
				else
					fout << temp[j] << " ";
			}
			bool checkk = false;
			for (int k = i + 1; k < Docsize; k++)
			{
				if (Doc[k]->getpatientsvisited() != nullptr)
					checkk = true;
			}
			if (checkk)
				fout << endl;
		}
	}
	fout.close();
}
void Clinic::saveappointments()
{
	ofstream fout;
	fout.open("Appointment.txt");
	//remove("Appointment.txt");
	for (int i = 0; i < Appointmentsize; i++)
	{
		if (sysAppointment[i] != nullptr)
		{
			fout << sysAppointment[i]->getDiseaseType() << " ";
			fout << sysAppointment[i]->getPid() << " ";
			fout << sysAppointment[i]->getDid() << " ";
			Date temp(sysAppointment[i]->getappDate());
			fout << temp.getday() << " ";
			fout << temp.getmonth() << " ";
			fout << temp.getyear() << " ";
			mTime temp1(sysAppointment[i]->getappTime());
			fout << temp1.gethour() << " ";
			fout << temp1.getmin() << " ";
			fout << temp1.getsec() << " ";
			fout << sysAppointment[i]->gettoken_Number() << " ";
			fout << sysAppointment[i]->getfee() << " ";
			fout << sysAppointment[i]->getstatus();
			if (i != Appointmentsize - 1)
				fout << endl;
		}
	}
	fout.close();
}
Clinic::~Clinic()
{
	if (Doc != nullptr)
	{
		for (int i = 0; i < Docsize; i++)
		{
			delete Doc[i];
		}
		Doc = nullptr;
	}
	else
	{
		Doc = nullptr;
	}
	if (sysPatient != nullptr)
	{
		for (int i = 0; i < Patientsize; i++)
		{
			delete sysPatient[i];
		}
		sysPatient = nullptr;
	}
	else
	{
		sysPatient = nullptr;
	}
	if (sysAppointment != nullptr)
	{
		for (int i = 0; i < Appointmentsize; i++)
		{
			delete sysAppointment[i];
		}
		sysAppointment = nullptr;
	}
	else
	{
		sysAppointment = nullptr;
	}
}
int main()
{
	int choice = -1;
	Clinic C1;
	C1.getpatientfromfile();
	C1.addpatienthistoryfromfile();
	C1.getdoctorfromfile();
	C1.addpatientvisitedfromfile();
	C1.addappointmentsfromfile();
	cout << "                                                  |CLINIC SYSTEM|" << endl;
	while (choice != 0)
	{
		cout << endl;
		cout << "0. Exit" << endl;
		cout << "1. Add new patient." << endl;
		cout << "2. Add new Doctor." << endl;
		cout << "3. Make an appointment for new patient." << endl;
		cout << "4. Update patient and doctor\'s record once an appointment status is completed, and remove it from appointment list." << endl;
		cout << "5. Make appointment for already existing patient." << endl;
		cout << "6. Print details of all patients, whom a doctor has visited on a particular date." << endl;
		cout << "7. Print details of all patients who visited same doctor but on different days." << endl;
		cout << "8. Print details of all pending appointments of a particular date." << endl;
		cout << "9. Print details of all pending appointments of a particular doctor." << endl;
		cout << "10. Print complete history of a patient, and doctor." << endl << endl;
		cout << "Enter Choice: ";
		cin >> choice;
		if (choice == 1)
		{
			char fname[20];
			char lname[20];
			int pid, day, month, year, age, nid;
			cout << "Enter Patient ID: ";
			cin >> pid;
			cout << "Enter First Name: ";
			cin >> fname;
			cout << "Enter Last Name: ";
			cin >> lname;
			cout << "Enter DOB:" << endl;
			cout << "Enter Day: ";
			cin >> day;
			cout << "Enter Month: ";
			cin >> month;
			cout << "Enter Year: ";
			cin >> year;
			cout << "Enter Age: ";
			cin >> age;
			cout << "Enter National ID: ";
			cin >> nid;
			Patient p(fname, lname, day, month, year, age, nid, pid, nullptr, 0, 0, 0, 0, 0, 0, 0, 0);
			C1.addPatient(p);
			cout << "Patient Added Successfully." << endl;
		}
		else if (choice == 2)
		{
			int did, day, month, year, age, nid;
			char fname[20];
			char lname[20];
			char spec[40];
			cout << "Enter Doctor ID: ";
			cin >> did;
			cout << "Enter First Name: ";
			cin >> fname;
			cout << "Enter Last Name: ";
			cin >> lname;
			cout << "Enter Specialization: ";
			cin >> spec;
			cout << "Enter DOB:" << endl;
			cout << "Enter Day: ";
			cin >> day;
			cout << "Enter Month: ";
			cin >> month;
			cout << "Enter Year: ";
			cin >> year;
			cout << "Enter Age: ";
			cin >> age;
			cout << "Enter National ID: ";
			cin >> nid;
			Doctor d(fname, lname, day, month, year, age, nid, did, spec, -111);
			C1.addDoc(d);
			cout << "Doctor Added Successfully." << endl;
		}
		else if (choice == 3)
		{
			char fname[20];
			char lname[20];
			int pid, day, month, year, age, nid;
			cout << "First Enter details of new Patient for Appointment." << endl;
			cout << "Enter Patient ID: ";
			cin >> pid;
			cout << "Enter First Name: ";
			cin >> fname;
			cout << "Enter Last Name: ";
			cin >> lname;
			cout << "Enter DOB:" << endl;
			cout << "Enter Day: ";
			cin >> day;
			cout << "Enter Month: ";
			cin >> month;
			cout << "Enter Year: ";
			cin >> year;
			cout << "Enter Age: ";
			cin >> age;
			cout << "Enter National ID: ";
			cin >> nid;
			Patient p(fname, lname, day, month, year, age, nid, pid, nullptr, 0, 0, 0, 0, 0, 0, 0, 0);
			C1.addPatient(p);
			cout << "Patient Added Successfully." << endl;
			cout << "Enter Appointment Details:" << endl;
			char disease[40];
			int did, hour, min, sec, token, fee, status;
			cout << "Enter Disease: ";
			cin >> disease;
			cout << "Enter Doctor ID: ";
			cin >> did;
			cout << "Enter Date of Appointment: " << endl;
			cout << "Enter Day: ";
			cin >> day;
			cout << "Enter Month: ";
			cin >> month;
			cout << "Enter Year: ";
			cin >> year;
			cout << "Enter Time: " << endl;
			cout << "Enter Hour: ";
			cin >> hour;
			cout << "Enter Min: ";
			cin >> min;
			cout << "Enter Sec: ";
			cin >> sec;
			cout << "Enter Token No: ";
			cin >> token;
			cout << "Enter Fee: ";
			cin >> fee;
			Appointment A(disease, pid, did, day, month, year, hour, min, sec, token, fee, 0);
			C1.addAppointment(A);
			cout << "Appointment Added Successfully." << endl;
		}
		else if (choice == 4)
		{
			int token;
			cout << "Enter Token No to complete Appointment: ";
			cin >> token;
			C1.updateappointment(token);
		}
		else if (choice == 5)
		{
			char disease[40];
			int did, pid, day, month, year, hour, min, sec, token, fee, status;
			cout << "Enter Disease: ";
			cin >> disease;
			cout << "Enter Patient ID: ";
			cin >> pid;
			cout << "Enter Doctor ID: ";
			cin >> did;
			cout << "Enter Date of Appointment: " << endl;
			cout << "Enter Day: ";
			cin >> day;
			cout << "Enter Month: ";
			cin >> month;
			cout << "Enter Year: ";
			cin >> year;
			cout << "Enter Time: " << endl;
			cout << "Enter Hour: ";
			cin >> hour;
			cout << "Enter Min: ";
			cin >> min;
			cout << "Enter Sec: ";
			cin >> sec;
			cout << "Enter Token No: ";
			cin >> token;
			cout << "Enter Fee: ";
			cin >> fee;
			Appointment A(disease, pid, did, day, month, year, hour, min, sec, token, fee, 0);
			C1.addAppointment(A);
			cout << "Appointment Added Successfully." << endl;
			C1.printAppointment();
		}
		else if (choice == 6)
		{
			int day, month, year, did;
			cout << "Enter Doctor ID: ";
			cin >> did;
			cout << "Enter Date: " << endl;
			cout << "Enter Day: ";
			cin >> day;
			cout << "Enter Month: ";
			cin >> month;
			cout << "Enter Year: ";
			cin >> year;
			C1.printpatientondate(day, month, year, did);
		}
		else if (choice == 7)
		{
			int did;
			cout << "Enter Doctor ID: ";
			cin >> did;
			C1.patientsamedoc(did);
		}
		else if (choice == 8)
		{
			int day, month, year;
			cout << "Enter Date: " << endl;
			cout << "Enter Day: ";
			cin >> day;
			cout << "Enter Month: ";
			cin >> month;
			cout << "Enter Year: ";
			cin >> year;
			C1.appointmentpendingdate(day, month, year);
		}
		else if (choice == 9)
		{
			int did;
			cout << "Enter Doctor ID: ";
			cin >> did;
			C1.appointmentpendingdoc(did);
		}
		else if (choice == 10)
		{
			int pid, did, check;
			cout << "Enter Choice(1 For Patient, 2 For Doctor): ";
			cin >> check;
			if (check == 1)
			{
				cout << "Enter Patient ID: ";
				cin >> pid;
				C1.printpatientid(pid);
			}
			else
			{
				cout << "Enter Doctor ID: ";
				cin >> did;
				C1.printdoctorid(did);
			}

		}
	}
	C1.savepatient();
	C1.savepatienthistory();
	C1.savedoc();
	C1.savepatientvisited();
	C1.saveappointments();
	system("pause");

}