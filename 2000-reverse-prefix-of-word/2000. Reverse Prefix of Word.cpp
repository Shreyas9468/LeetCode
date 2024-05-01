class Solution {
public:
    string reversePrefix(string word, char ch) {
        int pos =0;
        for(int i=0;i<word.length();i++)
        {
            if(word[i]==ch)
            {
                pos=i;
                break;
            }
            
        }
        if(pos == 0 )
        {
            return word;
        }
        else{
            reverse(word.begin(),word.begin()+pos+1);
            return word;
        }

    }
};