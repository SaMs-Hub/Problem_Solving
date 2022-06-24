// App 1 - Naive


ListNode* getMid(ListNode* head){
    ListNode* curr = head;
    while (curr->next != NULL && curr->next->next != NULL){
        head = head->next;
        curr = curr->next->next;
    }
    return head;

}

ListNode* reverse(ListNode* head){
    ListNode* prev = NULL;
    ListNode* nextNode;

    while (head->next != NULL){
        nextNode = head->next;
        head->next = prev;

        prev = head;
        head = nextNode;
    }
    head->next = prev;
    return head;

}


bool isPalindrome(ListNode* head){
    ListNode* midNode = getMid(head);
    ListNode* secondHalf = reverse(midNode->next);

    while (secondHalf != NULL){
        if (secondHalf->data != head->data){
            return false;
        }
        secondHalf = secondHalf->next;
        head = head->next;

    }
    return true;
}


// App 2- Naive Using Array
bool checkPal(vector<int> arr, int start, int end){
        if (start >= end){
            return true;
        }
        
        if (arr[start] == arr[end]){
            return checkPal(arr, start + 1, end - 1);
        }else{
            return false;
        }
    }
    
    bool isPalindrome(Node* head) {
        vector<int> arr;
        Node* currentNode = head;
        while (currentNode != NULL){
            arr.push_back(currentNode->data);
            currentNode = currentNode->next;
        }
        
        
        bool val = checkPal(arr, 0, arr.size() - 1);
        if (val){
            return true;
        }else{
            return false;
        }
    }
