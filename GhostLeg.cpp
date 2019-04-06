#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int* makeRandomList(int N,int range){
    srand(time(NULL));
    int* list = new int[N];

    int i=0;
    while(i!=N){
        int x = rand()%range;

        int dup =0;
        for(int j=0;j<i;j++){
            if(list[j]==x)
                dup = 1;  
        }
        if(dup == 0){
            list[i] = x;
            i++;
        }
    }

    return list;
}


string* load_file(int N){
    FILE* data = fopen("animal.txt","r");
    vector<string> allList;
    string* nameList = new string[N];
    char str[100];

    //name file loaded
    int size =0;
    while(1){
        fscanf(data,"%s",str);
        allList.push_back(str);
        if(feof(data)) break;
        size ++;
    }
    fclose(data);
    
    //set nameList
    int* list = makeRandomList(N,size);

    for(int i=0;i<N;i++)
        nameList[i]=allList[list[i]];

    return nameList;
}


int main(){
    int N=0;
    int* list = NULL;
    string* nameList = NULL;
    
    cout << "How many people are there?" << endl;
    cin >> N;
    cin.get();

    //load list for alias name
    nameList = load_file(N);

    cout << "\nChoose one among animal list below" << endl ;
    for(int i=0;i<N;i++){
        cout << i+1 << " ) " <<nameList[i] << endl;
    }

    cout << "\n\nPress enter when you're ready";
    
    cin.get();

    //make random number list 
    list = makeRandomList(N,N);

    cout << "\n\n----------------result----------------\n" << endl;
    for(int i=0;i<N;i++){
        cout << " -> " << nameList[list[i]];
    }

    char AGAIN;
    while(1){
        cout << "\nAGAIN? (Y/N)" <<endl;
        cin >> AGAIN;
        if(AGAIN=='Y') return main();
        else if(AGAIN=='N') return 0;
    }
}