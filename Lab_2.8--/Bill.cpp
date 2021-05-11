//Bil.cpp
#include "Bill.h"

//Time
int Bill::Time::counter = 0;

void Bill::Time::SetHour(unsigned int value)
{
	if (value > 23 || value < 0)
		value = 0;
	this->hour = value;
}

void Bill::Time::SetMinute(unsigned int value)
{
	if (value > 59 || value < 0)
		value = 0;
	this->minute = value;
}

void Bill::Time::SetSecond(unsigned int value)
{
	if (value > 59 || value < 0)
		value = 0;
	this->second = value;
}

Bill::Time::Time()
	:hour(0), minute(0), second(0)
{
	Bill::Time::counter++;
}

Bill::Time::Time(unsigned int y, unsigned int m, unsigned int d) 
{
	SetHour(y);
	SetMinute(m);
	SetSecond(d);
	Bill::Time::counter++;
}


Bill::Time& Bill::Time::operator = (const Time& n)
{
	hour = n.hour;
	minute = n.minute;
	second = n.second;
	return *this;
}

Bill::Time::operator string () const
{
	stringstream sout;
	sout << " " << hour << ":" << minute << ":" << second;
	return sout.str();
}

ostream& operator <<(ostream& out, const Bill::Time& p)
{
	out << string(p);
	return out;
}

istream& operator >>(istream& in, Bill::Time& p)
{
	unsigned int h, m, s;
	do {
		cout << " Enter hour: "; in >> h;
	} while (h > 23 || h < 0);

	do {
		cout << " Enter minute: "; in >> m;
	} while (m > 59 || m < 0);

	do {
		cout << " Enter second: "; in >> s;
	} while (s > 59 || s < 0);

	p.SetHour(h);
	p.SetMinute(m);
	p.SetSecond(s);
	return in;
}

Bill::Time& Bill::Time::operator --()
{
	--hour;
	return *this;
}

Bill::Time& Bill::Time::operator ++()
{
	++hour;
	return *this;
}

Bill::Time Bill::Time::operator --(int)
{
	Time a = *this;
	second--;
	//--second;
	return a;
}

Bill::Time Bill::Time::operator ++(int)
{
	Time a = *this;
	second++;
	//++second;
	return a;
}

bool operator <(const Bill::Time& T1, const Bill::Time& T2)
{
	return T1.hour < T2.hour ||
		T1.hour == T2.hour && T1.minute < T2.minute ||
		T1.hour == T2.hour && T1.minute == T2.minute && T1.second < T2.second;
}

bool operator == (const Bill::Time& T1, const Bill::Time& T2)
{
	return T1.hour == T2.hour && T1.minute == T2.minute && T1.second == T2.second;
}

bool operator > (const Bill::Time& T1, const Bill::Time& T2)
{
	return T1.hour > T2.hour ||
		T1.hour == T2.hour && T1.minute > T2.minute ||
		T1.hour == T2.hour && T1.minute == T2.minute && T1.second > T2.second;
}

bool operator <=(const Bill::Time& T1, const Bill::Time& T2)
{
	return !(T1 > T2);
}

bool operator >= (const Bill::Time& T1, const Bill::Time& T2)
{
	return !(T1 < T2);
}

bool operator != (const Bill::Time& T1, const Bill::Time& T2)
{
	return !(T1 == T2);
}

Bill::Time& Bill::Time::operator - (int substr)
{
	if (substr < 1)
		substr = 1;

	do {
		if (substr < second)
		{
			second = second - substr;
			substr = 0;
		}
		else {
			substr = substr - second;
			if (minute == 0)//1//60
			{
				minute = 60;//12//0//59
				hour--;
			}
			else {
				minute--;
				second = 60;
			}
		}
	} while (substr != 0);

	return *this;
}

