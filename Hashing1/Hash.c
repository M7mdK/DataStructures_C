#include<stdio.h>
#define n 20
typedef int element;

typedef struct {
	element data;
	int link;
}cell;

typedef cell hashtable[n];

int hf(element e) {
	return e % 5;
}

void reset(hashtable h) {//intializing links
	int i;
	for (i = 0; i < n; i++)
		h[i].link = -2;
	for (i = 0; i < n; i++)
		h[i].data = -2;
}

int searchInReserve(hashtable h , element e , int p , int m) {
	int i;
	for (i = m - 1; i > p; i--) {
		if (h[i].link == -2) {
			return i;
		}
	}
	return -1;
}

int add(hashtable h, element e, int p, int m) {
	int i;
	int z = hf(e);
	if (h[z].link == -2) {
		h[z].data = e;
		h[z].link = -1;
		return 1;
	}
	if (h[z].link == -1) {
		i=searchInReserve(h, e, p, m);
		if (i != -1) {
			h[i].data = e;
			h[i].link = -1;
			h[z].link = i;
			return 1;
		}
		return 0;
	}
	while (h[z].link != -1)
		z = h[z].link;
	i= searchInReserve(h, e, p, m);
	if (i != -1) {
		h[z].link = i;
		h[i].link = -1;
		h[i].data = e;
		return 1;
	}
	return 0;
}

int delete(hashtable h , element e , int p , int m) {
	int i,x,y,exists=0;
	int z = hf(e);
	if (h[z].link == -2 || (h[z].link == -1 && h[z].data != e)) //Data is not in the table
		return 0;

	if (h[z].link == -1 && h[z].data==e) {
		h[z].link = -2;
		h[z].data = -2;
		return 1;
	}
	if (h[z].data == e) {
		i = h[z].link;
		h[z] = h[i];
		h[i].link = -2;
		h[i].data = -2;
	}

	x = z;
	while (h[z].link != -1) {
		y = z;
		z = h[z].link;
		if (h[z].data == e) {
			exists = 1;
			break;
		}	
	}
	if (exists == 0)
		return 0;

	if (h[z].link == -1) {
		h[z].link = -2;
		h[y].link = -1;
		h[z].data = -2;
	}
	i = h[z].link;
	h[z].link = -2;
	h[y].link = i;
	h[i].link = -2;
	h[z].data = -2;
	return 1;
}

main() {
	int i;
	hashtable h;
	reset(h);

	for (i = 0; i < 16; i++) {
		add(h, i, 10, 20);
	}

	delete(h, 0, 10, 20);
	
	for (i = 0; i < n; i++) {
		printf("%d\n", h[i].data);
	}
}