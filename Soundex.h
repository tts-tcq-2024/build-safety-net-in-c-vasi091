#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) {
    static const char soundexTable[26] = {
        '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'
    };

    c = toupper(c);
    if (c >= 'A' && c <= 'Z') {
        return soundexTable[c - 'A'];
    }
    return '0'; // For non-alphabet characters
}

void appendCode(char *soundex, int *sIndex, char code) {
    if (*sIndex < 4 && code != '0' && code != soundex[*sIndex - 1]) {
        soundex[(*sIndex)++] = code;
    }
}

void padWithZeros(char *soundex, int sIndex) {
    memset(soundex + sIndex, '0', 4 - sIndex);
    soundex[4] = '\0';
}

void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;

    for (int i = 1; i < len && sIndex < 4; i++) {
        appendCode(soundex, &sIndex, getSoundexCode(name[i]));
    }

    padWithZeros(soundex, sIndex);
}

#endif // SOUNDEX_H
