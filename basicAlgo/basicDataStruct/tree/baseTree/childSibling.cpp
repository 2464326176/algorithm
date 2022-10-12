/*
 * @Author: yh
 * @Date: 2022/9/17 1:11
 * @Description: 
 * @FilePath: childSibling.cpp
 */
#include <iostream>
#include <queue>

struct TreeNode {
    int data;
    struct TreeNode *firstChildNode;
    struct TreeNode *nextSiblingNode;

    TreeNode(int data) : data(data), firstChildNode(nullptr), nextSiblingNode(nullptr) {}
};

void traverseByRecursion(TreeNode *headNode, int level) {
    if(!headNode) {
        return ;
    }
    std::string str(level * 2, ' ');
    TreeNode *pHeadNode = headNode;
    printf("%s%d ", str.c_str(), pHeadNode->data);
    printf("\n");

    if(pHeadNode->nextSiblingNode) {
        TreeNode *pNextSiblingNode = pHeadNode->nextSiblingNode;
        while(pNextSiblingNode) {
            printf("%s%d \n", str.c_str(), pHeadNode->data);
            if(pNextSiblingNode->firstChildNode) {\
                int firstChildLevel = level + 1;
                traverseByRecursion(pNextSiblingNode->firstChildNode, firstChildLevel);
            }
            pNextSiblingNode = pNextSiblingNode->nextSiblingNode;
        }
    }

    if(pHeadNode->firstChildNode) {
        ++level;
        std::string str(level * 2, ' ');
        TreeNode *pChildNode = pHeadNode->firstChildNode;
        while(pChildNode) {
            printf("%s%d \n", str.c_str(), pChildNode->data);
            if(pChildNode->firstChildNode) {
                int firstChildLevel = level + 1;
                traverseByRecursion(pChildNode->firstChildNode, firstChildLevel);
            }
            pChildNode = pChildNode->nextSiblingNode;
        }
    }
}

void traverseByQueue(TreeNode *headNode) {
    if(!headNode) {
        return ;
    }
    TreeNode *pHeadNode = headNode;
    std::queue<TreeNode *> treeQueue;

    treeQueue.push(pHeadNode);
    while(!treeQueue.empty()) {
        TreeNode *treeNode = treeQueue.front();
        treeQueue.pop();
        printf("%d ", treeNode->data);
        if(treeNode->nextSiblingNode) {
            treeQueue.push(treeNode->nextSiblingNode);
        }
        if(treeNode->firstChildNode) {
            treeQueue.push(treeNode->firstChildNode);
        }
    }


}

//"a > 2 || (b < 2 && c == 3)"
int main() {
    TreeNode *pHeadNode = new TreeNode(-1);

    TreeNode *pHeadNode0 = new TreeNode(1);
    TreeNode *pHeadNode1 = new TreeNode(11);
    TreeNode *pHeadNode2 = new TreeNode(12);
    TreeNode *pHeadNode3 = new TreeNode(13);
    TreeNode *pHeadNode4 = new TreeNode(121);
    TreeNode *pHeadNode5 = new TreeNode(122);
    TreeNode *pHeadNode6 = new TreeNode(131);
    TreeNode *pHeadNode7 = new TreeNode(1312);
    TreeNode *pHeadNode8 = new TreeNode(1314);


    pHeadNode->firstChildNode = pHeadNode0;
    pHeadNode0->firstChildNode = pHeadNode1;
    pHeadNode1->nextSiblingNode = pHeadNode2;
    pHeadNode2->nextSiblingNode = pHeadNode3;

    pHeadNode2->firstChildNode = pHeadNode4;
    pHeadNode4->nextSiblingNode = pHeadNode5;

    pHeadNode3->firstChildNode = pHeadNode6;
    pHeadNode6->firstChildNode = pHeadNode7;
    pHeadNode7->nextSiblingNode = pHeadNode8;
    int level = 1;
    //traverseByRecursion(pHeadNode->firstChildNode, level);
    traverseByQueue(pHeadNode->firstChildNode);


    return 0;
}
