#include<iostream>
using namespace std;

struct nod
{
    int info;
    nod *urm;
};

void append(nod* &primul, int informatie)
{
    cout<<"Succesfully added new node:";
    if(primul==NULL)
    {
        primul->info=informatie;
        primul->urm=NULL;
    }
    else
    {
        nod* nou=new nod;
        nou->info=informatie;
        nou->urm=primul;

        primul=nou;
    }
    cout<<informatie<<endl;
}
void print(nod* inceput)
{
    //cout<<"List of nodes is: ";
    while(inceput->urm!=NULL)
    {
        cout<<inceput->info<<" ";
        inceput=inceput->urm;
    }
    cout<<endl;
}
void del(nod* &inceput, int informatie)
{
    nod* parcurgere=inceput;
    while(parcurgere->urm->info!=informatie)
    {
        parcurgere=parcurgere->urm;
    }
    nod* p=new nod;
    p->info=parcurgere->urm->info;
    p->urm=parcurgere->urm->urm;

    parcurgere->urm=parcurgere->urm->urm;
    cout<<"This is the new list: ";
    print(inceput);
    cout<<"U sure u want this way? Y/N"<<endl;
    char rasp;
    cin>>rasp;
    if(rasp=='Y' || rasp=='y')
    {
        cout<<"i ve let it that way";
        delete p;
    }
    else
    {
        cout<<"Restoring list..."<<endl;
        parcurgere->urm=p;
        cout<<"This is the actual list: ";
        print(inceput);
    }

}

int main()
{
    cout<<"enter number of nodes for your list: ";
    nod* inceput;
    inceput->urm=NULL;
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cout<<"Enter a new node:"<<" ";
        int informatie_adaug;
        cin>>informatie_adaug;
        append(inceput,informatie_adaug);
    }
    cout<<"Want to delete smth? Y/N"<<endl;
    char rasp;
    cin>>rasp;
    if(rasp=='Y' || rasp=='y')
    {
        cout<<"What information do u want to delete?"<<endl;
        int del1;
        cin>>del1;
        del(inceput,del1);
    }
    else
    {
        cout<<"This is your list: ";
        print(inceput);
    }
    //print(inceput);

}
