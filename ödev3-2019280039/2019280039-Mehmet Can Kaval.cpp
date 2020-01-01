#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;
int selectionSort(double dizi[],int elemanSayisi,string numara[]){ //�nceki quizden kald� buraya yap�st�r�p ge�tim :D
	 int temp,enKucukDeger;
	 string strTemp;
	 
	 for(int i=0;i<elemanSayisi;i++){
	 	enKucukDeger=i;
	 	for(int  j=i+1;j<elemanSayisi;j++)
	 	if(dizi[j]<dizi[enKucukDeger]){
				enKucukDeger=j;								/*buradaki stringide dondurme hasim ensar kavakdan al�nt�d�r :)*/
				temp=dizi[enKucukDeger];
				strTemp=numara[enKucukDeger];
				dizi[enKucukDeger]=dizi[i];
				numara[enKucukDeger]=numara[i];
				dizi[enKucukDeger]=temp;
				numara[enKucukDeger]=strTemp;
				}
	 }
	 
	 int aciklik=dizi[0]-dizi[enKucukDeger];				/*acikligi burda d�nd�rd�m*/
	 return aciklik;
	}
	
	double Diziortalama(double dizi[],int elemanSayisi){
		double ortalama,toplam;
		for (int i=0;i<elemanSayisi;i++){
			toplam=dizi[i]+toplam;
			}
			ortalama=toplam/elemanSayisi;
			return ortalama;
	}
	int medyan(double dizi[],int elemanSayisi){
	int medyan,ortaEleman;
	if(elemanSayisi%2==0){
		ortaEleman=elemanSayisi/2;
		medyan=(dizi[ortaEleman]+dizi[ortaEleman+1])/2;
		return medyan;
	}
	else{//elemanSayisi tek ise
		ortaEleman=elemanSayisi/2;//int zaten
		medyan=dizi[ortaEleman];
		return medyan;
	}
	}
	
int main(){
	ifstream dosya;
	dosya.open("input.txt");
	string soru,cvpA;
	getline(dosya,soru);
	int soruSayisi=stoi(soru);
	//cout<<soruSayisi<<endl;//kontrol
	char cevapAnahtari[soruSayisi];
	getline(dosya,cvpA);
	int x=0;
	strcpy(cevapAnahtari,cvpA.c_str());
	//cout<<cevapAnahtari<<endl;//kontrol
	string ogrID[100],ogrCevap[100];
	int satirSayisi=0;
	while(!dosya.eof()){
		dosya>>ogrID[satirSayisi]>>ogrCevap[satirSayisi];
		satirSayisi++;
	}
	double puan[100] = {0};int dogru[100] = {0};int yanlis[100]= {0};int bos[100]= {0};;//puanlama icin laz�m olan her sey;
	for(int i=0;i<satirSayisi;i++){
		int x = 0;
		for(int j=0;j<10;j++){//virg�llerle birlikte ogrenci cevaplara 10 eleman yapt�g� icin 10kere d�nmesi laz�md� :)
			if (ogrCevap[i][j] != ',')
            {
                if (cevapAnahtari[x] == ogrCevap[i][j])
                {
                    dogru[i]++;
                }else if (ogrCevap[i][j] == 'x')
                {
                    bos[i]++;
                } else
                {
                    yanlis[i]++;
                }
                x++;
                j++;

            }
			
		}
	}
	int k=0;
	while(k<satirSayisi){
		puan[k]=((dogru[k]*4)-(yanlis[k]*1)+(bos[k]*0))*(100/20);// sinav�m�z�n 100 �zerinden olmas� i�in programdaki 
		if(puan[k]<0){											//  not 20 �zerinden oldugu i�i 100 ile �arp�p 20 ye b�l�yoruz :)
			puan[k]=0;
		}
        k++;
	}
	dosya.close();
	cout<<endl<<endl;
	ofstream out("output.txt");// burdan sonra medyan falan bul dosyaya yazd�r (kendime not)
	
	selectionSort(puan,satirSayisi,ogrID);
	cout<<"*********NOTLARLA ILGILI DOSYA OLUSTURULMUSTUR*********"<<endl;
	out<<"Ogrencilerin notlar�n�n siralanm�s hali"<<endl;
	for (int i=0;i<satirSayisi;i++){
		out<<ogrID[i]<<" "<<puan[i]<<endl;
	}
	out<<endl<<endl;
	
	out<<"Ogrencilerin Not Ortalamas� : "<<Diziortalama(puan,satirSayisi)<<endl;
	out<<"Notlarin Aciklik Degeri : "<<selectionSort(puan,satirSayisi,ogrID)<<endl;
	out<<"Notlarin Medyani : " <<medyan(puan,satirSayisi)<<endl;
	out.close();
}
/*	
	Mert Elektronik discord
	https://stackoverflow.com/questions/3072795/how-to-count-lines-of-a-file-in-c
	http://www.cplusplus.com/reference/string/string/at/
	http://www.cplusplus.com/reference/cstring/
*/
