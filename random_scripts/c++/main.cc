#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <optional>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <algorithm> //mainly for find, it always returns an iterator
#include <thread>


//TODO: STACKS
//NOTE: IF ITERATORS DON'T FIND WHAT THEY ARE LOOKING FOR THEY RETURN .end()

using namespace std;

void concfunc(){
    cout << "this is the other thread/func" << endl;
}

//there exists something called a unnion, but fuck em, so do enums, i don't even use constant let alone const structs
// Self referential structures, used in data structures like linked lists, gotta check out later for sure
struct GfG {
    int val;
    GfG *next;
};

int x=5;
vector<int> vec = {5,6,8,9,5,7};

int yo(int k = 20000);
string hey();

//definiction
void changepoint(int* x){
    *x = 100;
}

//there is such a thing as an online function, it makes some things fastser: it basically pushes the function code to insid ethe main func instead of calling it from far far away
inline void change(int& x){
    x=50;
}

struct structest {
    float sx;
    float sy;
    optional<float> sz; //nullpot , in case of pointer, you pass an address or nullptr like float *sz and the when passing &random_float or nullptr, in both cases you call them by *struct.sz
    float sum(){
        return sx + sy;
    }
};

typedef struct structest2{
    int x;
} stt;





int main() {

    //std::strings, they are treated like vectors and most vector features work on them
    string str = "wubba lubba dub dub";
    cout << str.length() << " | " << str.size() << endl;
    string substr = str.substr(0, 1);
    cout << substr << endl;

    cout << "DATA TYPES" << endl;

    cout << "--------------linked lists--------------------" <<endl;
    list<string> chain = {"barney stinson", "sheldon cooper", "bazinga"};
    chain.push_back("batman");
    chain.push_front("bruce wayn");
    //splicing exists, it's a headache
    for(auto &c:chain){
        cout << c << " | ";
    }
    cout << " " << endl;
    //iterators, btw find is cracked, works on all stl
    //1/
    for(auto it=chain.begin(); it != chain.end(); ++it){
        if(*it=="bazinga"){
            chain.insert(it, "peter parker");
            break;
        }
    }
    //2/
    auto chainit = find(chain.begin(), chain.end(), "sheldon cooper");
    chain.insert(chainit, "tony stark");

    for(auto &c:chain){
        cout << c << " | ";
    }
    cout << " " << endl;

    chain.pop_back();
    chain.pop_front();
    for(auto &c:chain){
        cout << c << " | ";
    }
    cout << " " << endl;

    chain.sort();
    for(auto &c:chain){
        cout << c << " | ";
    }
    cout << " " << endl;

    chain.reverse();
    for(auto &c:chain){
        cout << c << " | ";
    }
    cout << " " << endl;


    cout << "---------vecs----------" << endl;
    //there is also the deque, basically like a vector queu bastard child, just allows fast insertions and deletion AT FRONT

    vector<int> vec = {1,5,3,2,4};
    sort(vec.begin(), vec.end());
    vector<int> v(vec);

    for(int v:vec){
        cout << v << " ";
    }
    cout << " " << endl;
    for(int &v:v){
        cout << v << " ";
    }
    cout << " " << endl;

    cout << "vec size is: " << v.size() << " elements" << endl;
    cout << "v[0] says: " << v[0] << endl;
    cout << "v.front() says: " << v.front() << endl;
    cout << "v.back() says: " << v.back() << endl;

    v.push_back(10); 
    cout << "after .push_back: ";
    for(int &v:v){
        cout << v << " ";
    }
    cout << " " << endl;

    v.pop_back();     
    cout << "after .pop_back: ";
    for(int &v:v){
        cout << v << " ";
    }
    cout << " " << endl;

    cout << "inserts with v.insert(v.begin() + index, value): ";
    v.insert(v.begin() + 1, 20); 
    for(int &v:v){
        cout << v << " ";
    }
    cout << " " << endl;
    
    cout << "delete / erase elements with v.erase(v.begin() + index): ";
    v.erase(v.begin()+1);   
    for(int &v:v){
        cout << v << " ";
    }
    cout << " " << endl;

    //delete the whole vec
    v.clear(); //deletes all elements
    if(v.empty()){
        cout << "yo the vector is empty" << endl;
    } //returns true or false to see if empty

    cout << "-----------STACKS, LIFO order-----------" << endl;

    stack<string> stk;
    stk.push("jhon wick");
    stk.push("jhon cena");
    stack<string> stk2(stk);

    cout << "stack size is: " << stk.size() << endl; 
    cout << "stacks are lifo: " << stk.top() << endl;
    stk.pop();
    cout << "stacks are lifo: " << stk.top() << endl;
    stk.pop();
    if(stk.empty()){
        cout << "the staxk is now empty" << endl;
    }
    //for certain operations tou can just copy the suckah and eal with it that way
    int stk2size = stk2.size();
    for(int i=0; i < stk2size; i++){
        cout << stk2.top() << endl;
        stk2.pop();
    }

    cout << "-----------QUEUS, FIFO order-----------" << endl;

    queue<string> q;
    q.push("cm punk");
    q.push("edge");
    q.push("dean ambrose");
    auto qq(q);
    cout << "queue size is: " << q.size() << endl;
    cout << "there exists both front and back methods: " << q.front() << " | " << q.back() << endl;
    q.pop();
    cout << "after poping, the front is: " << q.front() << endl;
    if(!q.empty()){
        cout << "yo the queue is not empty" << endl;
    }
    int qsize = qq.size();
    for(int i = 0; i<qsize; i++){
        cout << qq.front() << endl;
        qq.pop();
    }

    cout << "------------------MAPS---------------------" << endl;
    //maps are unique, unrdered_maps are not, maybe use that in the future, there is also multimap
    cout << "heads up, maps have a lot of conflicting syntaxe" << endl;
    map<string, int> wins = {{"ortan", 15}, {"punk", 5}};
    //adding elements
    wins["cena"] = 17;
    wins.insert({"steve oston", 10});
    wins.emplace("lesnar", 6);
    //accessing
    cout << "the goat won: " << wins["cena"] << endl; //if doesn't exist creates it
    cout << "best in the world won: " << wins.at("punk") << endl; //if doesn't exist returns exception
    for(auto &win:wins){ // ps: the refrence here is not necessary
        cout << win.first << " " << win.second << endl;
    }
    wins.erase("lesnar"); // with key
    wins.erase(wins.find("steve oston")); //with iterator, you can al add a second argument to make it a range, like multiple deletions at once
    cout << "with iterators, after erase" << endl;
    //or with itirators
    for(auto it = wins.begin(); it!= wins.end(); ++it){
        cout << it->first << " " << it->second << endl;
    }

    cout << "----------------------SETS----------------------" << endl;
    //sets are unique and auto sort, there is unordered_set too, unique, NO AUTO SORT, also multiset, auto sort no unique
    set<string> birds = {"crow", "raven", "bee", "hawk"};
    birds.insert("owl");
    //iterator
    auto it = birds.find("hawk");
    if(it!=birds.end()){
        cout << "deleting " << *it << endl;
        birds.erase(it);
    }
    cout << "count says: " << birds.count("crow") << endl; //returns 1 if it exists else 0, better than find with iterators
    birds.erase("bee");
    for(auto &b:birds){
        cout << b << " ";
    }
    cout << " " << endl;

    cout << "---------------------------------------" << endl;

    //apearantly you can copy stuff like this, weird
    int ct = 5;
    int ctt(ct);
    cout << "copied value thing is: " <<  ctt << endl;

    int var;
    //input
    //cin >> var;
    var = 5;
    //output
    cout << var << endl;
    //error
    cerr << "error yo" <<endl;
    //if
    if(var%2 == 0){
        cout << "pair var?" << endl;
    }else{
        cout << "unique var?" << endl;
    }
    //switch
    switch (var){
        case 1:
            cout << "var is 1" << endl;
            break;
        case 5:
            cout << "var is 5" << endl;
            break;
        default:
            cout << "i don't know what kind of shinanigans you spewing" << endl;
    }
    //loops
    //for
    for(int i=0; i<10; i++){
        cout << "the i equals" << i << endl;
    }
    int xx = 2;
    //while, do while also exits
    while(xx<10){
        cout << "xx needs more" << endl;
        xx++;
    }
    //forech in c++
    for(auto x:vec){
        cout << x << " is a vec element" << endl;
    }
    cout << "yo the first loop is over now the poointer one" << endl;

    //the cooler foreach
    for (auto &x:vec){
        x=x+1;
        cout << x << " is a vec element" << endl;
        if(x==10){
            break;
        }
    }

    //calling fucntion with refrence
    int xxx = 20;
    cout << "xxx is " << xxx << endl;
    change(xxx);
    cout << "xxx is " << xxx << endl;
    changepoint(&xxx);
    cout << "xxx is " << xxx << endl;

    //structs
    struct structest s = {5.6, 9.2, nullopt};
    s.sx = 100.2; s.sy = 100.9;
    cout << s.sx << " | " << s.sy << " | " << s.sum() << " | " << sizeof(s) << endl;
    //you can have pointer to sturcts, like normal pointers really nothing special, in order to access stuff use -> instead of .
    stt ss ={5};
    cout << ss.x << endl;
    stt *ssp = &ss;
    cout << ssp->x << endl;

    //refrences, AKA EASY POINTERS, it can be the reurn of a function or argument
    int refrenced = 10;
    int &ref = refrenced;
    cout << "ref is: " << ref << endl;
    ref++;
    cout << "red is: " << ref << " and refrenced is: " << refrenced << endl;

    //basic pointers, btx int$ ptr = int *ptr
    int* ptr = &xxx;
    *ptr = 150;
    cout << "xxx is " << xxx << endl;
    int *nptr = NULL;
    cout << "the null pointers address is: " << &nptr << "they are usually used as int x; like for initializing" << endl;
    void* vptr = &xxx;
    cout << "the voic pointer is" << *(static_cast<int*>(vptr)) << endl;

    //MEMORY MANAGEMENT C STYLE YO
    //mighty malloc, calloc also exists and the only difference is that it initilizes the elements with 0 not NULL
    int *mptr = (int*)malloc(sizeof(int) * 5);
    if(mptr==NULL){
        cout << "no memory left, sorry" << endl;
        exit(0);
    }
    for(int i=0; i<5; i++){
        mptr[i] = i;
    }
    for(int i=0; i<5; i++){
        cout << mptr[i] <<endl;
    }
    //mighty realloc
    mptr = (int *)realloc(mptr, sizeof(int) * 6);
    mptr[5] = 5;
    for(int i=0; i<6; i++){
        cout << mptr[i] <<endl;
    }
    free(mptr);
    mptr=NULL; //this is for good practice, kinda crazy how easy that was, almost like i was overestimating this shit

    //MEMORY MANAGEMENT C++ STYLE, CAN'T MIX IT UP WITH C STYLE   
    int *cptr = new int(5);
    cout << "c++ pointer address: " << cptr << endl;
    cout << "c++ pointer value is: " << *cptr << endl;
    *cptr = 6;
    cout << "c++ pointer value is: " << *cptr << endl;

    int *cptra = new int[3] {1,2,3};
    for(int i=0; i<3; i++){
        cout << "cptra says: " << cptra[i] << endl;
    }
    delete mptr;
    delete[] cptra;

    //smart pointer, used wuth the c++ management style

    //auto_ptr<int> aptr(new int(5));
    //cout << "the auto pointer says: " <<  *aptr << endl;
    //auto pointer are shit, they change ownership behind teh scenes and you shouldn't use them

    auto uptr = make_unique<int>(5);//or with unique_ptr<int> as the data type instead of auto
    auto uptr2 = make_unique<int>();
    uptr2 = move(uptr);
    cout << "unique pointer1: " << *uptr << "unique pointer 2: " << *uptr2 << endl;
    //in unique pointer memory get dealocated/freed when the unique pointer is out of scope, unless it's been moved then it's when that one is out od scope

    auto sptr = make_shared<int>(5);
    auto sptr2 = make_shared<int>();
    sptr2 = sptr;
    cout << "shared pointers say: " << *sptr << sptr2 << endl;
    //memry gets freed when all the pointers are out of scope, i think

    shared_ptr<int> swptr = make_shared<int>(5);
    weak_ptr<int> wptr;
    wptr = swptr; 
    cout << "weak pointer says: " << wptr.lock() << endl;
    swptr.reset();
    cout << "weak pointer says: " << wptr.lock() << endl;//segmentation fault, the memory has been reset
    //weak pointers exists so we avoid the pointer cycle where memory can never be freed, just use it when two shared pointers point to each other

    //aight now for oop, which i don't even think i will use since structs can take functions, in second thoughts i will leave this for later
    //same goes for templates which are c++ generics

    //lambdas, which are basically true inline functions, they have a shit ton of features, can't be bothered to learn them now
    auto res = [] (int x){
        return (x*2);
    };
    cout << "the lambda says" << res(5) << endl;

    //goto exists, somehow, it gives assembly vibes
    cout << "Hello, World!" << endl;
    cout << hey() << endl;
    cout << yo() << endl;


    //concurrency/multithreading
   // thread otherthread(concfunc);
    //otherthread.join();



    
    return 0; 
}



int yo(int k){
    int y = k;
    return y;
}

string hey(){
    return "hey people";
}

