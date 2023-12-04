#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<String.h>
#include"Probing.h"
#include"Chaining.h"
#include"coalesced.h"
#include"Cuckoo.h"

//1-Linear Probing
//2-Quadratic Probing
//3-Separate Chaining
//4-Coalesced with separate zones
//5-Coalsced without separate zones
//6-Cuckoo
//7-Hopscotch
//Linear Probing:
int insert1(hash1 h , char data[] , int index) {	
	int i;
	if (strcmp(h[index].e, data) == 0)return 0;
	if (strcmp(h[index].e, "\0") == 0) {
		strcpy(h[index].e, data);
		h[index].v = index;
		return 1;
	}
	for (i = index + 1; i<=N1 ; i++) {
		if (i == N1)i = 0;
		if (i == index)return 0;	//No empty space was found
		if (strcmp(data, h[i].e) == 0)return 0; //data already exists

		if (strcmp(h[i].e, "\0") == 0) {
			strcpy(h[i].e, data);
			h[i].v = index;
			return 1;
		}
	}
	return 0;
}
//RK:
//Hon dayman 3am ntar nda5el l index 3ashan ma 3ena hash funtion ,
//Otherwise data kefye , heye btdelna 3al index using the HashFt
int search1(hash1 h , char data[] , int index) {		
	int i;											
	if (strcmp(h[index].e , data) == 0)return 1;
	for (i = index + 1; i <= N1; i++) {
		if (i == N1)i = 0;
		if (i == index)return 0;
		if (strcmp(h[i].e, data) == 0) {
			if (h[i].v != index)
				return -1;	//User mda5el index mesh mzbouta lal data y3ni masalan "aa" mara 3ateha index 2 wmara 7 
			return 1;
		}
	}
}

int delete1(hash1 h , char data[] , int index) {
	int i;
	if (strcmp(h[index].e, data) == 0) {
		strcpy(h[index].e, "\0");
		h[index].v = -1;
		return 1;
	}
	for (i = index + 1; i <= N1; i++) {
		if (i == N1)i = 0;
		if (i == index)return 0;
		if (strcmp(h[i].e, data) == 0) {
			strcpy(h[i].e, "\0");
			h[i].v = -1;
			return 1;
		}
	}
}

//Quadratic Probing:

int insert2(hash2 h, char data[], int index) {
	int i, j;
	if (strcmp(h[index].e, data) == 0)return 0;
	if (strcmp(h[index].e, "\0") == 0) {
		strcpy(h[index].e, data);
		h[index].v = index;
		return 1;
	}
	for (i = 1; i < N2 / 2; i++) {
		j = (index + i * i) % N2;
		if (strcmp(h[j].e, data) == 0)return 0;
		if (strcmp(h[j].e, "\0") == 0) {
			strcpy(h[j].e, data);
			h[j].v = index;
			return 1;
		}
	}
	return 0;
}

int search2(hash2 h , char data[] , int index) {
	int i, j;
	if (strcmp(h[index].e, data) == 0)return 1;
	for (i = 1; i < N2 / 2; i++) {
		j = (index + i * i) % N2;
		if (strcmp(h[j].e, data) == 0) {
			if (h[j].v != index)
				return -1;
			return 1;
		}
	}
	return 0;
}

int delete2(hash2 h , char data[] , int index) {
	int i,j;
	if (strcmp(h[index].e , data) == 0) {
		strcpy(h[index].e , "\0");
		h[index].v = -1;
		return 1;
	}
	for (i = 1; i < N2 / 2; i++) {
		j = (index + i * i) % N2;
		if (strcmp(h[j].e, data) == 0) {
			strcpy(h[j].e, "\0");
			h[j].v = -1;
			return 1;
		}
	}
	return 0;
}

//Separate chainning(Linked List):

int insert3(hash3 h , element3 e) {
	int z = hf3(e);
	return pushList(&h[z], e);
}

int search3(hash3 h , element3 e) {
	int z = hf3(e);
	return searchList(h[z], e);
}

int delete3(hash3 h , element3 e) {
	int z = hf3(e);
	return Remove(&h[z], e);
}


//Coalesced with separate zones:
int searchForEmpty1(hash4 h , element4 e) {	//Also checks if data is repeated
	int i;
	for (i = N4 - 1; i >= P; i--) {
		if (h[i].data == e)return -1;
		if (h[i].link == -2)
			return i;
	}
	return -1;
}

int insert4(hash4 h, element4 e) {
	int i,c;
	int z = hf4(e);
	if (h[z].link == -2) {
		h[z].data = e;
		h[z].link = -1;
		return 1;
	}
	if (h[z].data == e)return 0;
	for (c = z; h[c].link != -1; c = h[c].link);
		i = searchForEmpty1(h, e);
		if (i == -1)return 0;
		h[i].data = e;
		h[i].link = -1;
		h[c].link = i;
		return 1;
}

