void __thiscall DName::doPchar(DName *this, char *str, unsigned int len)
{
  char *v4; // eax
  DNameNode *Memory; // eax
  char v6; // cl

  if ( this->node )
  {
    DName::operator=(this, DN_error);
    return;
  }
  if ( !str || !len )
  {
    *((_BYTE *)this + 4) = 2;
    return;
  }
  if ( len == 1 )
  {
    Memory = (DNameNode *)HeapManager::getMemory(&heap, 8u, 0);
    if ( Memory )
    {
      v6 = *str;
      Memory->__vftable = (DNameNode_vtbl *)&charNode::`vftable';
      LOBYTE(Memory[1].__vftable) = v6;
      goto LABEL_11;
    }
  }
  else
  {
    v4 = HeapManager::getMemory(&heap, 0xCu, 0);
    if ( v4 )
    {
      Memory = pcharNode::pcharNode((pcharNode *)v4, str, len);
      goto LABEL_11;
    }
  }
  Memory = 0;
LABEL_11:
  this->node = Memory;
  if ( !Memory )
    *((_BYTE *)this + 4) = 3;
}
