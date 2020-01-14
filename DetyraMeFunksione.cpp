#include<iostream>
#include <string>
using namespace std;

void towerOfHanoi(int n, char from_rod,
	char to_rod, char aux_rod);

bool isPrime(int n, int i = 2);

int power(int x, int y);


void print(int p);

string Pjestuesit(int x, int indeks, string u);

int GjejShmvp(int x, int y);

int pmp(int n1, int n2);

double e(int n);
	long f(int n);

	int funks(int n, int temp);

void convert(int f);

void reverse(string& str, int k);

int fun2(int n, int m);
int fun1(int n, int m);

string HiqKarakter(string text, char c, int index = 0);
			

int main()
{
	
	int x;
	cout << "Shtyp numrat per funksionet\n"
		<< "1 per Kullat e Hanoit\n"
		<< "2 per te kontrolluar nese nje numer eshte i thjeshte\n"
		<< "3 per llogaritjen e fuqise me cfaredo baze e eksponenti\n"
		<< "4 per printimin e numrave nga n deri ne 1 duke u zvogluar\n"
		<< "5 per gjetjen e PMMP te dy numrave\n"
		<< "6 per llogaritjen e konstantes se Eulerit\n"
		<< "7 per te testuar se a eshte nje numer polidrom\n"
		<< "8 per te kthyer nje numer decimal ne binar\n"
		<< "9 per te gjetur dyshet e numrit n\n"
		<<"10 per te hequr karakter\n"
		<<"11 per te gjetur faktoret e nje numri\n"
		<<"13 per te gjetur SHMVP te dy numrave\n"
		<< "13 per te kthyer nje string mbrapsht\n";

		
		cin >> x;

		switch (x) {
		case 1:
			cout << "//Kullat e Hanoit//";
			int n ;
			cout << "Jep numrin e disqeve: ";
			cin >> n;
			towerOfHanoi(n, 'A', 'C', 'B'); 
			break;
		case 2:
			
			int l ;
			cout << "Shtyp numrin per te kontrolluar";
			cin >> l;

			if (isPrime(l))
				cout << "Numri eshte i thjeshte";
			else
				cout << "Numri nuk eshte i thjeshte";
			break;
			
		case 3:
			int i, j;
			cout << "Shtyp bazen";
			cin >> i;
			cout << "shtyp eksponentin";
				cin >> j;

				cout <<"rezultati"<< power(i, j);
				break;
		
		case 4:
			int o;
			cout << "Shtyp numrin";
				cin >> o;

				print(o);
				break;
				
		
			
		case 5:
			int q, f;
			cout << "Shtyp numrat per te gjetur PMMP";
			cin >> q >> f;
			cout << "PMMP e " << q << " dhe " << f << " :";
			cout << pmp(q, f);
			break;
		case 6:

			cout << "Konstantja e Eulerit eshte: ";

			cout << e(10);
			break;

		case 7: {
			int num;
			cout << "Shtyp numrin: ";
			cin >> num;

			int rez = funks(num, 0);

			if (rez == num)
				cout << "Numri " << num << " eshte polindrom" << endl;
			else
				cout << "Numri " << num << " nuk eshte polindrom" << endl;
			break;
		}
		case 8:
			int m;
			cout << "Jep numrin per ta kthyer ne numer binar";
			cin >> m;
			cout << "Numri" << m << "ne numer binar:";
			convert(m);
			break;

		

		case 9:
			int u;
			cout << "Shtyp numrin: ";
			cin >> u;
			cout << "Faktoret 2 te " << u << "jane";
			fun1(1, u);
			break;

		case 10:
			cout << HiqKarakter("Florian", 'F',0);
			break;

		case 11:
			int num;
			cout << "Shtyp numrin:";
			cin >> num;
			cout << Pjestuesit(num, 1, "");
			break;


		case 12:
			int num1, num2, SHMVP;

			
			cout << "Shkruaj dy numra per te gjetur SHMVP: " << endl;
			cin >> num1;
			cin >> num2;

			if (num1 > num2)
				SHMVP = GjejShmvp(num2, num1);
			else
				SHMVP = GjejShmvp(num1, num2);

			cout << "SHMVP i " << num1 << " dhe " << num2 << " eshte: " << SHMVP;

		case 13:
			string str;
			cout << "Jepni fjalen per te kthyer mbrapsht: ";
			cin >> str;

			reverse(str, 0);
			cout << "String mbrapsht eshte: " << str;
			break;
				
		
	}

		

	
}

