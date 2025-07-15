__m128i *__thiscall Scaleform::HeapPT::AllocEngine::Realloc(
        Scaleform::HeapPT::AllocEngine *this,
        Scaleform::Heap::HeapSegment *seg,
        __m128i *oldPtr,
        unsigned int newSize)
{
  unsigned int v5; // ecx
  unsigned int v6; // esi
  unsigned __int16 SegType; // ax
  unsigned int MinAlignShift; // ecx
  int v9; // edx
  unsigned int v10; // eax
  __m128i *result; // eax
  char AlignShift; // al
  unsigned int oldSize; // [esp+Ch] [ebp-4h] BYREF

  v5 = newSize;
  oldSize = 0;
  if ( newSize < 0x10 )
    v5 = 16;
  v6 = ~this->MinAlignMask & (this->MinAlignMask + v5);
  SegType = seg->SegType;
  if ( SegType > 7u )
  {
    if ( SegType == 10 )
    {
      result = (__m128i *)Scaleform::HeapPT::AllocBitSet2::ReallocInPlace(
                            &this->Allocator,
                            seg,
                            oldPtr->m128i_i8,
                            v6,
                            &oldSize);
      if ( !result )
      {
        AlignShift = Scaleform::HeapPT::AllocBitSet2::GetAlignShift(&this->Allocator, seg, (int)oldPtr, oldSize);
        return (__m128i *)Scaleform::HeapPT::AllocEngine::reallocGeneral(this, seg, oldPtr, oldSize, v6, AlignShift);
      }
    }
    else
    {
      return (__m128i *)Scaleform::HeapPT::AllocEngine::reallocSysDirect(
                          this,
                          seg,
                          oldPtr,
                          (LPCRITICAL_SECTION)(~this->MinAlignMask & (this->MinAlignMask + v5)));
    }
  }
  else
  {
    MinAlignShift = this->MinAlignShift;
    v9 = SegType;
    v10 = (SegType + 1) << MinAlignShift;
    oldSize = v10;
    if ( v6 > v10 )
      return (__m128i *)Scaleform::HeapPT::AllocEngine::reallocGeneral(
                          this,
                          seg,
                          oldPtr,
                          v10,
                          v6,
                          MinAlignShift + TinyPow2AllocType[v9]);
    else
      return oldPtr;
  }
  return result;
}
