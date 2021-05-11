//Bill.h
#pragma once
#pragma pack(1)//
#include <iostream>
#include <sstream>
#include <string>
#include "Time.h"

using namespace std;

class Bill
{
public:
	class Time
	{
	private:
		unsigned int hour, minute, second;
		static int counter;
	public:
		unsigned int GetHour() const { return hour; };
		unsigned int GetMinute() const { return minute; };
		unsigned int GetSecond() const { return second; };

		void SetHour(unsigned int);
		void SetMinute(unsigned int);
		void SetSecond(unsigned int);

		Time();
		Time(unsigned int, unsigned int, unsigned int);
		Time& operator = (const Time&);
		operator string () const;

		Time& operator ++ ();
		Time& operator -- ();
		Time operator ++ (int);
		Time operator -- (int);

		friend ostream& operator <<(ostream& out, const Time& p);
		friend istream& operator >>(istream& in, Time& p);

		// Порівняння моментів часу
		friend bool operator <(const Time&, const Time&);
		friend bool operator == (const Time&, const Time&);
		friend bool operator > (const Time&, const Time&);
		friend bool operator <=(const Time&, const Time&);
		friend bool operator >= (const Time&, const Time&);
		friend bool operator != (const Time&, const Time&);

		Time& operator - (int);//відніманняння з часу заданої кількості секунд
		Time& operator + (int);//додавання до часу задану кількість секунд

		friend unsigned int Difference(Time T1, Time T2);//seconds
		friend unsigned int DifferenceForT(Time T1, Time T2);//minutes
		unsigned int ToSeconds();// Переведення в секунди
		unsigned int ToMinutes();// Переведення у хвилини (з округленням до цілої хвилини)
		static int getCounter();
	};

	string GetSurname() const { return surname; };
	void SetSurname(string v) { this->surname = v; };

	string GetCellnumb() const { return cellnumb; };
	void SetCellnumb(string v) { this->cellnumb = v; }

	double GetTaryf() const { return taryf; };
	void SetTaryf(double);

	double GetZnyzhka() const { return znyzhka; };
	void SetZnyzhka(double);

	double GetSumforpay() const { return sumforpay; };
	void SetSumforpay(double);

	Bill();
	Bill(string, string, double, double, double);
	Bill(const Bill&);

	Bill& operator = (const Bill&);
	operator string () const;

	friend ostream& operator << (ostream& out, const Bill& s);
	friend istream& operator >> (istream& in, Bill& s);

	Bill& operator ++ ();
	Bill& operator -- ();
	Bill operator ++ (int);
	Bill operator -- (int);

	double For_Pay(Time T1, Time T2);

	static int getCounter();
private:
	string surname;
	string cellnumb;
	double taryf;
	double znyzhka;
	Time timebeg;
	Time timeend;
	double sumforpay;
	static int counter;
};
