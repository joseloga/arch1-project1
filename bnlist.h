#ifndef bn_list
#define bn_list

 struct bnlist{
   char name[20];                   //name of the employee.
   char last[20];                   //last name of the employee. 
   struct bnlist *right,*left;      // left and right child.

 };

#endif 
