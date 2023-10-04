#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

double getstringval(char str[21]);
bool comparestrings(char str1[21], char str2[21]);
void comparevalues(double val1, double val2, char str1[21], char str2[21], bool value);


double getstringval(char str[21]) {
  int length = strlen(str);
  double counter = 0;
  for (int i=0; i < length; ++i) {
    counter += toupper(str[i]);;
  }
  return counter;
}


bool comparestrings(char str1[21], char str2[21]) {
  for (int a = 0; str1[a] != '\0'; ++a) {
    if (str1[a] >= 'a' && str1[a] <= 'z') {
      str1[a] = str1[a] - 32;
    }
  }
  for (int b = 0; str2[b] != '\0'; ++b) {
    if (str2[b] >= 'a' && str2[b] <= 'z') {
      str2[b] = str2[b] - 32;
    }
  }
  char placehold;
  for (int j = 0; str1[j] != '\0'; ++j) {
    for (int i = 0; i < strlen(str1) - 1; ++i) {
      if (str1[i+1] < str1[i]) {
        placehold = str1[i+1];
        str1[i+1] = str1[i];
        str1[i] = placehold;
    }
  }
  }
  for (int j = 0; str2[j] != '\0'; ++j) {
    for (int i = 0; i < strlen(str2) - 1; ++i) {
      if (str2[i+1] < str2[i]) {
        placehold = str2[i+1];
        str2[i+1] = str2[i];
        str2[i] = placehold;
    }
  }
  }
  for (int i = 0; i < strlen(str1); ++i) {
    if (str1[i] == str2[i]) {
      continue;
    } else {
      return false;
    }
  }
  return true;
}


void comparevalues(double val1, double val2, char str1[21], char str2[21], bool value) {
  if (val1 == val2 && value) {
    printf("%s is an anagram of %s\n", str1, str2);
  } else {
    printf("%s is NOT an anagram of %s\n", str1, str2);
  }
}



int main() {
  char str1[21];
  char copystr1[21];
  char str2[21];
  char copystr2[21];
  double val1;
  double val2;
  bool value;

  printf("Please enter the first word: ");
  scanf("%s", str1);
  printf("Please enter the second word: ");
  scanf("%s", str2);
  strcpy(copystr1, str1);
  strcpy(copystr2, str2);
  value = comparestrings(str1, str2);
  val1 = getstringval(str1);
  val2 = getstringval(str2);
  comparevalues(val1,val2, copystr1, copystr2, value);
  return 0;
}
