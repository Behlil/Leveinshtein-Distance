#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <omp.h>

using namespace std;

// Calculate Levenshtein distance with early stopping
size_t  levenshtein_dp(const std::string& s1, const std::string& s2, size_t threshold){
    const size_t n = s1.size();
    const size_t m = s2.size();

    // Initialize the previous row
    std::vector<size_t> prev_row(m + 1);
    for (size_t j = 0; j <= m; ++j)
        prev_row[j] = j;

    for (size_t i = 1; i <= n; ++i) {
        // Initialize the current row with the deletion cost
        std::vector<size_t> curr_row(1, i);

        for (size_t j = 1; j <= m; ++j) {
            size_t cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            curr_row.push_back(std::min({ curr_row.back() + 1, prev_row[j] + 1, prev_row[j - 1] + cost }));
        }

        // Check if the minimum distance exceeds the threshold
        size_t min_dist = *std::min_element(curr_row.begin(), curr_row.end());
        if (min_dist > threshold)
            return 10;  // Set distance to 10 if it exceeds the threshold

        prev_row = std::move(curr_row);
    }

    return prev_row.back();
}

