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
		day = 60 + day;
		break;
	case 4:
		day = 91 + day;
		break;
	case 5:
		day = 121 + day;
		break;
	case 6:
		day = 152 + day;
		break;
	case 7:
		day = 182 + day;
		break;
	case 8:
		day = 213 + day;
		break;
	case 9:
		day = 244 + day;
		break;
	case 10:
		day = 274 + day;
		break;
	case 11:
		day = 305 + day;
		break;
	case 12:
		day = 335 + day;
		break;
	default:
		break;
	}
	return (day);
}

