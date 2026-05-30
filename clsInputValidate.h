#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"


class clsInputValidate
{

public:

	static bool IsNumberBetween(short Number, short From, short To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(int Number , int From, int To)
	{
		return (Number >= From && Number <= To);

	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		//Date>=From && Date<=To
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)) 
			&&
			(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
		  )
		{
			return true;
		}
		
		//Date>=To && Date<=From
		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)) 
			&&
			(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
		   )
		{
			return true;
		}

		return false;
	}

	static short ReadShortNumber(string ErrorMessage="Invalid Number, Enter again\n")
	{
		short Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static short ReadShortNumberBetween(short From, short To, string ErrorMessage="Number is not within range, Enter again:\n")
	{
		short Number=ReadShortNumber();
		while (!IsNumberBetween(Number,From,To)) 
		{
			cout << ErrorMessage;
			Number = ReadShortNumber();
		}
		return Number;
	}

	static int ReadIntNumber(string ErrorMessage="Invalid Number, Enter again\n")
	{
		int Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage ;
		}
		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage="Number is not within range, Enter again:\n")
	{
		int Number=ReadIntNumber();

		while (!IsNumberBetween(Number,From,To)) 
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		double Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To)) {
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}

	static float ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		float Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static clsDate ReadDate(string ErrorMessage = "Invalid Date, Enter again\n")
	{
		clsDate Date;
		string sDate;
		while (true)
		{
			cin >> sDate;
			Date = clsDate(sDate);
			if (IsValideDate(Date))
				break;
			else
				cout << ErrorMessage;
		}
		return Date;
	}

	static clsDate ReadDateBetween(clsDate From, clsDate To, string ErrorMessage = "Date is not within range, Enter again:\n")
	{
		clsDate Date;
		while (true)
		{
			Date = ReadDate();
			if (IsDateBetween(Date, From, To))
				break;
			else
				cout << ErrorMessage;
		}
		return Date;
	}
	
	static string ReadString(string ErrorMessage = "Invalid String, Enter again\n")
	{
		string sInput;
		while (true)
		{
			getline(cin >> ws, sInput);
			if (sInput != "")
				break;
			else
				cout << ErrorMessage;
		}
		return sInput;
	}

	static char ReadChar(string ErrorMessage = "Invalid Character, Enter again\n")
	{
		char Ch;
		while (true)
		{
			cin >> Ch;
			if (Ch != ' ')
				break;
			else
				cout << ErrorMessage;
		}
		return Ch;
	}

	static bool ReadBool(string ErrorMessage = "Invalid Boolean Value, Enter again\n")
	{
		string sInput;
		while (true)
		{
			cin >> sInput;
			if (sInput == "true" || sInput == "1")
				return true;
			else if (sInput == "false" || sInput == "0")
				return false;
			else
				cout << ErrorMessage;
		}
	}

	static bool IsValideDate(clsDate Date)
	{
		return	clsDate::IsValidDate(Date);
	}
 

};