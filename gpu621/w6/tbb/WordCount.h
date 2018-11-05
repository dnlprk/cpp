#pragma once

class WordCount {
private:
	const char* str;
	int* size;
	int* numb;
	int len;
	bool(*delimiter)(char);
public:

	WordCount(const char* const str, int* const size, int* const numb, int len, bool(*f)(char)) {
		this->str = str;
		this->size = size;
		this->numb = numb;
		this->len = len;
		this->delimiter = f;
	}

	void operator()(tbb::blocked_range<int>& r) const {

		for (int i = r.begin(); i < r.end(); i++) {
			if (!this->delimiter(str[i])) {
				int s = 0;
				while (i + s < len && !delimiter(str[i + s])) s++;
				size[i] = s;
				int n = 0;
				for (int j = i + s + 1; j + s < len; j++) {
					bool bad = false;
					for (int k = 0;
						k < s && k + i < len && k + j < len; k++) {
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