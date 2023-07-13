class Solution {
public:
    string intToRoman(int num) {
        string str = "";

        // handle thousands digit
        int num_3 = num / 1000;
        num = num % 1000;
        for(int i = 0; i < num_3; i++)
            str += "M";

        // handle hundreds digit
        int num_2 = num / 100;
        num = num % 100;
        if(num_2 == 9)
            str += "CM";
        else if(num_2 == 4)
            str += "CD";
        else if(num_2 >= 5){
            str += "D";
            num_2 = num_2 - 5;
            for(int i = 0; i < num_2; i++)
                str += "C";
        }
        else{
            for(int i = 0; i < num_2; i++)
                str += "C";
        }

        // handle tens digit
        int num_1 = num / 10;
        num = num % 10;
        if(num_1 == 9)
            str += "XC";
        else if(num_1 == 4)
            str += "XL";
        else if(num_1 >= 5){
            str += "L";
            num_1 = num_1 - 5;
            for(int i = 0; i < num_1; i++)
                str += "X";
        }
        else{
            for(int i = 0; i < num_1; i++)
                str += "X";
        }

        // handle units digit
        int num_0 = num;
        if(num_0 == 9)
            str += "IX";
        else if(num_0 == 4)
            str += "IV";
        else if(num_0 >= 5){
            str += "V";
            num_0 = num_0 - 5;
            for(int i = 0; i < num_0; i++)
                str += "I";
        }
        else{
            for(int i = 0; i < num_0; i++)
                str += "I";
        }

        return str;
    }
};