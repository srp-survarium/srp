int __thiscall pairNode::getLastChar(pairNode *this)
{
  int result; // eax

  result = ((int (__thiscall *)(DNameNode *))this->right->getLastChar)(this->right);
  if ( !(_BYTE)result )
    return ((int (__thiscall *)(DNameNode *))this->left->getLastChar)(this->left);
  return result;
}
