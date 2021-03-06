/*
This program was made for school purposes and contain some exercices that I have made from my exchange year
--- Coded by Giorgio Bella 17/05/19 License GNU 3.0 ---

 The program is coded based on the oop rules
*/
//including libs
#include "iostream"
#include "math.h"

using namespace std;

class bank{
   private:
     typedef double rate;
     long investiment, TotInv;
     double percent;
     int compaunding;

  public:
    //cunstructor
     bank( double TotInvestiment, double RatePercent,int AnnualCompounding){
       investiment = TotInvestiment;
       percent = RatePercent;
       compaunding = AnnualCompounding;
     }
     //methods
     long CalculateInvestiment(){
       //Decleration of loacl vars
       double decimalP;
       double TotInvSum;
       float  exp;

       //Calculate TotInv
       decimalP = percent/100;
       TotInvSum = decimalP/compaunding;
       TotInvSum = TotInvSum + 1;
       exp =  compaunding * percent+1; //Add one to the exponet
       TotInvSum = pow(TotInvSum,exp);
       TotInv = investiment * TotInvSum;

       return TotInv;
     }

     double CalculateTrueRate(){
       rate AnnualRate;
       double exp;

       AnnualRate = TotInv/investiment;
       exp = 1/percent;
       AnnualRate = pow(AnnualRate,exp);
       AnnualRate = AnnualRate -1;
     }

     ~bank (){
       cout << "Ended" << '\n';
     }
};


int main() {
  double TotInvestiment, RatePercent;
  int  AnnualCompounding;


  cout << "Insert the total of your investment" << '\n';
  cin >> TotInvestiment;
  cout << "Insert the rate in percent" << '\n';
  cin >> RatePercent;
  cout << "Insert Annual Compound" << '\n';
  cin >> AnnualCompounding;
  bank Inve1(TotInvestiment,RatePercent,AnnualCompounding);
  cout << "Final investment is: " << Inve1.CalculateInvestiment() << '\n';
  Inve1.~bank();
  return 0;
}
