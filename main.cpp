#include <iostream>
#include<iomanip>
#include<fstream>

using namespace std;

class IncomeTax
{
    char Emp_name[30];
    int Emp_age;
    int Emp_ID;
    int Enter_ID;
    long salary,hra,ta,sa,lta,medbills;
public:
    long tot_Income;
    long sec80c=150000;
    long sec80d;
    long sec80tta;
    long deduct_income,sal_income,tot_salIncome;
    long edu_cess,tot_incometax;
    void getdata();
    void taxEstimation();
    void printdata();
    void file_write();
};
void IncomeTax::getdata()
{
     cout<<"Enter ID: ";
    cin>>Emp_ID;
    cout<<"Enter the name: ";
    cin>>Emp_name;
    cout<<"Enter the Age: ";
    cin>>Emp_age;
    cout<<"Checking your eligibilty age :"<<endl;
    cout<<"Enter Salary: ";
    cin>>salary;
    if(Emp_age>18 && Emp_age<=60)
    {
        if(salary>=250000)
        {
    cout<<"You are eligible go ahead : "<<endl;
    cout<<"----Allowances from your Income: "<<endl;
    cout<<"Input HRA: ";
    cin>>hra;
    cout<<"Input TA: ";
    cin>>ta;
    cout<<"Input SA: ";
    cin>>sa;
    cout<<"Input LTA: ";
    cin>>lta;
    cout<<"Input Medical Bills: ";
    cin>>medbills;
    cout<<"Input Sec80D: ";
    cin>>sec80d;
    cout<<"Input Sec80TTA: ";
    cin>>sec80tta;
}
    else
        {
            cout<<"You are not eligible : "<<endl;
        }
}
    else
    {
        cout<<"You are not eligible : "<<endl;
    }
}
void IncomeTax::taxEstimation()
{
    tot_Income=salary+hra+ta+sa+lta+medbills;
    deduct_income=tot_Income-(sec80c+sec80d+sec80tta);
    if(deduct_income>=500000 && deduct_income<=1000000)
    {
        sal_income=0.1*250000;
        tot_salIncome=0.2*(deduct_income-500000);
        edu_cess=0.03*(sal_income+tot_salIncome);
        tot_incometax=sal_income+tot_salIncome+edu_cess;
    }
    else if(deduct_income>=1000000)
    {
        sal_income=0.1*250000;
        long salIncome2=0.2*500000;
        tot_salIncome=0.3*(deduct_income-1000000);
        edu_cess=0.03*(sal_income+salIncome2+tot_salIncome);
        tot_incometax=sal_income+salIncome2+tot_salIncome+edu_cess;
    }
    else
    {
        sal_income=0.1*250000;
        tot_salIncome=0.1*(deduct_income-250000);
        long net_salIncome=sal_income+tot_salIncome;
        edu_cess=0.03*net_salIncome;
        tot_incometax=sal_income+tot_salIncome+edu_cess;
    }
}
void IncomeTax::printdata()
{
    cout<<"---------------------------------------------------------------------"<<endl;
    cout<<setw(20)<<"ID "<<setw(25)<<Emp_ID<<endl;
    cout<<setw(20)<<"Name "<<setw(25)<<Emp_name<<endl;
    cout<<setw(20)<<"Salary "<<setw(25)<<salary<<endl;
    cout<<setw(20)<<"HRA: "<<setw(25)<<hra<<endl;
    cout<<setw(37)<<"Transport Allowances: "<<setw(8)<<ta<<endl;
    cout<<setw(35)<<"Special Allowances: "<<setw(10)<<sa<<endl;
    cout<<setw(20)<<"LTA: "<<setw(25)<<lta<<endl;
    cout<<setw(28)<<"Medical Bills "<<setw(17)<<medbills<<endl;
    cout<<setw(45)<<"Total Income from your Salary: "<<tot_Income<<endl;
    cout<<setw(50)<<"*******Deduction Under Section 80 VIA*******"<<endl;
    cout<<setw(27)<<"Section 80C: "<<setw(20)<<sec80c<<endl;
    cout<<setw(27)<<"Section 80D: "<<setw(20)<<sec80d<<endl;
    cout<<setw(27)<<"Section 80TTA: "<<setw(20)<<sec80tta<<endl;
    cout<<setw(45)<<"Deducted Income from your salary: "<<deduct_income<<endl;
    cout<<setw(55)<<"*******Calculation of Income Tax in India******* "<<setw(55)<<endl;
    cout<<setw(45)<<"Total taxable income salary income: "<<tot_salIncome<<endl;
    cout<<setw(27)<<"Education Cess: "<<setw(20)<<edu_cess<<endl;
    cout<<setw(27)<<"Gross Total Income Tax: "<<setw(20)<<tot_incometax<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;
    cout<<endl;
}
void IncomeTax::file_write()
{
    ofstream outline;
    outline.open("taxData.doc",std::ios_base::app);
    cout<<"Writing to the created file: "<<endl;
    outline<<setw(20)<<"---------------------------------------------------------------------"<<endl;
    outline<<setw(20)<<"ID "<<setw(25)<<Emp_ID<<endl;
    outline<<setw(20)<<"Name "<<setw(25)<<Emp_name<<endl;
    outline<<setw(20)<<"Salary "<<setw(25)<<salary<<endl;
    outline<<setw(20)<<"HRA: "<<setw(25)<<hra<<endl;
    outline<<setw(37)<<"Transport Allowances: "<<setw(8)<<ta<<endl;
    outline<<setw(35)<<"Special Allowances: "<<setw(10)<<sa<<endl;
    outline<<setw(20)<<"LTA: "<<setw(25)<<lta<<endl;
    outline<<setw(28)<<"Medical Bills "<<setw(17)<<medbills<<endl;
    outline<<setw(45)<<"Total Income from your Salary: "<<tot_Income<<endl;
    outline<<setw(50)<<"*******Deduction Under Section 80 VIA*******"<<endl;
    outline<<setw(27)<<"Section 80C: "<<setw(20)<<sec80c<<endl;
    outline<<setw(27)<<"Section 80D: "<<setw(20)<<sec80d<<endl;
    outline<<setw(27)<<"Section 80TTA: "<<setw(20)<<sec80tta<<endl;
    outline<<setw(45)<<"Deducted Income from your salary: "<<deduct_income<<endl;
    outline<<setw(55)<<"*******Calculation of Income Tax in India******* "<<setw(55)<<endl;
    outline<<setw(45)<<"Total taxable income salary income: "<<tot_salIncome<<endl;
    outline<<setw(27)<<"Education Cess: "<<setw(20)<<edu_cess<<endl;
    outline<<setw(27)<<"Gross Total Income Tax: "<<setw(20)<<tot_incometax<<endl<<endl;
    outline<<setw(27)<<"---------------------------------------------------------------------"<<endl;
    outline<<endl;
}
int main()
{
    IncomeTax dat;
    dat.getdata();
    dat.taxEstimation();
    cout<<"Fetching the data from user....."<<endl;
    char disp;
     dat.printdata();
     dat.file_write();
    cout<<setw(35)<<"File written successfully"<<endl;
    return 0;
}
