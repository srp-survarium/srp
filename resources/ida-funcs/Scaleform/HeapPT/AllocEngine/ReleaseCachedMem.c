void __thiscall Scaleform::HeapPT::AllocEngine::ReleaseCachedMem(Scaleform::HeapPT::AllocEngine *this)
{
  Scaleform::Heap::HeapSegment *pCachedBSeg; // eax
  Scaleform::Heap::HeapSegment *pCachedTSeg; // eax

  pCachedBSeg = this->pCachedBSeg;
  if ( pCachedBSeg && !pCachedBSeg->UseCount )
  {
    Scaleform::HeapPT::AllocBitSet1::ReleaseSegment(&this->Allocator, this->pCachedBSeg);
    Scaleform::HeapPT::AllocEngine::freeSegment(this, this->pCachedBSeg);
  }
  pCachedTSeg = this->pCachedTSeg;
  if ( pCachedTSeg && !pCachedTSeg->UseCount )
    Scaleform::HeapPT::AllocEngine::freeSegmentTiny(this, this->pCachedTSeg);
  this->pCachedBSeg = 0;
  this->pCachedTSeg = 0;
}
