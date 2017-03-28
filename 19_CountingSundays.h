#pragma once

/*You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty - one,
Saving February alone,
Which has twenty - eight, rain or shine.
And on leap years, twenty - nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century(1 Jan 1901 to 31 Dec 2000) ?*/

void sundays_in_20th_century() {

	int sundays_first_of_the_month = 0;


	int curr_sunday = 7;
	int start_year = 1900, end_year = 2000;

	int days = 31;

	for (int curr_year = start_year; curr_year <= end_year; ++curr_year) {
		for (int i = 1; i <= 12; ++i) {

			days = 31;

			switch (i){
			case 9: case 4: case 6: case 11:
				days = 30;
				break;
			case 2:
				bool leap = curr_year % 4 == 0;
				if (curr_year % 100 == 0)
					leap = curr_year % 400 == 0;

				days = leap ? 29 : 28;
				break;
			}

			while (curr_sunday < days)
				curr_sunday += 7;

			if (curr_sunday == days + 1) {
				if (curr_year != 1900) ++sundays_first_of_the_month;
				std::cout << "year " << curr_year << "; month " << i << ";\n";
				curr_sunday = 1;
			}
			else {
				curr_sunday -= days;
			}
		}
	}

	//173, but right value is 171?
	std::cout << "sundays_first_of_the_month = " << sundays_first_of_the_month << std::endl;
}