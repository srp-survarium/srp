DName *__thiscall DName::DName(DName *this, char **name, char terminator)
{
  unsigned int v4; // edx
  char v6; // al
  char *v7; // eax
  char v8; // cl
  char *v10; // [esp+10h] [ebp+8h]

  v4 = 0;
  *((_BYTE *)this + 4) = 0;
  *((_DWORD *)this + 1) &= 0xFFFF00FF;
  this->node = 0;
  if ( !*name )
  {
LABEL_24:
    *((_BYTE *)this + 4) = 2;
    return this;
  }
  if ( !**name )
    goto LABEL_23;
  v10 = *name;
  do
  {
    v6 = **name;
    if ( v6 == terminator )
      break;
    if ( v6 != 95
      && v6 != 36
      && v6 != 60
      && v6 != 62
      && v6 != 45
      && (v6 < 97 || v6 > 122)
      && (v6 < 65 || v6 > 90)
      && (v6 < 48 || v6 > 57)
      && v6 >= -1
      && ((unsigned int)&_sbh_sizeHeaderList & UnDecorator::disableFlags) == 0 )
    {
      goto LABEL_24;
    }
    ++v4;
    v7 = *name + 1;
    *name = v7;
  }
  while ( *v7 );
  DName::doPchar(this, v10, v4);
  v8 = **name;
  if ( !v8 )
  {
    if ( *((_BYTE *)this + 4) )
      return this;
LABEL_23:
    *((_BYTE *)this + 4) = 1;
    return this;
  }
  ++*name;
  if ( v8 != terminator )
  {
    this->node = 0;
    *((_BYTE *)this + 4) = 3;
  }
  return this;
}


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


DName *__thiscall DName::DName(DName *this, char *s)
{
  unsigned int v3; // ecx

  *((_BYTE *)this + 4) = 0;
  *((_DWORD *)this + 1) &= 0xFFFF00FF;
  this->node = 0;
  if ( s )
  {
    v3 = 0;
    if ( *s )
    {
      do
        ++v3;
      while ( s[v3] );
    }
    DName::doPchar(this, s, v3);
  }
  return this;
}


DName *__thiscall DName::DName(DName *this, DNameStatus st)
{
  char v3; // al
  DNameStatusNode *v4; // eax

  *((_DWORD *)this + 1) &= 0xFFFF00FF;
  if ( st == DN_invalid || st == DN_error )
    v3 = st;
  else
    v3 = 0;
  this->node = 0;
  *((_BYTE *)this + 4) = v3;
  if ( st == DN_truncated )
  {
    v4 = DNameStatusNode::make(1u);
    this->node = v4;
    if ( !v4 )
      *((_BYTE *)this + 4) = 3;
  }
  return this;
}


DName *__thiscall DName::DName(DName *this, __int64 num)
{
  unsigned int v2; // eax
  char *v4; // edi
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // rcx
  char v8; // [esp+13h] [ebp-1Dh]
  _BYTE v9[3]; // [esp+29h] [ebp-7h] BYREF

  v2 = HIDWORD(num);
  *((_BYTE *)this + 4) = 0;
  *((_DWORD *)this + 1) &= 0xFFFF00FF;
  v4 = v9;
  this->node = 0;
  v9[0] = 0;
  v8 = 0;
  if ( num < 0 )
  {
    v8 = 1;
    v2 = (unsigned __int64)-num >> 32;
    LODWORD(num) = -(int)num;
  }
  do
  {
    --v4;
    v6 = __PAIR64__(v2, num) % 0xA;
    v5 = __PAIR64__(v2, num) / 0xA;
    LODWORD(num) = v5;
    *v4 = v6 + 48;
    v2 = HIDWORD(v5);
  }
  while ( __PAIR64__(HIDWORD(v5), num) );
  if ( v8 )
    *--v4 = 45;
  DName::doPchar(this, v4, v9 - v4);
  return this;
}


DName *__thiscall DName::DName(DName *this, unsigned __int64 num)
{
  char *v3; // edi
  unsigned __int64 v4; // rcx
  _BYTE v6[4]; // [esp+28h] [ebp-8h] BYREF

  *((_BYTE *)this + 4) = 0;
  *((_DWORD *)this + 1) &= 0xFFFF00FF;
  v3 = v6;
  this->node = 0;
  v6[0] = 0;
  do
  {
    --v3;
    v4 = num % 0xA;
    num /= 0xAu;
    *v3 = v4 + 48;
  }
  while ( num );
  DName::doPchar(this, v3, v6 - v3);
  return this;
}
