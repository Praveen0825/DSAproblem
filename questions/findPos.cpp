/*
Given an index and an input string find the char at the given index of the string.
But here's the catch: if the index exceeds the length of the string, then you transform the string by removing the string's last character and appending it to the front and appending this transformed string to the original string until you have a string length that exceeds the desired index.

For example,if we have a string "abcd" and want to find the char at index 3 it would obviously be 'd'.
However, if we want to find the char at index 7 of "abcd" we would transform "abcd" to "abcddabc" and the char would be 'c'. If we want to find the char at index 12 of "abcd" we would transform "abcd" to "abcddabc" and then again transform to "abcddabccabcddab" and the char would be 'd.
*/

char getChar(string s, int i)
{
    int n = s.length();

    int m = n;
    while (m <= i)
    {
        m *= 2;
    }

    while (m != n)
    {
        int halved = m / 2;

        if (i >= halved)
        {
            i = (i - 1) % halved;
        }

        m = halved;
    }

    return s[i];
}
