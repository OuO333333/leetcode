class Solution {
public:
    string convert(string s, int numRows) {

        // numRows == 1, could have error when currentLine go down and change direction
        if(numRows == 1)
            return s;
        vector<string> v(numRows);
        int currentLine = 0;
        string str = "down";
        for(int i = 0; i < s.size(); i++){
            v[currentLine] += s[i];

            // currentLine go up and change direction
            if(currentLine == numRows - 1){
                str = "up";
                currentLine--;
            }

            // currentLine go down and change direction
            else if(currentLine == 0){ 
                str = "down";
                currentLine++;
            } else{

                // currentLine go up
                if(str == "up")
                    currentLine--;

                // currentLine go down
                if(str == "down")
                    currentLine++;
            }
        }

        // get the result string
        string ans = "";
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < v[i].size(); j++){
                ans += v[i][j];
            }
        }
        return ans;
    }
};