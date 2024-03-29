#include "Includes.h"
int cromMic = 0;
int stagnari = 0;
void main() {
	Initializare_pop();
	int populatie2[100][100];
	for (int i = 0; i < nr_populatie; i++) {
		for (int j = 0; j < concatenare.size(); j++) {
			populatie2[i][j] = populatie[i][j];
		}
	}
	int fitness[100];
	Fitness(populatie, fitness);
	int ft_curent = FitnessTotal(populatie, fitness);
	int ft_anterior = 0;
	int nretape = 0;
	int nrIteratii = 0;
	while (nrIteratii <= limitaIteratii) {
		nrIteratii++;
		Selectie_dupa_rang();
		Incrutisare_discreta();
		Mutatie_uniforma();
		Noua_populatie();
		ft_anterior = ft_curent;
		Fitness(populatie, fitness);
		ft_curent = FitnessTotal(populatie, fitness);
		bool ok = false;
		for (int i = 0; i < nr_populatie; i++) {
			cout << "\n" << fitness[i];
			if (fitness[i] == 0) {
				ok = true;
			}
		}
		if (ok==true) {
			break;
		}
		if (ft_anterior == ft_curent) {
			nretape++;
			if (nretape == 20) {
				stagnari++;
				for (int i = 0; i < nr_populatie; i++) {
					for (int j = 0; j < concatenare.size(); j++) {
						populatie[i][j] = populatie2[i][j];
					}
				}
				nretape = 0;
			}
		}
	}
	cout << "\nPopulatia finala:\n";
	for (int i = 0; i < nr_populatie; i++) {
		cout << "Cromozomul " << i + 1 << ": ";
		for (int j = 0; j < concatenare.size(); j++) {
			cout << populatie[i][j] << " ";
		}
		cout << "(" << fitness[i] << ") ";
		cout << endl;
	}
	for (int i = 0; i < nr_populatie; i++) {
		if (fitness[i] == 0) {
			int text1cript = 0, text2cript = 0, text3cript = 0;
			for (int contortext1 = 0; contortext1 < text1.size(); contortext1++) {
				for (int j = 0; j < concatenare.size(); j++) {
					if (text1[contortext1] == concatenare[j]) {
						text1cript = text1cript * 10 + populatie[i][j];
						break;
					}
				}
			}
			for (int contortext2 = 0; contortext2 < text2.size(); contortext2++) {
				for (int j = 0; j < concatenare.size(); j++) {
					if (text2[contortext2] == concatenare[j]) {
						text2cript = text2cript * 10 + populatie[i][j];
						break;
					}
				}
			}
			for (int contortext3 = 0; contortext3 < text3.size(); contortext3++) {
				for (int j = 0; j < concatenare.size(); j++) {
					if (text3[contortext3] == concatenare[j]) {
						text3cript = text3cript * 10 + populatie[i][j];
						break;
					}
				}
			}
			cromMic = i;
			cout << endl << "Cromozomul " << i+1;
			cout << endl;
			cout << text1 << " - ";
			cout << text1cript << endl;
			cout << text2 << " - ";
			cout << text2cript << endl;
			cout << endl;
			cout << text3 << " - ";
			cout << text3cript << endl;
		}
	}
	cout << "\n--STATS--\n";
	cout << "Limita iteratii: " << limitaIteratii << " / realizate: " << nrIteratii;
	cout << "\nCaractere distincte: " << concatenare;
	cout << "\nFitness ce mai mic: " << fitness[cromMic] << " la crom: " << cromMic + 1;
	cout << "\nAlg. a stagnat de " << stagnari << " ori.";
	_getch();
}




