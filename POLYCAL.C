#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
    int coef;
    int pow;
    struct node *link;
};

void create (struct node*);
void display (struct node*);
void sort (struct node*);
void swap (struct node*, struct node*);
void add (struct node*, struct node*);
void subtract (struct node*, struct node*);
void multiply (struct node*, struct node*);
void GroupLikePowers (struct node*);
void evaluate (struct node*);

void main()
{
	struct node *poly1 = NULL, *poly2 = NULL;
	int ch;

	poly1 = (struct node*) malloc (sizeof (struct node));
	poly2 = (struct node*) malloc (sizeof (struct node));

	clrscr();
	printf("\nPOLYNOMIAL CALCULATOR\nby Rahul M Dinesh (1NH18CS738)\nCSE 3-D, New Horizon College of Engineering\n");
	printf ("\nWhich operation would you like to perform?\n");
	printf ("1. Evaluation\n2. Addition\n3. Subtraction\n4. Multiplication\n\nChoice: ");
	scanf ("%d", &ch);

	switch (ch)
	{
		case 1:
		{
			printf ("\nEnter Polynomial: ");
			create (poly1);
			sort (poly1);
			free (poly2);
			evaluate (poly1);
		}
		break;

		case 2:
		{
			printf ("\nEnter Polynomial 1: ");
			create (poly1);
			sort (poly1);

			printf("\nEnter Polynomial 2: ");
			create (poly2);
			sort (poly2);

			add (poly1, poly2);
		}
		break;

		case 3:
		{
			printf ("\nEnter Polynomial 1: ");
			create (poly1);
			sort (poly1);

			printf("\nEnter Polynomial 2: ");
			create (poly2);
			sort (poly2);

			subtract (poly1, poly2);
		}
		break;

		case 4:
		{
			printf ("\nEnter Polynomial 1: ");
			create (poly1);
			sort (poly1);

			printf("\nEnter Polynomial 2: ");
			create (poly2);
			sort (poly2);

			multiply (poly1, poly2);
		}
		break;

		default:
			printf("\nWrong option.");
		break;
	}
	getch ();
}

void add (struct node *poly1, struct node *poly2)
{
	int highestPower = 0, coeff, i;
	struct node *polysum = NULL, *currentNode, *curr1, *curr2;

	printf("\nFirst Polynomial: ");
	display(poly1);
	printf("\nSecond Polynomial: ");
	display(poly2);

	curr1 = poly1;
	curr2 = poly2;

	while (1)
	{
		if (curr1->pow > highestPower)
		{
			highestPower = curr1->pow;
		}

		if (curr1->link == NULL)
		{
			break;
		}

		curr1 = curr1->link;
	}

	while (1)
	{
		if (curr2->pow > highestPower)
		{
			highestPower = curr2->pow;
		}

		if (curr2->link == NULL)
		{
			break;
		}

		curr2 = curr2->link;
	}

	//printf ("\nHighest power = %d\n", highestPower);

	for (i = highestPower; i >= 0; i--)
	{
		coeff = 0;
		curr1 = poly1;
		curr2 = poly2;

		while (1)
		{
			if (curr1->pow == i)
			{
				coeff = coeff + curr1->coef;
			}

			if (curr1->link == NULL)
			{
				break;
			}

			curr1 = curr1->link;
		}

		while (1)
		{
			if (curr2->pow == i)
			{
				coeff = coeff + curr2->coef;
			}

			if (curr2->link == NULL)
			{
				break;
			}

			curr2 = curr2->link;
		}

		if (coeff != 0)
		{
			if (polysum == NULL)
			{
				polysum = (struct node*) malloc (sizeof (struct node));
				polysum->coef = coeff;
				polysum->pow = i;
				polysum->link = NULL;

				currentNode = polysum;
			}
			else
			{
				currentNode->link = (struct node*) malloc (sizeof (struct node));

				currentNode = currentNode->link;
				currentNode->coef = coeff;
				currentNode->pow = i;
				currentNode->link = NULL;
			}
		}
	}

	printf ("\nThe polynomial sum is: ");
	display (polysum);
}

void subtract (struct node *poly1, struct node *poly2)
{
	int highestPower = 0, coeff, i;
	struct node *polydiff = NULL, *currentNode, *curr1, *curr2;

	printf("\nFirst Polynomial: ");
	display(poly1);
	printf("\nSecond Polynomial: ");
	display(poly2);

	curr1 = poly1;
	curr2 = poly2;

	while (1)
	{
		if (curr1->pow > highestPower)
		{
			highestPower = curr1->pow;
		}

		if (curr1->link == NULL)
		{
			break;
		}

		curr1 = curr1->link;
	}

	while (1)
	{
		if (curr2->pow > highestPower)
		{
			highestPower = curr2->pow;
		}

		if (curr2->link == NULL)
		{
			break;
		}

		curr2 = curr2->link;
	}

	//printf ("\nHighest power = %d\n", highestPower);

	for (i = highestPower; i >= 0; i--)
	{
		coeff = 0;
		curr1 = poly1;
		curr2 = poly2;

		while (1)
		{
			if (curr1->pow == i)
			{
				coeff = coeff + curr1->coef;
			}

			if (curr1->link == NULL)
			{
				break;
			}

			curr1 = curr1->link;
		}

		while (1)
		{
			if (curr2->pow == i)
			{
				coeff = coeff - curr2->coef;
			}

			if (curr2->link == NULL)
			{
				break;
			}

			curr2 = curr2->link;
		}

		if (coeff != 0)
		{
			if (polydiff == NULL)
			{
				polydiff = (struct node*) malloc (sizeof (struct node));
				polydiff->coef = coeff;
				polydiff->pow = i;
				polydiff->link = NULL;

				currentNode = polydiff;
			}
			else
			{
				currentNode->link = (struct node*) malloc (sizeof (struct node));

				currentNode = currentNode->link;
				currentNode->coef = coeff;
				currentNode->pow = i;
				currentNode->link = NULL;
			}
		}
	}

	printf ("\nThe polynomial difference is: ");
	display (polydiff);
}

