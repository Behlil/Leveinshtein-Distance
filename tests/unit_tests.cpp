#include <iostream>
#include <cassert>

size_t levenshtein_dp(const std::string& s1, const std::string& s2, size_t threshold);

void test_levenshtein_distance() {
    // Test case 1: strings are identical
    assert(levenshtein_dp("abc", "abc", 1) == 0);

    // Test case 2: strings have a Levenshtein distance within threshold
    assert(levenshtein_dp("kitten", "sitting", 3) == 3);

    // Test case 3: strings have a Levenshtein distance exceeding threshold
    assert(levenshtein_dp("kitten", "sitting", 2) == 10);

    // Test case 4: empty strings
    assert(levenshtein_dp("", "", 0) == 0);

    // Test case 5: one empty string
    assert(levenshtein_dp("abc", "", 1) == 3);

    // Test case 6: threshold is 0
    assert(levenshtein_dp("abc", "xyz", 0) == 10);

    // Test case 7: threshold is greater than the maximum possible distance
    assert(levenshtein_dp("abc", "xyz", 10) == 3);

    // Test case 8: threshold is less than the minimum possible distance
    assert(levenshtein_dp("abc", "xyz", 1) == 10);

    // Test case 9: strings have different lengths and distance is within threshold
    assert(levenshtein_dp("book", "back", 2) == 2);

    // Test case 10: strings have different lengths and distance exceeds threshold
    assert(levenshtein_dp("book", "back", 1) == 10);
}

int main() {
    test_levenshtein_distance();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
