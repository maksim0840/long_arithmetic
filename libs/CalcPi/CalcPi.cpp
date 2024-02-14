#include "CalcPi.h"

namespace cpi {

    std::string calculate_pi(const unsigned n, const bool time_counter = false) {
        clock_t start_time = clock();
        
        std::string pi;
        pi.reserve(n);
        int boxes = (n) * 10 / 3 + 1;
        std::vector<int> reminders(boxes, 2);
        int heldDigits = 0;
        for (int i = 0; i < n; i++) {
            int carriedOver = 0;
            int sum = 0;
            for (int j = boxes - 1; j >= 0; j--) {
                reminders[j] *= 10;
                sum = reminders[j] + carriedOver;
                int quotient = sum / (j * 2 + 1);
                reminders[j] = sum % (j * 2 + 1);
                carriedOver = quotient * j;
            }
            reminders[0] = sum % 10;
            int q = sum / 10;
            if (q == 9) {
                heldDigits++;
            } else if (q == 10) {
                q = 0;
                for (int k = 1; k <= heldDigits; k++) {
                    int replaced = pi[i - k] - '0';
                    if (replaced == 9) {
                        replaced = 0;
                    } else {
                        replaced++;
                    }
                    pi[i - k] = replaced + '0';
                }
                heldDigits = 1;
            } else {
                heldDigits = 1;
            }
            pi.push_back(q + '0');
        }
        if (pi.length() >= 2) {
            pi.insert(1, ".");
        }


        clock_t end_time = clock();

        if (time_counter == true) {
            std::cout << "Calculated " << n << " digits in " << end_time - start_time <<"ms:\n";
        }

        return pi;
    }

}