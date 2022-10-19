#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>

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
    map<string, int> wordList;

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

    //Open the file with the text.
    ifstream file;
    file.open("input.txt");

    //Input the text file into a string.
    while (!file.eof())
    {
        getline(file, line);
        fileText += line + "\n";
    }
    file.close();

    //Display the string as formatted in the text file.
    cout << fileText << endl;

    //Remove new lines from the string.
    fileText.erase(remove(fileText.begin(), fileText.end(), '\n'), fileText.cend());

    //Calculate the number of sentences in the string and display it in the console.
    int numberOfSentences = numSentences(fileText);
    cout << "Number of sentences: " << numberOfSentences << endl;

    int i ,size = fileText.size();

    //Replace punctuation in the string with spaces.
    for (i = 0; i < size; i++)
    {
        if (fileText[i] == '.' || fileText[i] == ',' || fileText[i] == '!' || fileText[i] == '?')
        {
            fileText[i] = ' ';
        }
    }

    //Calculate the number of words in the string and display it in the console.
    int numberOfWords = numWords(fileText);
    cout << "Number of words: " << numberOfWords << endl << endl;

    //Set the string to lower case.
    transform(fileText.begin(), fileText.end(), fileText.begin(), tolower);

    //Run the word frequency funtion with the text variable as an input.
    wordFrequency(fileText);

    return 0;
}
