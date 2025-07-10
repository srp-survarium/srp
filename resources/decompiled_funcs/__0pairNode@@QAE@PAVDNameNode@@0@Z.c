pairNode *__thiscall pairNode::pairNode(pairNode *this, DNameNode *left, DNameNode *right)
{
  pairNode *result; // eax

  result = this;
  this->myLen = -1;
  this->left = left;
  this->__vftable = (pairNode_vtbl *)&pairNode::`vftable';
  this->right = right;
  return result;
}
