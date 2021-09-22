//c++ program related to inheritance concept
#include <iostream>
using namespace std;
//to store the acccount related numbers
struct Accounts_list
{
    int acc_type;
    int acc_no;
    Accounts_list *link_ptr;
};
//accounts head variable taken as acc_head
Accounts_list *acc_head = NULL;
//to check whether there is an exitence of account or not
bool isExist(int acc_no)
{
    Accounts_list *temp_var = acc_head;
    while (temp_var != NULL)
    {
        if (temp_var->acc_no == acc_no)
        {
            return true;
        }
        //updating
        temp_var = temp_var->link_ptr;
    }
    return false;
}

class Account
{
public:
    int acc_no;
    //balance variable for initial balance
    double bal;
    //default constructor
    Account()
    {
        double bal;
        cout << "Enter the Initial Balance :-  ";
        cin >> bal;
        if (bal < 0)
        {
            this->bal = 0;
            cout << "-----Balance is taken as 0 as given balance is invalid-----" << endl;
        }
        else
        {
            //the entered balance
            this->bal = bal;
        }
        cout << "----------------Account created successfully-----------" << endl;
    }
    //account_number
    void create_accno()
    {
        int acc_no;
        Accounts_list *temp_var = acc_head;
        while (1)
        {
            cout << "Choose Your Account number between 100 and 999 :-  ";
            cin >> acc_no;
            //checking user input
            if (acc_no < 100 || acc_no > 999)
            {
                cout << "-------!please choose between 100 and 999!--------" << endl;
                continue;
            }
            //checking whether account number is available or not
            //isExist() checks
            if (isExist(acc_no))
            {
                cout << "---Account Number already exists-->please select another number---" << endl;
                continue;
            }
            //valid account number
            this->acc_no = acc_no;
            break;
        }
        cout << "----------------Account number created successfully---------------" << endl;
    }

    //balance calculation
    inline double get_bal()
    {
        return this->bal;
    }

    //to add money
    double credit(double amount)
    {
        if (amount < 0)
        {
            //checking whether entered amount is negative
            cout << "-----Please Enter valid Amount-----" << endl;
        }
        else
        {
            //adding credited money
            this->bal = this->bal + amount;
            cout << amount << " is added to account number " << this->acc_no << " successfully" << endl;
        }
        //return to present balance
        return this->bal;
    }

    //debit money function
    double debit(double amount)
    {
        if (amount < 0)
        {
            cout << "-----Please Enter valid Amount-----" << endl;
        }

        else if (amount > this->get_bal())
        {
            cout << "------------Balance is less than your Requirement----------" << endl;
        }
        else
        {
            this->bal -= amount;
            cout << amount << " is debited from account number " << this->acc_no << " successfully" << endl;
        }
        //finally returning to present balance
        return this->bal;
    }
};

class SavingsAccount : public Account
{
public:
    double int_rate;
    //default constructor for child saving account which also runs parent constructor and then the child initialising the interest rate
    SavingsAccount()
    {
        double int_rate;
        cout << "Please enter the interest rate of savings account:- ";
        cin >> int_rate;
        if (int_rate < 0)
        {
            this->int_rate = 3;
            cout << "------As interest rate is invalid int_rate is changed to 3 per month--------- " << endl;
        }
        else
        {
            //new interest rate gets updated
            this->int_rate = int_rate;
        }
        cout << "------------Savings account created successfully----------" << endl;
    }

    inline double cal_int()
    {
        //interest rate calculation
        return (this->bal * 12 * this->int_rate) / 100;
    }
};

class CheckingAccount : public Account
{
public:
    double fcpt;

    CheckingAccount()
    {
        double fcpt;
        cout << "Enter the transaction/fee charge of account :-  ";
        cin >> fcpt;
        if (fcpt < 0)
        {
            this->fcpt = 3;
            cout << "----------as the transaction fee is invalid it was made a 3 per transaction-------" << endl;
        }
        else
        {
            //transaction fee
            this->fcpt = fcpt;
        }
        cout << "--------------Checking account creation successful-------------------------" << endl;
    }

