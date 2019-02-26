#include <iostream>
#include <fstream>
#include <cstring>
#include<math.h>
#include<dos.h>
#include<ctime>
#include<stdlib.h>
#include<conio.h>
#include<ctime>
#include<ctype.h>
#include<windows.h>
#include<process.h>
#include<conio.h>
#include<cstdio>

using namespace std;

/************************************************* CLASSES PROTOTYPES ****************************************************/
class Aeroplane;
class Baggage;
class Date;
class Time;
class MemberShip;
class Miles;
class Person;
class Passenger;
class BoardingPass;

/********************************************* FUNCTIONS PROTOTYPES ******************************************************/
void gotoxy(int , int );
int t(void);
void mainmenu();
void mainmenu_passenger_employee();
void mainmenu_passenger();
void mainmenu_employee();
void mainmenu_member();
void printLine(char ,int );
void delay(unsigned int);
void printLineSlowly(char ,int ,int);
void printSquareBox(char,int ,int,int,int );
void printTirchaBox(char,int ,int,int,int );
void boxOperation(char l,int height,int width,int x ,int y,void (*functionPtr)(char,int ,int,int,int ));
void printStringSlowly(string , int);
bool Password(string );
void print_thankYou(int , int );
void draw_Logo(int, int, int);
void clear_Area(int, int, int, int);
template<typename T>
void chooseDest(T &);
template<typename T>
void chooseFrom(T & );
void login();
void logout();

/************************************************** GLOBAL VARIABLES *****************************************************/
const char* password = "FCIT";
const char* username1 = "Shaheer";
const char* username2 = "Ashir";
const char* username3 = "Basit";

/**************************************************** DATE CLASS *********************************************************/
class Date {
	
	//MEMBER VARIABLES 
	
	int day,month,year;
	string LetterDay;
	public:
		
		//CONSTRUCTORS 
		Date();
		//MEMBER FUNCTIONS
		void setDay(int);
		void setMonth(int);
		void setYear(int);
		void setLetterDay(string);
		int getDay()const;
		int getMonth()const;
		int getYear()const;
		string getLetterDay()const;
		friend ostream& operator << (ostream & , const Date&);
		//DESTRUCTOR
		~Date();
};
/*********************************************** DATE CLASS FUNCTIONS ****************************************************/
Date::Date():day(0),month(0),year(0),LetterDay("none"){
}
Date::~Date() {
	
}
void Date::setDay(int n){
	if(n<1 ||n>31){
		day=0;	
	}
	else{
		day=n;
	}
}
void Date::setMonth(int n){
	if(n<1 || n>12){
		month=0;	
	}
	else{
		month=n;
	}
}
void Date::setYear(int n){
	if(n<0){
		year=0;	
	}
	else{
		year=n;
	}
}
void Date::setLetterDay(string n){
	LetterDay=n;
}
int Date::getDay()const{
	return day;
}
int Date::getMonth()const{
	return month;
}
int Date::getYear()const{
	return year;
}
string Date::getLetterDay()const{
	return LetterDay;
}
ostream& operator<< (ostream& os , const Date& l){
	os<<l.day<<"-"<<l.month<<"-"<<l.year;
	return os;
}
/***************************************************** TIME CLASS ********************************************************/
class Time{
	
	//MEMBER VARIABLES 
	
	int second,minute,hour;
	public:
		
		//CONSTRUCTORS 
		Time();
		
		//MEMBER FUNCTIONS
		void setSecond(int );
		void setMinute(int );
		void setHour(int );
		int getSecond()const;
		int getMinute()const;
		int getHour()const;
		
		//DESTRUCTOR
		~Time();
};
/************************************************** TIME CLASS FUNCTIONS *************************************************/
Time::Time():minute(0),hour(0),second(0) {
}
Time::~Time() {
	

}
void Time::setHour(int hour){
	if (hour >=1 && hour <=24){
		this->hour = hour;
	}
}
void Time::setMinute(int minute){
	if (minute >=1 && minute <=60){
		this->minute = minute;
	}
}
void Time::setSecond(int second){
	if (second >=1 && second <=60){
		this->second = second;
	}
}
int Time::getHour()const{
	return hour;
}
int Time::getMinute()const{
	return minute;
}
int Time::getSecond()const{
	return second;
}

/******************************************************* PERSON CLASS ****************************************************/
//ABSTRACT CLASS( The object of this class can not be created)
class Person{
	
	//MEMBER VARIABLES
	
	string name,address,province,phone,city,country,nationality;
	int age;
	double height;
	protected:
		Date d_o_b;
	public:
		
		//CONSTRUCTORS
		Person();
		
		//MEMBER FUNCTIONS
		virtual void functionToMakeItAbstract()=0;
		void setName(string );
		void setNationality(string );
		void setAddress(string );
		void setPhone(string );
		void setCity(string );
		void setCountry(string );
		void setProvince(string );
		void setAge(int );
		void setHeight(double );
		string getNationality( )const;
		string getName()const;
		string getAddress()const;
		string getPhone()const;
		string getCity()const;
		string getProvince()const;
		string getCountry()const;
		int getAge()const;
		double getHeight()const;
		
		//DESTRUCTOR
		~Person();
};
/*********************************************** PERSON CLASS FUNCTIONS **************************************************/
Person::Person() {
	name = "none";
	age = 0;
	height = 0.0;
	address = "none";
	phone = "+00-000-000-0000";
	city = "none";
	country = "none";
	province = "none";
}
Person::~Person() {
	
}
void Person::setName(string name){
	this->name = name;
}
void Person::setAge(int age){
	this->age = age;
}
void Person::setHeight(double height){
	this->height = height;
}
void Person::setAddress(string address){
	this->address = address;
}
void Person::setPhone(string phone){
	this->phone = phone;
}
void Person::setCity(string city){
	this->city = city;
}
void Person::setCountry(string country){
	this->country = country;
}
void Person::setProvince(string province){
	this->province = province;
}
string Person::getName()const{
	return name;
}
void Person::setNationality(string nationality){
	this->nationality = nationality;
}
string Person::getNationality()const{
	return nationality;
}
int Person::getAge()const{
	return age;
}
double Person::getHeight()const{
	return height;
}
string Person::getAddress()const{
	return address;
}
string Person::getPhone()const{
	return phone ;
}
string Person::getCity()const{
	return city;
}
string Person::getCountry()const{
	return country ;
}
string Person::getProvince()const{
	return province;
}

/**************************************************** BAGGAGE CLASS ******************************************************/
class Baggage{
	
	//MEMBER VARIABLES
	
	const double weight_limit_per_bag;
	const int  bag_limit;
	int no_of_bags,no_of_handcarry;
	double total_weight;
	bool tag;
	public:
		//CONSTRUCTORS
		Baggage();
		
		//MEMBER FUNCTIONS
		void setNoOfBags(int );
		void setNoOfHandCarry(int );
		int checkTag();
		int checkWeight();
		int checkNoOfBags();
		void baggageTracking();
		void setTotalWeight(double);
		double getTotalWeight()const;
		int getNoOfBags()const;
		int getNoOfHandCarry()const;
		
		//DESTRUCTOR
		~Baggage();	
};
/********************************************** BAGGAGE CLASS FUNCTIONS **************************************************/
Baggage::Baggage():bag_limit(3),weight_limit_per_bag(23),no_of_bags(0),no_of_handcarry(0),total_weight(0),tag(false){
	
}
Baggage::~Baggage() {
	
}
void Baggage::setNoOfBags(int n){
	no_of_bags=n;
}
void Baggage::setNoOfHandCarry(int n){
	no_of_handcarry=n;
}
void Baggage::setTotalWeight(double n){
	total_weight=n;
}
double Baggage::getTotalWeight()const{
	return total_weight;
}
int Baggage::getNoOfBags()const{
	return no_of_bags;
}
int Baggage::getNoOfHandCarry()const{
	return no_of_handcarry;
}

