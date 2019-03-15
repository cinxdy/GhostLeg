#include<stdio.h>
#include<stdlib.h>

typedef struct {
  char name[20];
  int weight;
  int price;
  int priceS;
  int star;
  int comments;
} productList;

void _inputList(productList* list,int index){
  printf("%d-th product name?\n",index+1);
  scanf("%s",list[index].name);
  printf("%d-th product weight?\n",index+1);
  scanf("%d",&list[index].weight);
  printf("%d-th product price?\n",index+1);
  scanf("%d",&list[index].price);
  printf("%d-th product standard price?\n",index+1);
  scanf("%d",&list[index].priceS);
  printf("%d-th product star count?\n",index+1);
  scanf("%d",&list[index].star);
  printf("%d-th product comments count?\n",index+1);
  scanf("%d",&list[index].comments);
  printf("\n");
}

void _outputList(productList* list,int index){
  printf("--%d-th product--\n",index+1);
  printf("name: %s\n",list[index].name);
  printf("weight: %d\n",list[index].weight);
  printf("price: %d\n",list[index].price);
  printf("standard price: %d\n",list[index].priceS);
  printf("star count: %d\n",list[index].star);
  printf("comments count: %d\n",list[index].comments);
  printf("\n");
}

void _askIndex(int* index,int size){
  while(1){
    printf("Enter a index\n");
    scanf("%d",index);
    if(*index>size || *index<0)
      printf("Wrong input!\n");
    else break;
  }
  (*index)--;
}

void addList(productList* list,int* size){
  int newsize=0;
  printf("Now, size of product list : %d\n",*size);
  while(1){
  printf("Enter a size of list\n");
  scanf("%d",&newsize);
  if(newsize<*size)
    printf("Wrong input!\n");
  else break;
  }

  list = (productList*)realloc(list,sizeof(productList)*newsize);
  if(list==NULL) {
    printf("failed to memory allocate!\n");
    exit(-1);
  }

  for(int i=*size;i<newsize;i++)
    _inputList(list,i);

  *size = newsize;
}

void printList(productList* list,int size){
  int isall = 0;
  int index=0;

  printf("Do you want to print all? (Y:1 N:0)\n");
  scanf("%d",&isall);

  switch(isall){
    case 0:
      _askIndex(&index,size);
      _outputList(list,index);
      break;

    case 1:
      for(int i=0;i<size;i++){
        _outputList(list,i);
      }
      break;
    default : printf("Wrong input!\n"); break;
  }

}

void modifyList(productList* list,int size){
  int index=0;
  _askIndex(&index,size);
  _outputList(list,index);
  _inputList(list,index);

}

void deleteList(productList* list,int* size){
  int index = 0;
  int isdelete = 0;

  _askIndex(&index,*size);
  _outputList(list,index);

  printf("Do you want to delete? (Y:1 N:0)\n");
  scanf("%d",&isdelete);

  if(isdelete){
    for(int i=index;i<*size;i++)
      list[i]=list[i+1];
    (*size)--;
    list = (productList*)realloc(list,sizeof(productList)*(*size));
    if(list==NULL) {
      printf("failed to memory allocate!\n");
      exit(-1);
    }
  }
}

void saveList(productList* list,int size){
  FILE *fp = NULL;
  char name[20];

  printf("Enter a name of file\n");
  scanf("%s",name);
  fp = fopen(name,"wt");

  fprintf(fp,"==Product List==\n\n");
  for(int index=0;index<size;index++){
    fprintf(fp,"--%d-th product--\n",index+1);
    fprintf(fp,"name: %s\n",list[index].name);
    fprintf(fp,"weight: %d\n",list[index].weight);
    fprintf(fp,"price: %d\n",list[index].price);
    fprintf(fp,"standard price: %d\n",list[index].priceS);
    fprintf(fp,"star count: %d\n",list[index].star);
    fprintf(fp,"comments count: %d\n",list[index].comments);
    fprintf(fp,"\n");
  }

  fclose(fp);

  printf("Success to save\n");

}

int main(){
  int size = 0;
  int menu=0;
  enum menuName {QUIT,ADD,PRINT,MODIFY,DELETE,SAVE};

  productList *chocolate = (productList*)malloc(sizeof(productList)*size);
  if(chocolate==NULL) {
    printf("failed to memory allocate!\n");
    exit(-1);
  }

  printf("Choose the menu\n");
  do{
    printf("0.quit\t 1.addList\t 2.printList\t 3.modifyList\t 4.deleteList\t 5.saveList\n");
    scanf("%d",&menu);
    switch(menu){
      case QUIT : break;
      case ADD : addList(chocolate,&size);break;
      case PRINT : printList(chocolate,size);break;
      case MODIFY : modifyList(chocolate,size);break;
      case DELETE : deleteList(chocolate,&size);break;
      case SAVE : saveList(chocolate,size);break;
      default : printf("Wrong! Choose the menu again!\n");break;
    }
  }while(menu);
  free(chocolate);
  printf("Bye!\n");
}
