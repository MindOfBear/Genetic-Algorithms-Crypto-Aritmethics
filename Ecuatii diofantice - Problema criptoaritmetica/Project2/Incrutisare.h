#pragma once
void Incrutisare_discreta() {
	for (int i = 0; i < nr_parinti; i++) {
		for (int j = 0; j < concatenare.size(); j++) {
			int random;
			while (true) {
				random = rand() % nr_parinti;
				if (random == i) {
					break;
				}
				bool ok = true;
				for (int k = 0; k < j; k++) {
					if (parintii[random][k] == parintii[i][k]) {
						ok = false;
						break;
					}
				}
				if (ok == false) {
					continue;
				}
				break;
			}
			parintii[i][j] = parintii[random][j];
		}
	}
}