#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc của một nút trong danh sách liên kết
struct ListNode {
    int val;
    struct ListNode *next;
};

// Hàm tiện ích để tạo một nút mới
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // Sử dụng một nút giả để đơn giản hóa việc xử lý ở đầu danh sách
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    // Nối phần còn lại của danh sách không rỗng
    if (list1 != NULL) tail->next = list1;
    if (list2 != NULL) tail->next = list2;

    return dummy.next;
}

// Hàm tiện ích để in danh sách liên kết
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Tạo danh sách 1: 1 -> 2 -> 4
    struct ListNode* list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->next = createNode(4);

    // Tạo danh sách 2: 1 -> 3 -> 4
    struct ListNode* list2 = createNode(1);
    list2->next = createNode(3);
    list2->next->next = createNode(4);

    printf("Danh sách 1: ");
    printList(list1);
    printf("Danh sách 2: ");
    printList(list2);

    struct ListNode* mergedList = mergeTwoLists(list1, list2);

    printf("Danh sách sau khi trộn: ");
    printList(mergedList);

    // Giải phóng bộ nhớ (trong một ứng dụng thực tế, bạn nên có một hàm riêng cho việc này)
    // free(mergedList); // Cần một hàm giải phóng toàn bộ danh sách

    return 0;
}