#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <algorithm>
#include <ctime>
using namespace std;

vector<int> getVector(int size);
void printVector(vector<int> vec);
void printList(list<int> li);

int main(){

	int size = 100000;
	vector<int> vi0;
	vector<int> vi;
	list<int> li;

	vi0 = getVector(size);

	vi = vi0;
	copy(vi0.begin(), vi0.end(), back_inserter(li));


	clock_t start = clock();
	sort(vi.begin(), vi.end());
	clock_t end = clock();
	double sort_vector_time = (end - start)/60;
	cout<<sort_vector_time<<endl;

	start = NULL;
	end = NULL;

	start = clock();
	li.sort();
	end = clock();
	double sort_list_time = (end - start)/60;
	printList(li);
	cout<<sort_list_time<<endl;

	li.clear();
	vi.clear();
	copy(vi0.begin(), vi0.end(), back_inserter(li));

	start = clock();
	copy(li.begin(), li.end(), back_inserter(vi));
	sort(vi.begin(), vi.end());
	copy(vi.begin(), vi.end(), back_inserter(li));
	end = clock();
	double sort_list_via_copying_to_vector_time = (end - start)/60;
	cout<<sort_list_via_copying_to_vector_time<<endl;



	
	
	system("pause");
	exit(0);
	
}

vector<int> getVector(int size){

	vector<int> vec;
	for(int i = 0; i < size; i++){
		vec.push_back(rand()%10000);
	}
	return vec;
}

template<class T>
void print(T stlObject){
	for(T::iterator itr = stlObject.begin(); itr != stlObject.end(); ++itr){
		cout<<*stlObject<<endl;
		stlObject.pop_back();
	}

}

void printVector(vector<int> vec){

	for(vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr){

		cout<<*itr<<endl;
		vec.pop_back();
	}
}

void printList(list<int> li){

	for(list<int>::iterator itr = li.begin(); itr != li.end(); ++itr){
		cout<<*itr<<endl;
		li.pop_back();
	}
}
