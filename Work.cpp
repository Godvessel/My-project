#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include"Goodness.h"
using namespace std;
vector<string>  search_for_word(vector<string>&str,const string& search){
    vector<string>str1;
    for(int i=0;i<str.size();i++){
        auto n=str[i].find(search);
        if(n!=string::npos){
            str1.push_back(str[i]);
        }
    }
    
    return str1;
}
vector<string> sort_for_word(vector<string>& str,const string& search){
    vector<string>str1;
      for(int i=0;i<str.size();i++){
        auto m=str[i].compare(0,search.length(),search);
        if(m==0){
            str1.push_back(str[i]);
        }
    }
    
    return str1;
        }
int main(int argc, char *argv[])
{   vector<pair<string,string>>dictionary{make_pair("hello", "used to express a greeting, answer a telephone, or attract attention.")};

dictionary.push_back(make_pair("he","(personal) A male person or animal already known or implied."));
dictionary.push_back(make_pair("Girl","A female child, adolescent, or a young woman."));
dictionary.push_back(make_pair("1+1","this is an addition expression that gives 2 as an answer"));
dictionary.push_back(make_pair("hassan","(Islam) The eldest son of Ali and brother of Husayn, both are Imams.A male given name used by Muslims"));
dictionary.push_back(make_pair("hassan","From Arabic حَسَن"));
dictionary.push_back(make_pair("Michael","(countable) A male given name."));
dictionary.push_back(make_pair("Michael","example: 1629, Thomas Adams, Meditations upon Creed, The Works of Thomas Adams, James Nichol (1862), volume 3, page 212:Yea, it seems to me not fit for Christian humility to call a man Gabriel or Michael, giving the names of angels to the sons of mortality.2008, Philip Hensher, The Northern Clemency, Harpercollins, ISBN 9780007174799, page 498:He works in the steelworks, the boyfriend, on the factory floor. I'd say that was quite unusual, he's called Michael. Insists on that, he does, not being called Mike or Micky or Mick, pretends not to hear you, then, No, my name's actually Michael."));
dictionary.push_back(make_pair("ha","A representation of laughter."));
dictionary.push_back(make_pair("God","The omniscience,the omnipresent,Jeovah Elshaddai,Jeovah Nissi"));
dictionary.push_back(make_pair("god","human created idol"));
dictionary.push_back(make_pair("Go","(intransitive) To move through space (especially to or through a place). (May be used of tangible things like people or cars, or intangible things like moods or information.)"));
dictionary.push_back(make_pair("Light","The power of perception by vision."));
dictionary.push_back(make_pair("Li","The Chinese mile, a traditional unit of distance equal to 1500 chis or 150 zhangs, now standardized as a half-kilometer (500 meters)."));
dictionary.push_back(make_pair("Lie","An intentionally false statement; an intentional falsehood."));
dictionary.push_back(make_pair("Lien"," A right to take possession of a debtor’s property as security until a debt or duty is discharged."));
dictionary.push_back(make_pair("Bible","the word of God"))



 vector<string> str1={"hello","Hello","More","Greek","Girl","Yellow","house","Hassan","hassan","ha","amoha","Bahama","hat","have you cleaned the bathroom","have you washed plate","more","Move","move","he","girl","1+1","Michael","God","god","Go","Light","light","Lie","Lien"};
sort_m(str1.begin(),str1.end(),less<string>());
	string search={"Lie"};
    cout<<"search_word:"<<search<<endl;
	cout<<endl;
	cout<<"words in the database:"<<endl;
	for(auto i:str1){
	    cout<<i;
	    cout<<endl;
	}
	cout<<endl;
	vector<string> str2=search_for_word(str1,search);
	vector<string>str3=sort_for_word(str2,search);
	for(int i=0;i<dictionary.size();i++){
	    if(search==get<0>(dictionary[i])){
	        cout<<"word: "<<dictionary[i].first<<endl;
	        cout<<"meaning: "<<dictionary[i].second<<endl;
	
	}
	}
	cout<<endl;
		 cout<<"words or sentences/ meanings that match "<<search<<" are :"<<endl;

	if(!str3.empty()){
	    for(auto n:str3){
	        cout<<n<<endl;
	    }
	    }
	else{
	    cout<<"No word match"<<endl;
	}
	
}
