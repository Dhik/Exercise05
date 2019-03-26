/*
Nama: Mohammad Dhikri
npm: 140810180075
tanggal pembuatan: 26 Maret 2019
Deskripsi: pretest 04
no :1
Kelas: A
*/

//https://github.com/Dhik/Pretest-04.git
#include <iostream>
using namespace std;
struct Pembalap {
   int nomor;
   char nama[20];
   int waktu;
   Pembalap* next;
   Pembalap* prev;
};
typedef Pembalap* pointer;
typedef pointer list;
void createList(list& first){
	first=NULL;
}
void createNode(pointer& p){
	p= new Pembalap;
	cout<<"Nomor : "; cin>>p->nomor;
	cout<<"Nama : "; cin>>p->nama;
	cout<<"Waktu : "; cin>>p->waktu;
	p->next=NULL;
	p->prev=NULL;
}
void insertFirst(list& first, pointer p){
	if(first==NULL){
		first=p;
	}
	else{
		p->next=first;
		first->prev=p;
		first=p;
	}
}
// insert before a node
/*void insertBefore(list& First, pointer pCari, pointer pBaru){
	if (pCari->next==NULL){  
		cout<<"Unfounded....! "<<endl; 
	} 
	else {	
		pBaru->next=pCari;
		pBaru->prev=pCari->prev;
		pCari->prev->next=pBaru;
		pCari->prev= pBaru;
	} 
}
*/
void insertBefore(list& First, pointer pCari, pointer pBaru){ 
// I.S  List First mungkin kosong dan pBaru sudah //      terdefinisi 
// F.S  List bertambah satu elemen didepan dengan pBaru
	if (First==NULL)           // kasus kosong 
		First=pBaru; 
	else { //  kasus ada isi 
		pBaru->next=pCari;
		pBaru->prev=pCari->prev;
		pCari->prev->next=pBaru;
		pCari->prev= pBaru;
	}
}
// delete a node that have the key
void deleteByKey(Pembalap* &head, int nomorKey, Pembalap* &deletedNode);
void search(Pembalap* &firstNode, int nomorKey, Pembalap* &pToUpdate);
void traversal(list first){
	pointer pBantu;
	if (first==NULL){
		cout<<"Empty List....! "<<endl;
	}
	else{
		pBantu=first;
		do{
			cout<<pBantu->nomor<<endl;
			cout<<pBantu->nama<<endl;
			cout<<pBantu->waktu<<endl;
			pBantu=pBantu->next;
		}
		while(pBantu!= NULL);
	}
}
/*// sorting ascending
void sortingByNomor(Pembalap* &head);
// update Pembalap from user input
void update(Pembalap* firstNode, int nomorKey);
*/
void linearSearch(list First,char key, int& found, pointer& pCari){ 
	found=0;         // belum ditemukan 
	pCari=First;     // pencarian mulai dari elemen pertama     
	while (found==0 && pCari!=NULL) { 
		if (pCari->nomor==key) 
			found=1; 
		else pCari=pCari->next; 
	} 
}

typedef pointer poin[100];
main(){
	int n, keyNomor, found;
	poin pBaru;
	pointer pCari, pB;
	list pembalap;
	
	createList(pembalap);
	
	cout<<"Masukan banyak data : "; cin>>n;
	for (int i = 0; i < n; i++) {
   		createNode(pBaru[i]);
   		insertFirst(pembalap, pBaru[i]);
 	}

 	cout << "\n>>> List" << endl;
 	traversal(pembalap);

 	cout << "\n>>> Insert Before nomor "; cin>>keyNomor;
 	linearSearch(pembalap, keyNomor, found, pCari);
	if(found){
		cout<<"Founded...!"<<endl;
		createNode(pB);
		insertBefore(pembalap, pCari, pB);	
		traversal(pembalap);
	}
	else{
		cout<<"Unfounded...!"<<endl;
	}
// >>> lanjut ke samping >>> 

/*	 cout << "\n>>> SortingByNomor" << endl;
 	sortingByNomor(head);
 	traversal(head);

 	keyNomor = 3;
 	cout << "\n>>> Delete nomor " << keyNomor << endl;
 	Pembalap* pHapus = NULL;
 	deleteByKey(head, keyNomor, pHapus);
 	traversal(head);

 	keyNomor = 4;
 	cout << "\n>>> Update nomor " << keyNomor << endl;
 	update(head, keyNomor);

 	cout << "\n>>> Updated list\n";
 	traversal(head);
 	*/
}


