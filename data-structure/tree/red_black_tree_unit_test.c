#include "red_black_tree.c"

void RedBlackTreeUnitTesting();

int main() {
  RedBlackTreeUnitTesting();
  return 0;
}

const RedBlackTreeNode b = {};
const RedBlackTreeNode *c = &b;

void RedBlackTreeUnitTesting() {
  // 指向根结点
  RedBlackTreeNode *p1Root = NULL;

  int arr1Num[] = {87, 29, 87, 65, 25, 33, 78, 12, 5, 85, 15, 17, 23, 42, 66};
  int arr1NumLen = (sizeof(arr1Num) / sizeof(int));

  for (int i = 0; i < arr1NumLen; i++) {
    AddNode(&p1Root, arr1Num[i]);
  }

  InorderTraversal(p1Root);

  // DeleteNode(&p1Root, arr1Num[8]);

  InorderTraversal(p1Root);
}