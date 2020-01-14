class SolutionDecodeString {
public:

    void parse_helper(const string& s, int start, int end)
    {
        for(int i = start;i < end;i++)
        {

            //getnumber

            if(isdigit(s[i]))
            {
                int digitstart = i;
                i++;
                while(isdigit(s[i]))
                    i++;
                int number = atoi(s.substr(digitstart, i-digitstart).c_str());


                stack<char> bracketsStack;

                bracketsStack.push('[');
                i++;
                int substr_start_index = i;
                while(!bracketsStack.empty())
                {
                    if(s[i] == '[')
                        bracketsStack.push(s[i]);
                    else if(s[i] == ']')
                        bracketsStack.pop();
                    i++;
                }

                int substr_end_index = i-1;

                parse_helper(s, substr_start_index, substr_end_index);

                int a = 0;
            }
            else
            {
                while(s[i] >= 'A' && s[i] <= 'Z' ||
                      s[i] >= 'a' && s[i] <= 'z')
                {
                    cout << s[i];
                    i++;
                }
            }


            //get_symbols
        }
    }

    void decodeString(string s) {
        //s = "3[a]2[bc]", return "aaabcbc".

        parse_helper(s, 0, s.size() - 1);
    }
};
