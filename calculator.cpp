//Tim
//Feb 21 2018
//Code for a simple calculator
//uses <sstream> library for data validation:
//Reads input into string stream and out as corresponding datatype

#include <iostream>
#include <sstream>
using namespace std;

int main()
{
   //init
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   //data validation vars
   const int divZero = 0;  //cannot divide by zero
   const int exitInt = 0;  //if num1 && num2 == 0, exit program
   const int modZero = 0;  //if num1 % num2 = 0, ignore

   bool opErrFlag    = 0;  //repeat while flag is false
   char exitChar1    = 'q';//program exit character
   char exitChar2    = 'Q';//program exit character
   istringstream instream; //input stream variable

   //input vars
   int    num1, num2;      //input integers
   char   mathOperator;    //Mathematical Operator
   string equation;        //Read input as string

   //output vars
   int  result;            //holds mathmatical result
   int  divResult;         //holds mod '%' value

   //inputs
   do
   {
      cout << "\nEnter an equation or (i.e. 1 + 2)"
           << "\nTo exit, enter '0x0' or [Q]uit: ";
      getline (cin, equation);

      if (equation.at(0)==exitChar1||equation.at(0)==exitChar2)
      {
         cout << "\n***Exiting Program***" << endl;
         opErrFlag = 1;
         break;
      }
      else
      {
         instream.clear();
         instream.str(equation);
         instream >> num1 >> mathOperator >> num2;
      }

      //processing
      switch(mathOperator)
      {  
         //DIVISION
         case '/':
            
            //cannot divide by zero
            if (num2 == divZero)
            {
               cout << "\nInput Error: Cannot divide by zero"
                    << "\n                  Please try again:"
                    << endl;

               break;
            }
            else
            {
               //processing
               result    = num1 / num2;
               divResult = num1 % num2;
            
               if (divResult > modZero)
               {
                  //ouput
                  cout << "The result of "    << num1 << " "
                       << mathOperator << " " << num2 << " is "
                       << result       << " remainder "
                       << divResult    << endl;
               }
               else
               {
                  cout << "The result of "    << num1 << " "
                       << mathOperator << " " << num2 << " is "
                       << result       << endl;
               }
            }
         break;
         
         //MULTIPLICATION
         case '*':
         case 'x':
         case 'X':
            //exit sequence
            if (num1 == exitInt && num2 == exitInt)
            {
               cout << "\nExiting Program" << endl;
               opErrFlag = 1;
               break;
            }
            else
            {  //some processing
               result = num1 * num2;

               //output
               cout << "The result of "     << num1 << " "
                    << mathOperator << " "  << num2 << " is "
                    << result       << endl;
            }
         break;
         
         //ADDITION
         case '+':
            //processing
            result = num1 + num2;

            //outputs
            cout << "The result of "    << num1 << " "
                 << mathOperator << " " << num2 << " is "
                 << result       << endl;
         break;
         
         //SUBTRACTION
         case '-':
            //processing
            result = num1 - num2;
            
            //output
            cout << "The result of "    << num1 << " "
                 << mathOperator << " " << num2 << " is "
                 << result       << endl;
         break;

         default:
            cout << "Error: Invalid Input" << endl;
         break;
      }

   } while (opErrFlag == 0);
   
   //output
   cout << "\nThanks for using this calculator! Goodbye." << endl;

   return 0;
}
