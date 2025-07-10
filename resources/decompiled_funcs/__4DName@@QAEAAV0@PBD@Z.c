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
