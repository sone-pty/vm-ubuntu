#pragma once

#include <algorithm>
#include <string>

struct tm;

namespace sone
{
    namespace utils
    {
        class Date
        {
        public:
            struct YearMonthDay
            {
                int year;  // [1900..2500]
                int month; // [1..12]
                int day;   // [1..31]
            };

            static const int kDaysPerWeek = 7;
            static const int kJulianDayOf1970_01_01;

            ///
            /// Constucts an invalid Date.
            ///
            Date()
                : julianDayNumber_(0)
            {
            }

            ///
            /// Constucts a yyyy-mm-dd Date.
            ///
            /// 1 <= month <= 12
            Date(int year, int month, int day);

            ///
            /// Constucts a Date from Julian Day Number.
            ///
            explicit Date(int julianDayNum)
                : julianDayNumber_(julianDayNum)
            {
            }

            ///
            /// Constucts a Date from struct tm
            ///
            explicit Date(const struct tm &);

            // default copy/assignment/dtor are Okay

            void swap(Date &that)
            {
                std::swap(julianDayNumber_, that.julianDayNumber_);
            }

            bool valid() const { return julianDayNumber_ > 0; }

            ///
            /// Converts to yyyy-mm-dd format.
            ///
            std::string toIsoString() const;

            struct YearMonthDay yearMonthDay() const;

            int year() const
            {
                return yearMonthDay().year;
            }

            int month() const
            {
                return yearMonthDay().month;
            }

            int day() const
            {
                return yearMonthDay().day;
            }

            // [0, 1, ..., 6] => [Sunday, Monday, ..., Saturday ]
            int weekDay() const
            {
                return (julianDayNumber_ + 1) % kDaysPerWeek;
            }

            int julianDayNumber() const { return julianDayNumber_; }

        private:
            int julianDayNumber_;
        };

        inline bool operator<(Date x, Date y)
        {
            return x.julianDayNumber() < y.julianDayNumber();
        }

        inline bool operator==(Date x, Date y)
        {
            return x.julianDayNumber() == y.julianDayNumber();
        }
    }
}