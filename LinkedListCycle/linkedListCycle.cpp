// Link to problem
// https://leetcode.com/problems/linked-list-cycle
//

#include <unordered_set>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        auto rabbit = head;
        auto turtle = head;

        while(rabbit && rabbit->next)
        {
            rabbit = rabbit->next->next;
            turtle = turtle->next;

            if (rabbit == turtle)
            {
                return true;
            }
            
        }
        return false;
    }

    bool hasCycle2(ListNode *head)
    {
        auto set = std::unordered_set<ListNode*>();
        while(1)
        {
            if (!head)
            {
                return false;
            }
            if (set.find(head) != set.end())
            {
                return true;
            }
            set.insert(head);
            head = head->next;
        }
    }
};