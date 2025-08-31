// Experiment 1: Add two matrices
#include <iostream>
using namespace std;
int main() {
    int a[2][2], b[2][2], sum[2][2];
    cout << "Enter first 2x2 matrix:\n";
    for(int i=0;i<2;i++) for(int j=0;j<2;j++) cin >> a[i][j];
    cout << "Enter second 2x2 matrix:\n";
    for(int i=0;i<2;i++) for(int j=0;j<2;j++) cin >> b[i][j];
    for(int i=0;i<2;i++) for(int j=0;j<2;j++) sum[i][j] = a[i][j] + b[i][j];
    cout << "Sum:\n";
    for(int i=0;i<2;i++){ for(int j=0;j<2;j++) cout << sum[i][j] << " "; cout << "\n"; }
    return 0;
}

// Experiment 2: Array menu-driven program
#include <iostream>
using namespace std;
int main(){
    int arr[100], n=0, choice, pos, elem;
    while(true){
        cout << "\n1. Display 2. Insert 3. Delete 4. Exit: ";
        cin >> choice;
        if(choice==1){
            for(int i=0;i<n;i++) cout << arr[i] << " "; cout << "\n";
        } else if(choice==2){
            cout << "Enter element and position: "; cin >> elem >> pos;
            for(int i=n;i>pos;i--) arr[i]=arr[i-1]; arr[pos]=elem; n++;
        } else if(choice==3){
            cout << "Enter position: "; cin >> pos;
            for(int i=pos;i<n-1;i++) arr[i]=arr[i+1]; n--;
        } else break;
    }
}

// Experiment 3: Linear Search
#include <iostream>
using namespace std;
int main(){
    int n, key; cin >> n;
    int arr[n]; for(int i=0;i<n;i++) cin >> arr[i];
    cin >> key;
    for(int i=0;i<n;i++) if(arr[i]==key){ cout << "Found at position " << i; return 0; }
    cout << "Not found"; return 0;
}

// Experiment 4: Binary Search
#include <iostream>
using namespace std;
int main(){
    int n,key; cin >> n;
    int arr[n]; for(int i=0;i<n;i++) cin >> arr[i];
    cin >> key; int l=0,r=n-1;
    while(l<=r){
        int m=(l+r)/2;
        if(arr[m]==key){ cout << "Found at position "<<m; return 0; }
        else if(arr[m]<key) l=m+1; else r=m-1;
    }
    cout << "Not found"; return 0;
}

// Experiment 5: Bubble Sort
#include <iostream>
using namespace std;
int main(){
    int n; cin >> n; int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
    for(int i=0;i<n;i++) cout << arr[i] << " ";
}

// Experiment 6: Selection Sort
#include <iostream>
using namespace std;
int main(){
    int n; cin >> n; int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++) if(arr[j]<arr[min]) min=j;
        swap(arr[i],arr[min]);
    }
    for(int i=0;i<n;i++) cout << arr[i] << " ";
}

// Experiment 7: Insertion Sort
#include <iostream>
using namespace std;
int main(){
    int n; cin >> n; int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=1;i<n;i++){
        int key=arr[i], j=i-1;
        while(j>=0 && arr[j]>key){ arr[j+1]=arr[j]; j--; }
        arr[j+1]=key;
    }
    for(int i=0;i<n;i++) cout << arr[i] << " ";
}

// Experiment 8: Merge Sort
#include <iostream>
using namespace std;
void merge(int arr[],int l,int m,int r){
    int n1=m-l+1, n2=r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int j=0;j<n2;j++) R[j]=arr[m+1+j];
    int i=0,j=0,k=l;
    while(i<n1&&j<n2) arr[k++] = (L[i]<=R[j])?L[i++]:R[j++];
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
}
void mergeSort(int arr[],int l,int r){
    if(l<r){ int m=(l+r)/2;
        mergeSort(arr,l,m); mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
int main(){
    int n; cin >> n; int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++) cout << arr[i] << " ";
}

// Experiment 9: Singly Linked List Menu
#include <iostream>
using namespace std;
struct Node{int usn; string name,branch; int sem; string ph; Node* next;};
Node* head=nullptr;
void insertBeg(Node* n){n->next=head; head=n;}
void insertEnd(Node* n){ if(!head){head=n;return;} Node* t=head; while(t->next) t=t->next; t->next=n;}
void display(){Node* t=head; int c=0; while(t){cout<<t->usn<<" "<<t->name<<"\n";t=t->next;c++;} cout<<"Count="<<c;}
int main(){int ch; while(true){
 cout<<"\n1.InsertBeg 2.InsertEnd 3.Display 4.Exit: ";cin>>ch;
 if(ch==1){Node* n=new Node;cin>>n->usn>>n->name;n->next=nullptr;insertBeg(n);} 
 else if(ch==2){Node* n=new Node;cin>>n->usn>>n->name;n->next=nullptr;insertEnd(n);} 
 else if(ch==3) display(); else break; }}

// Experiment 10: Sorted Circular Linked List
#include <iostream>
using namespace std;
struct Node{int data; Node* next;};
Node* head=nullptr;
void insert(int x){Node* n=new Node{x,nullptr}; if(!head){head=n;n->next=head;return;} Node* t=head; Node* prev=nullptr; do{if(t->data>x) break; prev=t; t=t->next;}while(t!=head);
 if(!prev){n->next=head; Node* last=head; while(last->next!=head) last=last->next; last->next=n; head=n;} else {prev->next=n; n->next=t;} }
void display(){if(!head) return; Node* t=head; do{cout<<t->data<<" ";t=t->next;}while(t!=head);}
int main(){int ch,x; while(true){cout<<"\n1.Insert 2.Display 3.Exit:";cin>>ch; if(ch==1){cin>>x;insert(x);} else if(ch==2) display(); else break; }}
