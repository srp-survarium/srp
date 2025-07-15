Scaleform::Heap::HeapSegment *__thiscall Scaleform::HeapPT::AllocEngine::allocSegmentBitSet(
        Scaleform::HeapPT::AllocEngine *this,
        unsigned int size,
        unsigned int alignSize,
        unsigned int granularity,
        bool *limHandlerOK)
{
  Scaleform::LockSafe *p_RootLock; // ebx
  unsigned int v7; // eax
  Scaleform::HeapPT::AllocBitSet2 *p_Allocator; // edi
  unsigned int v9; // eax
  Scaleform::Heap::HeapSegment *v10; // eax
  Scaleform::Heap::HeapSegment *v11; // esi

  p_RootLock = &Scaleform::HeapPT::GlobalRoot->RootLock;
  EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
  v7 = this->MinAlignMask + 1;
  if ( alignSize > v7 )
    v7 = alignSize;
  p_Allocator = &this->Allocator;
  v9 = granularity * (((~(v7 - 1) & (v7 + (v7 > 0x1000 ? v7 : 0) + size - 1)) + granularity - 1) / granularity);
  v10 = Scaleform::HeapPT::AllocEngine::allocSegment(
          this,
          0xAu,
          v9,
          0x1000u,
          4 * (((((1 << this->Allocator.MinAlignShift) + v9 - 1) >> this->Allocator.MinAlignShift) + 15) >> 4),
          limHandlerOK);
  v11 = v10;
  if ( v10 )
    Scaleform::HeapPT::AllocBitSet2::InitSegment(p_Allocator, v10);
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  return v11;
}