Bill::Time& Bill::Time::operator + (int seconds)
{
	short SecondsLeft;
	do {
		SecondsLeft = 60 - second;
		if (seconds < SecondsLeft)
		{
			second = second + seconds;
			seconds = 0;
		}
		else
		{
			second = second + SecondsLeft;
			seconds = seconds - SecondsLeft;
			if (minute == 60)
			{
				minute = 0;//
				hour++;
			}
			else
			{
				second = 0;//
				minute++;
			}
		}
	} while (seconds != 0);
	return *this;
}



unsigned int Bill::Time::ToSeconds()
{
	unsigned int t;
	t = hour * 3600 + minute * 60 + second;
	return t;
}

unsigned int Bill::Time::ToMinutes()
{
	unsigned int t;
	if (second < 1)
	{
		t = hour * 60 + minute;
	}
	if (second > 0)
	{
		t = hour * 60 + minute + 1;
	}
	return t;
}

unsigned int Difference(Bill::Time T1, Bill::Time T2)
{
	return T2.ToSeconds() - T1.ToSeconds();
}

unsigned int DifferenceForT(Bill::Time T1, Bill::Time T2)
{
	int k;
	k = (T2.ToSeconds() - T1.ToSeconds()) / 60.;
	return k;
}

int Bill::Time::getCounter()
{
	return Bill::Time::counter;
}

//Bill
int Bill::counter = 0;

void Bill::SetTaryf(double v)
{
	this->taryf = v;
}

void Bill::SetZnyzhka(double v)
{
	if (v > 100 || v < 0)
	{
		v = 0;
	}
	this->znyzhka = v;
}

void Bill::SetSumforpay(double v)
{
	this->sumforpay = v;
}


Bill::Bill()
	:surname("a"), cellnumb("0"), taryf(0), znyzhka(0), sumforpay(0)
{
	Bill::counter++;

}


Bill::Bill(string surname, string cellnumb, double taryf, double znyzhka, double sumforpay)
{
	SetSurname(surname);
	SetCellnumb(cellnumb);
	SetTaryf(taryf);
	SetZnyzhka(znyzhka);
	SetSumforpay(sumforpay);
	Bill::counter++;
}

Bill::Bill(const Bill& v)
{
	*this = v;
	Bill::counter++;
}

Bill& Bill::operator = (const Bill& n)
{
	surname = n.surname;
	cellnumb = n.cellnumb;
	taryf = n.taryf;
	znyzhka = n.znyzhka;
	timebeg = n.timebeg;
	timeend = n.timeend;
	sumforpay = n.sumforpay;
	return *this;
}

Bill::operator string () const
{
	stringstream sout;
	sout << endl << " Surname: " << surname << endl;
	sout << " Phone number: " << cellnumb << endl;
	sout << " Taryf per minute: " << taryf << "UAH" << endl;
	sout << " Discount: " << znyzhka << "%" << endl;

	return sout.str();
}

ostream& operator <<(ostream& out, const Bill& s)
{
	out << string(s);
	return out;
}

istream& operator >>(istream& in, Bill& s)
{
	string surname;
	cout << " Enter surname: "; in >> surname;
	s.SetSurname(surname);

	string cellnumb;
	cout << " Enter phone number: "; in >> cellnumb;
	s.SetCellnumb(cellnumb);

	double taryf, znyzhka;
	cout << " Enter taryf per minute: "; in >> taryf;
	do {
		cout << " Enter discount, %: "; in >> znyzhka;
	} while (znyzhka > 100 || znyzhka < 0);
	s.SetTaryf(taryf);
	s.SetZnyzhka(znyzhka);

	return in;
}

double Bill::For_Pay(Time T1, Time T2)
{
	sumforpay = DifferenceForT(T1, T2) * taryf - (DifferenceForT(T1, T2) * taryf) * (znyzhka / 100);
	return sumforpay;
}

Bill& Bill::operator ++()
{
	++taryf;
	return *this;
}

Bill& Bill::operator --()
{
	--taryf;
	return *this;
}

Bill Bill::operator ++(int)
{
	Bill s(*this);
	taryf++;
	return s;
}

Bill Bill::operator --(int)
{
	Bill s(*this);
	taryf--;
	return s;
}

int Bill::getCounter()
{
	return Bill::counter;
}



