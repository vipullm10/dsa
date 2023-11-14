//
//  ListSort.cpp
//  DSA
//
//  Created by Vipul Devnani on 08/11/23.
//

#include <stdio.h>
#include <iostream>



using namespace std;


struct ListNode{
    int val;
    ListNode* next;
};




ListNode* insertionSortList(ListNode* head) {
    ListNode* outerPrev = head;
    ListNode* ptr = head->next;
    while(ptr!=NULL){
        ListNode* temp = head;
        ListNode* innerPrev = head;
        if(ptr->val < temp->val){
            ListNode* nextPtr = ptr->next;
            ptr->next = temp;
            outerPrev->next = nextPtr;
            head = ptr;
            ptr = outerPrev;
        }
        else{
            while(temp!=ptr){
                if(ptr->val < temp->val){
                    ListNode* nextPtr = ptr->next;
                    ptr->next = temp;
                    innerPrev->next = ptr;
                    outerPrev->next = nextPtr;
                    ptr = outerPrev;
                    break;
                }
                innerPrev = temp;
                temp = temp -> next;
            }
        }
        outerPrev = ptr;
        ptr = ptr -> next;
    }
    return head;
}

int main(){
    ListNode head;
    head.val = 4;
    ListNode node1;
    node1.val = 2;
    ListNode node2;
    node2.val = 1;
    ListNode node3;
    node3.val = 3;
    head.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;
    
    ListNode* newHead = insertionSortList(&head);
    ListNode* tempPtr = newHead;
    while(tempPtr!=NULL){
        cout<<tempPtr->val<<(tempPtr->next?"->":"");
        tempPtr = tempPtr->next;
    }
    
}
