#include <Datetime.h>
#include <chrono>
#include <Windows.h>

DateTime::TimeSpan::TimeSpan() 
	:mTicks(0) {};

DateTime::TimeSpan::TimeSpan(const TimeSpan & Object)
	:mTicks(Object.mTicks) {};

DateTime::TimeSpan::TimeSpan(Int Days, Int Hours, Int Minutes, Int Seconds, Int Milliseconds)
	
{
	mTicks = Milliseconds * TicksPerMillisecond + Seconds * TicksPerSecond + Minutes * TicksPerMinute + Hours * TicksPerHour + Days * TicksPerDay;

}

DateTime::TimeSpan::TimeSpan(Int Days, Int Hours, Int Minutes, Int Seconds)
{
	mTicks = Seconds * TicksPerSecond + Minutes * TicksPerMinute + Hours * TicksPerHour + Days * TicksPerDay;
}

DateTime::TimeSpan::TimeSpan(Int Hours, Int Minutes, Int Seconds)
{
	mTicks = Seconds * TicksPerSecond + Minutes * TicksPerMinute + Hours * TicksPerHour;
}

DateTime::TimeSpan::TimeSpan(Int Hours, Int Minutes)
{
	mTicks = Minutes * TicksPerMinute + Hours * TicksPerHour;
}

DateTime::TimeSpan::TimeSpan(Int64 Ticks)
	:mTicks(Ticks) {}
DateTime::TimeSpan::~TimeSpan() {} ;

Int DateTime::TimeSpan::Days() const
{
	return this->mTicks / TicksPerDay;
}

Int DateTime::TimeSpan::Hours() const
{
	return this->mTicks % TicksPerDay / TicksPerHour;
}

Int DateTime::TimeSpan::Minutes() const
{
	return this->mTicks % TicksPerHour / TicksPerMinute;
}

Int DateTime::TimeSpan::Seconds() const
{
	return this->mTicks % TicksPerMinute / TicksPerSecond;
}

Int DateTime::TimeSpan::Milliseconds() const
{
	return this->mTicks % TicksPerSecond / TicksPerMillisecond;
}

Int64 DateTime::TimeSpan::Ticks() const
{
	return this->mTicks;
}

DateTime::TimeSpan DateTime::TimeSpan::Add(const TimeSpan & Object) const
{
	return DateTime::TimeSpan (Object.Ticks()+this->mTicks);

}

DateTime::TimeSpan DateTime::TimeSpan::AddDays(Int Days) const
{
	return DateTime::TimeSpan (Days * TicksPerDay + this->mTicks);

}

DateTime::TimeSpan DateTime::TimeSpan::AddHours(Int Hours) const
{
	return DateTime::TimeSpan (Hours * TicksPerHour + this->mTicks);
}

DateTime::TimeSpan DateTime::TimeSpan::AddMinutes(Int Minutes) const
{
	return DateTime::TimeSpan (Minutes * TicksPerMinute + this->mTicks);
}

DateTime::TimeSpan DateTime::TimeSpan::AddSeconds(Int Seconds) const
{
	return DateTime::TimeSpan (Seconds * TicksPerSecond + this->mTicks);
}

DateTime::TimeSpan DateTime::TimeSpan::AddMilliseconds(Int Milliseconds) const
{
	return DateTime::TimeSpan (Milliseconds * TicksPerMillisecond + this->mTicks);
}

DateTime::TimeSpan DateTime::TimeSpan::AddTicks(Int64 Ticks) const
{
	return DateTime::TimeSpan (Ticks + this->mTicks);
}

bool DateTime::TimeSpan::operator<(const TimeSpan & Object) const
{
	return (this->mTicks < Object.mTicks) ? true : false;
}

bool DateTime::TimeSpan::operator>(const TimeSpan & Object) const
{
	return (this->mTicks > Object.mTicks) ? true : false;
}

bool DateTime::TimeSpan::operator<=(const TimeSpan & Object) const
{
	return (this->mTicks <= Object.mTicks) ? true : false;
}

bool DateTime::TimeSpan::operator>=(const TimeSpan & Object) const
{
	return (this->mTicks >= Object.mTicks) ? true : false;
}

bool DateTime::TimeSpan::operator==(const TimeSpan & Object) const
{
	return (this->mTicks == Object.mTicks) ? true : false;
}

bool DateTime::TimeSpan::operator!=(const TimeSpan & Object) const
{
	return (this->mTicks != Object.mTicks) ? true : false;
}

DateTime::TimeSpan & DateTime::TimeSpan::operator=(const TimeSpan & Object)
{
	this->mTicks = Object.mTicks;
	return (*this);
}

