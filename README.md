# Levenshtein Distance Implementation
This repository contains an implementation of the Levenshtein Distance algorithm in C++. 

## About Levenshtein Distance
Levenshtein Distance, also known as Edit Distance, is a measure of similarity between two strings. It is calculated as the minimum number of single-character edits (insertions, deletions or substitutions) required to change one word into the other.
<!-- add the algorithm of calculation -->
## Algorithm

The Levenshtein Distance algorithm with early stopping is as follows:

1. Initialize a two-dimensional array `d` of size `n+1` by `m+1`, where `n` and `m` are the lengths of the two input strings. Set `d[i][0] = i` and `d[0][j] = j` for all `i` and `j`.

2. For each character `i` in the first string and each character `j` in the second string:
    - If the characters are the same, the cost is `0`. If they are different, the cost is `1`.
    - Set `d[i][j]` to the minimum of:
      - `d[i-1][j] + 1` (deletion)
      - `d[i][j-1] + 1` (insertion)
      - `d[i-1][j-1] + cost` (substitution)

3. If the current minimum distance exceeds a given threshold, stop the algorithm and return the threshold. This is the early stopping condition.

4. After all characters have been processed, `d[n][m]` will hold the Levenshtein distance between the two strings.

Please note that this algorithm assumes that the strings are indexed from `1` to `n` or `m`. In most programming languages, strings are indexed from `0`, so you may need to adjust the indices accordingly.

## Implementation Details
The implementation is done in C++ for efficiency and performance. It uses dynamic programming to solve the problem in O(nm) time where n and m are the lengths of the two input strings.

## How to Use
1. Clone the repository to your local machine.
2. Navigate to the directory containing the source code.
3. Compile the code using a C++ compiler.
4. Run the executable, providing two strings as arguments.

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License
[MIT](https://choosealicense.com/licenses/mit/)