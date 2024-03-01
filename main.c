/*****************************************************************************************************************************************
 -This programme stores a temperature value (1. Fahrenheit, 2. Celcius, 3. Kelvin) and convert it to another type of temperature format.
 Also acknowlage the user weather the temperatur is too hot(>30 Celcius) or too cold(<18 Celcius)-

 Author: Mücahid Emre KARABAYIR
 Date: 01.03.2024
*****************************************************************************************************************************************/

#include <stdio.h>

int tempTypeCoice();
int convTypeCoice();
float valueInp();
float Fahrenheit_to_Celcius(float fahr);
float Fahrenheit_to_Kelvin(float fahr);
float Celcius_to_Fahrenheit(float celc);
float Celcius_to_Kelvin(float celc);
float Kelvin_to_Fahrenheit(float kel);
float Kelvin_to_Celcius(float kel);
void Hot_or_Cold(float temp);
int isAlpha(char ch);

int main() {
    int choice = tempTypeCoice();
    int convType = convTypeCoice();
    float toCelcius;
    float tempInput, convResult;
    char inpChar, convChar;

    tempInput = valueInp();
    switch(choice) {
        //From Fahrenheit
        case 1:
            inpChar = 'F';
            toCelcius = Fahrenheit_to_Celcius(tempInput);
            switch (convType) {
                //To Fahrenheit
                case 1:
                    convResult = tempInput;
                    convChar = inpChar;
                    break;

                //To Celcius
                case 2:
                    convResult = Fahrenheit_to_Celcius(tempInput);
                    convChar = 'C';
                    break;

                //To Kelvin
                case 3:
                    convResult = Fahrenheit_to_Kelvin(tempInput);
                    convChar = 'K';
                    break;
            }
        break;
        //From Celcius
        case 2:
            inpChar = 'C';
            toCelcius = tempInput;
            switch (convType) {
                //To Fahrenheit
                case 1:
                    convResult = Celcius_to_Fahrenheit(tempInput);
                    convChar = 'F';

                    break;
                //To Celcius
                case 2:
                    convResult = tempInput;
                    convChar = inpChar;
                    break;
                  
                //To Kelvin
                case 3:
                    convResult = Celcius_to_Kelvin(tempInput);
                    convChar = 'K';
            }
        break;
        //From Kelvin
        case 3:
            inpChar = 'C';
            toCelcius = Kelvin_to_Celcius(tempInput);
            switch (convType) {
                //To Fahrenheit
                case 1:
                    convResult = Kelvin_to_Fahrenheit(tempInput);
                    convChar = 'F';

                    break;
                //To Celcius
                case 2:
                    convResult = Kelvin_to_Celcius(tempInput);
                    convChar = 'C';
                    break;
                  
                //To Kelvin
                case 3:
                    convResult = tempInput;
                    convChar = inpChar;
                    break;
            }
        break;
    }
    printf("\n (%.3f %c) = (%.3f %c)", tempInput, inpChar,convResult, convChar);
    Hot_or_Cold(toCelcius);
    
    char charr;
    printf("\n\nPress a key to finish: ");
    scanf("%c", charr);

    return 0;
}

int tempTypeCoice() {
    int choice;
    do {
        printf("\nCoose the index of the type of a temperature that you want to convert:\n"
            "1. From Fahrenheit,\n"
            "2. From Celcius,\n"
            "3. From Kelvin,\n"
            "Enter Your Choice: ");
        scanf("%d", &choice);
        if(1 <= choice && choice <= 3){
            break;
        }
        else{
            printf("\n\n*****Invalid Input Try Again Please!!!*****\n\n");
        }
    }while(1);

    return choice;
}

int convTypeCoice() {
    int choice;
    do {
        printf("\nCoose the index of the type of a temperature that you want to convert:\n"
            "1. To Fahrenheit,\n"
            "2. To Celcius,\n"
            "3. To Kelvin,\n"
            "Enter Your Choice: ");
        scanf("%d", &choice);
        if(1 <= choice && choice <= 3){
            break;
        }
        else{
            printf("\n\n*****Invalid Input Try Again Please!!!*****\n\n");
        }
    }while(1);

    return choice;
}

float valueInp() {
    float value;
    printf("\nEnter the value: ");
    scanf("%f", &value);
    
    return value;
}

float Fahrenheit_to_Celcius(float fahr) {;
    return (((fahr-32)*5)/9);
}
float Fahrenheit_to_Kelvin(float fahr) {
    return (((fahr-32)*5)/9 + 273.15); 
}
float Celcius_to_Fahrenheit(float celc) {
    return ((celc*9)/5 +32); 
}
float Celcius_to_Kelvin(float celc) {
    return (celc + 273.15); 
}
float Kelvin_to_Fahrenheit(float kel) {
    return Celcius_to_Fahrenheit(kel - 273.15); 
}
float Kelvin_to_Celcius(float kel) {
    return (kel - 273.15); 
}
void Hot_or_Cold(float temp) {
    if(temp < 18) {
        printf("\nToo Cold!");
    }
    else if(temp > 30) {
        printf("\nToo Hot!");
    }
}
int isAlpha(char ch) {
    if(ch >= 97 && ch <= 127){
        return 1;
    }
    else {
        return 0;
    }
}