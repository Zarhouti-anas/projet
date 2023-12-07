#include <iostream>
using namespace std;
#include <fstream>

void echanger(long& A, long& B)
{
	long transfert = A;
	A = B;
	B = transfert;
}
void Lire(string nomFichierEntree, long T[], long& N)
{
	ifstream entree(nomFichierEntree, ios::in);
	entree >> N;
	for (long K = 0; K < N; K++)
		entree >> T[K];
	entree.close();
}
void Ecrire(string nomFichierSortie, long T[], long N)
{
	ofstream sortie(nomFichierSortie, ios::out);
	sortie << N;
	for (long K = 0; K < N; K++)
		sortie << T[K] << endl;
	sortie.close();
}

bool triPartielInsertion(long T[], long debut, long fin)
{
	bool changer = false;
	for (long i = debut + 1; i > 0; i--)
	{
		if (T[i] < T[i - 1])
		{
			echanger(T[i], T[i - 1]);
			changer = true;
		}
	}
	return changer;

}

void TriParInsertion(long T[], long debut, long fin)
{

	for (long droite = debut + 1; droite <= fin; droite++)
	{
		triPartielInsertion(T, debut, droite);
	}
		

}
int main()
{
	const long tailleDuTableau = 10000;
	long T[tailleDuTableau] = { 0 };
	long N = 0, debut, fin;
	string nomFichierEntree;
	string nomFichierSortie;
	string nomFichierCommandes;
	cout << "Entrer le nom du fichier de commandes : ";
	cin >> nomFichierCommandes;
	ifstream commandes(nomFichierCommandes, ios::in);
	commandes >> nomFichierEntree;
	commandes >> nomFichierSortie;
	commandes >> debut;
	commandes >> fin;
	commandes.close();
	Lire(nomFichierEntree, T, N);
	if (N == 0)
	{
		cout << "La lecture des donnes est un echec." << endl;
		return -1;
	}
	if (debut < 0 || fin < debut || fin >= N)
	{
		cout << " le debut et la fin ne sont pas valider ";
		return -2;
	}
	TriParInsertion(T, debut, fin);
	Ecrire(nomFichierSortie, T, N);


}