#include <iostream>
#include <cstring>
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
            cout << messageBeforeDog << ", " << messageBeforeDot << ", " << messageAfterDot;
            if (!messageBeforeDog.empty() && messageBeforeDog.find_first_of("@.") == -1 &&
                !messageBeforeDot.empty() && messageBeforeDot.find_first_of("@.") == -1 &&
                !messageAfterDot.empty() && messageAfterDot.find_first_of("@.") == -1)
                return true;
        }
    }
    return false;
}

int main(int argc, char* argv[])
{
    cout << isEmail("vlad@yandex.ru");
}