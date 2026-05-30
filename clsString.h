#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cctype>



using namespace std;

class clsString
{
private:
	string _Value;


public:

	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}

	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;

	static int Length(string S1)
	{
		return S1.length();
	}

	short Length()
	{
		return Length(_Value);
	}

	static short CountWords(string S1)
	{
		string delim = " "; // delimiter
		short Counter = 0;
		short pos = 0;
		string sWord; // define a string variable
		// use find() function to get the position of the delimiters
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word
			if (sWord != "")
			{
				Counter++;
			}
			//erase() until positon and move to next word.
			S1.erase(0, pos + delim.length());
		}
		if (S1 != "")
		{
			Counter++; // it counts the last word of the string.
		}
		return Counter;
	}

	short CountWords()
	{
		return CountWords(_Value);
	}

	static void PrintFirstLetterOfEachWord(string words)
	{
		bool IsfirstLetter = true;
		cout << "First letters of this string : \n";
		for (int i = 0; i < words.length(); i++)
		{
			if (words[i] != ' ' && IsfirstLetter)
			{
				cout << words[i] << endl;
			}
			IsfirstLetter = (words[i] == ' ' ? true : false);
		}
	}

	void PrintFirstLetterOfEachWord()
	{
		return PrintFirstLetterOfEachWord(_Value);
	}

	static string UpperFirstLetterOfEachWord(string words)
	{
		bool IsfirstLetter = true;
		cout << "your string with upper case : \n";
		for (int i = 0; i < words.length(); i++)
		{
			if (words[i] != ' ' && IsfirstLetter)
			{
				words[i] = toupper(words[i]);
			}
			IsfirstLetter = (words[i] == ' ' ? true : false);
		}
		return words;
	}

	void UpperFirstLetterOfEachWord()
	{
		_Value = UpperFirstLetterOfEachWord(_Value);
	}

	static string LowerFirstLetterOfEachWord(string words)
	{
		bool IsfirstLetter = true;
		cout << "your string with lower case : \n";
		for (int i = 0; i < words.length(); i++)
		{
			if (words[i] != ' ' && IsfirstLetter)
			{
				words[i] = tolower(words[i]);
			}
			IsfirstLetter = (words[i] == ' ' ? true : false);
		}
		return words;
	}

	void LowerFirstLetterOfEachWord()
	{
		_Value = LowerFirstLetterOfEachWord(_Value);
	}

	static string UpperCaseString(string words)
	{
		for (short i = 0; i < words.length(); i++)
		{
			words[i] = toupper(words[i]);
		}
		return words;
	}

	void UpperCaseString()
	{
		_Value = UpperCaseString(_Value);
	}

	static string LowerCaseString(string words)
	{
		for (short i = 0; i < words.length(); i++)
		{
			words[i] = tolower(words[i]);
		}
		return words;
	}

	void LowerCaseString()
	{
		_Value = LowerCaseString(_Value);
	}

	static int CountCapitalLetters(string words)
	{
		int counter = 0;
		for (int i = 0; i < words.length(); i++)
		{
			if (isupper(words[i]))
				counter++;
		}
		return counter;
	}

	int CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}

	static int CountSmallLetters(string words)
	{
		int counter = 0;
		for (int i = 0; i < words.length(); i++)
		{
			if (islower(words[i]))
				counter++;
		}
		return counter;
	}

	int CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}

	static int CountLetter(string words, char Ch)
	{
		int counter = 0;
		for (int i = 0; i < words.length(); i++)
			if (Ch == words[i])
				counter++;
		return counter;
	}

	int CountLetter(char Ch)
	{
		return CountLetter(_Value, Ch);
	}

	static int CountLetterBothCase(string words, char Ch, bool MatchCase = true)
	{
		int counter = 0;
		for (int i = 0; i < words.length(); i++)
		{
			if (MatchCase)
				if (Ch == words[i])
				{
					counter++;
				}
				else
				{
					if (tolower(words[i]) == tolower(Ch))
					{
						counter++;
					}
				}

		}
		return counter;
	}

	int CountLetterBothCase(char Ch, bool MatchCase = true)
	{
		return CountLetterBothCase(_Value, Ch, MatchCase);
	}

	static bool IsVowel(char letter)
	{
		letter = tolower(static_cast<unsigned char>(letter));
		return (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u');
	}

	static int CountVowelLetter(string words)
	{
		int counter = 0;
		for (int i = 0; i < words.length(); i++)
		{
			IsVowel(words[i]) ? counter++ : counter;
		}
		return counter;
	}

	int CountVowelLetter()
	{
		return CountVowelLetter(_Value);
	}

	static void PrintAllVowelInString(string words)
	{

		for (int i = 0; i < words.length(); i++)
		{
			if (IsVowel(words[i]))
				cout << setw(4) << words[i];
		}
	}

	void PrintAllVowelInString()
	{
		return PrintAllVowelInString(_Value);
	}

	static void PrintEachWordInString(string S1)
	{
		string delim = " "; // delimiter
		cout << "\nYour string wrords are: \n\n";
		short pos = 0;
		string sWord; // define a string variable
		// use find() function to get the position of the delimiters
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word
			if (sWord != "")
			{
				cout << sWord << endl;
			}
			S1.erase(0, pos + delim.length()); /* erase() until
			positon and move to next word. */
		}
		if (S1 != "")
		{
			cout << S1 << endl; // it print last word of the string.
		}
	}

	void PrintEachWordInString()
	{
		return PrintEachWordInString(_Value);
	}

	static vector<string> Split(string S1, string Delim)
	{
		vector<string> vString;
		short pos = 0;
		string sWord; // define a string variable
		// use find() function to get the position of the delimiters
		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word
			if (sWord != "")
			{
				vString.push_back(sWord);
			}
			S1.erase(0, pos + Delim.length()); /* erase() until
			positon and move to next word. */
		}
		if (S1 != "")
		{
			vString.push_back(S1); // it adds last word of the string.
		}
		return vString;
	}

	vector <string> Split(string Delim)
	{
		return Split(_Value, Delim);
	}

    static string TrimLeft(string words)
	{
		size_t pos = words.find_first_not_of(' ');
		if (pos == string::npos) return "";
		return words.substr(pos);
	}

   void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

    static string TrimRight(string words)
	{
		size_t pos = words.find_last_not_of(' ');
		if (pos == string::npos) return "";
		return words.substr(0, pos + 1);
	}

  void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	static string Trim(string words)
	{
		return TrimLeft(TrimRight(words));
	}

   void Trim()
	{
		_Value = Trim(_Value);
	}

    static string ReverseWordsInString(string S1)
	{
		vector<string> vString = Split(S1, " ");
		if (vString.empty()) return "";
		string S2;
		for (int i = (int)vString.size() - 1; i >= 0; --i)
		{
			S2 += vString[i];
			if (i > 0) S2 += ' ';
		}
		return S2;
	}

   void ReverseWordsInString()
	{
		_Value = ReverseWordsInString(_Value);
	}

    static string ReplaceWordInStringUsingBuildInFunction(string S1, string wordToReplaced, string ReplaceTo)
	{
		if (wordToReplaced.empty()) return S1; // avoid infinite loop
		size_t pos = S1.find(wordToReplaced);
		while (pos != string::npos)
		{
			S1.replace(pos, wordToReplaced.length(), ReplaceTo);
			pos = S1.find(wordToReplaced, pos + ReplaceTo.length());
		}
		return S1;
	}

 void ReplaceWordInStringUsingBuildInFunction(string wordToReplaced, string ReplaceTo)
	{
		_Value = ReplaceWordInStringUsingBuildInFunction(_Value, wordToReplaced, ReplaceTo);
	}

    static string RemovePunctuationsInString(string S1)
	{
		string result;
		result.reserve(S1.length());
		for (size_t i = 0; i < S1.length(); ++i)
		{
			unsigned char c = static_cast<unsigned char>(S1[i]);
			if (!ispunct(c)) result.push_back(S1[i]);
		}
		return result;
	}

	void RemovePunctuationsInString()
	{
		_Value = RemovePunctuationsInString(_Value);
	}





};

