void __thiscall Scaleform::HeapPT::AllocEngine::freeTiny(
        Scaleform::HeapPT::AllocEngine *this,
        Scaleform::Heap::HeapSegment *seg,
        Scaleform::HeapPT::AllocEngine::TinyBlock *ptr)
{
  Scaleform::List<Scaleform::HeapPT::AllocEngine::TinyBlock,Scaleform::HeapPT::AllocEngine::TinyBlock> *v3; // esi
  Scaleform::HeapPT::AllocEngine::TinyBlock *pNext; // edi

  ptr->pSegment = seg;
  v3 = &this->TinyBlocks[seg->SegType];
  pNext = this->TinyBlocks[seg->SegType].Root.pNext;
  ptr->pPrev = (Scaleform::HeapPT::AllocEngine::TinyBlock *)v3;
  ptr->pNext = pNext;
  v3->Root.pNext->pPrev = ptr;
  v3->Root.pNext = ptr;
  this->TinyFreeSpace += (seg->SegType + 1) << this->MinAlignShift;
  if ( seg->UseCount-- == 1 )
    Scaleform::HeapPT::AllocEngine::freeSegmentTiny(this, seg);
}
