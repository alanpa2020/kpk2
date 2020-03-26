/*�� ���������������� ����� "���������" ������ ������������� ��� ���������� ������ � �������.
 ���������. ������� - �������� 3 �������:
 (1) ����� ������� ����� � ������ � ������� ��������� ������;
 (2) ��������� �����,
 (3) "�������" (����� �������) ����� ������� ����� ������ (word) � ������� ������ (text).
 ���� �� ���� ������� �����������, � �� ���� ������ � ��������� ��� ������ ����������� ���������,
 ����� �� �� ������� � ������� ����, � ���� � ���. ����� �� ���� ������ ��� ��������� ����� ����������
  ������� ����������� ���������.*/

#include <iostream>

int strPos (char c, char s[], int strLen);
bool strEqual (char s1[], char s2[]);
int wordPos (char word[], char text[]);
int strLen (char word[]);


//----------------------------------------------------------------------------
int main () {
    char symbol ='a';
    char text[] = "good day";
    char text2[] = "_1_good days";
    int strLen = 8;

    int posSymbolInText = strPos (symbol, text, strLen);
    std::cout << "function strPos (\"" << symbol << "\", \"" << text << "\", "<< strLen << ") returned " << posSymbolInText << "\n";

    std::cout << "function strEqual (\"" << text << "\", \"" << text2 << "\", " << ") returned "<< strEqual (text, text2) << "\n";

    std::cout << "function wordPos (\"" << text << "\", \"" << text2 << "\", " << ") returned "<< wordPos (text, text2) << "\n";

    return 0;
}
//----------------------------------------------------------------------------


// ������� ������ ������� ������� c � ������ s. -1, ���� �� �������. �������� strLen - ����� �������� ����� ������ s
int strPos (char c, char s[], int strLen) {
    for (int i = 0; i < strLen; i++)
        if (c == s[i]) return i;
    return -1;
}

//������� ���������� ��������� �����
bool strEqual (char s1[], char s2[]) {
    if (strLen (s1) != strLen (s2))
        return false;

    for (int i = 0; i < strLen (s1); i++) {
        if (s1[i] != s2[i]) return false;
    }

    return true;
}


//������� ����������� ����� ������
int strLen (char word[]) {
     int len = 0;

     while (word [len] != '\0')
        len++;

     return len;
}


// ������� ������ ��������� word � ������ text. -1, ���� �� �������
int wordPos (char word[], char text[]){
    for (int i = 0; i < strLen (text) - strLen (word); i++) {
        int lenEqual = 0;

        for (int currentSymb = 0; currentSymb < strLen (word); currentSymb ++) {
            if (word[currentSymb] == text[currentSymb + i]) {
                lenEqual += 1;
            }
        if  (lenEqual == strLen (word)) return i;

        }
    }
    return -1;
}
