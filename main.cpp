#include <stdio.h>
#include <iostream>
#include <string> 
#include <vector>

using namespace std;

//Brak działających polskich znaków.

void Nominals(int number)
{
	string Units[] = {"", "jeden", "dwa", "trzy", "cztery", "piec", "szesc", "siedem", "osiem", "dziewiec"};
	string Teens[] = {"dziesiec", "jedenascie", "dwanascie", "trzynascie", "czternascie", "pietnascie", "szescnascie", "siedemnascie", "osiemnascie", "dziewietnascie"};
	string Tens[]  = {"dwadziescia", "trzydziesci", "czterdziesci", "piecdziesiat", "szescdziesiat", "siedemdziesiat", "osiemdziesiat", "dziewiecdziesiat"};
	string Hundreds[]  = {"sto", "dwiescie", "trzysta", "czterysta", "piecset", "szescset", "siedemset", "osiemset", "dziewiecset"};
	string Thousands[] = {"tysiąc", "tysiące", "tysięcy"};

	string Nominal[6];
	int digits[5];

	if (number > 999999 || number <= 0)
		cout << "Liczba spoza zakresu 6 cyfr, bądź jest zerem";

	else
	{
		for (int i = 0; i < 6; i++)
		{
			digits[i] = (number%10);
			number /= 10;
		}
	}
	

	for (int c = 0; c < 7; c++)
	{
		if (digits[c] == 0) Nominal[c] = ""; 	//Jezeli pusty, przeskakuje dalej
		else
		{
			while (c == 0)
			{
				for(int i = 1; i < 10; i++)
					if (digits[c] == i) Nominal[0] = Hundreds[i]; 
			}

			while (c == 1)
			{
				if(digits[c] == 1) 
				{
					for (int i = 1; i < 10; i++) 
						Nominal[1] = Teens[i];
				}
				
				else
				{	
					for(int i = 2; i < 10; i++)
						if (digits[c] == i) Nominal[1] = Tens[i];
				}
			}

			while (c == 2)
			{	
				if(digits[1] == 1) Nominal[2] = "";
				else
				{
					for(int i = 1; i < 10; i++)
						if (digits[c] == i) Nominal[2] = Units[i]; 
				}
			}			
			
			while (c == 3)
			{
				if (digits[2] != 0 && digits[1] != 0)
				{
					if (digits[2] == 1) Nominal[3] = Thousands[1];
					if (digits[2] > 1 && digits[2] < 5) Nominal[3] = Thousands[2];
					else Nominal[3] = Thousands[2]; 
				}

				else Nominal[3] = Thousands[2];
				
			}			

			while (c == 4)
			{
				for(int i = 1; i < 10; i++)
					if (digits[3] == i) Nominal[4] = Hundreds[i];
			}

			while (c == 5)
			{
				if(digits[4] == 1) 
				{
					for (int i = 1; i < 10; i++) 
						Nominal[5] = Teens[i];
				}
				
				else
				{	
					for(int i = 2; i < 10; i++)
						if (digits[4] == i) Nominal[5] = Tens[i];
				}
			}

			while (c == 6)
			{	
				if(digits[5] == 1) Nominal[6] = "";
				else
				{
					for(int i = 1; i < 10; i++)
						if (digits[5] == i) Nominal[6] = Units[i]; 
				}
			}	
		}
	}

	for (int i = 0; i < 6; i++)
		cout << Nominal[i] << " ";
}

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);

	Nominals(n);

	printf("Hello, World!\n");
}