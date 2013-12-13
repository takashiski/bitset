//#include <bitset>
//#include <iostream>
//#include <string>
#include <vector>
#include <boost/dynamic_bitset.hpp>

class BitsetRecorder{
	/*
		boost::dynamic_bitsetをvector<unsigned int>に変換します
		vector<unsigned int>の先頭にはbitsetのサイズがはいりますのでご注意ください
	*/
	public:
		std::vector<unsigned int> save(boost::dynamic_bitset<>& set){
			std::vector<unsigned int> vi;
			unsigned int n = 0;
			unsigned int k = 0;
			unsigned int i = 0;

			vi.push_back(set.size());
			while(true){
				for(i=0;i<32;i+=1){
					if(i+k < set.size())
						n |= (set[i+k]<<i);
					else break;
				}
				std::cout << n << std::endl;
				std::cout << k << std::endl;
				vi.push_back(n);
				n = 0;
				k += i;
				if(k >= set.size())break;
			}
			return vi;
		}
		boost::dynamic_bitset<> load(std::vector<unsigned int> vi){
			boost::dynamic_bitset<> set;
			unsigned int n = 0;
			unsigned int i = 0;
			unsigned int k = 0;

			set.resize(vi[k++]);
			while(true){
				int tmp = vi[k];
				int index = (k-1)*32;
				for(i=0;i<32;i++){
					if(i+index < set.size()){
						set[i + index] = tmp & (1<<i); 
					}
					else break;
				}
				k+=1;
				if(index + i >= set.size())break;
			}
			
			return set;
		}
};

//以下テスト
/*
int main(void){
	int size = 128;
	boost::dynamic_bitset<> set;
	set.resize(size);
	std::cout << "resize\n";
	for(int i=0;i<size;i+=5)
		set.set(i);
	std::cout << "bitset:\n";
	std::cout << set << std::endl;

	std::vector<unsigned int> vi = save(set);
	std::cout << "save\n";
	std::vector<unsigned int>::iterator it = vi.begin();
//	for(int i=0;i<vi.size();i++)
	for(;it != vi.end();++it)
		std::cout << *it << std::endl;
	std::cout << "save\n" << std::endl;	
	set = load(vi);
	std::cout << set << std::endl;
	return 0;
}
*/