/***************************************************** MILE CLASS ********************************************************/
class Miles{
	
		//MEMBER VARIABLES
		
		long no_of_miles;
		double mile_price;
	public:
		
		//CONSTRUCTORS
		Miles();
		//MEMBER FUNCTIONS
		void setMiles(long );
		long getMiles()const;
		void increaseMiles(int);
		
		//DESTRUCTOR
		~Miles();
};
/************************************************** MILE CLASS FUNCTIONS *************************************************/
Miles::Miles(){
	no_of_miles = 0;
	mile_price = 0.45;
}
Miles::~Miles() {
	
}
void Miles::setMiles(long no_of_miles) {
	this->no_of_miles = no_of_miles;
}
long Miles::getMiles()const {
	return no_of_miles;
}
void Miles::increaseMiles(int n) {
	no_of_miles += n;
}

/*************************************************** BOARDINGPASS CLASS **************************************************/
class BoardingPass {
	
	//MEMBER VARIABLES
	
	string flight_no;
	Time boarding_time,departure_time,arrival_time;
	Date Boarding_date;
	int gate_no;
	public:
		//CONSTRUCTORS
		BoardingPass();
		
		//MEMBER FUNCTIONS
		void setflightNo(string );
		void setGateNo(int);
		string getflightNo()const;
		int getGateNo()const;
		void generateBoardingPass();
		
		//DESTRUCTOR
		~BoardingPass();
};
/******************************************* BOARDINGPASS CLASS FUNCTIONS ************************************************/
BoardingPass::BoardingPass() {
	
}
void BoardingPass::setflightNo(string s){
	flight_no=s;
}
string BoardingPass::getflightNo()const{
	return flight_no;
}
void BoardingPass::setGateNo(int s){
	gate_no=s;
}
int BoardingPass::getGateNo()const{
	return gate_no;
}
BoardingPass::~BoardingPass() {
	
}

/*********************************************** AEROPLANE CLASS *********************************************************/
class Aeroplane{
	
	//MEMBER VARIABLES
	
	string size,flight_no;
	int no_of_decks,no_of_seats;
	public:
		
		//CONSTRUCTORS
		Aeroplane();
		
		//MEMBER FUNCTIONS
		
		void setSize(string);
		void setFlightNo(string);
		void setNoOfDecks(int);
		void setNoOfSeats(int);
		string getSize()const;
		string getFlightNo()const;
		int getNoOfDecks()const;
		int getNoOfSeats()const;
		
		//DESTRUCTOR
		~Aeroplane();
};
/********************************************* AEROPLANE CLASS FUNCTIONS *************************************************/
Aeroplane::Aeroplane() :size("none"),flight_no("none"),no_of_decks(0),no_of_seats(0){
}
void Aeroplane::setSize(string n){
	size=n;
}
void Aeroplane::setFlightNo(string n){
	flight_no=n;
}
void Aeroplane::setNoOfDecks(int n){
	no_of_decks=n;
}
void Aeroplane::setNoOfSeats(int n){
	no_of_seats=n;
}
string Aeroplane::getSize()const{
	return size;
}
string Aeroplane::getFlightNo()const{
	return flight_no;
}
int Aeroplane::getNoOfDecks()const{
	return no_of_decks;
}
int Aeroplane::getNoOfSeats()const{
	return no_of_seats;
}
Aeroplane::~Aeroplane() {
	
}

/**************************************************** PASSENGER CLASS ****************************************************/
class Passenger: public Person{
	
	//MEMBER VARIABLES
	string to,from,seat_type,class_type,flight_type;	// only a passenger can be a member.
	int seat_no;
	double total_cost;
	BoardingPass bp;									// Composition with Boarding pass &
	Baggage ba;											// Baggage since only a passneger can have both.
	int seats_booked[100];
	
	public:
		//CONSTRUCTORS
		Passenger();
		
		//MEMBER FUNCTION
		void functionToMakeItAbstract();
		void setTo(string );
		void setFrom(string );
		void setSeatType(string );
		void setClassType(string );
		void setFlightType(string );
		void setSeatNo(int );
		void increaseMiles (int);
		string getTo()const;
		string getFrom()const;
		string getSeatType()const;
		string getClassType()const;
		string getFlightType()const;
		int getSeatNo()const;
		void getMiles()const;
		void bookFlight();
		void cancelFlight();
		void bookingEnquiry();
		void calculateCost();
		bool reEnter(string &, string&, int&);
		double getTotalCost()const;
		void setSeat (int);
		int getSeat (int);
		
		//DESTRUCTOR
		~Passenger();
};
/******************************************* PASSENGER CLASS FUNCTIONS ***************************************************/
Passenger::Passenger():to("none"), from("none"), seat_type("none"), class_type("none"), flight_type("none"),seat_no(0),total_cost(0.0) {
	for(int i=0;i<100;i++){
		seats_booked[i]=0;
	}
}
Passenger::~Passenger() {
	
}
void Passenger::setSeat(int n) {
	seats_booked[n] = 1;
}
int Passenger::getSeat(int n) {
	return seats_booked[n];
}
bool Passenger::reEnter (string &ct, string &st, int &sn) {
	bool yes, mark;
	int choice;
	clear_Area(45,13,115,11);
	gotoxy(45,15); cout<<"1. First Class \t2. Business\t 3. Economy\t 4.other";
	gotoxy(45,16); cout<<"*Class Type: "; cin >> choice;
	fflush(stdin);
	if (choice == 1) setClassType("First Class");
	else if (choice == 2) setClassType("Business Class");
	else if (choice==3) setClassType("Economy Class");
	else if (choice == 4) {
		gotoxy(45,17); cout << "Enter your preference:\t";
		getline(cin, ct);
		setClassType(ct);
	}
	else {
		gotoxy(45,18); cout << "Invalid Entery. Please re-enter";
		Sleep(2000);
		return false;
	}
	gotoxy(45,19); cout << "1. Window\t 2. Aisle\t 3. Other";
	gotoxy(45,20); cout<<"*Seat Type: "; cin >> choice;
	fflush (stdin);
	if (choice == 1) {
		st = "Window Seat";
		setSeatType(st);
	}
	else if (choice == 2) {
		st = "Aisle Seat";
		setSeatType(st);
	}
	else if (choice == 3) {
		gotoxy(45,21); cout << "Enter your preference :\t";
		getline(cin, st);
		setSeatType(st);
	}
	else {
		gotoxy(45,22); cout << "Invalid Entery. Please re-enter";
		Sleep(2000);
		return false;
	}
	do {
		clear_Area(45,13,115,11);
		gotoxy(45,16); cout<<"*Seat Number: "; cin>>sn;
		fflush (stdin);
		if (sn > 99 || sn < 0) {
			gotoxy (45,24); cout << "Sorry, our flights only have seat limits from 0-99";
			gotoxy (45,25); cout << " Please re-enter";
			yes = false;
			mark = false;
		}
		else {
			mark = true;
			yes = true;
		}
		if (mark) {
			if (getSeat(sn)) {
				gotoxy (45,26); cout << "Seat already taken, please choose another.";
				Sleep(2000);
				yes = false;
			}
			else {
				//setSeat(sn);
				yes = true;
			}
		}
		
	} while (yes != true);
	setSeatNo(sn);
	fflush(stdin);
	return true;
}

