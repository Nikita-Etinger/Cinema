#pragma once

void reader(string path, Theater& theater) {
	ifstream out;
	out.open(path);
	if (out.is_open()) {
		string buf = "";
		string compliteStr = "";
		getline(out, buf);//������� 1 ������
		getline(out, buf);//������� 2 ������
		while (getline(out, buf)) {
			if (buf[1] == '}') {
				getline(out, buf);
				theater.addCinema(compliteStr);
				buf = "";
				compliteStr = "";
				continue;

			}
			for (int i = 0; i < buf.length();i++) {
				if(buf[i]!='\t')
				compliteStr += buf[i];
			}
		}



	}





}