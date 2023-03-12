//**************************
// Author:  yh
// Time:    2022/2/20
//**************************
#include "seqString.h"

#include <stdlib.h>
#include <string.h>

/*
 * Function description: char[] -> string
 * @param string
 * @param chars
 *
 * @return success or fail
 */
Status assign(HString &string, char *chars) {
    if (string.ch) {
        free(string.ch);
        string.ch = nullptr;
    }

    char *ch = chars;
    int strLength = 0;
    while (*ch != '\0') {
        ++strLength;
        ++ch;
    }

    if (!strLength) {
        string.ch = nullptr;
        string.length = 0;
    } else {
        string.ch = (char *) malloc((strLength + 1) * sizeof(char));
        if (nullptr == string.ch) {
            exit(OVERFLOW);
        }
        strncpy(string.ch, chars, strLength);
        string.length = strLength;
    }
    return EXIT_SUCCESS;
}

/*
 * Function description: get length of string
 *
 * @return length of string
 */
int getLength(HString string) { return string.length; }

/*
 * Function description: compare dest and target string
 * @param list
 * @param targerString
 *
 * @return int
 */
Status compare(HString string, HString targerString) {
    for (int i = 0; i < string.length; ++i) {
        if (string.ch[i] != targerString.ch[i]) {
            return string.ch[i] - targerString.ch[i];
        }
    }

    return string.length - targerString.length;
}

/*
 * Function description: empty string element
 * @param string
 *
 * @return success or fail
 */
Status clear(HString &string) {
    if (string.ch) {
        free(string.ch);
        string.ch = nullptr;
    }

    string.length = 0;
    return EXIT_SUCCESS;
}

/*
 * Function description: s1 + s2 -> string
 * @param string
 * @param s1
 * @param s2
 *
 * @return success or fail
 */
Status concat(HString &string, HString S1, HString S2) {
    if (string.ch) {
        free(string.ch);
        string.ch = nullptr;
    }

    string.ch = (char *) malloc((S1.length + S2.length + 1) * sizeof(char));
    if (!string.ch) {
        exit(OVERFLOW);
    }
    strncpy(string.ch, S1.ch, S1.length);
    strncat(string.ch, S2.ch, S2.length);
    string.length = S1.length + S2.length;
    return EXIT_SUCCESS;
}

/*
 * Function description: get sub string
 * @param subString
 * @param string
 * @param pos
 * @param len
 *
 * @return success or fail
 */
Status subString(HString subString, HString string, int pos, int len) {
    if ((pos < 1) || (pos > string.length) || (len < 0) || (len > string.length - pos + 1)) {
        return EXIT_FAILURE;
    }

    if (string.ch) {
        free(string.ch);
        string.ch = nullptr;
    }

    if (!len) {
        string.ch = nullptr;
        string.length = 0;
    } else {
        subString.ch = (char *) malloc((len + 1) * sizeof(char));
        if (!string.ch) {
            exit(OVERFLOW);
        }
        strncpy(subString.ch, string.ch, len);
        subString.length = len;
    }
    return EXIT_SUCCESS;
}

/*
 * Function description: string pattern match
 * @param S target string
 * @param T mode string
 * @param pos start with pos position
 *
 * @return the position of the subString after the Pos character in the main string S. if it does not exist, return 0;
 */

Status Index(HString S, HString T, int pos) {
    int i = pos, j = 0;

    while (i <= S.length && j < T.length) {
        if (S.ch[i] == T.ch[j]) {
            ++i;
            ++j;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }

    return j >= T.length ? i - T.length : 0;
}