    double credit(double amount)
    {
        if (amount < 0)
            cout << "---------------------!Please enter correct amount!-----------------" << endl;
        else
        {
            this->bal = this->bal + amount;
            //transaction fee subtracts
            this->bal -= this->fcpt;
            cout << amount << " + " << this->fcpt << " is credited to " << this->acc_no << " successfully" << endl;
        }
        //returning to cur balance
        return this->bal;
    }
    double debit(double amount)
    {
        if (amount < 0)
            cout << "---------------------!Please enter correct amount!-----------------" << endl;
        else if (amount > this->bal)
            cout << "-----Required amount is higher than available,so we couldnt proceed transaction-----" << endl;
        else
        {
            //amount gets debited
            this->bal -= amount;
            this->bal -= this->fcpt;
            cout << amount << " + " << this->fcpt << " is debited from " << this->acc_no << " succesfully" << endl;
        }
        return this->bal;
    }
};

struct SavingsAccounts_list
{
    //saqvings account list
    SavingsAccount savingsAccount;
    SavingsAccounts_list *link_ptr;
};

struct CheckingAccounts_list
{
    //checking accounts list
    CheckingAccount checkingAccount;
    CheckingAccounts_list *link_ptr;
};
//head for savings and checking account
SavingsAccounts_list *savingsacc_head = NULL;
CheckingAccounts_list *checkingacc_head = NULL;

//upadting accounts list
void updAccounts_list(int acc_no, int acc_type)
{
    //cur - current one
    Accounts_list *cur = new Accounts_list;
    cur->acc_no = acc_no;
    cur->acc_type = acc_type;
    cur->link_ptr = NULL;
    if (acc_head == NULL)
        acc_head = cur;
    else
    {
        Accounts_list *temp_var = acc_head;
        while (temp_var->link_ptr != NULL)
            temp_var = temp_var->link_ptr;
        temp_var->link_ptr = cur;
    }
}

double updateSavingsAccounts_list()
{
    SavingsAccounts_list *cur = new SavingsAccounts_list;
    cur->savingsAccount.create_accno();
    cur->link_ptr = NULL;
    //head as null intialisation
    if (savingsacc_head == NULL)
        savingsacc_head = cur;
    else
    {
        SavingsAccounts_list *temp_var = savingsacc_head;
        while (temp_var->link_ptr != NULL)
            temp_var = temp_var->link_ptr;
        temp_var->link_ptr = cur;
    }
    return cur->savingsAccount.acc_no;
}

double updateCheckingAccounts_list()
{
    CheckingAccounts_list *cur = new CheckingAccounts_list;
    cur->checkingAccount.create_accno();
    cur->link_ptr = NULL;
    //initiailising head
    if (checkingacc_head == NULL)
        checkingacc_head = cur;
    else
    {
        CheckingAccounts_list *temp_var = checkingacc_head;
        while (temp_var->link_ptr != NULL)
            temp_var = temp_var->link_ptr;
        temp_var->link_ptr = cur;
    }
    return cur->checkingAccount.acc_no;
}

int checkacc_type(int acc_no)
{
    Accounts_list *temp_var = acc_head;
    while (temp_var != NULL)
    {
        if (temp_var->acc_no == acc_no)
            return temp_var->acc_type;
        temp_var = temp_var->link_ptr;
    }
    return temp_var->acc_type;
}