void Passenger::bookFlight(){
	string n, ad, ci, pro, co, ph, st, ct,na,ema,day2;
	int a, b,d,c,sn,u;
	bool check;
	int day, day1;
	bool agreed;
	long amount;
	char ans;
	gotoxy(45,15); cout<<"*Name: ";
	gotoxy(105,15); cout<<"*Age: ";
	gotoxy(45,16); cout<<"*Address: ";
	gotoxy(45,17); cout<<"*City: ";
	gotoxy(105,17); cout<<"*Province: ";
	gotoxy(45,18); cout<<"*Country: ";
	gotoxy(105,18); cout<<"*Phone: ";
	gotoxy(45,19); cout<<"*Nationality: ";
	gotoxy(45,20); cout<<"Date of Birth(day/month/year): ";
	gotoxy(80,20); cout<< "-";
	gotoxy(84,20); cout<< "-";
	gotoxy(52,15);getline(cin, n);
	this->setName(n);
	gotoxy(111,15);cin>>a;
	ofstream fout( ("Passenger Boarding Passes\\"+n+".txt").c_str() );
	fflush(stdin);
	this->setAge(a);
	gotoxy(55,16);getline(cin, ad);
	this->setAddress(ad);
	gotoxy(52,17);getline(cin, ci);
	this->setCity(ci);
	gotoxy(116,17);getline(cin, pro);
	this->setProvince(pro);
	gotoxy(55,18);getline(cin, co);
	this->setCountry(co);
	gotoxy(113,18);getline(cin, ph);
	this->setPhone(ph);
	gotoxy(59,19);getline(cin, na);
	this->setNationality(na);
	gotoxy(78,20);cin>>b;
	gotoxy(82,20);cin>>c;
	gotoxy(85,20);cin>>d;
	d_o_b.setDay(b);
	d_o_b.setMonth(c);
	d_o_b.setYear(d);
	do {
	clear_Area(45,13,115,9);
	chooseFrom(*this);
	clear_Area(45,13,115,9);
	chooseDest(*this);
	while(getTo()==getFrom()){
		gotoxy(45,22); cout<<"Invalid Destination or Departure.";getch();
		clear_Area(45,13,115,10);
		chooseFrom(*this);
		clear_Area(45,13,115,10);
		chooseDest(*this);
	}
		clear_Area(45,13,115,11);
	do {
		check = reEnter (ct, st, sn);
	}while (!check);
	srand (time(NULL));
	amount = (rand() % 15) + 1;
	clear_Area(45,13,115,11);
	gotoxy (45,15); cout << "Ticket price calculated :\t" << amount << "$";
	gotoxy (45,16); cout << "Are you comfortable with the price ?";
	gotoxy (45,17); cout << "If not, then you are requested to alter your destination (yes=y/no=n) :\t"; ans=getch();
	if (ans =='y' || ans == 'Y') {
		agreed = true;
		setSeat(getSeatNo());
	}
	else agreed = false;
	} while (!agreed);
	time_t t;
	time(&t);
	struct tm waqt;
	waqt = *localtime(&t);
	day = waqt.tm_mday + 3;
	if (day > 31) day = 1;
	day1 = waqt.tm_wday+3;
	if (day1 > 7) day1 = 1;
	switch (day1) {
		case 1:
			day2 = "Monday";
			break;
		case 2:
			day2 = "Tuesday";
			break;
		case 3:
			day2 = "Wednesday";
			break;
		case 4:
			day2 = "Thursday";
			break;
		case 5:
			day2 = "Friday";
			break;
		case 6:
			day2 = "Saturday";
			break;
		case 7:
			day2 = "Sunday";
			break;
		default:
			cout << endl;
	} 
	//cout<<ctime(&t);
	u = (rand() % 50000) + 20000;
	fout<<"Boarding Pass\n\n"<<"Wonder Air Airline\n"<<"Name: "<<getName()<<"\nDestination: "<<getFrom()<<" To "<<getTo()<<"\nAirCraft Details: \n"<<"Class: "<<getClassType()<<"\nSeat: "<<getSeatType()<<" (Seat No. "<<getSeatNo()<<") \nGate No : G"<<u<<"\nBoarding Time: "<<waqt.tm_hour<<":"<<waqt.tm_min<<"PM"<<"("<<day2<<")"<<day<<"of August"<<"\n\n\t\tXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
	clear_Area(45,13,115,11);
	gotoxy (45,15); cout << "Your Boarding Pass is being generated.";
	gotoxy (45,16); cout << "Print your pass and you will be taken back to main screen.";
	gotoxy (45,17); cout << "THANK YOU FOR FLYING WONDER AIR ! see you on the other side.";
	Sleep (7000);
	HWND hwnd = ::CreateWindowA("STATIC","dummy",WS_VISIBLE,0,0,50,50,NULL,NULL,NULL,NULL);
	::SetWindowTextA(hwnd,"Ignore This Window!");
	ShellExecute (hwnd,"open",("Passenger Boarding Passes\\"+n+".txt").c_str(),NULL,NULL,SW_SHOW);
	//system((n+".txt").c_str());		//opening 
	Sleep(5000);
	fout.close();
	clear_Area(0,13,30,11);
	mainmenu_passenger_employee();
}

void Passenger::functionToMakeItAbstract(){
}
void Passenger::setTo(string to) {
	this->to = to;
}
void Passenger::setFrom(string from){
	this->from = from;
}
void Passenger::setSeatType(string seat_type){
	this->seat_type = seat_type;
}
void Passenger::setFlightType(string flight_type){
	this->flight_type = flight_type;
}
void Passenger::setClassType(string class_type){
	this->class_type = class_type;
}
void Passenger::setSeatNo(int seat_no){
	this->seat_no = seat_no;
}
string Passenger::getTo() const {
	return to;
}
string Passenger::getFrom()const{
	return from;
}
string Passenger::getSeatType()const{
	return seat_type;
}
string Passenger::getFlightType()const{
	return flight_type;
}
string Passenger::getClassType()const{
	return class_type;
}
int Passenger::getSeatNo()const{
	return seat_no;
}
double Passenger::getTotalCost()const{
	return total_cost;
}

/*************************************************** MEMBERSHIP CLASS ****************************************************/
class Membership : public Person {
	string to,from,seat_type,class_type,flight_type;	// only a passenger can be a member.
	int seat_no;
	const string card_name;
	string username,email;
	Date validation_date,member_since;
	Miles m;
	int seats_booked[100];
	
	double dist_travel;
	public:
		
		//CONSTRUCTORS
		Membership():card_name("Wonder Air") {
		}
		//MEMBER FUNCTIONS
		void setUsername (string);
		void setPassword(char *);
		void setEmail(string);
		void setDist(double);
		bool checkPassword(char *);
		double getDist() const;
		void getPassword(char *)const;
		string getUsername () const;
		string getEmail () const;
		void registerYourself();
		void checkMember();
		void giveDiscount();
		void giveMoreMiles();
		void book(string);
		void setTo(string );
		void setFrom(string );
		void setSeatType(string );
		void setClassType(string );
		void setFlightType(string );
		void setSeatNo(int );
		string getTo()const;
		string getFrom()const;
		string getSeatType()const;
		string getClassType()const;
		string getFlightType()const;
		int getSeatNo()const;
		void flightInquiry();
		void functionToMakeItAbstract();
		
