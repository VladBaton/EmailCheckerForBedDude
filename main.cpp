#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

bool isEmail(string message)
{
    if (!message.empty())
    {
        int firstDog = message.find_first_of("@");
        int firstDot = message.find_first_of(".");
        if (firstDog != -1 && firstDot != -1 && message.find_first_of(" ") == -1)
        {
            string messageBeforeDog = message.substr(0, firstDog);
            string messageBeforeDot = message.substr(firstDog + 1, firstDot - firstDog - 1);
            string messageAfterDot = message.substr(firstDot + 1);
            if (!messageBeforeDog.empty() && messageBeforeDog.find_first_of("@.") == -1 &&
                !messageBeforeDot.empty() && messageBeforeDot.find_first_of("@.") == -1 &&
                !messageAfterDot.empty() && messageAfterDot.find_first_of("@.") == -1)
                return true;
        }
    }
    return false;
}

struct Email
{
    string email;
    int position;
};

int main(int argc, char* argv[])
{
    ifstream emailsFile("example.txt");
    ofstream foundEmailsPutter("foundEmails.txt");
    vector<Email> foundEmails;
    string inputLine;
    if (emailsFile.is_open())
    {
        getline(emailsFile, inputLine);
        for (int i = 0; !emailsFile.eof(); getline(emailsFile, inputLine), i++)
            if (isEmail(inputLine))
                foundEmails.push_back({ inputLine, i });
    }
    cout << "Found emails : " << foundEmails.size();
    foundEmailsPutter << "Found emails : " << foundEmails.size() << endl;
    for (int i = 0; i < foundEmails.size(); i++)
        foundEmailsPutter << foundEmails[i].email << " on position : " << foundEmails[i].position + 1 << endl;
    return 0;
}