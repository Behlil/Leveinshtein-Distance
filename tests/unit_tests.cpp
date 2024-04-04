#include <cassert>
#include <iostream>
#include <string>
#include "../include/header_files.hpp"

void test_levenshtein_distance() {
    // Test case 1: strings are identical
    

    // Test case 6: long strings with different characters
    assert(levenshtein_dp("abcdefghijklmnopqrstuvwxyz", "zyxwvutsrqponmlkjihgfedcba") == 26);

    // Test case 7: long strings with some characters matching
    assert(levenshtein_dp("abcdefghijklmnopqrstuvwxyz", "abcdeffghijklmnopqrstuuuuuuu") == 7);

    // Test case 8: one string is much longer than the other
    assert(levenshtein_dp("short", "this is a very long string") == 23);
   

    // Test case 9: strings are similar but with different case
    assert(levenshtein_dp("AbC", "aBc") == 3);

    // Test case 10: strings with special characters
    assert(levenshtein_dp("!@#$%^&*()_+", "0123456789") == 12);

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    test_levenshtein_distance();
    return 0;
}
