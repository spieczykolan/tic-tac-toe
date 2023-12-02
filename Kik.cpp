#include <iostream>

using namespace std;

#define X 3
#define Y 3

char pole[X][Y];
int graj(char pole[][Y], int ruch);
void stworz_pole(char pole[][Y]);
char wyswietl_pole(char pole[][Y]);
int sprawdz_wynik(char pole[][Y], int ruch);

int main(){

	int ruch = 1;
	int opcja = 0;
	int koniec = 0;

	cout << "Witamy w kolko i krzyzyk !" << endl << "Jesli chcesz rozpoczac gre wprowadz: 1, jesli nie wprowadz: 0. Opcja : ";
	cin >> opcja;

	while(opcja != 1 && opcja != 0){
		cout << "Wprowadz poprawna opcje : ";
		cin >> opcja;
	}
	
	if(opcja == 1){
		stworz_pole(pole);
		wyswietl_pole(pole);
		koniec = graj(pole, ruch);		
	}
	
	else if(opcja == 0) cout << "Do zobaczenia wkrotce !" << endl;

	return 0;
}

int graj(char pole[][Y], int ruch){

	int status = 0;
	
	while(ruch <= 9){
		int kolumna = 0;
		int wiersz = 0;
		int wynik = 0;
		cout << " Wybierz kolumne i wiersz : ";
		cin >> kolumna >> wiersz;
		if(pole[wiersz][kolumna] != '#'){
	
			cout << "Wybierz wlasciwe pole. ";
	
		}
		else{
			if(ruch % 2 != 0){
				pole[wiersz][kolumna] = 'X';
			}
			else pole[wiersz][kolumna] = 'O';
			
			cout << "-------------------------" << endl;
			cout << "Ruch : " << ruch << endl;
			cout << "-------------------------" << endl;
			wynik = sprawdz_wynik(pole, ruch);
			wyswietl_pole(pole);
			if(wynik == 1){
				cout << "Wygraly krzyzyki ! " << endl;
				status = 2;
				break;
			}
			else if(wynik == 2){
				cout << "Wygraly kolka ! " << endl;
				status = 2;
				break;
			}
			ruch += 1;
		}
	}
	if(ruch == 9) status = 1;
	return status;
}

void stworz_pole(char pole[][Y]){


	for(int j = 0; j < X; j++){
	
		for(int k = 0; k <= Y; k++){
				pole[j][k] = '#';	
		}
	}
}

char wyswietl_pole(char pole[][Y]){

	cout << "    " <<  0 << "   " << 1 << "   " << 2 << endl;
	for(int i = 0; i < X; i++){
		cout << i;
		for(int j = 0; j < Y; j++){
			cout << " | " << pole[i][j];
		}
		cout << endl;
	}
	return pole[X][Y];
}

int sprawdz_wynik(char pole[][Y], int ruch){

	int licznik_x = 0;
	int licznik_o = 0;
	
	if(ruch >= 5){
	
	//Poziomo
		for(int i = 0; i < Y; i++){
			licznik_x = 0;
			licznik_o = 0;
			for(int j = 0; j < X; j++){
				if(pole[i][j] == 'X'){
					licznik_x += 1;
					if(licznik_x == 3) return 1;
				}
				else if(pole[i][j] == 'O'){
					licznik_o += 1;
					if(licznik_o == 3) return 2;
				}
			}
		}
	//Pionowo
		for(int i = 0; i < Y; i++){
			licznik_x = 0;
			licznik_o = 0;
			for(int j = 0; j < X; j++){
				if(pole[j][i] == 'X'){
					licznik_x += 1;
					if(licznik_x == 3) return 1;
				}
				else if(pole[j][i] == 'O'){
					licznik_o += 1;
					if(licznik_o == 3) return 2;
				}
			}
		}
	//Skos
		if(pole[0][0] == 'X' && pole[1][1] == 'X' && pole[2][2] == 'X') return 1;
		else if(pole[0][0] == 'O' && pole[1][1] == 'O' && pole[2][2] == 'O') return 2;	
		
		if(pole[2][0] == 'X' && pole[1][1] == 'X' && pole[0][2] == 'X') return 1;
		else if(pole[2][0] == 'O' && pole[1][1] == 'O' && pole[0][2] == 'O') return 2;	
	}
	return 0;
}
