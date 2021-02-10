#include <vector>
#include <pwd.h>
#include "dirent.h"

using namespace std;

/*
@fn int getFirstRepeatedNumber()
@brief Method to get the first repeated number of two vectors
@param viFirstVector first vector
@param viSecondVector second vector
@return int
@author EMM
*/
int getFirstRepeatedNumber(vector<int> viFirstVector, vector<int> viSecondVector) {

  for (int iNumFirstVector : viFirstVector) {
    for (int iNumSecondVector : viSecondVector) {
      if (iNumFirstVector == iNumSecondVector)
        return iNumFirstVector;
    }
  }

  return -1;
}

/*
@fn string getFile(string sPath)
@brief Method to get the first file of a path that meets the following requirements:
a. The file owner is admin
b. The file is executable
c. The file has a size lower than 14*2^20
@param sPath path of the file system to search for the file
@return string
@author EMM
*/
string getFile(string sPath) {
  string sFile;
  string sFilePath;

  DIR *dir;
  struct dirent *diread;
  struct stat file_stats;
  vector<char *> files;

  if ((dir = opendir(sPath.c_str())) != nullptr) {      //Open directory
    while ((diread = readdir(dir)) != nullptr) {        //Read through files
      string sCurrentFile = diread->d_name;
      if (sCurrentFile.find(".exe") != string::npos) {  //The file is executable
        sFilePath = sPath + "/" + sCurrentFile;
        if (!stat(sFilePath.c_str(), &file_stats)) {
          if (file_stats.st_size < 14680064) {         //The file has a size lower than 14*2^20 
            struct passwd *pInfo = getpwuid(file_stats.st_uid);
            if (pInfo != NULL)
            {
              if (pInfo->pw_name == "admin")            //The file owner is admin
                sFile = diread->d_name;
            }
          }
        }
      }
    }
  }
  closedir(dir);

  return sFile; //If empty, file not found
}

/*
@fn int getMinNumberOfPermutations(vector<bool> vbSequence)
@brief Method to get the minimum number of permutations so that the sequence ends interspersed
@param vbSequence sequence of coin flips
@return int
@author EMM
*/
int getMinNumberOfPermutations(vector<bool> vbSequence) {
  int iNumberOfTails = 0;
  int iNumberOfHeads = 0;

  //Sequence cannot get interspersed if there is a difference in the number of tails and heads higher than 1
  for (bool bCoinFlip : vbSequence) {
    if (bCoinFlip)
      iNumberOfHeads++;
    else
      iNumberOfTails++;
  }

  if (!(iNumberOfHeads == iNumberOfTails || iNumberOfHeads == iNumberOfTails - 1 || iNumberOfTails == iNumberOfHeads - 1))
    return -1;

  //If there are no head or tails no permutations can be done
  if (iNumberOfTails == 0 || iNumberOfHeads == 0)
    return 0;

  //Count the number of 0 and 1 that are in odd and even positions
  int iNumberOfTailsOdd = 0;
  int iNumberOfTailsEven = 0;
  int iNumberOfHeadsOdd = 0;
  int iNumberOfHeadsEven = 0;
  bool bOdd = false;
  for (bool bCoinFlip : vbSequence) {
    if (!bCoinFlip) {
      if (bOdd)
        iNumberOfTailsOdd++;
      else
        iNumberOfTailsEven++;
    }
    else {
      if (bOdd)
        iNumberOfHeadsOdd++;
      else
        iNumberOfHeadsEven++;
    }
    bOdd = !bOdd;
  }

  //Decide if to use tails or heads in case there is not the same number in the sequence
  bool bTails;
  if (iNumberOfTailsOdd != iNumberOfTailsEven)
    bTails = false;
  else
    bTails = true;

  //The lower number is the minimum number of permutations to get the sequence interspersed
  if (bTails) {
    if (iNumberOfTailsOdd >= iNumberOfTailsEven)
      return iNumberOfTailsEven;
    else
      return iNumberOfTailsOdd;
  }
  else {
    if (iNumberOfHeadsOdd >= iNumberOfHeadsEven)
      return iNumberOfHeadsEven;
    else
      return iNumberOfHeadsOdd;
  }
}