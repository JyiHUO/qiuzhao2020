/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
#include<unordered_map>
class Solution {
public:
  RandomListNode* Clone(RandomListNode* pHead)
  {
    if(pHead == NULL)return NULL;
    unordered_map<RandomListNode*, RandomListNode*> old_new;
    RandomListNode* new_head = new RandomListNode(pHead->label);
    RandomListNode* res_head = pHead;
    old_new[pHead] = new_head;
    while(pHead!=NULL){
      if(pHead->next!=NULL && old_new[pHead->next])new_head->next = old_new[pHead->next];
      else{
        if(pHead->next!=NULL){
          new_head->next = new RandomListNode(pHead->next->label);
          old_new[pHead->next] = new_head->next;
        } else{
          new_head->next = NULL;
        }
      }
      if(pHead->random!=NULL && old_new[pHead->random])new_head->random = old_new[pHead->random];
      else{
        if(pHead->random!=NULL){
          new_head->random = new RandomListNode(pHead->random->label);
          old_new[pHead->random] = new_head->random;
        }else{
          new_head->random = NULL;
        }
      }
      pHead = pHead->next;
      new_head = new_head->next;
      }
      return old_new[res_head];
  }
};