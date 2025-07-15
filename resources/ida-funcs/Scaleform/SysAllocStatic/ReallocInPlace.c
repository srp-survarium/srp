bool __thiscall Scaleform::SysAllocStatic::ReallocInPlace(
        Scaleform::SysAllocStatic *this,
        char *oldPtr,
        unsigned int oldSize,
        unsigned int newSize,
        unsigned int alignment)
{
  unsigned int NumSegments; // ebx
  int v6; // esi
  unsigned int *i; // eax

  NumSegments = this->NumSegments;
  v6 = 0;
  if ( !NumSegments )
    return 0;
  for ( i = &this->Segments[0][4]; (unsigned int)oldPtr < *i || (unsigned int)oldPtr >= *i + i[1]; i += 8 )
  {
    if ( ++v6 >= NumSegments )
      return 0;
  }
  return Scaleform::HeapPT::AllocLite::ReallocInPlace(
           this->pAllocator,
           (Scaleform::HeapPT::TreeSeg *)(i - 4),
           oldPtr,
           oldSize,
           newSize,
           alignment) < 2;
}
