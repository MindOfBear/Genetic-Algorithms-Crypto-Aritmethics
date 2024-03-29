#pragma once
void Noua_populatie() {
	int parintisicopii[100][100];
	for (int i = 0; i < nr_populatie; i++) {
		for (int j = 0; j < concatenare.size(); j++) {
			parintisicopii[i][j] = populatie[i][j];
		}
	}
	for (int i = nr_populatie; i < nr_populatie + nr_parinti; i++) {
		for (int j = 0; j < concatenare.size(); j++) {
			parintisicopii[i][j] = copii[i - nr_populatie][j];
		}
	}
	nr_populatie = nr_populatie + nr_parinti;
	int fitness[100];
	Fitness(parintisicopii, fitness);

	int fitnesssortat[100];
	for (int i = 0; i < nr_populatie; i++) {
		fitnesssortat[i] = fitness[i];
	}
	int min = fitnesssortat[0];
	for (int i = 0; i < nr_populatie - 1; i++) {
		for (int j = i+1; j < nr_populatie; j++) {
			if (fitnesssortat[i] > fitnesssortat[j]) {
				int aux = fitnesssortat[i];
				fitnesssortat[i] = fitnesssortat[j];
				fitnesssortat[j] = aux;
			}
		}
	}
	nr_populatie = nr_populatie - nr_parinti;
	for (int i = 0; i < nr_populatie; i++) {
		for (int j = 0; j < nr_populatie + nr_parinti; j++) {
			if (fitnesssortat[i] == fitness[j]) {
				for (int k = 0; k < concatenare.size(); k++) {
					populatie[i][k] = parintisicopii[j][k];
				}
				break;
			}
		}
	}
}