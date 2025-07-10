int __thiscall pairNode::length(pairNode *this)
{
  DNameNode *left; // edi
  int v3; // ebx

  if ( this->myLen < 0 )
  {
    left = this->left;
    v3 = this->right->length(this->right);
    this->myLen = left->length(left) + v3;
  }
  return this->myLen;
}