int search4(hash4 h, element4 e) {
	int z = hf4(e);
	if (h[z].link == -2)return 0;
	if (h[z].data == e)return 1;
	z = h[z].link;
	while(z!=-1) {
		if (h[z].data == e && h[z].link != -2)
			return 1;
		z = h[z].link;
	}
	return 0;
}

int delete4(hash4 h, element4 e) {
	int t,c,z = hf4(e);
	if (h[z].link == -2)return 0;
	if (h[z].data == e) {
		if (h[z].link == -1) {
			h[z].link = -2;
			h[z].data = '\0';
		}
		else {
			t = h[z].link;
			h[z] = h[t];
			h[t].link = -2;
			h[t].data = '\0';
		}
		return 1;
	}
	t = z;
	c = z;
	while (c != -1) {
		t = c;
		c = h[c].link;
		if (h[c].data == e) {
			h[t].link = h[c].link;
			h[c].link = -2;
			h[c].data = '\0';
			return 1;
		}
	}
	return 0;
}

//Coalesced without zones

int searchForEmpty2(hash5 h, element5 e) {	//Also checks if data is repeated
	int i,j=-1;
	for (i = N5 - 1; i >= 0; i--) {
		if (h[i].data == e)return -1;
		if (h[i].link == -2 && j == -1)
			j = i;
	}
	if (j == -1)//Full
		return -1;
	return j;
}
int insert5(hash5 h, element5 e) {
	int i,c,v;
	int z = hf5(e);
	if (h[z].link == -2) {
		h[z].link = -1;
		h[z].data = e;
		return 1;
	}
	i = searchForEmpty2(h , e);
	if (i == -1)return 0;//Full or data already exists
	v = hf5(h[z].data);
	if(v != z){//From another family
		for (v; h[v].link != z; v = h[v].link);
		h[v].link = i;
		h[i] = h[z];
		h[z].data = e;
		h[z].link = -1;
		return 1;
	}
	//Family member:
	for (c = z; h[c].link != -1; c = h[c].link);
	h[c].link = i;
	h[i].data = e;
	h[i].link = -1;
	return 1;
}
int search5(hash5 h, element5 e) {//Same as search4
	int z = hf5(e);
	if (h[z].link == -2)return 0;
	if (h[z].data == e)return 1;
	z = h[z].link;
	while (z != -1) {
		if (h[z].data == e && h[z].link !=-2)
			return 1;
		z = h[z].link;
	}
	return 0;
}
int delete5(hash5 h, element5 e) {
	int t,c,z = hf5(e);
	if (h[z].link == -2)return 0;
	t = hf5(h[z].data);
	if (t != z)return 0;//Fe shi ma7ala mesh men l3ayle. So according to insert5, e mesh bel table
	if (h[z].data == e) {
		if (h[z].link == -1) {
			h[z].link = -2;
			h[z].data = '\0';
		}
		else {
			t = h[z].link;
			h[z] = h[t];
			h[t].link = -2;
			h[t].data = '\0';
		}
		return 1;
	}
	t = z;
	c = z;
	while (c !=-1) {
		t = c;
		c = h[c].link;
		if (h[c].data == e) {
			h[t].link = h[c].link;
			h[c].link = -2;
			h[c].data = '\0';
			return 1;
		}
	}
	return 0;
}

//CUCKOO HASHING
int insert6(hash6 *h, element6 e) {//BE CAREFUL, lezem pointer 3ala hash6 2w ma btzbat la2n hon mesh array metel 2bl, Hon struct
	int i, a, v1, v2;	
	v1 = H1(e);
	v2 = H2(e);
	if (h->T1[v1] == e || h->T2[v2] == e)return 0; //Data already exists
	for (i = 0; i < N6 * 2; i++) {
		if (h->T1[v1] == -1) {
			h->T1[v1] = e;
			return 1;
		}
		else {
			a = h->T1[v1];
			v2 = H2(a);
			h->T1[v1] = e;
		}
		if (h->T2[v2] == -1) {
			h->T2[v2] = a;
			return 1;
		}
		else {
			e = h->T2[v2];
			v1 = H1(e);
			h->T2[v2] = a;
		}
	}
	return 0;
}
int search6(hash6 h, element6 e) {
	int v1,v2;
	v1 = H1(e);
	v2 = H2(e);
	if (h.T1[v1] == e || h.T2[v2] == e)
		return 1;
	return 0;
}
int delete6(hash6 *h, element6 e) {
	int v1, v2;
	v1 = H1(e);
	v2 = H2(e);
	if (h->T1[v1] == e) {
		h->T1[v1] = -1;
		return 1;
	}
	if (h->T2[v2] == e) {
		h->T2[v2] = -1;
		return 1;
	}
	return 0;
}

