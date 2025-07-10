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
