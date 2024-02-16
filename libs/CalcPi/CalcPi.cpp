#include "CalcPi.h"

namespace cpi {

    std::string calculate_pi(const unsigned n, const bool time_counter) {
        clock_t start_time = clock();

        int len = n * 10 / 3 + 1;
        std::vector<int> reminders(len, 2);
        std::string pi;
        pi.reserve(n + 1);
        int held_predigits_count = 0;

        for (unsigned i = 0; i < n; i++) {
            int carried = 0;
            int sum = 0;

            for (int j = len - 1; j >= 0; j--) {
                sum = reminders[j] * 10 + carried;
                int num = j;
                int den = j * 2 + 1;
                int quotient = sum / (j * 2 + 1);
                if (j > 0) {
                    reminders[j] = sum % den;
                }
                else {
                    reminders[j] = sum % 10;
                }
                carried = quotient * num;
            }

            int predigit = sum / 10;

            if (predigit == 9) {
                held_predigits_count++;
            }
            else if (predigit == 10) {
                predigit = 0;
                for (int k = 1; k <= held_predigits_count; k++) {
                    int replaced = pi[i - k] - '0';
                    if (replaced == 9) {
                        replaced = 0;
                    }
                    else {
                        replaced++;
                    }
                    pi[i - k] = replaced + '0';
                }
                held_predigits_count = 1;
            }
            else {
                held_predigits_count = 1;
            }
            

            pi.push_back(predigit + '0');
            if (i == 0 && n > 1) {
                pi.push_back('.');
            }
        }

        clock_t end_time = clock();

        if (time_counter == true) {
            std::cout << "Calculated " << n << " digits in " << end_time - start_time <<"ms:\n";
        }

        return pi;
    }
}