		void setSeat (int);
		int getSeat (int);
		
		
		//DESTRUCTOR
		~Membership();
};
/********************************************** MEMBERSHIP CLASS FUNCTIONS ***********************************************/
Membership::~Membership() {
	
}
void Membership::functionToMakeItAbstract(){
}
void Membership::setSeat(int n) {
	seats_booked[n] = 1;
}
int Membership::getSeat(int n) {
	return seats_booked[n];
}
void Membership::setUsername(string s) {
	username=s;
}
string Membership::getUsername()const {
	return username;
}
void Membership::setEmail(string s) {
	email=s;
}
string Membership::getEmail()const {
	return email;
}
void Membership::setDist(double s) {
	dist_travel=s;
}
double Membership::getDist()const {
	return dist_travel;
}
bool Membership::checkPassword(char *password){
	char p[5];
	int i=0,l=strlen(password);
	while(i<l)
	{
	p[i]=getch();
	cout<<"*";
	++i;
	}
	return (p==password);
}
void Membership::registerYourself(){
	string n, ad, ci, pro, co, ph, st, ct, ft,na,ema;
	int a, sn,b,c,d;
	gotoxy(45,15); cout<<"*Name: ";
	gotoxy(105,15); cout<<"*Age: ";
	gotoxy(45,16); cout<<"*Address: ";
	gotoxy(45,17); cout<<"*City: ";
	gotoxy(105,17); cout<<"*Province: ";
	gotoxy(45,18); cout<<"*Country: ";
	gotoxy(105,18); cout<<"*Phone: ";
	gotoxy(45,19); cout<<"*Nationality: ";
	gotoxy(105,19); cout<<"*Email: ";
	gotoxy(45,20); cout<<"Date of Birth(day/month/year): ";
	gotoxy(80,20); cout<< "-";
	gotoxy(84,20); cout<< "-";
	gotoxy(52,15);getline(cin, n);
	this->setName(n);
	gotoxy(111,15);cin>>a;
	fflush(stdin);
	this->setAge(a);
	gotoxy(55,16);getline(cin, ad);
	this->setAddress(ad);
	gotoxy(52,17);getline(cin, ci);
	this->setCity(ci);
	gotoxy(116,17);getline(cin, pro);
	this->setProvince(pro);
	gotoxy(55,18);getline(cin, co);
	this->setCountry(co);
	gotoxy(113,18);getline(cin, ph);
	this->setPhone(ph);
	gotoxy(59,19);getline(cin, na);
	this->setNationality(na);
	gotoxy(113,19);getline(cin, ema);
	this->setEmail(ema);
	gotoxy(78,20);cin>>b;
	gotoxy(82,20);cin>>c;
	gotoxy(85,20);cin>>d;
	d_o_b.setDay(b);
	d_o_b.setMonth(c);
	d_o_b.setYear(d);
	clear_Area(45,13,115,9);
	
	string s,si;
	string c1,c2;
	
	bool tag;
	ofstream fout;
	ifstream fin;
	do {
		again:
		gotoxy(45,14);cout<<"Enter a Unique Username: ";
		fflush(stdin);
		getline(cin,s);
		for(int i=0;i<s.length();i++){
			if(s[i]==32){
			gotoxy(45,15);
			cout<<"Username Cannot contain a Space! Please try again without using space.";getch();
			clear_Area(45,14,115,2);
			goto again;
		}
	}
	fin.open("Usernames and Passwords\\Usernames.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	while(!fin.eof()){
		fin>>si;
		if(si==s){
			tag=false;
			break;
		}
		tag=true;
	}
	fin.close();
		if(tag==false){
			gotoxy(45,15); cout<<"Username is already Used. Please try a Different one.";
			getch();
			clear_Area(45,14,115,2);
		}
	} while (tag==false);
	
		fout.open("Usernames and Passwords\\Usernames.txt", std::fstream::in | std::fstream::out | std::fstream::app);
		fout<<s<<"\n";
	fout.close();
	do{
		gotoxy(45,15);cout<<"Enter your new Password: ";
		cin>>c1;
		if(c1.length()>15 || c1.length()<4){
			gotoxy(45,16);cout<<"Password's length should be in between 4 to 15 characters. ";getch();
			clear_Area(45,15,115,2);
		}	
	}
	while(c1.length()>15 || c1.length()<4);
	do{
		gotoxy(45,16);cout<<"Enter your Password again: ";
		cin>>c2;
		if(c1!=c2){
			gotoxy(45,17); cout<<"You Put wrong Password"; getch();
			clear_Area(45,16,115,2);
		}	
	}
	while(c1!=c2);
	
	fout.open("Usernames and Passwords\\Passwords.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout<<c1<<"\n";
	fout.close();
	fout.open("All Details\\all details.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fout<<s<<"\n";
	fout<<"\n"<<getName()<<"\'Details\n\n\nAge: "<<getAge()<<"\nAddress: "<<getAddress()<<"\nCity: "<<getCity()<<"\nProvince: "<<getProvince()
	<<"\nCountry: "<<getCountry() <<"\nNationality : "<<getNationality()<<"\nEmail : "<<getEmail()<< "\nContact: "<<getPhone()<<"\n\n***\n\n";	
	ofstream fm( ("Members Details\\"+getName()+".txt").c_str() );
	fm<<"\n"<<getName()<<"\'Details\n\n\nAge: "<<getAge()<<"\nAddress: "<<"\nDate of Birth : "<<d_o_b<<getAddress()<<"\nCity: "<<getCity()<<"\nProvince: "<<getProvince()
	<<"\nCountry: "<<getCountry() <<"\nNationality : "<<getNationality()<<"\nEmail : "<<getEmail()<< "\nContact: "<<getPhone()<<"\n\n***\n\n";	
	fout.close();
	fm.close();
	clear_Area(45,13,115,9);
	clear_Area(45,13,115,10);
	ofstream f1( ("Members Card\\"+s+".txt").c_str() );
	f1<<"MemberShip Card \n-------------------------"<<"\n\n|WONDER AIR|"<<"\n\nWONDER AIRLINES" <<"\nMEMBER"<< "\t\tUsername : "<<s<<"\nDate of Birth : "<<d_o_b<<"\tNationality : "<<na<<"\n\n---------------------------------------";
	clear_Area(45,13,115,11);
	gotoxy (45,15); cout << "Your Membership Card has being generated.";
	gotoxy (45,16); cout << "Print your Card if you want.";
	gotoxy (45,17); cout << "THANK YOU FOR CHOOSING WONDER AIR ! Press any key to use your account for first time.";getch();
	//HWND hwnd = ::CreateWindowA("STATIC","dummy",WS_VISIBLE,0,0,50,50,NULL,NULL,NULL,NULL);
	//::SetWindowTextA(hwnd,"Ignore This Window!");
	//ShellExecute (hwnd,"open",("Members Card\\"+s+".txt").c_str(),NULL,NULL,SW_SHOW);
	//system((n+".txt").c_str());		//opening 
	login();
	//Sleep(5000);
	f1.close();
	clear_Area(45,13,115,11);
	this->book(s);	
}
void Membership::book(string s){
	int choice,y;
	long amount;
	char ans,hu;
	ofstream fout( ("Member Boarding Passes\\"+s+".txt").c_str() );
	string ct,st;
	int sn;
	bool mark,yes,agreed;
	clear_Area(45,13,115,9);
	gotoxy(45,15);cout<<"1.Reserve a flight.";
	gotoxy(45,16);cout<<"2.Details";
	gotoxy(45,17);cout<<"3.Logout";
	gotoxy(47,19);cout<<"*Enter your Choice:  ";
	cin>>choice;
	HWND hwnd = ::CreateWindowA("STATIC","dummy",WS_VISIBLE,0,0,50,50,NULL,NULL,NULL,NULL);
			::SetWindowTextA(hwnd,"Ignore This Window!");
	switch(choice){
		case 1:
			pi:
			clear_Area(45,13,115,9);
	chooseFrom(*this);
	clear_Area(45,13,115,9);
	chooseDest(*this);
			while(getTo()==getFrom()){
		gotoxy(45,22); cout<<"Invalid Destination or Departure.";getch();
		clear_Area(45,13,115,10);
		chooseDest(*this);
		clear_Area(45,13,115,10);
		chooseFrom(*this);
	}
	clear_Area(45,13,115,11);
	gotoxy(45,16); cout<<"*Class Type (First Class,Business,Economy or Other): ";
	gotoxy(45,17); cout<<"*Seat Type (Window,Aisle or Other): ";
	gotoxy(45,18); cout<<"*Preffered Seat Number : ";
	fflush(stdin);
	gotoxy(45+53,16); getline(cin, ct);
	this->setClassType(ct);
	fflush(stdin);
	gotoxy(45+36,17); getline(cin, st);
	this->setSeatType(st);
	fflush(stdin);
	gotoxy(45+25,18); cin>>sn;
	this->setSeatNo(sn);
	fflush(stdin);
	clear_Area(45,13,115,10);
	srand (time(NULL));
	amount = (rand() % 50000) + 20000;
	clear_Area(45,13,115,10);
	gotoxy (45,15); cout << "Ticket price calculated :\t" << amount << "Rs";
	gotoxy (45,16);
	cout<<"Are you okay with the price ? ";
	gotoxy (45,17);
	cout<<"if you are comfortable press (y) Else press (n) ";
	hu=getch();
	if(hu=='n' || hu=='N'){
		goto pi;
	}
	clear_Area(45,13,115,10);
	y=(rand() % 15) + 1;
	fout<<"Boarding Pass\n\n"<<"Wonder Air Airline\n"<<"Name: "<<getName()<<"\nDestination: "<<getFrom()<<" To "<<getTo()<<"\nAirCraft Details: \n"<<"Class: "<<getClassType()<<"\nSeat: "<<getSeatType()<<" (Seat No. "<<getSeatNo()<<") "<<"\nGate no : G"<<y<<"\n\n\t\tXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
	clear_Area(45,13,115,11);
	gotoxy (45,15); cout << "Your Boarding Pass is being generated.";
	gotoxy (45,16); cout << "Print your pass and you will be taken back to main screen.";
	gotoxy (45,17); cout << "THANK YOU FOR FLYING WONDER AIR ! see you on the other side.";
	Sleep (7000);
	ShellExecute (hwnd,"open",("Member Boarding Passes\\"+s+".txt").c_str(),NULL,NULL,SW_SHOW);
	//system((n+".txt").c_str());		//opening 
	Sleep(5000);
	fout.close();
	clear_Area(0,13,30,11);
	mainmenu_member();
		break;
		case 2:
			this->flightInquiry();
			getch();
			mainmenu_member();			
		break;
		case 3:
			logout();
			mainmenu_member();
		break;
		default:
			book(s);
	}
	
}
void Membership::flightInquiry(){
	string s,si,su,pass,c3,c4;
	char ch,c;
	int i=13,tag=0,tag1=0;
	ifstream fin1,fin2;
	fin1.open("Usernames and Passwords\\Usernames.txt");
	fin2.open("Usernames and Passwords\\Passwords.txt");
	clear_Area(45,13,115,14);
	gotoxy(45,14);
	cout<<"Enter your username : ";
	cin>>s;
	gotoxy(45,15);
	cout<<"Enter you Password to verify that its you : ";
	cin>>pass;
		while(!fin1.eof() || !fin2.eof()){
			getline(fin1,c3);
			getline(fin2,c4);
			if(s==c3 && pass==c4){
				tag1=1;
				clear_Area(45,13,115,14);
				ifstream fin;
				fin.open("All Details\\all details.txt");
				while(!fin.eof()){
					do{
					fin>>si;
					if(si==s){
						tag=1;
						getline(fin,su);
							while(su!="***"){
							gotoxy(45,i++);
							cout<<su<<"\n";
							getline(fin,su);
							}
						}	
					} 
					while(si!=s);
				}
				fin.close();
			}
		}
	fin1.close();
	fin2.close();
	if(tag1==0){
			this->flightInquiry();
		}
		gotoxy(45,14);
		cout<<"Press any key to exit or Backspace to go back :  ";
		c=getch();
		if(c==8){
			this->flightInquiry();
		}
		else{
			exit(0);
		}
}
void Membership::checkMember(){
	ifstream fin1,fin2;
	string c1,c2,c3,c4;
	int tag=0;
	fin1.open("Usernames and Passwords\\Usernames.txt");
	fin2.open("Usernames and Passwords\\Passwords.txt");
	clear_Area(45,13,115,11);
	gotoxy(45,14);
	cout<<"SIGN IN ";
	gotoxy(45,16);
	cout<<"Enter Username: ";
	gotoxy(45,17);
	cout<<"Enter Password: ";
	gotoxy(64,16);
	getline(cin,c1);
	gotoxy(64,17);
	getline(cin,c2);
	login();
	while(!fin1.eof() || !fin2.eof()){
		getline(fin1,c3);
		getline(fin2,c4);
		if(c1==c3 && c4==c2){
			tag=1;
			this->book(c1);
		}
	}
	fin1.close();
	fin2.close();
	if(tag==0){
		gotoxy(45,18);
		cout<<"Invalid Username OR Password , Press any key to try again.";
		getch();
		clear_Area(45,13,115,11);	
		this->checkMember();
	}
}
void Membership::setTo(string to) {
	this->to = to;
}
void Membership::setFrom(string from){
	this->from = from;
}
void Membership::setSeatType(string seat_type){
	this->seat_type = seat_type;
}
void Membership::setFlightType(string flight_type){
	this->flight_type = flight_type;
}
void Membership::setClassType(string class_type){
	this->class_type = class_type;
}
void Membership::setSeatNo(int seat_no){
	this->seat_no = seat_no;
}
string Membership::getTo() const {
	return to;
}
string Membership::getFrom()const{
	return from;
}
string Membership::getSeatType()const{
	return seat_type;
}
string Membership::getFlightType()const{
	return flight_type;
}
string Membership::getClassType()const{
	return class_type;
}
int Membership::getSeatNo()const{
	return seat_no;
}

/*************************************************** NORMAL FUNCTIONS ****************************************************/
void gotoxy(int x, int y){ 
	COORD coord; 
 	coord.X = x;
 	coord.Y = y;
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int t(void){
	time_t t;
	time(&t);
	cout<<ctime(&t);
	return 0 ;
}

void printLine(char l,int k){
	for(int i=0;i<k;i++){
		cout<<l;
	}
}

void printLineSlowly(char l,int k,int t){
	for(int i=0;i<k;i++){
		delay(t);
		cout<<l;
	}
}

void delay (unsigned int mseconds){
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

//POINTER TO FUNCTION
void boxOperation(char l,int height,int width,int x ,int y,void (*functionPtr)(char,int ,int,int,int )){
	(*functionPtr)(l,height,width,x,y);
}

void printSquareBox(char l,int height,int width,int x ,int y){
	if(width>=200 ){
		width=180;
	}
	if(y>=140 ){
		y=100;
	}
	if(height>=80){
		height=70;
	}
	if(x>=60){
		x=50;
	}
	gotoxy(x,y++);
	for(int i=1;i<=height;i++){
		for(int j=1;j<=width;j++){
			if(i==height || i==1 || i==height-1 || i==2 || i==height-2 || i==3 || i==height-3 || i==4 ){
				cout<<l;
			}
			else
			{
				if( j==1 || j==width || j==2 || j==width-1 || j==3 || j==width-2 || j==4 || j==width-3 || j==5 || j==width-4){
					cout<<l;
				}
				else{
					cout<<" ";
				}
			}
		}
		cout<<endl;
		gotoxy(x,y++);
	}	
}

void printTirchaBox(char l,int height,int width,int x ,int y){
	if(width>=200 ){
		width=180;
	}
	if(y>=140 ){
		y=100;
	}
	if(height>=80){
		height=70;
	}
	if(x>=60){
		x=50;
	}
	gotoxy(x++,y++);
	for(int i=1;i<=height;i++){
		for(int j=1;j<=width;j++){
			if(i==height || i==1 || i==height-1 || i==2 || i==height-2 || i==3 || i==height-3 || i==4 || i==height-4 || i==5 ){
				cout<<l;
			}
			else
			{
				if( j==1 || j==width || j==2 || j==width-1 || j==3 || j==width-2 || j==4 || j==width-3 || j==5 || j==width-4){
					cout<<l;
				}
				else{
					cout<<" ";
				}
			}
		}
		cout<<endl;
		gotoxy(x++,y++);
	}	
}


void printStringSlowly(string s, int t){
	int len = s.length();
	for(int i=0;i<len;i++){
		delay(t);
		cout<<s[i];
	}
}

void draw_Logo(int x, int y, int t){
	int i;
	for (i = 1; i <= 5; i++){
		switch(i){
			case 1:
				gotoxy(x, y); printStringSlowly("    ***", t-1);
				break;
			case 2:
				gotoxy(x, y+1); printStringSlowly("   **", t-1);
				break;
			case 3:
				gotoxy(x, y+2); printStringSlowly("  ** ", t-1);
				break;
			case 4:
				gotoxy(x, y+3); printStringSlowly(" **** ", t-1);
				break;
			case 5:
				gotoxy(x, y+4); printStringSlowly("********", t-1);
				break;
		}
	}
	for (i = 1; i <= 2; i++){
		switch(i){
			case 1:
				gotoxy(x+5, y+2); printStringSlowly("WONDER", t);
				break;
			case 2:
				gotoxy(x+6, y+3); printStringSlowly("AIR", t);
				break;
		}
	}
}

void clear_Area(int x, int y, int width, int height){
	int x1 = x;
	for (int i = 1; i <= height; i++){
		for (int j = 1; j <= width; j++){
			gotoxy(x,y); cout<<" ";
			x++;
		}
		x = x1;
		y++;
	}
}
void print_thankYou(int x, int y){
	int i;
	int a = x+6;
	for (i = 1; i <= 5; i++){
		switch(i){
			case 1:
				gotoxy(a,y); cout<<"    * * * * *";
				break;
			case 2:
				gotoxy(a,y+1); cout<<"       *    ";
				break;
			case 3:
				gotoxy(a,y+2); cout<<"      *    ";
				break;
			case 4:
				gotoxy(a,y+3); cout<<"     *    ";
				break;
			case 5:
				gotoxy(a,y+4); cout<<"    *    ";
				break;
		}
	}
	for (i = 1; i <= 5; i++){
		switch(i){
			case 1:
				gotoxy(a+13,y); cout<<"   *       *";
				break;
			case 2:
				gotoxy(a+12,y+1); cout<<"   *       *";
				break;
			case 3:
				gotoxy(a+12,y+2); cout<<"  * * * * *";
				break;
			case 4:
				gotoxy(a+12,y+3); cout<<" *       *";
				break;
			case 5:
				gotoxy(a+12,y+4); cout<<"*       *";
				break;
		}
	}
	for (i = 1; i <= 5; i++){
		switch(i){
			case 1:
				gotoxy(a+25,y); cout<<"   * * * * *";
				break;
			case 2:
				gotoxy(a+24,y+1); cout<<"   *       *";
				break;
			case 3:
				gotoxy(a+24,y+2); cout<<"  * * * * *";
				break;
			case 4:
				gotoxy(a+24,y+3); cout<<" *       *";
				break;
			case 5:
				gotoxy(a+24,y+4); cout<<"*       *";
				break;
		}
	}
	for (i = 1; i <= 5; i++){
		switch(i){
			case 1:
				gotoxy(a+37,y); cout<<"   *       *";
				break;
			case 2:
				gotoxy(a+36,y+1); cout<<"   * *     *";
				break;
			case 3:
				gotoxy(a+36,y+2); cout<<"  *   *   *";
				break;
			case 4:
				gotoxy(a+36,y+3); cout<<" *     * *";
				break;
			case 5:
				gotoxy(a+36,y+4); cout<<"*       *";
				break;
		}
	}
	for (i = 1; i <= 5; i++){
		switch(i){
			case 1:
				gotoxy(a+49,y); cout<<"   *       *";
				break;
			case 2:
				gotoxy(a+48,y+1); cout<<"   *     *  ";
				break;
			case 3:
				gotoxy(a+48,y+2); cout<<"  * * *";
				break;
			case 4:
				gotoxy(a+48,y+3); cout<<" *     *  ";
				break;
			case 5:
				gotoxy(a+48,y+4); cout<<"*       *";
				break;
		}
	}
	for (i = 1; i <= 5; i++){
		switch(i){
			case 1:
				gotoxy(a+64,y); cout<<"   *       *";
				break;
			case 2:
				gotoxy(a+63,y+1); cout<<"     *   *  ";
				break;
			case 3:
				gotoxy(a+63,y+2); cout<<"      *    ";
				break;
			case 4:
				gotoxy(a+63,y+3); cout<<"     *    ";
				break;
			case 5:
				gotoxy(a+63,y+4); cout<<"    *    ";
				break;
		}
	}
	for (i = 1; i <= 5; i++){
		switch(i){
			case 1:
				gotoxy(a+76,y); cout<<"   * * * * *";
				break;
			case 2:
				gotoxy(a+75,y+1); cout<<"   *       *";
				break;
			case 3:
				gotoxy(a+75,y+2); cout<<"  *       *";
				break;
			case 4:
				gotoxy(a+75,y+3); cout<<" *       *";
				break;
			case 5:
				gotoxy(a+75,y+4); cout<<"* * * * *";
				break;
		}
	}
	for (i = 1; i <= 5; i++){
		switch(i){
			case 1:
				gotoxy(a+88,y); cout<<"   *       *";
				break;
			case 2:
				gotoxy(a+87,y+1); cout<<"   *       *";
				break;
			case 3:
				gotoxy(a+87,y+2); cout<<"  *       *";
				break;
			case 4:
				gotoxy(a+87,y+3); cout<<" *       *";
				break;
			case 5:
				gotoxy(a+87,y+4); cout<<"    *    ";
				break;
		}
	}
	gotoxy(x+43,y+6); cout<<"        FOR  CHOOSING        ";
	for (i = 1; i <= 5; i++){
		switch(i){
			case 1:
				gotoxy(x,y+8); cout<<"    *       *";
				break;
			case 2:
				gotoxy(x,y+9); cout<<"   *       *";
				break;
			case 3:
				gotoxy(x,y+10); cout<<"  *   *   *";
				break;
			case 4:
				gotoxy(x,y+11); cout<<" * *   * *";
				break;
			case 5:
				gotoxy(x,y+12); cout<<"*       *";
				break;
		}
	}
	for (i = 1; i <= 5; i++){
		switch(i){
			case 1:
				gotoxy(x+13,y+8); cout<<"   * * * * *";
				break;
			case 2:
				gotoxy(x+12,y+9); cout<<"   *       *";
				break;
			case 3:
				gotoxy(x+12,y+10); cout<<"  *       *";
				break;
			case 4:
				gotoxy(x+12,y+11); cout<<" *       *";
				break;
			case 5:
				gotoxy(x+12,y+12); cout<<"* * * * *";
				break;
		}
	}
	for (i = 1; i <= 5; i++){
		switch(i){
			case 1:
				gotoxy(x+25,y+8); cout<<"   *       *";
				break;
			case 2:
				gotoxy(x+24,y+9); cout<<"   * *     *";
				break;
			case 3:
				gotoxy(x+24,y+10); cout<<"  *   *   *";
				break;
			case 4:
				gotoxy(x+24,y+11); cout<<" *     * *";
				break;
			case 5:
				gotoxy(x+24,y+12); cout<<"*       *";
				break;
		}
	}
	for (i = 1; i <= 5; i++){
		switch(i){
			case 1:
				gotoxy(x+37,y+8); cout<<"   * * * *  ";
				break;
			case 2:
				gotoxy(x+36,y+9); cout<<"   *       *";
				break;
			case 3:
				gotoxy(x+36,y+10); cout<<"  *       *";
				break;
			case 4:
				gotoxy(x+36,y+11); cout<<" *       *";
				break;
			case 5:
				gotoxy(x+36,y+12); cout<<"* * * *  ";
				break;
		}
	}
	for (i = 1; i <= 5; i++){
		switch(i){
			case 1:
				gotoxy(x+49,y+8); cout<<"   * * * * *";
				break;
			case 2:
				gotoxy(x+48,y+9); cout<<"   *        ";
				break;
			case 3:
				gotoxy(x+48,y+10); cout<<"  * * * *  ";
				break;
			case 4:
				gotoxy(x+48,y+11); cout<<" *        ";
				break;
			case 5:
				gotoxy(x+48,y+12); cout<<"* * * * *";
				break;
		}
	}
	for (i = 1; i <= 5; i++){
		switch(i){
			case 1:
				gotoxy(x+61,y+8); cout<<"   * * * * *";
				break;
			case 2:
				gotoxy(x+60,y+9); cout<<"   *       *";
				break;
			case 3:
				gotoxy(x+60,y+10); cout<<"  * * * *  ";
				break;
			case 4:
				gotoxy(x+60,y+11); cout<<" *     *  ";
				break;
			case 5:
				gotoxy(x+60,y+12); cout<<"*       *";
				break;
		}
	}
	for (i = 1; i <= 5; i++){
		switch(i){
			case 1:
				gotoxy(x+76,y+8); cout<<"   * * * * *";
				break;
			case 2:
				gotoxy(x+75,y+9); cout<<"   *       *";
				break;
			case 3:
				gotoxy(x+75,y+10); cout<<"  * * * * *";
				break;
			case 4:
				gotoxy(x+75,y+11); cout<<" *       *";
				break;
			case 5:
				gotoxy(x+75,y+12); cout<<"*       *";
				break;
		}
	}
	for (i = 1; i <= 5; i++){
		switch(i){
			case 1:
				gotoxy(x+88,y+8); cout<<"     * * *  ";
				break;
			case 2:
				gotoxy(x+87,y+9); cout<<"       *    ";
				break;
			case 3:
				gotoxy(x+87,y+10); cout<<"      *    ";
				break;
			case 4:
				gotoxy(x+87,y+11); cout<<"     *    ";
				break;
			case 5:
				gotoxy(x+87,y+12); cout<<"  * * *  ";
				break;
		}
	}
	for (i = 1; i <= 5; i++){
		switch(i){
			case 1:
				gotoxy(x+100,y+8); cout<<"   * * * * *";
				break;
			case 2:
				gotoxy(x+99,y+9); cout<<"   *       *";
				break;
			case 3:
				gotoxy(x+99,y+10); cout<<"  * * * *  ";
				break;
			case 4:
				gotoxy(x+99,y+11); cout<<" *     *  ";
				break;
			case 5:
				gotoxy(x+99,y+12); cout<<"*       *";
				break;
		}
	}
	gotoxy(x+39,y+15); cout<<"HAVE A GREAT AND SAFE JOURNEY";
}
void exit_menu(){
	clear_Area(0,0,200,50);
	print_thankYou(45,13);
	delay(5000);
	gotoxy(1,35);
	exit(0);
}
bool Password(string s){ 
	
   	char ch, incrementer='A';
   	int i=0,j;
   	char* pass = new char[20];
   	gotoxy(60,13); cout<<"                                            ";
   	gotoxy(45,16); cout<<"                                                                   ";
   	gotoxy(45,13);
   	string str = s;
   	cout<<s;
   	char a;
	while(ch!=13){
		ch=getch();
		if (ch == 8) {
			if (i != 0) {
				cout << "\b \b";
				i--;
			}
		}
		if(ch!=13 && ch!=8){
		   pass[i] = ch;
		   putch('*');
		   i++;
		}
	}
   	pass[i] = '\0';
   	if (str == "ENTER PASSWORD: "){
   		if(strcmp(pass,password)==0){
    		gotoxy(45,16);
    		cout<<"CORRECT PASSWORD.";
    		gotoxy(45,17);
    		cout<<"Press Any Key To Continue.";
    		getch();
    		return true;
   		}
   		else{
     		gotoxy(45,16);
     		cout<<"WRONG PASSWORD. ";
     		ch = getch();
     		if (ch == 27){
     			exit_menu();
			}
     		Password(s);
   		}
	}
   	else{
   		if(strcmp(pass,username1)==0 || strcmp(pass,username2)==0 || strcmp(pass,username3)==0){
   			login();
    		gotoxy(45,16);
    		cout<<"ACCESSED TO Mr. "<<pass;
    		gotoxy(45,17);
    		cout<<"Press Any Key To Continue.";
    		getch();
    		return true;
   		}
   		else{
		   login();
     		gotoxy(45,16);
     		cout<<"INVALID USERNAME. If You are not an Employee Please Press Backspace.";
     		ch = getch();
     		if (ch == 8){
     			mainmenu_passenger_employee();
			}
     		else if(ch == 27){
     			exit_menu();
			}
			Password(s);
		}
	}
}
template<typename T>
void chooseDest(T & p){
	char ch;
	gotoxy(45,14);cout<<"Choose Your Destination: ";
	gotoxy(45,15);cout<<"1. Turkey";
	gotoxy(45,16);cout<<"2. Russia";
	gotoxy(45,17);cout<<"3. China";
	gotoxy(45,18);cout<<"4. Pakistan";
	gotoxy(45,19);cout<<"5. Indonesia";
	gotoxy(45,20);cout<<"6. Singapore";
	gotoxy(45,21);cout<<"7. UAE";
	gotoxy(45,22);ch = getch();
	switch(ch){
		case '1':
			p.setTo("Turkey");
		break;
		case '2':
			p.setTo("Russia");
		break;
		case '3':
			p.setTo("China");
		break;
		case '4':
			p.setTo("Pakistan");
		break;
		case '5':
			p.setTo("Malaysia");
		break;
		case '6':
			p.setTo("Indonesia");
		break;
		case '7':
			p.setTo("Singapore");
		break;
		case '8':
			p.setTo("UAE");
		break;
		default:
			cout<<"You Entered Invalid Destination. ";
			chooseDest(p);
	}
}
template<typename T>
void chooseFrom(T & p){
	char ch;
	gotoxy(45,14);cout<<"Choose Your Departure: ";
	gotoxy(45,15);cout<<"1. Turkey";
	gotoxy(45,16);cout<<"2. Russia";
	gotoxy(45,17);cout<<"3. China";
	gotoxy(45,18);cout<<"4. Pakistan";
	gotoxy(45,19);cout<<"5. Indonesia";
	gotoxy(45,20);cout<<"6. Singapore";
	gotoxy(45,21);cout<<"7. UAE";
	gotoxy(45,22);ch = getch();
	switch(ch){
		case '1':
			p.setFrom("Turkey");
		break;
		case '2':
			p.setFrom("Russia");
		break;
		case '3':
			p.setFrom("China");
		break;
		case '4':
			p.setFrom("Pakistan");
		break;
		case '5':
			p.setFrom("Malaysia");
		break;
		case '6':
			p.setFrom("Indonesia");
		break;
		case '7':
			p.setFrom("Singapore");
		break;
		case '8':
			p.setFrom("Dubai");
		break;
		default:
			cout<<"You Entered Invalid Destination. ";
			chooseFrom(p);
	}
}

void mainmenu(){
	boxOperation('|',25,160,24,7,printSquareBox);
	gotoxy(45,12); printLineSlowly('|',50,5);
	gotoxy(95,12); printStringSlowly("PASSWORD PROTECTED", 5);
	gotoxy(114,12); printLineSlowly('|',50,5);
	draw_Logo(166, 12, 5);
	Password("ENTER PASSWORD: ");
	mainmenu_passenger_employee();
}

void mainmenu_passenger_employee(){
	boxOperation('|',25,160,24,7,printSquareBox);
	gotoxy(45,12); printLineSlowly('|', 49, 5);
	gotoxy(94,12); printStringSlowly("WELCOME TO WONDER AIR", 5);
	gotoxy(115,12); printLineSlowly('|', 49, 5);
	draw_Logo(166, 12, 5);
	gotoxy(57,18); cout<<"                            ";
	gotoxy(45,14); cout<<"1. FOR PASSENGER";
	gotoxy(45,15); cout<<"2. FOR EMPLOYEE";
	gotoxy(45,16); cout<<"3. MEMBERSHIP";
	gotoxy(45,17); cout<<"4. EXIT OR PRESS";
	gotoxy(45,19); cout<<"CHOOSE ONE: ";
	char ch;
	ch = getch();
	if (ch == 27){
		exit_menu();
	}
	switch(ch){
		case '1':
			mainmenu_passenger();
			break;
		case '2':
			mainmenu_employee();
			break;
		case '3':
			mainmenu_member();
			break;
		case '4':
			gotoxy(1,35);
			exit_menu();
		default:
			gotoxy(57,20); cout<<"WRONG ENTRY. ";
			getch();
			mainmenu_passenger_employee();
	}
	
}


void mainmenu_passenger(){
	char ch;
	boxOperation('|',25,160,24,7,printSquareBox);
	gotoxy(45,12); printLineSlowly('|', 49, 5);
	gotoxy(94,12); printStringSlowly("  PASSENGER SECTION  ", 5);
	gotoxy(115,12); printLineSlowly('|', 49, 5);
	gotoxy(45,13); cout<<"Press any key to Start or Backspace to go Back";
	gotoxy(45,14); 
	ch = getch();
	if (ch == 8){
		mainmenu_passenger_employee();
	}
	else{
		clear_Area(45,13,115,6);
		gotoxy(45,13);
		Passenger p;
		p.bookFlight();
	}
}

void mainmenu_employee(){
	boxOperation('|',25,160,24,7,printSquareBox);
	gotoxy(45,12); printLineSlowly('|', 49, 5);
	gotoxy(94,12); printStringSlowly(" FOR OFFICE USE ONLY ", 5);
	gotoxy(115,12); printLineSlowly('|', 49, 5);
	draw_Logo(166, 12, 5);
	Password("ENTER PASSWORD TO UNLOCK DETAILS (OFFICE USE) : ");
	clear_Area(45,13,115,6);
	char ch;
	int i=13,tag=0,y=15;
	string s1,s2,s3,s4;
	ifstream fin1,fin2;
	gotoxy(45,13); cout<<"Press any key to Start or Backspace to go Back";
	gotoxy(45,14); 
	ch = getch();
	if (ch == 8){
		mainmenu_passenger_employee();
	}
	else {
		if(ch == 27 || ch == 51){
			exit_menu();
		}
		else{
			back:
			char choice,d;
			clear_Area(45,13,115,11);
			gotoxy(45,16);
			cout<<"1.View Details About Members ";
			gotoxy(45,17);
			cout<<"2.Go Back (Backspace) ";
			gotoxy(45,18);
			cout<<"3.Exit";
			gotoxy(45,19);	
			cout<<"Enter Your Choice : ";
			choice=getch();
			if(ch =='2'){
				mainmenu_employee();
			}
			switch(choice){
				case '1':
					hi:
					clear_Area(45,13,115,11);
					gotoxy(45,15);
					cout<<"1.View Usernames and their Passwords.";
					gotoxy(45,16);
					cout<<"2.View Details by Username. ";
					gotoxy(45,17);
					cout<<"3.Go Back (Backspace) ";
					gotoxy(45,18);
					cout<<"Enter your Choice :";
					d=getch();
					switch(d){
						case '1':
							fin1.open("Usernames and Passwords\\Usernames.txt");
							fin2.open("Usernames and Passwords\\Passwords.txt");
							clear_Area(45,13,115,11);
							gotoxy(45,13);
							cout<<"USERNAMES: \tPASSWORDS:";
							while(!fin1.eof() || !fin2.eof()){
								getline(fin1,s1);
								getline(fin2,s2);
							    gotoxy(45,y);
								cout<<s1;
								gotoxy(65,y);
								cout<<s2;
								y++;
							}
							fin1.close();
							fin2.close();
							gotoxy(45,20);
							cout<<"Press any key to go back . ";
							getch();
							goto hi;
							break;
						case '2':
							wapis:
							clear_Area(45,13,115,11);
							gotoxy(45,15);
							cout<<"Enter Username of Any Member to show details of his / her : ";
							cin>>s1;
								fin1.open("All Details\\all details.txt");
								while(!fin1.eof()){
									do{
									fin1>>s2;
									if(s2==s1){
										tag=1;
										getline(fin1,s3);
											while(s3!="***"){
											gotoxy(45,++i);
											cout<<s3<<"\n";
											getline(fin1,s3);
											}
										}
									} 
									while(s2!=s1);
								}
								if(tag==0){
									goto wapis;
								}
								else{
								fin1.close();
								gotoxy(45,13);
								cout<<"Press any key to go back.";
								getch();
								clear_Area(45,13,115,15);
								goto hi;
								}
						break;
						case '3':
						 	exit_menu();
						break;
						default:
						gotoxy(57,20); cout<<"WRONG ENTRY. press any key..";
						getch();
						goto back;
					}
				break;
				case '2':
					mainmenu_passenger_employee();
				case '3':
					exit_menu();
				break;
				default:
				gotoxy(57,20); cout<<"WRONG ENTRY. press any key";
				getch();
				mainmenu_employee();
			}
		}	
	}
	clear_Area(45,13,115,6);
	gotoxy(45,13);
}
void login(){
	clear_Area(45,11,119,15);
	gotoxy(85,16); printStringSlowly("LOGGING IN",5);
	for (int i = 1; i <= 2 ;i++){
		gotoxy(96,16); cout<<"      ";
		gotoxy(96,16); printLineSlowly('.',6,300);
 }
	
	clear_Area(45,11,118,15);
}
void logout(){
	clear_Area(45,11,119,15);
	gotoxy(85,16); printStringSlowly("LOGGING OUT",5);
	for (int i = 1; i <= 2; i++){
		gotoxy(96,16); cout<<"      ";
		gotoxy(96,16); printLineSlowly('.',6,300);
 }
	
	clear_Area(45,11,118,15);
}
void mainmenu_member(){
	boxOperation('|',25,160,24,7,printSquareBox);
	char ch;
	gotoxy(45,12); printLineSlowly('|', 49, 5);
	gotoxy(94,12); printStringSlowly(" MEMBERSHIP  SECTION ", 5);
	gotoxy(115,12); printLineSlowly('|', 49, 5);
		clear_Area(45,13,115,6);
		gotoxy(45,13);
		Membership m;
		cout<<"1. Sign Up";
		gotoxy(45,14); cout<<"2. Sign In";
		gotoxy(45,15); cout<<"3. Exit or ESC";
		gotoxy(45,16); cout<<"Choose Any: ";
		ch = getch();
		if (ch == 27){
			exit_menu();
		}
		else if(ch == 8){
			mainmenu_passenger_employee();
		}
		switch(ch){
			case '1':
				clear_Area(45,13,115,6);
				m.registerYourself();
				break;
			case '2':
				m.checkMember();
				break;
			case '3':
				exit_menu();
				break;
			}

}

/************************************************** MAIN FUNCTION ********************************************************/
int main (){
	system("mode con: cols=200 lines=80");
	HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd,SW_SHOWMAXIMIZED);
    gotoxy(90,2);
    cout<<"Starting Time Of Program";
    gotoxy(90,4);
    t();
    mainmenu();
	return 0;
}
