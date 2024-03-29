#pragma once
void Fitness(int pop[100][100], int fitness[100]) {
	for (int i = 0; i < nr_populatie; i++) {
		int text1cript = 0, text2cript = 0, text3cript = 0;
		for (int contortext1 = 0; contortext1 < text1.size(); contortext1++) {
			for (int j = 0; j < concatenare.size(); j++) {
				if (text1[contortext1] == concatenare[j]) {
					text1cript = text1cript * 10 + pop[i][j];
					break;
				}
			}
		}
		for (int contortext2 = 0; contortext2 < text2.size(); contortext2++) {
			for (int j = 0; j < concatenare.size(); j++) {
				if (text2[contortext2] == concatenare[j]) {
					text2cript = text2cript * 10 + pop[i][j];
					break;
				}
			}
		}
		for (int contortext3 = 0; contortext3 < text3.size(); contortext3++) {
			for (int j = 0; j < concatenare.size(); j++) {
				if (text3[contortext3] == concatenare[j]) {
					text3cript = text3cript * 10 + pop[i][j];
					break;
				}
			}
		}
		fitness[i] = abs(text3cript - text2cript - text1cript);
	}
}
int FitnessTotal(int pop[100][100], int fitness[100]) {
	int ft = 0;
	for (int i = 0; i < nr_populatie; i++) {
		ft += fitness[i];
	}
	return ft;
}
void Selectie_dupa_rang() {
	int fitness[100];
	Fitness(populatie, fitness); 
	int fitnesssortat[100];
	for (int i = 0; i < nr_populatie; i++) {
		fitnesssortat[i] = fitness[i];
	}
	int min = fitnesssortat[0];
	for (int i = 1; i < nr_populatie-1; i++) {
		for (int j = i; j < nr_populatie; j++) {
			if (fitnesssortat[i] > fitnesssortat[j]) {
				int aux = fitnesssortat[i];
				fitnesssortat[i] = fitnesssortat[j];
				fitnesssortat[j] = aux;
			}
		}
	}
	for (int i = 0; i < nr_parinti; i++) {
		for (int j = 0; j < nr_populatie; j++) {
			if (fitnesssortat[i] == fitness[j]) {
				for (int k = 0; k < concatenare.size(); k++) {
					parintii[i][k] = populatie[j][k];
				}
				break;
			}
		}
	}
}