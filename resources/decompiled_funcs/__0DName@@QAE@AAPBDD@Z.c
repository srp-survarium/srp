DName *__thiscall DName::DName(DName *this, char **name, char terminator)
{
  int v4; // edx
  char v6; // al
  const char *v7; // eax
  char v8; // cl
  char *s; // [esp+10h] [ebp+8h]

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
  s = *name;
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
    *name = (char *)v7;
  }
  while ( *v7 );
  DName::doPchar(this, s, v4);
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
