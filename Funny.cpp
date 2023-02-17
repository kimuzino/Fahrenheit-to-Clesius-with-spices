#include <iostream>
#include <windows.h>
#include <string>
#include <limits>

int main(){
    int a;
    int b;
    int c;
    std::string user_input;
    int n = 0;

    

    while (true) {
        std::cout << "1 celsius to fahrenheit\n";
        std::cout << "2 fahrenheit to celsius\n";
        std::cin >> a;

        if (a == 1){
            std::cout << "Enter celsius : ";
            std::cin >> b;
            c = (b * 1.8f + 32);
            std::cout << "Temperature in fahrenheit : " << c << '\n';
            Sleep (1000);
            break;
        }

        else if (a == 2){
            std::cout << "Enter fahrenheit : ";
            std::cin >> b;
            c = (b - 32) * 5/9;
            std::cout << "Temperature in celsius : " << c << '\n';
            Sleep (1000);
            break;
        }

        else if (a != 1 || a != 2) {
            n++;
            if (n == 2) {
                std::cout << "Answering with something else than 1 or 2 again?\n";
                Sleep (1500);
                std::cout << "Im going to punish you.\n";
                Sleep (1500);
                std::cout << "BY SHUTTING DOWN YOUR COMPUTER.\n";
                Sleep (1500);
                std::cout << "BYE BYE.\n";

                // Get the necessary privileges to shut down the computer
                HANDLE hToken;
                TOKEN_PRIVILEGES tkp;
                OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken);
                LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid);
                tkp.PrivilegeCount = 1;
                tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
                AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);

                // Shut down the system without prompting the user
                ExitWindowsEx(EWX_SHUTDOWN | EWX_FORCE, SHTDN_REASON_MAJOR_OTHER | SHTDN_REASON_MINOR_OTHER);

                return 0;  // Windows sammutus elementti
            }

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Are you stupid?\n";
            Sleep(1500);
            std::cout << "I said 1 or 2 not anything else\n";
            Sleep(1500);
            std::cout << "I hope that was a mistake.\n";
            Sleep (1500);
            std::cout << "Want to try again. (Yes/No) : ";
            std::cin >> user_input;

            if (user_input == "Yes" || user_input == "yes" || user_input == "YES") {
                std::cout << "Excellent\n";
                Sleep (1500);
                std::cout << "Restarting program\n";
                Sleep (1500);
                continue;
            }

            else if (user_input == "No" || user_input == "no" || user_input == "NO") {
                std::cout << "Why?\n";
                Sleep (1500);
                std::cout << "I tough you wanted to convert Celsius or Fahrenheit.\n";
                Sleep (1500);
                std::cout << "But you don't want to try again.\n";
                Sleep (1500);
                std::cout << "Sad :(\n";
                Sleep (1500);
                std::cout << "Bye then.\n";
                Sleep (500);
                break;
            }

            else if (user_input == "Maybe" || user_input == "maybe" || user_input == "MAYBE") {
                std::cout << "Oh maybe?\n";
                Sleep (2000);
                std::cout << "Maybe because you don't understand.\n";
                Sleep (2000);
                std::cout << "Maybe because you are stupid.\n";
                Sleep (2000);
                std::cout << "Nobody knows.\n";
                Sleep (2000);
                std::cout << "You should learn to answer to questions better.\n";
                Sleep (2000);
                std::cout << "But.\n";
                Sleep (2000);
                std::cout << "Have fun :)\n";
                Sleep (2000);
                std::cout << "Goodbye.\n";
                Sleep (1000);
                break;
            }

            else {
                std::cout << "I said yes or no.\n";
                Sleep (2000);
                std::cout << "And you answered with something else.\n";
                Sleep (2000);
                std::cout << "Huh?\n";
                Sleep (2000);
                std::cout << "You are stupid.\n";
                Sleep (2000);
                std::cout << "Goodbye.\n";
                Sleep (1000);
                break;
            }
        }
    }
    
    return 0;

}