//Zgjidhja per Kullat e Hanoit
//Kullat e hanoit perbehen nga 3 shtylla dhe n disqe te shkallezuara, kerkesa eshte qe disqet
//qe gjenden ne shtyllen 'a' te zhvendosen ne shtyllen 'b' ne ate menyre qe 
//nese disku eshte me i madh se disku perkates nuk mundet te vendoset mbi te.
void towerOfHanoi(int n, char from_rod,
	char to_rod, char aux_rod)
{
	if (n == 1)
	{
		cout << "Leviz diskun 1 nga shtylla " << from_rod <<
			" te shtylla " << to_rod << endl;
		return;
	}
	towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
	cout << "Leviz diskun " << n << " nga shtylla " << from_rod <<
		" te shtylla " << to_rod << endl;
	towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

//Printon numrat nga p deri ne 1;
void print(int p)
{
	if (p == 0)
		return;
	cout << p<<"\n";
	print(p - 1);
	return;
}

//kalkulon fuqin me bazen x e eksponent y
int power(int x, int y) {
	

	if (y != 0)
		return x * power(x, y - 1);
	else
		return 1;

}

//Kalkulon pjestuesin me te madh te perbashket
int pmp(int n1, int n2)
{
	if (n2 != 0)
		return pmp(n2, n1 % n2);
	else
		return n1;
}

//tregon se a eshte nje numer i thjeshte  
bool isPrime(int n, int i)
{
	if (n <= 2)
		return (n == 2) ? true : false;
	if (n % i == 0)
		return false;
	if (i * i > n)
		return true;

	
	return isPrime(n, i + 1);
}

//kalulon vleren e konstantes se Eulerit e cila kalkulohet
//  1/1!+1/2!+...+1/n!
double e(int n) {
	if (n == 0) {
		return 1.0;
	}
	return 1.0 / f(n) + e(n - 1);
}
//funksioni ndihmes per konstanten e Eulerit
long f(int n) {
	if (n == 1) return 1;
	return n * f(n - 1);
}
using namespace std;

//funksioni qe gjen gjatesine e karaktereve
//komanda '/0' sherben ne vend te null ose blank\
// char* eshte pointer qe permban veten adresen te variables
int gjatesia(char* str)
{
	// if we reach at the end of the string 
	if (*str == '\0')
		return 0;
	else
		return 1 + gjatesia(str + 1);
}

//Tregon a eshte nje numer polidrom.

/*Numri polidrom eshte numri qe ka vlere te njejte edhe nese 
lexohet nga mbrapa p.sh 131, 1441.*/
int funks(int n, int temp)
{
	if (n == 0)
		return temp;

	temp = temp * 10 + n % 10;
	return funks(n / 10, temp);
}

// Komanda to_string ben konvertimin e nje numri ne string
string Pjestuesit(int x, int indeks, string u)
{
	if (indeks <= x) {
		if (x % indeks == 0)
			u += to_string(indeks) + " ";
		return Pjestuesit(x, indeks + 1, u);
	}
	return u;
}

//Konvertimi ne numer binar
void convert(int f)
{
	if (f > 1)
		convert(f / 2);
	cout << f % 2;
}

//kthimi mbrapsht i string-ut
void reverse(string& str, int k)
{
	static int i = 0;

	// nese kemi arritu ne fund te string-ut
	if (k == str.length())
		return;

	reverse(str, k + 1);

	if (i <= k)
		swap(str[i++], str[k]);
}

//Faktoret 2 te nje numri
int fun1(int n, int m) {
	if (n > m)
		return 0;
	return fun2(n + 1, m);
}
int fun2(int n, int m) {
	cout << n << " ";
	return fun1(n + 1, m);
}

//heq karakter nga nje string
string HiqKarakter(string teksti, char c, int indeks)
{
	if (indeks < teksti.length()) {
		if (teksti[indeks] == c)
			teksti = teksti.substr(0, indeks) + teksti.substr(indeks + 1, teksti.length() - 1);
		return HiqKarakter(teksti, c, indeks + 1);
	}
	return teksti;
}
//Shmvp
int GjejShmvp(int x, int y)
{
	static int shumzuesi = 0;

	//rrit shumzuesi-n duke i mbledhur vlera te y
	shumzuesi += y;

	if ((shumzuesi % x == 0) && (shumzuesi % y == 0))
	{
		return shumzuesi;
	}
	else
	{
		return GjejShmvp(x, y);
	}
}