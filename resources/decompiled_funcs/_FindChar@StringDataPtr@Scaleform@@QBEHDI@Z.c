int __thiscall Scaleform::StringDataPtr::FindChar(Scaleform::StringDataPtr *this, char c, unsigned int init_ind)
{
  int result; // eax
  unsigned int Size; // edx

  result = init_ind;
  Size = this->Size;
  if ( init_ind >= Size )
    return -1;
  while ( this->pStr[result] != c )
  {
    if ( ++result >= Size )
      return -1;
  }
  return result;
}
