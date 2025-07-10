DName *__thiscall DName::operator+=(DName *this, char ch)
{
  char *Memory; // eax

  if ( *((char *)this + 4) <= 1 && ch )
  {
    if ( this->node )
    {
      Memory = HeapManager::getMemory(&heap, 8u, 0);
      if ( Memory )
      {
        *(_DWORD *)Memory = &charNode::`vftable';
        Memory[4] = ch;
      }
      else
      {
        Memory = 0;
      }
      DName::append(this, (DNameNode *)Memory);
    }
    else
    {
      DName::operator=(this, ch);
    }
  }
  return this;
}
