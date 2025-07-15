void __thiscall Scaleform::HeapPT::AllocEngine::freeSegmentTiny(
        Scaleform::HeapPT::AllocEngine *this,
        Scaleform::Heap::HeapSegment *seg)
{
  Scaleform::LockSafe *p_RootLock; // ebx
  Scaleform::Heap::HeapSegment *pCachedTSeg; // eax
  unsigned int Footprint; // eax

  p_RootLock = &Scaleform::HeapPT::GlobalRoot->RootLock;
  EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
  pCachedTSeg = this->pCachedTSeg;
  if ( pCachedTSeg && pCachedTSeg != seg && !pCachedTSeg->UseCount )
    Scaleform::HeapPT::AllocEngine::releaseSegmentTiny(this, this->pCachedTSeg);
  Footprint = this->Footprint;
  this->pCachedTSeg = 0;
  if ( Footprint - (this->Allocator.Bin.FreeBlocks << this->Allocator.MinAlignShift) == this->TinyFreeSpace )
  {
    if ( Footprint >= seg->DataSize + this->Reserve )
      Scaleform::HeapPT::AllocEngine::releaseSegmentTiny(this, seg);
    LeaveCriticalSection(&p_RootLock->mLock.cs);
  }
  else
  {
    this->pCachedTSeg = seg;
    LeaveCriticalSection(&p_RootLock->mLock.cs);
  }
}
