// laba4.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <iostream>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root;

struct node *createtree(struct node *root, struct node *r, int data) 
{
	if (r==NULL)
	{
		r = (struct node*)malloc(sizeof(struct node));

		if (r == NULL)
		{
			printf("Ошибка выделения памяти");
			exit(0);
		}

		r->left = NULL;
		r->right = NULL;
		r->data = data;

		if(root == NULL)
			return r;
		if (data > root->data)
			root->left = r;
		else
			root->right = r;
		return r;

		if(data > r-> data)
			createtree(r, r->left, data);
		else
			createtree(r, r->right, data);

		return root;
	}
}

void printtree(struct node *r, int l)
{
	if(r == NULL)
	{
		return;
	}

	printtree(r->right, l + 1);
	for (int i=0; i<l; i++)
	{
		printf(" ");
	}

	printf("%d\n",r->data);
	printtree(r->left, l+1);
}

int main()
{
	setlocale(LC_ALL, "");

	int D, start = 1;
	root=NULL;
	printf("-1 - окончание построения дерева\n");
	while (start)
	{
		printf("Введите число: ");
		scanf("%d",&D);
		if (D == -1)
		{
			printf("Построение дерева оконченно\n\n");
			start = 0;
		}
		else
			root = createtree(root, root, D);
	}

	printtree(root,5);

	scanf("%d", &D);  
	return 0;
}