DateTime::TimeSpan DateTime::TimeSpan::operator+(const TimeSpan & Object) const
{
	return DateTime::TimeSpan (this->mTicks + Object.mTicks);
}

DateTime::TimeSpan DateTime::TimeSpan::operator-() const 
{
	return DateTime::TimeSpan (-this->mTicks);
}

DateTime::TimeSpan DateTime::TimeSpan::operator-(const TimeSpan & Object) const
{
	return DateTime::TimeSpan (this->mTicks - Object.mTicks);
}

DateTime::TimeSpan & DateTime::TimeSpan::operator+=(const TimeSpan & Object)
{
	this->mTicks = this->mTicks + Object.mTicks;
	return (*this);
}

DateTime::TimeSpan & DateTime::TimeSpan::operator-=(const TimeSpan & Object)
{
	this->mTicks = this->mTicks - Object.mTicks;
	return (*this);
}

DateTime::Time::Time()
	:mTicks(0) {};


DateTime::Time::Time(const Time & Object)
	:mTicks (Object.mTicks) {}

DateTime::Time::Time(Int Hours, Int Minutes, Int Seconds, Int Milliseconds)
{
	mTicks = (Hours * DateTime::TimeSpan::TicksPerHour + Minutes * DateTime::TimeSpan::TicksPerMinute +
		Seconds * DateTime::TimeSpan::TicksPerSecond + Milliseconds * DateTime::TimeSpan::TicksPerMillisecond) % DateTime::TimeSpan::TicksPerDay;
}

DateTime::Time::Time(Int Hours, Int Minutes, Int Seconds)
{
	mTicks = (Hours * DateTime::TimeSpan::TicksPerHour + Minutes * DateTime::TimeSpan::TicksPerMinute +
		Seconds * DateTime::TimeSpan::TicksPerSecond) % DateTime::TimeSpan::TicksPerDay;
}

DateTime::Time::Time(Int Hours, Int Minutes)
{
	mTicks = (Hours * DateTime::TimeSpan::TicksPerHour + Minutes * DateTime::TimeSpan::TicksPerMinute) % DateTime::TimeSpan::TicksPerDay;
}

DateTime::Time::Time(Int64 Ticks)
	: mTicks(Ticks% DateTime::TimeSpan::TicksPerDay) {}


DateTime::Time::~Time() {}


Int DateTime::Time::Hour() const
{
	return this->mTicks / DateTime::TimeSpan::TicksPerHour;
}


Int DateTime::Time::Minute() const
{
	return this->mTicks % DateTime::TimeSpan::TicksPerHour / DateTime::TimeSpan::TicksPerMinute;
}

Int DateTime::Time::Second() const
{
	return this->mTicks % DateTime::TimeSpan::TicksPerMinute / DateTime::TimeSpan::TicksPerSecond;
}

Int DateTime::Time::Millisecond() const
{
	return this->mTicks % DateTime::TimeSpan::TicksPerSecond / DateTime::TimeSpan::TicksPerMillisecond;
}

Int64 DateTime::Time::Ticks() const
{
	return this->mTicks;
}


DateTime::Time DateTime::Time::Now()
{
	return (DateTime::Time::UtcNow() + DateTime::Time::Timezone());
}

DateTime::Time DateTime::Time::UtcNow()
{
	return DateTime::Time(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count() / 100);

}

bool beforeUTC(SYSTEMTIME UTC_Time, SYSTEMTIME Local_Time)
{
	if (Local_Time.wYear > UTC_Time.wYear) return true;
	if (Local_Time.wMonth > UTC_Time.wMonth) return true;
	if (Local_Time.wDay > UTC_Time.wDay) return true;
	if (Local_Time.wHour > UTC_Time.wHour) return true;
	if (Local_Time.wMinute > UTC_Time.wMinute) return true;
	return false;
}


bool afterUTC(SYSTEMTIME UTC_Time, SYSTEMTIME Local_Time)
{
	return beforeUTC(Local_Time, UTC_Time);
}


DateTime::TimeSpan DateTime::Time::Timezone()
{
	SYSTEMTIME UTC_Time, local_Time;
	GetSystemTime(&UTC_Time);
	GetLocalTime(&local_Time);

	if (UTC_Time.wDay != local_Time.wDay)
	{
		if (beforeUTC(UTC_Time, local_Time))
			local_Time.wHour += 24;
		if (afterUTC(UTC_Time, local_Time))
			UTC_Time.wHour += 24;
	}

	return DateTime::TimeSpan (local_Time.wHour - UTC_Time.wHour, local_Time.wMinute - UTC_Time.wMinute);

	
}

DateTime::Time DateTime::Time::Add(const TimeSpan & Ts) const
{
	return DateTime::Time (Ts.Ticks() + this->mTicks);
}

