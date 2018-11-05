#pragma once

class WordCount {
private:
	const char* str;
	int* size;
	int* numb;
	bool(*delimiter)(char);
public:

	WordCount(const char* str, int* const size, int* numb, bool(*f)(char)) {
		this->str = str;
		this->size = size;
		this->numb = numb;
		this->delimiter = f;
	}

	void operator()(int start, int end) {
		for (int i = start; i < end; i++) {
			if (!this->delimiter(str[i])) {
				int s = 0;
				while (i + s < end && !delimiter(str[i + s])) s++;
				size[i] = s;
				int n = 0;
				for (int j = i + s + 1; j + s < end; j++) {
					bool bad = false;
					for (int k = 0;
						k < s && k + i < end && k + j < end; k++) {
						if (str[i + k] != str[j + k]) {
							bad = true;
							break;
						}
					}
					if (!bad && delimiter(str[j + s])) n++;
				}
				numb[i] = n;
			}
			else {
				size[i] = 0;
				numb[i] = 0;
			}
			i += size[i];
		}
	}
};