main() {
	/*
	hash6 h6 = createHash6();
	insert6(&h6, 20);
	insert6(&h6, 50);
	insert6(&h6, 53);
	insert6(&h6, 75);
	insert6(&h6, 72);
	insert6(&h6, 72);
	printHash6(h6);
	printf("%d ", search6(h6,50));
	printf("%d ", search6(h6,72));
	printf("%d\n", search6(h6,10));
	delete6(&h6, 50);
	delete6(&h6, 72);
	printHash6(h6);
	*/
	/*
	hash5 h5;
	createHash5(h5);
	insert5(h5, 'A');
	insert5(h5, 'A');//Repeated
	insert5(h5, 'E');
	insert5(h5, 'M');//Son of A
	insert5(h5, 'Q');//Son of E
	insert5(h5, 'Y');//Son of M
	insert5(h5, 'Y');//Repeated
	insert5(h5, 'H');
	insert5(h5, 'A');//Repeated
	insert5(h5, 'J');//Must replace Y
	insert5(h5, 'l');//Son of H 
	insert5(h5, 'C');
	printHash5(h5);
	printf("%d ",search5(h5,'A'));
	printf("%d ",search5(h5,'M'));
	printf("%d ",search5(h5,'Y'));
	printf("%d ",search5(h5,'J'));
	printf("%d\n",search5(h5,'B'));//NO B
	delete5(h5, 'B');//NO B
	delete5(h5, 'E');
	delete5(h5, 'M');
	delete5(h5, 'C');
	printHash5(h5);
	*/
	/*
	hash4 h4;
	createHash4(h4);
	insert4(h4, 'A');
	insert4(h4, 'A');//Repeated
	insert4(h4, 'M');
	insert4(h4, 'H');
	insert4(h4, 'D');
	insert4(h4, 'F');
	insert4(h4, 'Z');//Son of F
	insert4(h4, 'Z');//Repeated (in the reserve)
	insert4(h4, 'K');//Son of A
	insert4(h4, 'd');//Son of Z
	insert4(h4, 'N');//Son of D
	insert4(h4, 'P');//Son of d
	insert4(h4, 'U');//Has to be son of K , but reserve is full
	printHash4(h4);
	printf("%d ",search4(h4, 'A'));
	printf("%d ",search4(h4, 'd'));
	printf("%d ",search4(h4, 'P'));
	printf("%d ",search4(h4, 'Z'));
	printf("%d ",search4(h4, 'U'));//No U
	printf("%d\n",search4(h4, 'B'));//NO B
	delete4(h4, 'E');//NO E
	delete4(h4, 'C');//same hash as M but No C , so nothing happens
	delete4(h4, 'A');
	delete4(h4, 'd');
	delete4(h4, 'N');
	delete4(h4, 'H');
	printHash4(h4);
	*/
	/*
	hash3 h3;
	createHash3(h3);
	insert3(h3, 3);
	insert3(h3, 13);
	insert3(h3, 1);
	insert3(h3, 6);
	insert3(h3, 11);
	insert3(h3, 21);
	printHash3(h3);
	printf("%d\t", search3(h3, 1));
	printf("%d\t", search3(h3, 11));
	printf("%d\t", search3(h3, 3));
	printf("%d\n", search3(h3, 7));
	delete3(h3, 6);
	delete3(h3,11);
	delete3(h3,3);
	printHash3(h3);
	*/
	/*
	hash2 h2;
	createHash2(h2);
	insert2(h2, "aa", 2);
	insert2(h2, "bb", 2);
	insert2(h2, "cc", 2);
	insert2(h2, "dd", 2);
	insert2(h2, "ee", 2);
	insert2(h2, "zz", 3);
	printHash2(h2);
	printf("%d\t", search2(h2, "aa", 2));
	printf("%d\t", search2(h2, "cc", 2));
	printf("%d\t", search2(h2, "dd", 2));
	printf("%d\t", search2(h2, "zz", 3));
	printf("%d\t", search2(h2, "xx", 2));
	printf("%d\t", search2(h2, "aa", 7));
	printf("%d\n", search2(h2, "ii", 8));
	delete2(h2, "aa", 2);
	delete2(h2, "dd", 2);
	delete2(h2, "ff", 7);
	delete2(h2, "kk", 2);
	printHash2(h2);
	*/
	/*
	hash1 h1;
	createHash1(h1);
	insert1(h1, "aa", 1);
	insert1(h1, "jj", 1);
	insert1(h1, "dd", 6);
	insert1(h1, "ee", 9);
	insert1(h1, "ff", 10);
	insert1(h1, "gg", 9);
	insert1(h1, "hh", 9);
	insert1(h1, "mm", 4);
	insert1(h1, "nn", 11);
	insert1(h1, "pp", 9);
	insert1(h1, "ii", 9);
	insert1(h1, "ii", 9);
	printHash1(h1);
	printf("%d\t", search1(h1, "aa", 1));
	printf("%d\t", search1(h1, "aa", 2));
	printf("%d\t", search1(h1, "gg", 9));
	printf("%d\t", search1(h1, "pp", 9));
	printf("%d\t", search1(h1, "zz", 9));
	printf("%d\n", search1(h1, "xx", 12));
	delete1(h1, "ee", 9);
	delete1(h1, "pp", 9);
	delete1(h1, "zz", 9);
	printHash1(h1);
	*/
}