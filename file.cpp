#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <omp.h>

using namespace std;

// Calculate Levenshtein distance with early stopping
size_t levenshtein_dp(const std::string& s1, const std::string& s2, size_t threshold) {
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

int main() {
    ifstream file("data_concatenated.csv");
    if (!file.is_open()) {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    string line;
    getline(file, line); // Skip header line

    vector<string> concatenated_cols;

    // Read concatenated_col values into a vector
    while (getline(file, line)) {
        stringstream ss(line);
        string ctm_cta_id, concatenated_col;
        getline(ss, ctm_cta_id, ',');
        getline(ss, concatenated_col, ',');
        concatenated_cols.push_back(concatenated_col);
    }

    file.close();

    // Open a new file to write the results
    ofstream output_file("distances_1.csv");
    if (!output_file.is_open()) {
        cout << "Failed to open the output file." << endl;
        return 1;
    }

    // Calculate Levenshtein distance for each pair of concatenated_col values in parallel
    output_file << "Pair,Levenshtein distance" << endl;



#pragma omp parallel for schedule(guided) num_threads(4)
    for (size_t i = 0; i < concatenated_cols.size(); ++i) {
        for (size_t j = i + 1; j < concatenated_cols.size(); ++j) {
            size_t distance = levenshtein_dp(concatenated_cols[i], concatenated_cols[j], 5);
            if (distance <= 5) {
#pragma omp critical
                {
                    output_file << "(" << i << "," << j << ")," << distance << endl;
                }
            }
            
            
        }
    }

    output_file.close();

    return 0;
}
