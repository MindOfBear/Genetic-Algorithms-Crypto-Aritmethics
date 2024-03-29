#pragma once
void citire() {
	concatenare = "";
	cout << "Introduceti primul text: ";
	getline(cin, text1);
	cout << "Introduceti al doilea text: ";
	getline(cin, text2);
	cout << "Introduceti al treilea text: ";
	getline(cin, text3);
	for (int i = 0; i < text1.size(); i++) {
		if (concatenare.find(text1[i]) == string::npos) {
			concatenare += text1[i];
		}
	}
	for (int i = 0; i < text2.size(); i++) {
		if (concatenare.find(text2[i]) == string::npos) {
			concatenare += text2[i];
		}
	}
	for (int i = 0; i < text3.size(); i++) {
		if (concatenare.find(text3[i]) == string::npos) {
			concatenare += text3[i];
		}
	}
	if (concatenare.size() > 10) {
		cout << "Textele nu au voie sa contina mai mult de 10 caractere distincte.\n";
		citire();
	}
}
void Initializare_pop() {
	citire();
	srand(time(NULL));
	for (int i = 0; i < nr_populatie; i++) {
		for (int j = 0; j < concatenare.size();j++) {
			int x;
			while (true) {
				x = rand() % 10;
				bool ok = true;
				for (int k = 0; k < j; k++) {
					if (x == populatie[i][k]) {
						ok = false;
						break;
					}
				}
				if (ok == false) {
					continue;
				}
				break;
			}
			populatie[i][j] = x;
		}
	}
	cout << "\nPopulatia initiala:\n";
	for (int i = 0; i < nr_populatie; i++) {
		cout << "Cromozomul " << i+1 << ": ";
		for (int j = 0; j < concatenare.size(); j++) {
			cout << populatie[i][j] << " ";
		}
		cout << endl;
	}
}