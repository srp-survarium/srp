char __thiscall pDNameNode::getLastChar(pDNameNode *this)
{
  DName *me; // eax
  DNameNode *node; // eax

  me = this->me;
  if ( me && (node = me->node) != 0 )
    return node->getLastChar(node);
  else
    return 0;
}
