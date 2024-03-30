import pandas as pd
import random

pd.options.display.float_format = '${:.2f}'.format

# Variable Interest Rate Generator
def variable_interest_rate(low, high):
    return random.randint(low, high)/100

# Interest Payment Formula
def interest_payment(balance, rate):
    return balance*rate

# Loan Payment Formula
def loan_payment(balance, rate, t0, t1):
    top = balance * rate
    bottom = 1.0 - pow(1 + rate, -(t1 - t0))
    return top/bottom



# Loan Parameters
loan_balance = 1200000
maturity = 2
periods = 12

maturity = maturity * periods


# DataFrame Columns
columns = ['Balance','Interest','Payment']

# Loan Table
table = [[loan_balance, '-', '-']]

for i in range(1, maturity):
    vr = variable_interest_rate(5, 23)
    vr = vr / periods

    ipmt = interest_payment(loan_balance, vr)
    pmt = loan_payment(loan_balance, vr, i, maturity)

    loan_balance = loan_balance + ipmt - pmt

    table.append([loan_balance, ipmt, pmt])

df = pd.DataFrame(table, columns=columns)

df.to_csv('LoanTable.csv')











