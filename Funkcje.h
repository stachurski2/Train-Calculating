#include "Unit9.h"

//Convert1 - convert a table to smaller table includes element between <pointer> ... </pointer>
TStringList* Convert1(TStringList*,String);
void FillVectors(TStringList*, std::vector<double>&, std::vector<double>&, std::vector<double>&, std::vector<bool>&);
void FillDescription(TStringList*, std::vector<String>&, std::vector<double>&);

class Train;
class Route {
//describe speeds
std::vector<double> *begin;
std::vector<double> *end;
std::vector<int> *speed;
std::vector<bool> *spot;
//description
std::vector<String> *description;
std::vector<double> *points;
public:
//construtcor
Route(TStringList*,bool=0);
//destructor
~Route();
// Section Functions
void AddSection(double, double, int, bool);   // first param - begin of section, second end of section, third speed of section, fourth  - point
void DeleteSection();
AnsiString ShowSection(int);
AnsiString ShowStart(int);
AnsiString ShowEnd(int);
AnsiString ShowSpeed(int);
bool ShowSpot(int);
int FindSection(int);
void OptimizeSections();
void ChangeSection(bool,int,double,double,int,bool);
double ShowLength() const;
int Size();
// Desription Functions
void AddDescribe(double,String);
void DeleteDescribe(int=0);
void DeleteDescribes(int);
AnsiString ShowDescribe(int);
int DescribeLocation(int);
int DescriptionCount();
// Save Function
TStringList* SaveToFile();
// Graph functions
int Vmax(int, int=0,int=0); // first param - localizatiton of train, second - length of train, third - Vmax of train
int NextSpeed(double, int=0,int=0); // Next less speed (needed to brake)
int DistanceToSpeedChange(double, int=0,int=0);  // Distance to next less speed (needed to brake)
int DistanceToVmax(double, int=0,int=0);  // Distance to next other speed;
int NextVmax(double, int=0,int=0);  // Next other speed;
String Show(int); //description show
//Functions to calcuting
std::map<std::pair<int,int>,int> StartPoints(Train*) const;
int TheHighestSpeed();
};


class Vehicle {
protected:
AnsiString name;
int wheels;
double weight;
double length;
std::map<int,double> *characteristic;

public:
//constructor
Vehicle(TStringList *pointer=0);
//destructor
~Vehicle();
//copying construcotr
Vehicle(Vehicle*);
//display
AnsiString ShowName();
AnsiString ShowWheels();
AnsiString ShowWeight();
AnsiString ShowLength();
AnsiString ShowChar(int,std::map<int,double>::iterator);
int CharSize();
// Changing
void ChangeName(AnsiString);
void ChangeWheels(AnsiString);
void ChangeWeight(AnsiString);
void ChangeLength(AnsiString);
void DeleteChar(int);
void AddChar(int,double);
// Graph
double MaxForce();
int Vmax();
int ShowSpeed(int);
double ShowForce(int);
// Save
TStringList* SaveToFile();
//Counting
double CountWeight();
double Force(int); // count Force depended from speed
bool ReadyToGo();// checking wether Vehicle is good to counting
};

class Train:public Vehicle {
protected:
int Locos;
int CarWheels;
int CarLength;
double CarWeight;
int MaxSpeed;
int PercentOfBrakingMass;
public:
Train(Vehicle*,int,int,double,int,int,int);
int TrainLength();
double TrainWeight();
int TrainMaxSpeed();
int LWheels();
int CWheels();
double AccValue(int);  // change speed in km/h in period of second
int AccSpeed(int, int, int); //first param point of train, second start point of accelarating, third start speed;
std::map<std::pair<int,int>,std::pair<int,int> > AccSpeeds(Route*);
friend class Brake;
friend std::map<std::pair<int,int>,std::pair<int,int> >  brakecount(Train*,Route*,Brake*);
};



class Brake {
std::map<int,std::map<int,double> > curves;
public:
Brake(TStringList*);
double BrakeValue(int,double,bool=0);     // change speed in km/h in period of second
int DistanceOfBraking(int,int,int)const; //distance needed to change speed
std::pair<std::pair<int,int>,std::pair<int,int> > BrakeLaunch(int,Route*,Train*) const;
int BrakingSpeed(int,int,int,Train*)const; //first param speed during starting brake, second parameter distance from braking start to currently point of train
};


std::map<std::pair<int,int>,std::pair<int,int> > brakecount(Train*,Route*,Brake*);    //board of distance of braking road for Train on Route


std::map<int,int> staticprofile(Route*,Train*);       //board of maximumspeed for Train with Rute
std::map<int,int> trainride(Train*,Route*,Brake*);   //board of speed for Train on Route with Brake and acceleration

class TimeTable: public Train {
std::map<std::pair<int,int>,double> Times;
std::map<int,AnsiString> Points;
std::map<int,int> Stops;
std::map<int,std::pair<double,double> > Schedule;
int StartTime;
int LeadingPoint;

public:
TimeTable(std::map<int,int>,Route*,Train&);
//functions neccessary to edit TimeTable:

int CountSection() ;
int StartingTime();
double TrainRide(int) ;
double StopTime(int) ;
void ChangeStartTime(int,int=0,bool=0);
int ChangeSection(TimeTable*,int,AnsiString,int,int);
void RoundTimes();
double ReserveTime(int, TimeTable*);
TStringList *FinalReport(TimeTable*);
//Functions to show data in window
AnsiString ConvertTime(int) ;
AnsiString ShowStart(int);
AnsiString ShowEnd(int) ;
AnsiString ShowTime(int) ;
AnsiString ShowStop(int) ;
AnsiString ShowSchedule(int) ;
AnsiString ShowNamePoint(int) ;
AnsiString ShowTime1(int) ;
AnsiString ShowTime2(int);
AnsiString ShowStop1(int);
AnsiString ShowStop2(int);
AnsiString ShowPosition(int);

};


















