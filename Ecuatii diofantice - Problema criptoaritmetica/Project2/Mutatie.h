#pragma once
void Mutatie_uniforma() {
	float pm = 0.25;
	for (int i = 0; i < nr_parinti; i++) {
		for (int j = 0; j < concatenare.size(); j++) {
			float r = (float)rand() / (float)(RAND_MAX / 1);
			if (r < pm) {
				int random;
				while (true) {
					random = rand() % 10;
					bool ok = true;
					for (int k = 0; k < j; k++) {
						if (random == copii[i][k]) {
							ok = false;
							break;
						}
					}
					if (ok == false) {
						continue;
					}
					break;
				}
				copii[i][j] = random;
			}
			else {
				copii[i][j] = parintii[i][j];
				bool ok = true;
				for (int k = 0; k < j; k++) {
					if (parintii[i][j] == copii[i][k]) {
						ok = false;
						break;
					}
				}
				if (ok == false) {
					int random;
					while (true) {
						random = rand() % 10;
						ok = true;
						for (int k = 0; k < j; k++) {
							if (random == copii[i][k]) {
								ok = false;
								break;
							}
						}
						if (ok == false) {
							continue;
						}
						break;
					}
					copii[i][j] = random;
				}
			}
		}
	}
}