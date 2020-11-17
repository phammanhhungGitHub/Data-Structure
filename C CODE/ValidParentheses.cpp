#include<iostream>
#include<string>

bool IsValidString(std::string str)
{
    int s = 0;
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == '(')
            ++s;
        else if (str[i] == ')')
            --s;
        if (s < 0)
            return false;
    }

    if (s > 0)
        return false;
    else
        return true;
}

void CorrectString(std::string str, int balanceParen = 0, int deg = 0)
{
   while (deg < str.length() && str[deg] != '?')
   {
        if (str[deg] == '(')
            ++balanceParen;
        else
            --balanceParen;

        if (balanceParen < 0)
            return;
        ++deg;
   }

   if (deg == str.length() && IsValidString(str))
   {
       std::cout << str << '\n';
       return;
   }

   if (balanceParen - 1 >= 0)
   {
       str[deg] = ')';
       CorrectString(str, balanceParen - 1, deg + 1);
   }

   str[deg] = '(';
   CorrectString(str, balanceParen + 1, deg + 1);

}

int main()
{
    std::string str;
    std::cout << "String = ";
    getline(std::cin, str);

    CorrectString(str);
    //std::cout << IsValidString(str);
    getchar();
    return 0;
}