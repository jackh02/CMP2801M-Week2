#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int numSentences(string fileText)
{
    int i, size = fileText.size(), numberOfSentences = 0;

    for (i = 0; i < size; i++)
    {
        if (fileText[i] == '.' || fileText[i] == '!' || fileText[i] == '?')
        {
            numberOfSentences++;
        }
    }
    return numberOfSentences;
}

int numWords(string fileText)
{
    int i, size = fileText.size(), numberOfWords = 0;

    for (i = 0; i < size; i++)
    {
        if (fileText[i] == ' ')
        {
            numberOfWords++;
        }
    }
    return numberOfWords;
}

void wordFrequency(string fileText)
{
    unordered_map<string, int> wordList;

    string word = "";

    int i, length = fileText.length();

    for (i = 0; i <= length; i++)
    {
        if (fileText[i] == ' ')
        {
            if (wordList.count(word) == 0)
            {
                wordList[word] = 1;
                word = "";
            }
            else
            {
                wordList[word]++;
                word = "";
            }
        }
        else
        {
            word += fileText[i];
        }
    }

    for (auto& wl : wordList)
    {
        cout << wl.first << ": " << wl.second << endl;
    }
}

int main()
{
    string line, fileText;

    ifstream file;
    file.open("input.txt");

    while (!file.eof())
    {
        getline(file, line);
        fileText += line + "\n";
    }
    file.close();

    cout << fileText << endl;

    fileText.erase(remove(fileText.begin(), fileText.end(), '\n'), fileText.cend());

    int numberOfSentences = numSentences(fileText);
    cout << "Number of sentences: " << numberOfSentences << endl;

    int i ,size = fileText.size();

    for (i = 0; i < size; i++)
    {
        if (fileText[i] == '.' || fileText[i] == ',' || fileText[i] == '!' || fileText[i] == '?')
        {
            fileText[i] = ' ';
        }
    }

    int numberOfWords = numWords(fileText);
    cout << "Number of words: " << numberOfWords << endl << endl;

    transform(fileText.begin(), fileText.end(), fileText.begin(), tolower);

    wordFrequency(fileText);

    return 0;
}
