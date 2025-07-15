bool __thiscall Scaleform::HeapPT::Granulator::Free(
        Scaleform::HeapPT::Granulator *this,
        Scaleform::HeapPT::DualTNode *ptr,
        unsigned int size,
        unsigned int alignSize)
{
  Scaleform::HeapPT::TreeSeg *LeEq; // esi

  LeEq = (Scaleform::HeapPT::TreeSeg *)Scaleform::RadixTree<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegTreeAccessor>::FindLeEq(
                                         &this->UsedSeg,
                                         (unsigned int)ptr);
  Scaleform::HeapPT::AllocLite::Free(&this->Allocator, LeEq, ptr, size, alignSize);
  return LeEq->UseCount-- != 1 || Scaleform::HeapPT::Granulator::freeSegment(this, (Scaleform::HeapMH::NodeMH *)LeEq);
}
