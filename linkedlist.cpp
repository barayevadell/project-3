#include "linkedlist.h"  
#include <chrono>  

// Fixed the function signature and removed the semicolon after the function name  
void remove(link* head, int index) {  
  if (!head || index < 0) return;  
  link* prev = nullptr;  
  link* curr = head;  
  int i = 0;  
  while (curr && i < index) {  
      prev = curr;  
      curr = curr->next;  
      i++;  
  }  
  if (curr) {  
      if (prev) prev->next = curr->next;  
      delete curr;  
  }  
}  

link* circle_exists(link* head) {  
   link* slow = head;  
   link* fast = head;  
   while (fast && fast->next) {  
       slow = slow->next;  
       fast = fast->next->next;  
       if (slow == fast) return slow;  
   }  
   return nullptr;  
}  

int size_of_circle(link* head) {  
   link* meet = circle_exists(head);  
   if (!meet) return 0;  
   int count = 1;  
   link* temp = meet->next;  
   while (temp != meet) {  
       count++;  
       temp = temp->next;  
   }  
   return count;  
}
