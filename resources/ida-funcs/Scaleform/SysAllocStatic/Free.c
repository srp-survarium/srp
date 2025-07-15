char __thiscall Scaleform::SysAllocStatic::Free(
        Scaleform::SysAllocStatic *this,
        void *ptr,
        unsigned int size,
        unsigned int alignment)
{
  unsigned int NumSegments; // ebp
  int v5; // esi
  unsigned int *i; // eax

  NumSegments = this->NumSegments;
  v5 = 0;
  if ( !NumSegments )
    return 0;
  for ( i = &this->Segments[0][4]; (unsigned int)ptr < *i || (unsigned int)ptr >= *i + i[1]; i += 8 )
  {
    if ( ++v5 >= NumSegments )
      return 0;
  }
  Scaleform::HeapPT::AllocLite::Free(this->pAllocator, (Scaleform::HeapPT::TreeSeg *)(i - 4), ptr, size, alignment);
  return 1;
}
