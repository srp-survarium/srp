DName *__thiscall DName::operator=(DName *this, const DName *rd)
{
  DName *result; // eax

  result = this;
  *this = *rd;
  return result;
}


DName *__thiscall DName::operator=(DName *this, char ch)
{
  *((_BYTE *)this + 4) = 0;
  *((_DWORD *)this + 1) &= 0xFFFF00FF;
  this->node = 0;
  if ( ch )
    DName::doPchar(this, &ch, 1);
  return this;
}


DName *__thiscall DName::operator=(DName *this, char *str)
{
  int v3; // ecx

  *((_BYTE *)this + 4) = 0;
  *((_DWORD *)this + 1) &= 0xFFFF00FF;
  this->node = 0;
  v3 = 0;
  if ( *str )
  {
    do
      ++v3;
    while ( str[v3] );
  }
  DName::doPchar(this, str, v3);
  return this;
}


DName *__thiscall DName::operator=(DName *this, DNameStatus st)
{
  DNameStatusNode *v3; // eax

  *((_DWORD *)this + 1) &= 0xFFFF00FF;
  *((_BYTE *)this + 4) = st;
  if ( st == DN_truncated )
  {
    v3 = DNameStatusNode::make(DN_truncated);
    this->node = v3;
    if ( !v3 )
      *((_BYTE *)this + 4) = 3;
  }
  else
  {
    this->node = 0;
  }
  return this;
}


DName *__thiscall DName::operator+(DName *this, DName *result, const DName *rd)
{
  *result = *this;
  DName::operator+=(result, rd);
  return result;
}


DName *__thiscall DName::operator+(DName *this, DName *result, char ch)
{
  *result = *this;
  DName::operator+=(result, ch);
  return result;
}


DName *__thiscall DName::operator+(DName *this, DName *result, char *str)
{
  *result = *this;
  DName::operator+=(result, str);
  return result;
}


DName *__thiscall DName::operator+(DName *this, DName *result, DNameStatus st)
{
  *result = *this;
  DName::operator+=(result, st);
  return result;
}


DName *__thiscall DName::operator+=(DName *this, const DName *rd)
{
  if ( *((char *)this + 4) <= 1 )
  {
    if ( rd->node )
    {
      if ( this->node )
        DName::append(this, rd->node);
      else
        DName::operator=(this, rd);
    }
    else
    {
      DName::operator+=(this, (DNameStatus)*((char *)rd + 4));
    }
  }
  return this;
}


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


DName *__thiscall DName::operator+=(DName *this, DNameStatus st)
{
  DNameStatusNode *v3; // eax

  if ( *((char *)this + 4) <= 1 )
  {
    if ( !this->node || st == DN_invalid || st == DN_error )
    {
      DName::operator=(this, st);
    }
    else if ( st )
    {
      v3 = DNameStatusNode::make(st);
      DName::append(this, v3);
    }
  }
  return this;
}


DName *__thiscall DName::operator|=(DName *this, const DName *rd)
{
  DName *result; // eax
  char v3; // dl

  result = this;
  if ( *((_BYTE *)this + 4) != 3 )
  {
    v3 = *((_BYTE *)rd + 4);
    if ( v3 > 1 )
      *((_BYTE *)this + 4) = v3;
  }
  return result;
}
