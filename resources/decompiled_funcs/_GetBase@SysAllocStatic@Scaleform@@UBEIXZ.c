unsigned int __thiscall Scaleform::SysAllocStatic::GetBase(Scaleform::SysAllocStatic *this)
{
  unsigned int NumSegments; // esi
  unsigned int result; // eax
  unsigned int *v3; // edx

  NumSegments = this->NumSegments;
  result = -1;
  if ( NumSegments )
  {
    v3 = &this->Segments[0][4];
    do
    {
      if ( *v3 < result )
        result = *v3;
      v3 += 8;
      --NumSegments;
    }
    while ( NumSegments );
  }
  return result;
}
