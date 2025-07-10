unsigned __int8 *__thiscall Scaleform::SysAllocMapper::allocMem(
        Scaleform::SysAllocMapper *this,
        unsigned int size,
        unsigned int alignment)
{
  unsigned int LastSegment; // eax
  unsigned __int8 *result; // eax
  unsigned int i; // edi

  LastSegment = this->LastSegment;
  if ( LastSegment != -1 )
  {
    result = Scaleform::SysAllocMapper::allocMem(this, LastSegment, size, alignment);
    if ( result )
      return result;
    this->LastUsed = 0;
  }
  for ( i = 0; i < this->NumSegments; ++i )
  {
    if ( i != this->LastSegment )
    {
      result = Scaleform::SysAllocMapper::allocMem(this, i, size, alignment);
      if ( result )
        return result;
      this->LastUsed = 0;
    }
  }
  return 0;
}
