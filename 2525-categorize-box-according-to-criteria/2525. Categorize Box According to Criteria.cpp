class Solution {
	public:
		string categorizeBox(int l, int w, int h, int m) {
			long long volume=(long long)(l)*(long long)(w)*(long long)h;

			bool check1= (volume>=1e9 || (l>=1e4 || w>=1e4 || h>=1e4));
			bool check2= m>=100;

			if(check1 && check2) return "Both";
			else if(check1) return "Bulky";
			else if(check2) return "Heavy";
			else return "Neither";
		}
	};