void multiply(struct node* poly1, struct node* poly2)
{
    struct node *curr1, *curr2, *currentNode = NULL, *polyprod = NULL;
    int coef, pow;
    curr1 = poly1;
    curr2 = poly2;
    while (curr1 != NULL)
    {
	while (curr2 != NULL)
	{

	    coef = curr1->coef * curr2->coef;

	    pow = curr1->pow + curr2->pow;

	    if (coef != 0)
		{
			if (polyprod == NULL)
			{
				polyprod = (struct node*) malloc (sizeof (struct node));
				polyprod->coef = coef;
				polyprod->pow = pow;
				polyprod->link = NULL;

				currentNode = polyprod;
			}
			else
			{
				currentNode->link = (struct node*) malloc (sizeof (struct node));

				currentNode = currentNode->link;
				currentNode->coef = coef;
				currentNode->pow = pow;
				currentNode->link = NULL;
			}
		}

	    curr2 = curr2->link;
	}

	curr2 = poly2;

	curr1 = curr1->link;
    }

    GroupLikePowers (polyprod);

    printf("\nPolynomial 1: ");
    display(poly1);
    printf("\nPolynomial 2: ");
    display(poly2);

    printf("\nThe polynomial product is: ");
    display(polyprod);
}

void GroupLikePowers(struct node* first)
{
    struct node *curr1, *curr2, *dup;
    curr1 = first;

    while (curr1 != NULL && curr1->link != NULL)
    {
	curr2 = curr1;

	while (curr2->link != NULL)
	{
	    if (curr1->pow == curr2->link->pow)
	    {

		curr1->coef = curr1->coef + curr2->link->coef;
		dup = curr2->link;
		curr2->link = curr2->link->link;

		// remove the 2nd element
		free (dup);
	    }
	    else
		curr2 = curr2->link;
	}
	curr1 = curr1->link;
    }
}

void evaluate (struct node *poly)
{
	int sum=0, x;
	struct node *temp = NULL;

	printf("\nPolynomial entered: ");
	display(poly);

	temp = poly;

	printf("\nEnter value for x: ");
	scanf("%d", &x);

	while(temp!=NULL)
	{
		sum = sum + ((temp->coef)*(pow(x,temp->pow)));

		temp = temp->link;
	}

	printf("\nThe value of f(x) for x = %d is: %d ", x, sum);
}

void create (struct node *first)
{
	int coef, pow, i, n;
	struct node *curr;

	curr = first;

	printf ("Enter the number of terms in the polynomial: ");
	scanf ("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf ("\tEnter term %d's coeficient & power: ",i+1);
		scanf ("%d%d", &coef, &pow);

		curr->coef = coef;
		curr->pow = pow;

		if (i < n-1)
		{
			curr->link = (struct node*) malloc (sizeof (struct node));
			curr = curr->link;
		}
		else
		{
			curr->link = NULL;
		}

	}
}

void display (struct node *first)
{
	struct node* temp;
	temp = first;

	while (1)
	{
	    if (temp->link == NULL)
	    {
		if (temp->pow == 0)
		{
		    printf ("%d", temp->coef);
		    break;
		}

		if (temp->pow == 1)
		{
		    printf ("%dx", temp->coef);
		    break;
		}
		else
		{
		    printf ("%dx^%d", temp->coef, temp->pow);
		    break;
		}
	    }
	    else if (temp->pow == 1)
		printf ("%dx + ", temp->coef);

	    else if (temp->pow == 0)
		printf("%d + ", temp->coef);

	    else
		printf ("%dx^%d + ", temp->coef, temp->pow);

	    temp = temp->link;

	}
}

void sort (struct node *first)
{
    int swapped, i;
    struct node *temp;

    if (first == NULL)
	return;

    do
    {
	swapped = 0;
	temp = first;

	while (temp->link != NULL)
	{
	    if (temp->pow < temp->link->pow)
	    {
		swap (temp, temp->link);
		swapped = 1;
	    }

	    temp = temp->link;
	}
    }
    while (swapped);
}

void swap (struct node *a, struct node *b)
{
    int temcurr1, temcurr2;
    temcurr1 = a->pow;
    a->pow = b->pow;
    b->pow = temcurr1;

    temcurr2 = a->coef;
    a->coef = b->coef;
    b->coef = temcurr2;
}