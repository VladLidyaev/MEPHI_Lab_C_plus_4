#include "tools.h"

bool operator== (const coord &c1, const coord &c2)
{

    return (c1.X == c2.X &&
            c1.Y== c2.Y);
}

float get_length(coord a, coord b){
    return sqrt( (b.X - a.X) * (b.X - a.X) + (b.Y - a.Y) * (b.Y - a.Y) );
}

bool is_content(coord a,std::vector<coord> b){
    bool ans = false;
    for (int i=0; i < b.size(); i++){
        if (b[i] == a){
            ans = true;
        }
    }
    return ans;
}

std::string add_space(std::string str){
    if (str.size() < 35){
        for (int i=str.size(); i<35;i++){
            str += " ";
        }
    }
    return str;
}

level str_to_level(int x){
    switch (x) {
        case 1:
            return stupid;
        case 2:
            return beginner;
        case 3:
            return middle;
        case 4:
            return pro;
        default:
            return beginner;
    }
}