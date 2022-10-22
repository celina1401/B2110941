#include <stdio.h> 
#define Maxlenght 300

typedef int ElementType;
typedef int Position;
typedef struct {
    ElementType Elements[Maxlenght];
    Position Last;
}List;
void makenullList(List *L){
    L->Last = 0;
}

Position endList (List L){
    return L.Last+1;
}
Position next(Position p, List L){
    return p+1;
}
ElementType retrieve(Position p, List L){
    return L.Elements[p-1];
}
// Position locate (ElementType x, List L)
// {
//     Position p;
//     int found = 0;
//     p = 1;
//     while ((p!=L.Last+1) && (found == 0))
//         if (L.Elements[p-1] == x) found = 1;
//         else p +=1;
//     return p;    
// }
Position locate (ElementType x, List L)
{
    Position i;
   for (i = 0; i < L.Last; i++){
       if(L.Elements[i] == x) return i;
   }
   return L.Last+1;
}
// void deleteList (Position p, List *pL){
//     int i;
//     for (i=p; i< pL->Last; i++){

//         pL->Elements[i-1] = pL ->Elements[i];
//     }
//     for (i=p-1; i<pL->Last-1; i++){

//         pL->Elements[i] = pL->Elements[i+1];
//     }
//     pL->Last--;
// }
void deleteList (Position p, List *pL){
    int i;
    for (i=p; i<pL->Last-1; i++){

        pL->Elements[i] = pL->Elements[i+1];
    }
    pL->Last--;
}
// void erase(ElementType x, List *pL){
//     Position p;
//     p = locate(x, *pL);
//     if( p != pL->Last+1)
//         deleteList(p, pL);
// }
void erase(ElementType x, List *pL){
    Position p;
    p = locate(x, *pL);
    if(p<=pL->Last)
    deleteList(p,pL);
}

int main(){
 List L;
int i;
L.Last=0;
for(i=0;i<5;i++)
  {  L.Elements[i] = 2*i;}
L.Elements[i] = 2;
L.Last=6;
erase(2,&L);
for(i=0;i<L.Last;i++)
    {printf("%d ",L.Elements[i]);}
} 