void savingAccountOperations(int acc_no, int flag)
{
    //saving account
    SavingsAccounts_list *temp_var = savingsacc_head;
    while (temp_var != NULL)
    {
        if (temp_var->savingsAccount.acc_no == acc_no)
            break;
        temp_var = temp_var->link_ptr;
    }
    switch (flag)
    {
    case 2:
    {
        double amount;
        cout << "Enter Amount to credit in account :-  ";
        cin >> amount;
        amount = temp_var->savingsAccount.credit(amount);
        cout << "Current balance is :- " << amount << endl;
    }
    break;
    case 3:
    {
        double amount;
        cout << "Enter amount to debit in acccount:- ";
        cin >> amount;
        amount = temp_var->savingsAccount.debit(amount);
        cout << "Current balance is :-  " << amount << endl;
    }
    break;
    case 4:
    {
        double int_rate;
        cout << "Enter New interest rate :-  ";
        cin >> int_rate;
        temp_var->savingsAccount.int_rate = int_rate;
        cout << "Interest changed to " << int_rate << " per month of your account" << endl;
    }
    break;
    case 5:
    {
        cout << "Interest for account number " << acc_no << " is " << temp_var->savingsAccount.cal_int() << " per year" << endl;
    }
    break;
    case 6:
    {
        cout << "Interest for account number " << acc_no << " is " << temp_var->savingsAccount.cal_int() << " Per year" << endl;
        double int_rate;
        cout << "Enter New interest rate:-  ";
        cin >> int_rate;
        temp_var->savingsAccount.int_rate = int_rate;
        cout << "Interest rate successfully changed to " << int_rate << " per one month" << endl;
    }
    break;
    }
}

