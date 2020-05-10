#include <stdio.h>
#include <stdlib.h>

struct listNode {
	int data;
	unsigned int hash;
	struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

// прототипы функций
void insert( ListNodePtr *sPtr, int value, unsigned int hsh );
int delete( ListNodePtr *sPtr, int value );
int isEmpty( ListNodePtr sPtr );
void printList( ListNodePtr currentPtr );
void instructions( void );
int h_hash(int x);


//*************************************************************************

int main( void )
{
	ListNodePtr startPtr = NULL; // изначально список пуст
	unsigned int choice;		// выбор пользователя
	int item;					// символ, введённый ползователем

	instructions();
	printf( "%s", "? " );
	scanf( "%u", &choice );

	// выполнять цикл, пока ползователь не выберет пункт 3
	while( choice != 3 ){

		switch( choice ){

			case 1:
				printf( "%s", "Enter a character: " );
				scanf( "\n%d", &item );
				insert( &startPtr, item, h_hash(item) ); //вставить элемент в список
				printList( startPtr );
				break;

			case 2: // удалить элемент
				// если список не пуст
				if ( !isEmpty( startPtr ) ){
					printf("%s", "Enter character to be deleted: " );
					scanf( "\n%d", &item );

					// если символ найден, удалить его из списка
					if ( delete( &startPtr, item ) ){ // удалить элемент
						printf("%d deleted.\n", item );
						printList( startPtr );
					}
					else {
						printf("%d not found.\n\n", item );
					}
				}
				else {
					puts( "Lisst is empty.\n" );
				}
				break;

			

			default:
				puts( "Invalid choice.\n" );
				instructions();
				break;
		}
		printf( "%s", "? " );
		scanf( "%u", &choice );
	}

	puts( "End of run." );
}

//*************************************************************************

// выводит инструкцию по работе с программой
void instructions( void ){
	
	puts( "Enter your choice:\n"
		"	1 to insert an element into the list.\n"
		"	2 to delete an element from the list.\n"
		"	3 to find element (hash needed) in the list.\n"
		"	4 to end." );
}

// вставляет новое значение в список в порядке сортировки
void insert( ListNodePtr *sPtr, int value, unsigned int hsh ){

	ListNodePtr newPtr;			// указатель на новый узел
	ListNodePtr previousPtr;	// указатель на предыдущий узел
	ListNodePtr currentPtr; 	// указатель на текущий узел

	newPtr = malloc( sizeof( ListNode ) ); // создать узел

	if ( newPtr != NULL){		// если память выделена
		newPtr->data = value;	// записать значение в узел
		newPtr->hash = hsh;		// записать хэш
		newPtr->nextPtr = NULL; // узел пока не связан с другим узлом
		previousPtr = NULL;
		currentPtr = *sPtr;

		// найти место в списке для вставки нового узла
		while ( currentPtr != NULL && hsh > currentPtr->hash ){
			previousPtr = currentPtr;		  // перейти к ...
			currentPtr = currentPtr->nextPtr; // ... следующему узлу
		}

		// вставить новый узел в начало списка
		if ( previousPtr == NULL ){
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}
		else { //вставить новый узел между previousPtr и currentPtr
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
	}
	else {
		printf( "%d not inserted. No memory available.\n", value );
	}
}


// удаляет элемент из списка
int delete( ListNodePtr *sPtr, int value ){

	ListNodePtr previousPtr; // указатель на предыдущий узел в списке
	ListNodePtr currentPtr;  // указатель на текущий узел в списке
	ListNodePtr tempPtr;	 // временный указатель на узел

	// удалить первый узел
	if ( value == ( *sPtr )->data ){
		tempPtr = *sPtr; 			// сохранить указатель на удаляемый узел
		*sPtr = ( *sPtr )->nextPtr; // исключить узел из списка
		free( tempPtr ); // освободить память, занимаемую исключённым узлом
		return value;
	}
	else {
		previousPtr = *sPtr;
		currentPtr = ( *sPtr )->nextPtr;

		// найти элемент списка с указанным символом
		while ( currentPtr != NULL && currentPtr->data != value ){
			previousPtr = currentPtr;		  // перейти к ...
			currentPtr = currentPtr->nextPtr; // ... следующему узлу
		}

		// удалить узел currentPtr
		if ( currentPtr != NULL ){
			tempPtr = currentPtr;
			previousPtr->nextPtr = currentPtr->nextPtr;
			free( tempPtr );
			return value;
		}
	}

	return '\0';
}

// возвращает 1, если список пуст, 0 - в противном случае
int isEmpty( ListNodePtr sPtr ){

	return sPtr == NULL;
}

// выводит список
void printList( ListNodePtr currentPtr ){

	// если список пуст
	if (isEmpty( currentPtr ) ){
		puts( "List is empty.\n" );
	}
	else {
		puts( "The list is:" );

		// пока не достигнут конец списка
		while ( currentPtr != NULL ){
			printf( "%u(%d) --> ", currentPtr->hash, currentPtr->data );
			currentPtr = currentPtr->nextPtr;
		}

		puts( "NULL\n" );
	}
}

int h_hash(int x){
	x = ((((x*37+13)<<3)*1000/7)>>2)%10000;
	return x;
}
