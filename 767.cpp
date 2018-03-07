#include <iostream>
#include <cmath>
#include <cerrno>
#include <cfenv>
#include <cstring>
using namespace std;
class Solution {
public:
    string reorganizeString(string S) {
        
        int N = S.length();
        int i = 0;
        char result[N+1];
        result[N] = 0;

        char input[N+1];
        strcpy(input, S.c_str());

        int count[26] = {0};

        for(i = 0; i < N; i++)
        {
        	count[input[i] - 'a']++;	
        }


        int total = 0;

        for(i = 0; i < 26; i++)
        {
        	if(count[i] > 0) total++;

        }


        int final[total][2];
        int j = 0;

        for(i = 0; i < 26; i++)
        {
        	if(count[i] > 0) 
        	{

        		final[j][1] = count[i];
        		final[j][0] = i;
        		//if(j == 13) cout <<final[j][1] <<'\n';
        		j++;

        	}
        }

        int all = pow(2, total-1);

        int odd = 0;
        int even = 0;
        int possible = 0;
        int marker = 0;

        for(i = 0; i < all; i++)
        {
        	odd  = 0;
        	even = 0;
        	possible = i;
        	for(j = 0; j < total; j++)
        	{
        		if((possible & 1) == 0) odd += final[j][1];
        		else even += final[j][1];
        		possible = possible >> 1; 
        		//if(final[j][1] <0) cout <<total <<' ' <<j <<' ' <<final[j][1] <<'\n'; 
        	}

        	if(odd == N - N/2 || odd == N/2)
        	{
        		marker = 1;
        		break;
        	}

        }

      //  cout <<N <<' ' <<odd <<' ' <<even <<'\n';

        if(marker == 0) return "";
        if( odd == N - N/2) marker = 0;
        else marker = 1;

        odd = 0;
        even = 1;

        possible = i;
        for(j = 0; j < total; j++)
        {
        	if((possible & 1) == marker) 
        	{
     			while(final[j][1] > 0)
        		{
        			result[odd] = 'a' + final[j][0];
        			final[j][1]--;
        			odd += 2;
        		}        		

        	}
        	else
        	{
        		while(final[j][1] > 0)
        		{
        			result[even] = 'a' + final[j][0];
        			final[j][1]--;
        			even += 2;
        		}   
        	}
        	possible = possible >> 1; 
        }
        /*
        int N = S.length();
        char result[N+1];
        result[N+1] = 0;
        char input[N+1];
        strcpy(input, S.c_str());
        int count[26] = {0};
        int i = 0;
        int odd = 0;
        int even = 1;
        int index;


        for(i = 0; i < N; i++)
        {
        	count[input[i] - 'a']++;	
        }

        for(i = 0; i < 26; i++)
        {

        	index = std::distance(count, std::max_element(count,count+26));
        	
        	
        	if(odd < even) 
        	{
        		while(count[index] > 0)
        		{
        			if(odd >= N) return "";
        			result[odd] = 'a' + index;
        			count[index]--;
        			odd += 2;


        		}
        	}
        	else 
        	{	
        		while(count[index] > 0)
        		{

        			if(even >= N) return "";
        			result[even] = 'a' + index;
        			even +=2;
        			count[index]--;
        		}
        	}

        	cout <<result <<'\n';
        	
        }

        return string(result);

        */
        return string(result);
    }

};

int main(int argc, char const *argv[])
{
	string a = "vvvlo";
	string b = 
	//"aaab";
	"snnnnbpngobwznvnnnlnwhvnnnnfjnnlnnnnnnbnknnqkndzefncknnnnnaiqrntnndnnnjninnnunnunqhndnnqnnsjqnnpiqshntnnncnvnnnncnnqenlnninyndnnnljongnnjwnnnngllnnngkbnllnnnnontlbpngjnnenqnsnnnnnjeqqghnfpngepnodnnnnnnvnsrnughbnipvnhqmnzonoonnnjotnnonoennnpnfnnkdnnbmnmnpnqninnxronnnnvnlanlnnnebnnnlnvnfknsnbincnttnmnguqenhnnxunnnntnnnnhnqnzehvunfnvnndvnjnnnbnnpxnqipwnmnonnndlnsnonnninnxnnnjnnnnnesennmyiednnnnnnnnnhimtnnnonjlicnwnwvnntaxmnrntnnnnsnbnanninnecbcfjxncnnkvnnqgnunensanpnngjnzxjnopnnyvnnxskniyytnsnnnnx";
	//"tndsewnllhrtwsvxenkscbivijfqnysamckzoyfnapuotmdexzkkrpmppttficzerdndssuveompqkemtbwbodrhwsfpbmkafpwyedpcowruntvymxtyyejqtajkcjakghtdwmuygecjncxzcxezgecrxonnszmqmecgvqqkdagvaaucewelchsmebikscciegzoiamovdojrmmwgbxeygibxxltemfgpogjkhobmhwquizuwvhfaiavsxhiknysdghcawcrphaykyashchyomklvghkyabxatmrkmrfsppfhgrwywtlxebgzmevefcqquvhvgounldxkdzndwybxhtycmlybhaaqvodntsvfhwcuhvuccwcsxelafyzushjhfyklvghpfvknprfouevsxmcuhiiiewcluehpmzrjzffnrptwbuhnyahrbzqvirvmffbxvrmynfcnupnukayjghpusewdwrbkhvjnveuiionefmnfxao";
	Solution s;
	cout << s.reorganizeString(b) <<'\n';
	return 0;
}