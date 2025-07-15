pcharNode *__thiscall pcharNode::pcharNode(pcharNode *this, const char *str, int len)
{
  int v3; // edi
  char *Memory; // eax
  const char *v6; // ecx

  v3 = len;
  this->__vftable = (pcharNode_vtbl *)&pcharNode::`vftable';
  if ( len && str )
  {
    Memory = HeapManager::getMemory(&heap, len, 0);
    this->me = Memory;
    this->myLen = len;
    if ( Memory )
    {
      v6 = (const char *)(str - Memory);
      do
      {
        *Memory = Memory[(_DWORD)v6];
        ++Memory;
        --v3;
      }
      while ( v3 );
    }
  }
  else
  {
    this->me = 0;
    this->myLen = 0;
  }
  return this;
}
