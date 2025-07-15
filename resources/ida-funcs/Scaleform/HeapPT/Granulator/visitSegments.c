void __thiscall Scaleform::HeapPT::Granulator::VisitSegments(
        Scaleform::HeapPT::Granulator *this,
        Scaleform::Heap::SegVisitor *visitor,
        unsigned int catSeg,
        unsigned int catUnused)
{
  Scaleform::HeapPT::Granulator::visitSegments(this, this->UsedSeg.Root, visitor, catSeg);
  Scaleform::HeapPT::AllocLite::VisitUnused(&this->Allocator, visitor, catUnused);
}
