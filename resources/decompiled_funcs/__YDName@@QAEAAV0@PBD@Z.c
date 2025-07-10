DName *__thiscall DName::operator+=(DName *this, char *str)
{
  char *Memory; // eax
  int v4; // edx
  pcharNode *v5; // eax

  if ( *((char *)this + 4) <= 1 && str && *str )
  {
    if ( this->node )
    {
      Memory = HeapManager::getMemory(&heap, 0xCu, 0);
      if ( Memory )
      {
        v4 = 0;
        if ( *str )
        {
          do
            ++v4;
          while ( str[v4] );
        }
        v5 = pcharNode::pcharNode((pcharNode *)Memory, str, v4);
      }
      else
      {
        v5 = 0;
      }
      DName::append(this, v5);
    }
    else
    {
      DName::operator=(this, str);
    }
  }
  return this;
}
