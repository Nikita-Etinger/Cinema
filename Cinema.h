#pragma once

class Cinema
{
private:
	string pathImg;
	float rating;
	bool subscription;
	bool top10;
	vector<string> category;

	map<string, string> getFields(string str) {
		map<string, string> array;

		for (int i = 0, k = 0; i < str.length(); i++) {
			if (str[i] == '"') {
				string key = "";

				for (int j = i + 1; str[j] != '"'; j++) {
					key += str[j];
				}

				for (int j = i + key.length(); j < str.length(); j++) {
					if (str[j] == ':') {
						k = j + 1;
						break;
					}
				}

				for (int j = k; j < str.length(); j++) {
					if (str[j] != ' ') {
						k = j;
						break;
					}
				}

				bool flagArr = (str[k] == '[');
				bool flagStr;
				if (str[k] == '"') {
					k++;
					flagStr = true;
				}
				else flagStr = false;
				string value = "";
				for (int j = k; j < str.length(); j++) {
					if (flagArr) {
						value += str[j];
						if (str[j] == ']')
						{
							k = j;
							break;

						}
					}
					else if (flagStr) {
						value += str[j];
						if (str[j + 1] == '"') {
							k = j + 1;
							break;

						}
					}
					else {
						if (str[j] == ',') {
							k = j;
							break;
						}
						else value += str[j];
					}
				}

				array[key] = value;
				i = k;
			}

		}
		return array;
	}

	void loadField(map<string, string> array) {

		//запись
		pathImg = array["pathImg"];
		rating = stof(array["rating"]);

		if (array["subscription"] == "true") {
			subscription = 1;
		}
		else subscription = 0;

		if (array["top10"] == "true") {
			top10 = 1;
		}
		else top10 = 0;

		string bufStr = "";
		for (int i = 0; i <=array["category"].length(); i++) {
			if (array["category"][i] == ','||array["category"][i]=='\0') {
				category.push_back(bufStr);
				bufStr = "";
				i++;
				continue;
			}
			bufStr += array["category"][i];
		}
		cout << endl;

	}
public:
	Cinema() {

	}
	Cinema(string str) {
		map<string, string> array = getFields(str);
		loadField(array);
		//for (const auto& el : array) {
		//	cout << el.first << ": " << el.second << endl;
		//}
	}
	void showInfo() {
		cout << "pathImg: " << pathImg << endl;
		cout << "rating: " << rating << endl;
		cout << "subs: " << subscription << endl;
		cout << "top10: " << top10 << endl;
		cout << "category: ";
		for (auto el : category) {
			cout << el << ",";
		}
		cout << endl;
	}
};
class Theater {
private:
	 vector<Cinema> cinemas;

public:

	void addCinema(string str) {
		cinemas.push_back(Cinema(str));
	}

	void showAllCinemas() {
		for (Cinema& cinema : cinemas) {
			cinema.showInfo();
			 cout << "---------------------" <<  endl;
		}
	}
};

