# embeddedTest

The uploaded code in functions.h implements the following three functions:
  - getFirstRepeatedNumber()
  - getFile()
  - getMinNumberOfPermutations()

# getFirstRepeatedNumber()
The getFirstRepeatedNumber() function returns the first repeated number in the given vectors and it can be either a positive or negative one. Moreover, if there is not a repeated number between the vectors or some vector is empty, a -1 is returned.

# getFile()
The getFile() function returns the name of the file with the extension included just in case the file that meets the requirements (file owner is admin, file is an executable and file size lower than 14*2^20) is found. If either the file is not found, or the directory does not exists an empty string is returned.

# getMinNumberOfPermutations()
The getMinNumberOfPermutations() function returns the minimum number of permutations to achieve an interspersed sequence of 0s and 1s. It also works for sequences that include one 0 more than 1s or viceversa. Additionaly, if the number of 0s exceeds by more than one the number of 1s or viceversa the function returns a -1 value, since a interspersed sequence cannot be achieved.

# Unit tests
All the unit tests covering the test cases described in the descriptions with some additional ones can be found in unittest_Functions.cpp.
