void __thiscall DName::append(DName *this, DNameNode *newRight)
{
  char *Memory; // eax
  pairNode *v4; // eax

  if ( !newRight
    || ((Memory = HeapManager::getMemory(&heap, 0x10u, 0)) == 0
      ? (v4 = 0)
      : (v4 = pairNode::pairNode((pairNode *)Memory, this->node, newRight)),
        (this->node = v4) == 0) )
  {
    *((_BYTE *)this + 4) = 3;
  }
}
