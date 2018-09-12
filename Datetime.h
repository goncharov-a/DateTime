# pragma once
# ifndef DATETIME_H
    # define DATETIME_H
# endif

# include <cstypes.h>

namespace DateTime
{
    /*

The TimeSpan class represents the duration of an arbitrary time interval in measure.
            Duration of a measure: 100 nanoseconds        
    */
    class TimeSpan
    {
        public:
            static const Int64  TicksPerMillisecond =  10000;
            static const Int64  TicksPerSecond      =   1000 * TicksPerMillisecond;
            static const Int64  TicksPerMinute      =     60 * TicksPerSecond;
            static const Int64  TicksPerHour        =     60 * TicksPerMinute;
            static const Int64  TicksPerDay         =     24 * TicksPerHour;
        public:
            explicit TimeSpan ();
                     TimeSpan (const TimeSpan & Object);
            explicit TimeSpan (Int Days, Int Hours, Int Minutes, Int Seconds, Int Milliseconds);
            explicit TimeSpan (Int Days, Int Hours, Int Minutes, Int Seconds);
            explicit TimeSpan (Int Hours, Int Minutes, Int Seconds);
            explicit TimeSpan (Int Hours, Int Minutes);
            explicit TimeSpan (Int64 Ticks);
                    ~TimeSpan ();
        public:
            Int      Days            () const;
            Int      Hours           () const;
            Int      Minutes         () const;
            Int      Seconds         () const;
            Int      Milliseconds    () const;
            Int64    Ticks           () const;
            TimeSpan Add             (const TimeSpan & Object) const;
            TimeSpan AddDays         (Int Days               ) const;
            TimeSpan AddHours        (Int Hours              ) const;
            TimeSpan AddMinutes      (Int Minutes            ) const;
            TimeSpan AddSeconds      (Int Seconds            ) const;
            TimeSpan AddMilliseconds (Int Milliseconds       ) const;
            TimeSpan AddTicks        (Int64 Ticks            ) const;
        public:
                bool    operator <   (const TimeSpan & Object) const;
                bool    operator >   (const TimeSpan & Object) const;
                bool    operator <=  (const TimeSpan & Object) const;
                bool    operator >=  (const TimeSpan & Object) const;
                bool    operator ==  (const TimeSpan & Object) const;
                bool    operator !=  (const TimeSpan & Object) const;
            TimeSpan &  operator =   (const TimeSpan & Object);
            TimeSpan    operator +   (const TimeSpan & Object) const;
            TimeSpan    operator -   ()                        const;
            TimeSpan    operator -   (const TimeSpan & Object) const;
            TimeSpan &  operator +=  (const TimeSpan & Object);
            TimeSpan &  operator -=  (const TimeSpan & Object);
        private:
            Int64 mTicks;
    };


    /*
	The Time class represents the time in the interval [00:00:00, 23:59:60).
            Accuracy: Determined by TimeSpan :: TicksPerSecond
            The minimum time is 00:00:00
            The maximum time value is 23: 59: 59.xxxxxxx (the fractional part is defined by TimeSpan :: TicksPerSecond)
      
    */
    class Time
    {
        public:
            static const Int MinHour        =   0;
            static const Int MinMinute      =   0;
            static const Int MinSecond      =   0;
            static const Int MinMillisecond =   0;
            static const Int MaxHour        =  23;
            static const Int MaxMinute      =  59;
            static const Int MaxSecond      =  59;
            static const Int MaxMillisecond = 999;
        public:
            explicit Time ();
                     Time (const Time & Object);
            explicit Time (Int Hours, Int Minutes, Int Seconds, Int Milliseconds);
            explicit Time (Int Hours, Int Minutes, Int Seconds);
            explicit Time (Int Hours, Int Minutes);
            explicit Time (Int64 Ticks);
                    ~Time ();
        public:
               Int Hour        () const;
               Int Minute      () const;
               Int Second      () const;
               Int Millisecond () const;
             Int64 Ticks       () const;
        public:
            static Time     Now      ();   
            static Time     UtcNow   ();   
            static TimeSpan Timezone ();   
        public:
            Time Add             (const TimeSpan & Ts) const;
            Time AddHours        (Int Hours          ) const;  
            Time AddMinutes      (Int Minutes        ) const;
            Time AddSeconds      (Int Seconds        ) const;
            Time AddMilliseconds (Int Milliseconds   ) const;
            Time AddTicks        (Int64 Ticks        ) const;
        public:
                bool   operator <  (const Time & Object) const;
                bool   operator >  (const Time & Object) const;
                bool   operator <= (const Time & Object) const;
                bool   operator >= (const Time & Object) const;
                bool   operator == (const Time & Object) const;
                bool   operator != (const Time & Object) const;
                Time & operator =  (const Time & Object);
                Time   operator +  (const TimeSpan & Ts) const;
                Time   operator -  (const TimeSpan & Ts) const;
            TimeSpan   operator -  (const Time & Object) const;
                Time & operator += (const TimeSpan & Ts);
                Time & operator -= (const TimeSpan & Ts);
        private:
            Int64 mTicks;
    }; 
   
    /*
        
The Date class represents the date in the interval [01.01.0001, 31.12.9999].
            Accuracy: 1 day
            The minimum date is: 01.01.0001
            The maximum date value is: 31.12.9999
    */
    class Date
    {
        public:
            static const Int MinDay      =     1;
            static const Int MinMonth    =     1;
            static const Int MinYear     =     1;
            static const Int MaxDay      =    31;
            static const Int MaxMonth    =    12;
            static const Int MaxYear     =  9999;
        public:
            explicit Date ();
                     Date (const Date & Object);
            explicit Date (Int Day, Int Month, Int Year);
            explicit Date (Int64 Ticks);
                    ~Date () {};
        public:
              Int Day   () const;
              Int Month () const;
              Int Year  () const;
            Int64 Ticks () const;
             bool IsLeapYear () const;
        public:
            static Date Today ();   
        public:
            Date Add       (const TimeSpan & Ts) const;
            Date AddDays   (Int Days   ) const;
            Date AddMonths (Int Months ) const; 
            Date AddYears  (Int Years  ) const; 
            Date AddTicks  (Int64 Ticks) const;
        public:
                bool   operator <  (const Date & Object) const;
                bool   operator >  (const Date & Object) const;
                bool   operator <= (const Date & Object) const;
                bool   operator >= (const Date & Object) const;
                bool   operator == (const Date & Object) const;
                bool   operator != (const Date & Object) const;
                Date & operator =  (const Date & Object);
                Date   operator +  (const TimeSpan & Ts) const;
            TimeSpan   operator -  (const Date & Object) const;
                Date & operator += (const TimeSpan & Ts);
                Date & operator -= (const TimeSpan & Ts);
        private:
            Int64 mTicks;
    };
}
