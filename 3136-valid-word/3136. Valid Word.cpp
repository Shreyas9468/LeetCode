class Solution {
public:
    bool isValid(string word) {
        bool v = false , c = false , d = false ;
        if(word.length()<3){
            return false;
        }
        for(auto it : word){
            if (it == 'a' || it == 'i' || it == 'e' || it == 'o' || it == 'u' ||
                it == 'A' || it == 'E' || it == 'I' || it == 'O' || it == 'U') {
                v = true; // It's a vowel
            } else if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z')) {
                c = true; // It's a consonant
            }
            if(it =='@' ||it=='#' ||it=='$'){
                return false;
            }
            
            
        }
        return (v&&c);
        
    }
};