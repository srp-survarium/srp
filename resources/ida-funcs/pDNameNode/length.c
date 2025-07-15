int __thiscall pDNameNode::length(pDNameNode *this)
{
  DName *me; // eax
  DNameNode *node; // eax

  me = this->me;
  if ( me && (node = me->node) != 0 )
    return node->length(node);
  else
    return 0;
}
