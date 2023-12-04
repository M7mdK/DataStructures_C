#define N4 15
#define P (N4 - N4/3)	//Greatest index in the Primary zone is P-1  , first index in the reserve is P
#define N5 12
typedef char element4;
typedef char element5;
typedef struct {
	element4 data;
	int link;
}cell;

typedef cell hash4[N4];
typedef cell hash5[N5];

//With separated zones

int hf4(element4 e) {
	return (e - 65) % P;	//Best to deal with A...Z , so that A has hash of zero
}

void createHash4(hash4 h) {
	int i;
	for (i = 0; i < N4; i++) {
		h[i].link = -2;
		h[i].data = '\0';//Bas 3ashan l print , will not be taken in consideration (y3ni mn3ref eno cell empty lama ykon link -2 , ma 5as data)
	}
}

void printHash4(hash4 h) {
	int i;
	printf("index data link\n");
	for (i = 0; i < N4; i++) {
		if (i == P)
			printf("--------------\n");
		printf("%d\t%c  %d\n", i,h[i].data,h[i].link);
	}
	printf("\n");
}

//WITHOUT Separated zones

int hf5(element5 e) {
	return (e - 65) % N5;	//Best to deal with A...Z , so that A has hash of zero
}
void createHash5(hash5 h) {
	int i;
	for (i = 0; i < N5; i++) {
		h[i].link = -2;
		h[i].data = '\0';//Bas 3ashan l print , will not be taken in consideration (y3ni mn3ref eno cell empty lama ykon link -2 , ma 5as data)
	}
}
void printHash5(hash5 h) {
	int i;
	printf("index data link\n");
	for (i = 0; i < N5; i++)
		printf("%d\t%c  %d\n", i, h[i].data, h[i].link);
	printf("\n");
}