#include <iostream>
using namespace std;

struct Link{
	int data;
	struct Link* next;
};

void sort(Link* head,int n){
	Link *head2=NULL,*p1=NULL,*p2=NULL,*pr1=NULL,*pr2=NULL;
	int i;
	if(n>3){
	    head2 = head->next;
		p1 = head;
		p2 = head2;
	    for(i=3;i<n;i=i+2){
			pr1 = p1->next->next;
			p1->next = pr1;
			p1 = pr1;
			pr2 = p2->next->next;
			p2->next = pr2;
			p2 = pr2;
		}
		if(n%2==0){
			pr1->next = head2;
			pr2->next = NULL;
		}
		else{
			pr1 = pr2->next;
			p1->next = pr1;
			pr1->next = head2;
			pr2->next = NULL;
		}
	}
	else if(n==3){
		head2 = head->next;
		p1 = head;
		p2 = head2;
		pr1 = p1->next->next;
		p1->next = pr1;
		pr1->next = head2;
		p2->next = NULL;
	}	
	else return;
}

int main(){
	Link *head=NULL,*p1=NULL,*p2=NULL,*p=NULL;
	int i,n;
	cout<<"How many nodes do you want to input?"<<endl;
	cin>>n;
	int *datas = new int[n];
	cout<<"Input the datas: ";
	for(i=0;i<n;i++){
		cin>>datas[i];
	}
	head = new Link;
	p1 = head;
	p2 = p1;
	for(i=0;i<n;i++){
		p2 = new Link;
		p1->data = datas[i];
		p1->next = p2;
		p1 = p2;
	}
    sort(head,n);
	cout<<"The final order is: "<<endl;
	p = head;
	for(i=0;i<n;i++){
		cout<<p->data<<"->";
		p = p->next;
	}
	cout<<"NULL"<<endl;
	p1 = head;
	p2 = p1->next;
	delete []datas;
	for(i=0;i<n;i++){
		delete p1;
		p1 = p2;
		p2 = p2->next;
	}
	return 0;
}

