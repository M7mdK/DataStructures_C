typedef int element;
typedef struct node {
	element data;
	struct node* left, * right;
}*Btree;

/*
int deleteBST(Btree *b , element e) {
	Btree t,p,temp,temp2;
	if (!(*b))return 0;
	if ((*b)->left == NULL && (*b)->right == NULL) {
		if ((*b)->data == e) {
			free(*b);
			*b = NULL;
			return 1;
		}
		else
			return 0;
	}
	t = p = *b;
	while(t) {
		if (e == t->data) {
			if (t->left == NULL && t->right == NULL) {
				if (p->right->data == e)
					p->right = NULL;
				if (p->left->data == e)
					p->left = NULL;
				free(t);
				return 1;
			}
			for (temp = t->right , temp2 = t; temp->left ; temp = temp->left) {
				temp2 = temp;
			}
			t->data = temp->data;
			free(temp);
			if (temp2 == t)
				t->right == NULL;
			else
				temp2->left = NULL;
			return 1;
		}
		if (e > t->data) {
			p = t;
			t = t->right;
		}
		else if (e > t->data) {
			p = t;
			t = t->left;
		}
	}
	return 0;
}
*/