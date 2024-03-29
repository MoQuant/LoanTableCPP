#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>

double var_int_rate(int lower_bound, int upper_bound)
{
    int random_number = lower_bound + rand() % (upper_bound - lower_bound + 1);
    return (double) random_number / 100.0;   
}

double int_payment(double balance, double rate, double t0, double t1)
{
    return balance*rate/(t1 - t0);
}

double loan_payment(double balance, double rate, double t0, double t1)
{
    double top = balance*rate;
    double bottom = 1.0 - pow(1 + rate, -(t1 - t0));
    return top/bottom;
}

int main() {
    // Seed the random number generator
    srand(time(nullptr));
    
    double balance = 500000.00;
    double maturity = 5.0;
    double period = 12.0;

    maturity = maturity * period;

    std::cout << "Balance\tInterest\tPayment" << std::endl;
    std::cout << balance << "\t-\t-" << std::endl;

    for(double t0 = 1; t0 < maturity; ++t0){
        double vr = var_int_rate(4, 20)/period;
        double ipmt = int_payment(balance, vr, t0, maturity);
        double pmt = loan_payment(balance, vr, t0, maturity);

        balance = balance + ipmt - pmt;
        std::cout << balance << "\t" << ipmt << "\t" << pmt << std::endl;
    }


    
    return 0;
}
