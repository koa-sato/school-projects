// bankaccount.h - defines class BankAccount

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <iosfwd>

class BankAccount
{
public:

    void set(int dollars, int cents, double rate);
    //Postcondition: The account balance has been set to dollars.cents.
    //The interest rate has been set to rate percent.
    
    void set(int dollars, double rate);
    //Postcondition: The account balance has been set to dollars.cents.
    //The interest rate has been set to rate percent.
    
    void update( );
    //Postcondition: One year of simple interest has been
    //added to the account balance.
    
    double get_balance( );
    //Returns the current account balance.
    
    double get_rate( );
    //Returns the current account interest rate as a percentage.
    
    void output(std::ostream& outs);
    //Precondition: If outs is a file output stream, then
    //outs has already been connected to a file.
    //Postcondition: Account balance and interest rate have
    //been written to the stream outs.
    
private:

    double balance;
    double interest_rate;
    
    double fraction(double percent);
    //Converts a percentage to a fraction.
    // For example, fraction(50.3) returns 0.503.
};

#endif
