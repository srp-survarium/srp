char *__thiscall DName::getString(DName *this, char *buf, char *end)
{
  DNameNode *node; // ecx

  node = this->node;
  if ( node )
    return node->getString(node, buf, end);
  else
    return buf;
}


char *__thiscall DName::getString(DName *this, char *buf, unsigned int max)
{
  DNameNode *node; // ecx
  char *Memory; // esi
  unsigned int v5; // edi

  node = this->node;
  Memory = buf;
  if ( node )
  {
    if ( buf )
    {
      v5 = max;
LABEL_6:
      *DName::getString(this, Memory, &Memory[v5 - 1]) = 0;
      return Memory;
    }
    v5 = node->length(node) + 1;
    Memory = HeapManager::getMemory(&heap, v5, 0);
    if ( Memory )
      goto LABEL_6;
  }
  else if ( buf )
  {
    *buf = 0;
  }
  return Memory;
}
