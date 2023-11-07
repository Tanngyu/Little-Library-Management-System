#include <stdio.h>
#include <string.h>

void putclass() ;
void scan_action();
void signin(char new_book_name[], char new_book_author[]);
void search(char book_name[]);

typedef struct book{

	char name[50];
	char author[50];
	
	struct book* next ;

}book ;

book* head = NULL ; 
book* now_book ;




int main(void){
	
	while(1){
	
	
	putclass();//���� 
	
	scan_action(); //�������������Ӧ 
	
	sleep(3);//��Ӧ��Ϻ�˯�� 
	
}
	return 0 ;
}


void putclass(){	
	printf("this is a simple library management , input the number for what you wanna do : \n 1.sign in new books \n 2.search the book \n 3.borrow the books you want\n");	
}  //���������� 

void scan_action(){
	int order , books_num;
	
	scanf("%d",&order);
	switch (order) {	//�������������Ӧ 
	
	case 1 ://�� 

;
			char new_book_name[50] , new_book_author[50];
			
			printf("book's name:");
			getchar();
			fgets(new_book_name , sizeof(new_book_name) , stdin);
					
			printf("book's author:");
		//	getchar();
			fgets(new_book_author , sizeof(new_book_author) , stdin);
					
			signin(new_book_name , new_book_author);
		
		break ;
	
	case 2 ://�� 
		;
		char sbook_name[50] ;
		printf("book's name :");
		
		getchar();
		fgets(sbook_name , sizeof(sbook_name) , stdin);
		
		search(sbook_name);
		break ;
		
		
	case 3 ://�裨ɾ�� 
		;
		char bbook_name[50];
		printf("book's name :");
		
		getchar();
		fgets(bbook_name ,sizeof(bbook_name) , stdin);
		
		borrow(bbook_name);
		break ;
	}
}

		
void signin(char new_book_name[], char new_book_author[]){
	
	book* now_book = (book*)malloc(sizeof(book));
	
	//�������Ҫ�����ַ�ռ䣬��Ȼ����strcpy�ĵ�һ������������û�е�ַ��ָ�룩 
	
	
	strcpy(now_book -> name , new_book_name);
	strcpy(now_book -> author , new_book_author);
	
	
	if (head == NULL){
		head = now_book;
		head -> next = (book*)malloc(sizeof(book)) ;
		head -> next =NULL ;
		
		printf("Alright!\n");
		return ;
	}
	
	else if(head != NULL){
		
		now_book  = head  ;
		
		book* new_book= (book*)malloc(sizeof(book)); //ÿһ�� ����malloc �������һ���µĿռ� �� 
		
		strcpy(new_book -> name , new_book_name);
		strcpy(new_book -> author , new_book_author);
		
		while (now_book -> next != NULL){
			now_book  = now_book -> next ; }
									
		now_book ->next =new_book ;
		new_book ->next = NULL ;
		
		printf("Alright!\n") ;
		return ;
		
	}
		
} 

void search(char book_name[]){
	
	now_book = head ;
	
	while (now_book  != NULL){
		if(strcmp(now_book -> name , book_name) == 0 ){
			printf("%s",now_book -> name);
			printf("author:%s" , now_book -> author); 
			return ;
		}
		now_book = now_book -> next ;

	}
		printf("error: NOT FOUND !\n");
		return ;
}

void borrow(char book_name[]){
	
	now_book = head;
	
	while (now_book != NULL){
		
		book* certen ;
		
		if ( strcmp(book_name , head -> name) == 0 ){
		certen = head ->next ;
		free (head ->next) ;
		head = certen ;
		free (certen) ;
		printf("Alright!\n");
		return ;
		
		}else{
			if(strcmp((now_book -> next) -> name , book_name) == 0){
				certen = now_book ->next ;
				free (now_book -> next);
				now_book -> next = certen ;
				
				printf("Alright!\n");
				return ;
			}

		}
		
		now_book = now_book -> next ;
		
		}
		
	
	} 
	

