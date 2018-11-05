#pragma once
template<typename K, typename V, int N>

class KVList
{
private:

	K k[N];
	V v[N];

	size_t count = 0;
public:
	KVList() {

	}
	size_t size() const {
		return count;
	}
	const K& key(int i) const {
		if (i >= 0 && i < count)
		{
			return k[i];
		}
	}
	const V& value(int i) const {
		if (i >= 0 && i < count)
		{
			return v[i];
		}
	}
	KVList& add(const K& newK, const V& newV) {
		if (count < N)
		{
			k[count] = newK;
			v[count] = newV;
			count++;
		}
		return *this;
	}
	int find(const K& kk) const {
		for (size_t i = 0; i < count; i++)
		{
			if (k[i] == kk)
			{
				return i;
			}
		}
		return 0;
	}
	KVList& replace(int i, const K& newK, const V& newV) {
		if (i >= 0 && i < count)
		{
			k[i] = newK;
			v[i] = newV;
		}
		return *this;
	}
	~KVList() {

	}
};