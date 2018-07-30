/*
    Pretty print a json object using proper indentation.

    Every inner brace should increase one indentation to the following lines.
    Every close brace should decrease one indentation to the same line and the following lines.
    The indents can be increased with an additional ‘\t’
    Example 1:

    Input : {A:"B",C:{D:"E",F:{G:"H",I:"J"}}}
    Output :
    {
        A:"B",
        C:
        {
            D:"E",
            F:
            {
                G:"H",
                I:"J"
            }
        }
    }
    Example 2:

    Input : ["foo", {"bar":["baz",null,1.0,2]}]
    Output :
    [
        "foo",
        {
            "bar":
            [
                "baz",
                null,
                1.0,
                2
            ]
        }
    ]
    [] and {} are only acceptable braces in this case.

    Assume for this problem that space characters can be done away with.

    Your solution should return a list of strings, where each entry corresponds to a single line. The strings should not have “\n” character in them.
*/

vector<string> Solution::prettyJSON(string A) {

    vector<string> ret;
    int tab = 0;
    string temp;
    for (int i = 0; i < A.size(); i++)
    {
        if ((A[i] == '}' || A[i] == ']'))
        {
            if (tab > 0)
                tab--;

            if (!temp.empty())
            {
                ret.push_back(temp);
                temp.clear();
            }
        }

        if ((A[i] == '{' || A[i] == '[') && !temp.empty())
        {
            ret.push_back(temp);
            temp.clear();
        }

        if (temp.empty())
        {
            for (int j = 0; j < tab; j++)
                temp.push_back('\t');
        }
        temp.push_back(A[i]);

        if (A[i] == '{' || A[i] == '[')
        {
            tab++;
            ret.push_back(temp);
            temp.clear();
        }

        if ((A[i] == '}' || A[i] == ']') && A[i + 1] != ',')
        {
            ret.push_back(temp);
            temp.clear();
        }
        if (A[i] == ',')
        {
            ret.push_back(temp);
            temp.clear();
        }
    }

    return ret;
}