DateTime::Time DateTime::Time::AddHours(Int Hours) const
{
	return DateTime::Time (Hours * DateTime::TimeSpan::TicksPerHour + this->mTicks);
}

DateTime::Time DateTime::Time::AddMinutes(Int Minutes) const
{
	return DateTime::Time (Minutes * DateTime::TimeSpan::TicksPerMinute + this->mTicks);
}

DateTime::Time DateTime::Time::AddSeconds(Int Seconds) const
{
	return DateTime::Time (Seconds * DateTime::TimeSpan::TicksPerSecond + this->mTicks);
}

DateTime::Time DateTime::Time::AddMilliseconds(Int Milliseconds) const
{
	return DateTime::Time (Milliseconds * DateTime::TimeSpan::TicksPerMillisecond + this->mTicks);
}

DateTime::Time DateTime::Time::AddTicks(Int64 Ticks) const
{
	return DateTime::Time (Ticks + this->mTicks);
}

bool DateTime::Time::operator<(const Time & Object) const
{
	return (this->mTicks < Object.mTicks) ? true : false;
}

bool DateTime::Time::operator>(const Time & Object) const
{
	return (this->mTicks > Object.mTicks) ? true : false;
}

bool DateTime::Time::operator<=(const Time & Object) const
{
	return (this->mTicks <= Object.mTicks) ? true : false;
}

bool DateTime::Time::operator>=(const Time & Object) const
{
	return (this->mTicks >= Object.mTicks) ? true : false;
}

bool DateTime::Time::operator==(const Time & Object) const
{
	return (this->mTicks == Object.mTicks) ? true : false;
}

bool DateTime::Time::operator!=(const Time & Object) const
{
	return (this->mTicks != Object.mTicks) ? true : false;
}

DateTime::Time & DateTime::Time::operator=(const Time & Object)
{
	this->mTicks = Object.mTicks;
	return (*this);
}

DateTime::Time DateTime::Time::operator+(const TimeSpan & Ts) const
{
	return DateTime::Time (this->mTicks + Ts.Ticks());
}

DateTime::Time DateTime::Time::operator-(const TimeSpan & Ts) const
{
	return DateTime::Time(this->mTicks - Ts.Ticks());
}

DateTime::TimeSpan DateTime::Time::operator-(const Time & Object) const
{
	return DateTime::TimeSpan(this->mTicks - Object.Ticks());
}

DateTime::Time & DateTime::Time::operator+=(const TimeSpan & Ts)
{
	this->mTicks = (this->mTicks + Ts.Ticks()) % DateTime::TimeSpan::TicksPerDay;
	return (*this);
}

DateTime::Time & DateTime::Time::operator-=(const TimeSpan & Ts)
{
	this->mTicks = (this->mTicks - Ts.Ticks()) % DateTime::TimeSpan::TicksPerDay;
	return (*this);
}

DateTime::Date::Date()
	:mTicks(0) {}

DateTime::Date::Date(const Date & Object)
	:mTicks (Object.mTicks) {}



DateTime::Date::Date(Int Day, Int Month, Int Year)
{
	Int Num_of_Day = Day - 1;

	Int Days_in_Jan = 31;
	Int Days_in_Feb = ((!(Year % 4)) && (Year % 100) || (!(Year % 400)))? 29: 28;
	Int Days_in_Mar = 31;
	Int Days_in_Apr = 30;
	Int Days_in_May = 31;
	Int Days_in_Jun = 30;
	Int Days_in_Jul = 31;
	Int Days_in_Aug = 31;
	Int Days_in_Sep = 30;
	Int Days_in_Oct = 31;
	Int Days_in_Now = 30;
	Int Days_in_Dec = 31;
	Int Days_in_mounth[12 + 1]{ 0, Days_in_Jan, Days_in_Feb, Days_in_Mar, Days_in_Apr, Days_in_May, Days_in_Jun, Days_in_Jul, Days_in_Aug, Days_in_Sep, Days_in_Oct, Days_in_Now, Days_in_Dec };
	
	for (Int i = 0; i < Month; i++)
			Num_of_Day += Days_in_mounth[i];

	Int Num_of_LeapYear = Year / 4 - Year / 100 + Year / 400;
	Int Day_in_noLeapYear = 365;
	Num_of_Day += (Year - 1) * Day_in_noLeapYear + Num_of_LeapYear;

	mTicks = Num_of_Day;
}

DateTime::Date::Date(Int64 Ticks)
	:mTicks (Ticks) {}


Int DateTime::Date::Day() const
{
	Int Year = this->Year();
	Int Month = this->Month();
	return this->mTicks - DateTime::Date(01, Month, Year).Ticks() + 1;
}

