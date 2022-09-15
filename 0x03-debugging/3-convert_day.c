#include "main.h"

/**
* convert_day - converts day of month to day of year, without accounting
* for leap year
* @month: month in number format
* @day: day of month
* Return: day of year
*/

int convert_day(int month, int day)
{
	switch (month)
	{
	case 2:
		day = 31 + day;
		break;
	case 3:
		day = 59 + day;
		break;
	case 4:
		day = 90 + day;
		break;
	case 5:
		day = 120 + day;
		break;
	case 6:
		day = 151 + day;
		break;
	case 7:
		day = 181 + day;
		break;
	case 8:
		day = 212 + day;
		break;
	case 9:
		day = 243 + day;
		break;
	case 10:
		day = 273 + day;
		break;
	case 11:
		day = 304 + day;
		break;
	case 12:
		day = 334 + day;
		break;
	default:
		break;
	}
	return (day);
}

