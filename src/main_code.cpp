#include <string>
#include <vector>
#include <algorithm>
#include <cassert>


size_t levenshtein_dp(const std::string& s1, const std::string& s2) {
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

        prev_row = std::move(curr_row);
    }

    return prev_row.back();
}