Int DateTime::Date::Month() const
{
	Int Year = this->Year();
	Int DaysLast = this->mTicks - DateTime::Date(01, 01, Year).Ticks();
	Int Days_in_Jan = 31;
	Int Days_in_Feb = ((!(Year % 4)) && (Year % 100) || (!(Year % 400))) ? 29 : 28;
	Int Days_in_Mar = 31;
	Int Days_in_Apr = 30;
	Int Days_in_May = 31;
	Int Days_in_Jun = 30;
	Int Days_in_Jul = 31;
	Int Days_in_Aug = 31;
	Int Days_in_Sep = 30;
	Int Days_in_Oct = 31;
	Int Days_in_Now = 30;
	Int Days_in_Dec = 31;
	Int Days_in_month[12 + 1]{ 0, Days_in_Jan, Days_in_Feb, Days_in_Mar, Days_in_Apr, Days_in_May, Days_in_Jun, Days_in_Jul, Days_in_Aug, Days_in_Sep, Days_in_Oct, Days_in_Now, Days_in_Dec };
	
	for (Int Month = 1; ; Month++)
	{
			if (DaysLast < Days_in_month[Month])
			return Month;
		DaysLast -= Days_in_month[Month];
	}
}

Int DateTime::Date::Year() const
{
	Int DaysLast = this->Ticks();
	for (Int Year = 1;; Year++)
	{
		Int Days_in_Year = ((!(Year % 4)) && (Year % 100) || (!(Year % 400))) ? 366 : 365;
		if (DaysLast < Days_in_Year)
			return Year;
		DaysLast -= Days_in_Year;
	}
}

Int64 DateTime::Date::Ticks() const
{
	return this->mTicks;
}

bool DateTime::Date::IsLeapYear() const
{
	Int Year = this->Year();
	return ((!(Year % 4)) && (Year % 100) || (!(Year % 400))) ? true : false;
}

DateTime::Date DateTime::Date::Today()
{
	SYSTEMTIME local_Time;
	GetLocalTime(&local_Time);
	return DateTime::Date(local_Time.wDay, local_Time.wMonth, local_Time.wYear);
}

DateTime::Date DateTime::Date::Add(const TimeSpan & Ts) const
{
	return DateTime::Date(this->mTicks + Ts.Ticks()/DateTime::TimeSpan::TicksPerDay);
}

DateTime::Date DateTime::Date::AddDays(Int Days) const
{
	return DateTime::Date (this->mTicks + Days);
}

DateTime::Date DateTime::Date::AddMonths(Int Months) const
{
	Int Days_in_Month = 30;
	return DateTime::Date(this->mTicks + Months * Days_in_Month);
}

DateTime::Date DateTime::Date::AddYears(Int Years) const
{
	Int Days_in_Year = 365;
	return DateTime::Date(this->mTicks + Years * Days_in_Year);
}

DateTime::Date DateTime::Date::AddTicks(Int64 Ticks) const
{
	return DateTime::Date(this->mTicks + Ticks);
}

bool DateTime::Date::operator<(const Date & Object) const
{
	return (this->mTicks < Object.mTicks) ? true : false;
}

bool DateTime::Date::operator>(const Date & Object) const
{
	return (this->mTicks > Object.mTicks) ? true : false;
}

bool DateTime::Date::operator<=(const Date & Object) const
{
	return (this->mTicks <= Object.mTicks) ? true : false;
}

bool DateTime::Date::operator>=(const Date & Object) const
{
	return (this->mTicks >= Object.mTicks) ? true : false;
}

bool DateTime::Date::operator==(const Date & Object) const
{
	return (this->mTicks == Object.mTicks) ? true : false;
}

bool DateTime::Date::operator!=(const Date & Object) const
{
	return (this->mTicks != Object.mTicks) ? true : false;
}

DateTime::Date & DateTime::Date::operator=(const Date & Object)
{
	this->mTicks = Object.mTicks;
	return (*this);
}

DateTime::Date DateTime::Date::operator+(const TimeSpan & Ts) const
{
	return DateTime::Date(this->mTicks + Ts.Ticks()/DateTime::TimeSpan::TicksPerDay);
}

DateTime::TimeSpan DateTime::Date::operator-(const Date & Object) const
{
	return DateTime::TimeSpan((this->mTicks - Object.Ticks()) * DateTime::TimeSpan::TicksPerDay);
}

DateTime::Date & DateTime::Date::operator+=(const TimeSpan & Ts)
{
	this->mTicks = this->mTicks + Ts.Ticks() / DateTime::TimeSpan::TicksPerDay;
	return (*this);
}

DateTime::Date & DateTime::Date::operator-=(const TimeSpan & Ts)
{
	this->mTicks = this->mTicks - Ts.Ticks() / DateTime::TimeSpan::TicksPerDay;
	return (*this);
}
