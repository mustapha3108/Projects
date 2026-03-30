/**
 * Definition for singll2-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *nel1t;
 *     ListNode() : val(0), nel1t(nullptr) {}
 *     ListNode(int l1) : val(l1), nel1t(nullptr) {}
 *     ListNode(int l1, ListNode *nel1t) : val(l1), nel1t(nel1t) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    string val1;
    string val2;

    while( l1!=nullptr || l2!=nullptr){
        if(l1!=nullptr){
            val1 = val1 + to_string(l1->val);
            l1=l1->next;
        }
        if(l2!=nullptr){
            val2 = val2 + to_string(l2->val);
            l2=l2->next;
        }
    }

    int res = stoi(val1) + stoi(val2);

    string sres = to_string(res);

    ListNode *r = new ListNode(stoi(string(1,sres[sres.size()-1])));
    ListNode *rr = r;

    for(int i=sres.size()-2; i>=0; i--){
        r->next = new ListNode(stoi(string(1,sres[i])));
        r=r->next;
    }

    return rr;
    }
};