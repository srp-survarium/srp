void __thiscall Scaleform::HeapPT::AllocEngine::freeSegmentBitSet(
        Scaleform::HeapPT::AllocEngine *this,
        Scaleform::Heap::HeapSegment *seg)
{
  Scaleform::LockSafe *p_RootLock; // ebx
  Scaleform::Heap::HeapSegment *pCachedBSeg; // eax
  unsigned int Footprint; // edx

  p_RootLock = &Scaleform::HeapPT::GlobalRoot->RootLock;
  EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
  pCachedBSeg = this->pCachedBSeg;
  if ( pCachedBSeg && pCachedBSeg != seg && !pCachedBSeg->UseCount )
  {
    Scaleform::HeapPT::AllocBitSet1::ReleaseSegment(&this->Allocator, this->pCachedBSeg);
    Scaleform::HeapPT::AllocEngine::freeSegment(this, this->pCachedBSeg);
  }
  Footprint = this->Footprint;
  this->pCachedBSeg = 0;
  if ( Footprint - (this->Allocator.Bin.FreeBlocks << this->Allocator.MinAlignShift) == this->TinyFreeSpace
    || seg->DataSize > 4 * this->Granularity )
  {
    if ( Footprint >= seg->DataSize + this->Reserve )
    {
      Scaleform::HeapPT::AllocBitSet1::ReleaseSegment(&this->Allocator, seg);
      Scaleform::HeapPT::AllocEngine::freeSegment(this, seg);
    }
    LeaveCriticalSection(&p_RootLock->mLock.cs);
  }
  else
  {
    this->pCachedBSeg = seg;
    LeaveCriticalSection(&p_RootLock->mLock.cs);
  }
}
