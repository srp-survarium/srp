DName *__thiscall DName::DName(DName *this, DName *pd)
{
  char *Memory; // eax
  pDNameNode *v4; // eax

  if ( pd )
  {
    Memory = HeapManager::getMemory(&heap, 8u, 0);
    if ( Memory )
      v4 = pDNameNode::pDNameNode((pDNameNode *)Memory, pd);
    else
      v4 = 0;
    this->node = v4;
    *((_BYTE *)this + 4) = v4 != 0 ? 0 : 3;
  }
  else
  {
    this->node = 0;
    *((_BYTE *)this + 4) = 0;
  }
  *((_DWORD *)this + 1) &= 0xFFFF00FF;
  return this;
}
