#include <stdio.h>
#include <math.h>

// CONSTS
const int INITIAL_AMOUNT = 1000000 * 100; // FIRST INPUT IN BANK (KOPECK) BOB AND ALICE
const int FIRST_PAYMENT = 1000000 * 100; // BOB'S INPUT IN FLAT (KOPECK)
const int RENT_PRICE = 20000000 * 100; // FLAT'S PRICE (KOPECK)
const int MONTH_PAY = 126408 * 100; // BOB'S MONTHLY WASTE ON FLAT (KOPECK)
const int PERIOD = 30; // YEARS
const int INFLATION_PERCENT = 5;

struct Client {
    unsigned long long int bank_account; // KOPECK
    int month_cash; // CASH THAT IS AVAILABLE UNTIL END OF THE MONTH (KOPECK)
    int salary; // KOPECK
    int waste; // MONTHLY WASTE (KOPECK)
    int year_percent; // BANK'S PERCENT
};

struct Client Alice;
struct Client Bob;

void init_bob(struct Client* init_Bob);

void init_alice(struct Client* init_Alice);

void month_event(int month);

void add_bank_percents(struct Client* client);

void add_salary(struct Client* client);

void remove_wastes(struct Client* client);

void remove_month_payment(struct Client* client);

void deposit(struct Client* client);

void inflation(struct Client* client);

void print_out();

void simulation();

void init_bob(struct Client* init_Bob) {
    // BOB IPOTEKA
    init_Bob->bank_account = INITIAL_AMOUNT - FIRST_PAYMENT;
    init_Bob->month_cash = 0;
    init_Bob->salary = 200000 * 100;
    init_Bob->waste = 50000 * 100;
    init_Bob->year_percent = 11;
}

void init_alice(struct Client* init_Alice) {
    // ALICE SAVINGS
    init_Alice->bank_account = INITIAL_AMOUNT;
    init_Alice->month_cash = 0;
    init_Alice->salary = 200000 * 100;
    init_Alice->waste = 100000 * 100;
    init_Alice->year_percent = 11;
}

void month_event(int month) {
    // SALARY INDEXATION
    if (month > 12) month -= 12;
    if (month == 12) {
        Bob.salary += (int)((double)Bob.salary * (INFLATION_PERCENT / 100.0));
        Alice.salary += (int)((double)Alice.salary * (INFLATION_PERCENT / 100.0));
        // printf("Bob salary = %0.2d kop \n", Bob.salary);
        // printf("Alice salary = %0.2d kop \n", Alice.salary);
    }

}

void add_bank_percents(struct Client* client) {
    double month_percent = client->year_percent * 0.01 / 12;
    client->month_cash += (unsigned int)((double)client->bank_account * month_percent);
}

void add_salary(struct Client* client) {
    client->month_cash += client->salary;
}

void remove_wastes(struct Client* client) {

    client->month_cash -= client->waste;

}

void remove_month_payment(struct Client* client) {
    client->month_cash -= MONTH_PAY;
}

void deposit(struct Client* client) {
    //printf("Bob month cash = %0.2d kop \n", Bob.month_cash);
    client->bank_account += client->month_cash;
    client->month_cash = 0;
}

void inflation(struct Client* client) {
    client->waste += (int)((double)client->waste * (INFLATION_PERCENT / 12.0 * 0.01));
}

void print_out() {

    Bob.bank_account += (unsigned long long int)(RENT_PRICE * pow(1 + INFLATION_PERCENT / 100.0, PERIOD));
    unsigned long long int Bob_rubles = Bob.bank_account / 100;
    unsigned long long int Alice_rubles = Alice.bank_account / 100;
    printf("Bob: %0.2llu Rub %0.2d Kop \n", Bob_rubles, (int)(Bob.bank_account % 100));
    printf("Alice: %0.2llu Rub %0.2d Kop\n", Alice_rubles, (int)(Alice.bank_account % 100));
    if (Bob.bank_account > Alice.bank_account) printf("Bob is richer\n");
    else printf("Alice is richer\n");

}


void simulation() {
    int START_MONTH = 9;
    // YEAR CYCLE STARTS
    for (int year = 0; year < PERIOD; year++) {
        for (int mon = 0; mon < 12; mon++) {
            // BOB
            //printf("Bob salary = %0.2d rub \n", Bob.salary / 100);
            //printf("Bob wastes = %0.2d rub \n", Bob.waste / 100);
            add_bank_percents(&Bob);
            add_salary(&Bob);
            remove_month_payment(&Bob);
            remove_wastes(&Bob);
            //printf("Bob month cash = %0.2d rub \n", Bob.month_cash / 100);
            deposit(&Bob);
            inflation(&Bob);

            // ALICE
            add_bank_percents(&Alice);
            add_salary(&Alice);
            remove_wastes(&Alice);
            deposit(&Alice);
            inflation(&Alice);
            // SOMETHING CHANGED
            month_event(mon + START_MONTH);
        }

    }
    print_out();
}


int main() {

    init_bob(&Bob);
    init_alice(&Alice);
    simulation();
    return 0;
}
