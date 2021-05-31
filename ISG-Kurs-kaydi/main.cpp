#include <iostream>
#define SIZE 10

using namespace std;

struct node{
    int id;
    string ad, soyad, bolum;
    node* next;
};


struct stack{
    node *top= NULL;
    int counter=0;
};

struct geriStack{
    int secim[SIZE]; //Silme islemi yapilirsa 0, ekleme yapilirsa 1
    int id[SIZE], indis=-1;
    string ad[SIZE], soyad[SIZE], bolum[SIZE];
};

geriStack gs;


void push(stack *stk, int id, string ad, string soyad, string bolum){
    gs.indis++;
    gs.id[gs.indis]=id;
    gs.ad[gs.indis]=ad;
    gs.soyad[gs.indis]=soyad;
    gs.bolum[gs.indis]=bolum;
    gs.secim[gs.indis]=1;

    node *temp = new node();
    temp->ad=ad;
    temp->soyad=soyad;
    temp->id=id;
    temp->bolum=bolum;

    if(stk->counter==10){ //Stack dolu ise
        cout << "Kontenjan doldugu icin kayit yapilamadi!" << endl;}

    else if(stk->counter==0){ //Stack bos ise
        stk->top=temp;
        stk->top->next=NULL;
        stk->counter++;
        cout << id << " numarali ilk ogrenci kursa kaydedildi!" << endl;}

    else{ //Stack ne bos ne de dolu ise
        temp->next=stk->top;
        stk->top=temp;
        stk->counter++;
        cout << id << " numarali ogrenci kursa kaydedildi!" << endl;}
}

void pop(stack *stk){
    if(stk->counter==0){ //Stack bos ise
        cout << "Kayit listesi bos!" << endl;}
    else{
        gs.indis++;
        gs.id[gs.indis]=stk->top->id;
        gs.ad[gs.indis]=stk->top->ad;
        gs.soyad[gs.indis]=stk->top->soyad;
        gs.bolum[gs.indis]=stk->top->bolum;
        gs.secim[gs.indis]=-1;

        if(stk->top->next==NULL){ //Tek elemanli stack ise
            cout << stk->top->id << " numarali tek ogrencinin kaydi silindi!" << endl;
            delete stk->top;
            stk->top=NULL;
            stk->counter--;}

        else{
            cout << stk->top->id << " numarali ogrencinin kaydi silindi!" << endl;
            node *temp2= stk->top->next;
            delete stk->top;
            stk->top=temp2;
            stk->counter--;}
    }


}

void yazdir(stack *stk){
    if(stk->counter==0){ //Stack bos ise
        cout << "Kayit listesi bos!" << endl;}
    else{
        node* iter=stk->top;
        while(iter!=NULL){
            cout << iter->id << " " << iter->ad << " " << iter->soyad << " " << iter->bolum << " " << endl;
            iter=iter->next;}}
}

void geriAl(stack *stk){
    if(gs.secim[gs.indis]==1){
        cout << stk->top->id << " numarasiyla kaydedilen ogrenci silindi!" << endl;
        node* temp= stk->top->next;
        delete stk->top;
        stk->top=temp;
        stk->counter--;}

    else if(gs.secim[gs.indis]==-1){
        node *temp= new node();
        temp->id=gs.id[gs.indis];
        temp->ad=gs.ad[gs.indis];
        temp->soyad=gs.soyad[gs.indis];
        temp->bolum=gs.bolum[gs.indis];
        gs.indis++;

        temp->next=stk->top;
        stk->top=temp;
        stk->counter++;
        cout << stk->top->id << " numarali ogrenci kursa yeniden kaydedildi!" << endl;}


    else{
        cout << "Hicbir islem yapilmadi!" << endl;}


}

int main()
{
    stack stk;
    int id, secim;
    string ad, soyad, bolum;
    while(true){
        cout << endl;
        cout << "ISG Kurs Kayit Uygulamasi" << endl;
        cout << "0- Cikis" << endl;
        cout << "1- Push (Ekle)" << endl;
        cout << "2- Pop (Cikar)" << endl;
        cout << "3- Geri al" << endl;
        cout << "4- Print (Yazdir)" << endl;
        cout << "Yapmak istediginiz islemi seciniz: ";
        cin >> secim;
        switch(secim){
        case 0:
            cout << "Cikis yapiliyor..." << endl;
            return 0;
        case 1:
            cout << "Numarasini giriniz: "; cin >> id;
            cout << "Adini giriniz     : "; cin >> ad;
            cout << "Soyadini giriniz  : "; cin >> soyad;
            cout << "Bolumunu giriniz  : "; cin >> bolum;
            push(&stk,id,ad,soyad,bolum);
            break;
        case 2:
            pop(&stk);
            break;
        case 3:
            geriAl(&stk);
            break;
        case 4:
            yazdir(&stk);
            break;}
    }
    return 0;
}
