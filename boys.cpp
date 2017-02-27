#include <string>
class boys{
	public:
	std::string name;
	std::string type;
	std::string status;
	int attractiveness;
	int budget;
	int intelligence;

		boys()
		{
		}
		void boys1(std::string n,std::string c,std::string s,int a,int b,int i)
		{
			name=n;
			type=c;
			status=s;
			attractiveness=a;
			budget=b;
			intelligence=i;
		}
		
};