void checkingAccountOperations(int acc_no, int flag)
{
    //checking account
    CheckingAccounts_list *temp_var = checkingacc_head;
    while (temp_var != NULL)
    {
        if (temp_var->checkingAccount.acc_no == acc_no)
            break;
        temp_var = temp_var->link_ptr;
    }
    switch (flag)
    {
    case 2:
    {
        double amount;
        cout << "Enter the amount to credit from account :-  ";
        cin >> amount;
        amount = temp_var->checkingAccount.credit(amount);
        cout << "Current balance is :-  " << amount << endl;
    }
    break;
    case 3:
    {
        double amount;
        cout << "Enter Amount to debit from account :-  ";
        cin >> amount;
        amount = temp_var->checkingAccount.debit(amount);
        cout << "Current balance is :-  " << amount << endl;
    }
    break;
    case 7:
    {
        double fcpt;
        cout << "Enter New interest rate :-  ";
        cin >> fcpt;
        temp_var->checkingAccount.fcpt = fcpt;
        cout << "fee charge per transaction successfully changed to " << fcpt << " successfully" << endl;
    }
    break;
    case 8:
    {
        cout << "Fee Charge of account_number " << acc_no << " is " << temp_var->checkingAccount.fcpt << " per one transaction" << endl;
    }
    break;
    }
}
//main function
int main()
{
    int option = 1;
    //variables related to account
    int acc_type = 1, acc_no;
    //all necessary operations
    cout << "-----------------Select Required option to perform the operation-------------------------" << endl;
    while (option != 10)
    {
        cout << "--------------------------------------------------------------------" << endl;
        cout << "   1 - TO Open New Account" << endl;
        cout << "   2 - To Credit Amount " << endl;
        cout << "   3 - TO Debit the Amount" << endl;
        cout << "   4 - To Update the Interest rate of Savings account" << endl;
        cout << "   5 - To Calculate Interest of savings account per year" << endl;
        cout << "   6 - To Calculate interest and change Interest of savings account" << endl;
        cout << "   7 - To Change fee amount for checking account" << endl;
        cout << "   8 - To print checking fee of account" << endl;
        cout << "   9 - To debit in checking account and to check bal" << endl;
        cout << "   10 - To Exit the program" << endl;
        cout << "----------------------------------------------------------------------" << endl;
        cout << "Enter your required option :-  ";
        cin >> option;
        //all ten cases are wriiten for required operation
        switch (option)
        {
        case 1:
        {
            while (1)
            {
                cout << "----------which Type of account-----------" << endl;
                cout << "   1 - Savings_Account" << endl;
                cout << "   2 - Checking_Account" << endl;
                cout << "Enter the option:- ";
                //acc_type variable is for this option
                cin >> acc_type;
                //checking valid option entry
                if (acc_type == 1 || acc_type == 2)
                    break;
                cout << "-----!Please Enter either option 1 or 2!-----" << endl;
            }
            if (acc_type == 1)
            {
                //for savings account
                updAccounts_list(updateSavingsAccounts_list(), 1);
            }
            else
            {
                //for checking account
                updAccounts_list(updateCheckingAccounts_list(), 2);
            }
        }
        break;
        case 2:
        {
            cout << "-----please enter correct details to credit the amount-----" << endl;
            cout << "Enter Account_Number :- " << endl;
            cin >> acc_no;
            //to check whether account exist or not
            if (!isExist(acc_no))
            {
                cout << "------!Entered account number doesnt exist!-------" << endl;
            }
            else
            //to credit the amount
            {
                acc_type = checkacc_type(acc_no);
                if (acc_type == 1)
                {
                    //to credit into savings account
                    savingAccountOperations(acc_no, option);
                }
                else
                {
                    //to credit into checking account
                    checkingAccountOperations(acc_no, option);
                }
            }
        }
        break;
        case 3:
        {
            cout << "-----please enter correct details to debit the amount-----" << endl;
            cout << "Enter Account_Number :- " << endl;
            cin >> acc_no;
            if (!isExist(acc_no))
            {
                cout << "------!Entered account number doesnt exist!-------" << endl;
            }
            else
            {
                acc_type = checkacc_type(acc_no);
                if (acc_type == 1)
                {
                    //to debit from savings account
                    savingAccountOperations(acc_no, option);
                }
                else
                    checkingAccountOperations(acc_no, option);
            }
        }
        break;
        case 4:
        {
            cout << "-----please enter correct details to change interest rate-----" << endl;
            cout << "Enter Account_Number :- " << endl;
            cin >> acc_no;
            if (!isExist(acc_no))
            {
                cout << "------!Entered account number doesnt exist!-------" << endl;
            }
            else if (checkacc_type(acc_no) == 1)
            {
                //to change interest rate in savings account
                savingAccountOperations(acc_no, option);
            }
            else
            {
                cout << "-----!It is not savings account!-----" << endl;
            }
        }
        break;
        case 5:
        {
            cout << "Enter Account_Number :- " << endl;
            cin >> acc_no;
            if (!isExist(acc_no))
            {
                cout << "------!Entered account number doesnt exist!-------" << endl;
            }
            else if (checkacc_type(acc_no) == 1)
            {
                //to calcuate interest per year
                savingAccountOperations(acc_no, option);
            }
            else
            {
                cout << "-----!It is not savings account!-----" << endl;
            }
        }
        break;
        case 6:
        {

            cout << "Enter Account_Number :- " << endl;
            cin >> acc_no;
            if (!isExist(acc_no))
            {
                cout << "------!Entered account number doesnt exist!-------" << endl;
            }
            else if (checkacc_type(acc_no) == 1)
            {
                //to update the interest
                savingAccountOperations(acc_no, option);
            }
            else
                cout << "-----!It is not savings account!-----" << endl;
        }
        break;
        case 7:
        {
            cout << "Enter Account_Number :- " << endl;
            cin >> acc_no;
            if (!isExist(acc_no))
                cout << "------!Entered account number doesnt exist!-------" << endl;
            else if (checkacc_type(acc_no) == 2)
            {
                //to change fee amount
                checkingAccountOperations(acc_no, option);
            }
            else
            {
                cout << "-----Its not a Checking account-----" << endl;
            }
        }
        break;
        case 8:
        {
            cout << " Enter Account_Number :-" << endl;
            cin >> acc_no;
            if (!isExist(acc_no))
            {
                cout << "------!Entered account number doesnt exist!-------" << endl;
            }
            else if (checkacc_type(acc_no) == 2)
            {
                checkingAccountOperations(acc_no, option);
            }
            else
                cout << "-----Its not a Checking account-----" << endl;
        }
        break;
        case 9:
        {
            cout << "Enter Account_Number :-" << endl;
            cin >> acc_no;
            if (!isExist(acc_no))
            {
                cout << "------!Entered account number doesnt exist!-------" << endl;
            }
            else if (checkacc_type(acc_no) == 2)
            {
                checkingAccountOperations(acc_no, 3);
            }
            else
            {
                cout << "-----Its not a Checking account-----" << endl;
            }
        }
        break;
        case 10:
            //program exit
            cout << "------------------------Program exited successfully----------------------" << endl;
            break;
        default:
            cout << "-------------!please select the option only shown above!-----------------" << endl;
            break;
        }
    }
    return 0;
}
