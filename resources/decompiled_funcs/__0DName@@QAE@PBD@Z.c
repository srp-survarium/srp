DName *__thiscall DName::DName(DName *this, char *s)
{
  int v3; // ecx

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
