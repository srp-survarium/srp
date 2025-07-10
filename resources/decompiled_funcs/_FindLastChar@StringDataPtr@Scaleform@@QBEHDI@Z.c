unsigned int __thiscall Scaleform::StringDataPtr::FindLastChar(
        Scaleform::StringDataPtr *this,
        char c,
        unsigned int init_ind)
{
  unsigned int Size; // eax
  const char *pStr; // ecx

  if ( init_ind == -1 || init_ind > this->Size )
    Size = this->Size;
  else
    Size = init_ind + 1;
  if ( !Size )
    return -1;
  pStr = this->pStr;
  while ( pStr[Size - 1] != c )
  {
    if ( !--Size )
      return -1;
  }
  return Size - 1;
}
