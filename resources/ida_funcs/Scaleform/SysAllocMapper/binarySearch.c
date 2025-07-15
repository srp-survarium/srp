unsigned int __thiscall Scaleform::SysAllocMapper::binarySearch(Scaleform::SysAllocMapper *this, unsigned __int8 *ptr)
{
  int NumSegments; // edi
  unsigned int result; // eax
  int v4; // esi

  NumSegments = this->NumSegments;
  result = 0;
  while ( NumSegments > 0 )
  {
    v4 = (NumSegments >> 1) + result;
    if ( this->Segments[v4].Memory >= ptr )
    {
      NumSegments >>= 1;
    }
    else
    {
      result = v4 + 1;
      NumSegments += -1 - (NumSegments >> 1);
    }
  }
  return result;
}
