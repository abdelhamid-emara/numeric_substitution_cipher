#include <iostream>
#include <cctype>

void NumSubEncryption(std::string&);
void NumSubDecryption(std::string&);

int main()
{
    std::string myString = "Hello World! Welcome To Numeric_Substitution Cipher.";
    std::string s = myString;

    NumSubEncryption(s);
    std::cout << s << std::endl;

    NumSubDecryption(s);
    std::cout << s << std::endl;

    return 0;
}

void NumSubEncryption(std::string& plain)
{
    std::string tmp{""};

    for(int i = 0; i < plain.size(); i++)
        plain[i] = toupper(plain[i]);

    for(int i = 0; i < plain.size(); i++)
    {
        if(plain[i] >= 'A' && plain[i] <= 'Z')
            tmp += std::to_string(plain[i] - 'A');
        
        // Un-comment The Condition To Save Non-Letters
        // else
        //     tmp.push_back(plain[i]);
    }

    plain = tmp;
}

void NumSubDecryption(std::string& cipher)
{
    std::string tmp{""};
    char keys[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K','L', 'M',
                    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};


    for(int i = 0; i < cipher.size(); i++)
    {
        if (cipher[i] >= '3') 
            tmp.push_back(keys[int(cipher[i] - '0')]);

        else if (cipher[i] == '2' && cipher[i + 1] > '5')
                tmp.push_back(keys[int(cipher[i] - '0')]);

        else if(cipher[i] == '1' ||(cipher[i] == '2'))
        {
            tmp.push_back('(');
            tmp.push_back(keys[int(cipher[i] - '0')]);
            tmp.push_back(',');
            int index = (cipher[i] - '0');
            index = (i != cipher.size() - 1) ? (index * 10) + (cipher[i + 1] - '0') : index; 
            tmp.push_back(keys[index]);
            tmp.push_back(')');
        }
    }

    cipher = tmp;
}
