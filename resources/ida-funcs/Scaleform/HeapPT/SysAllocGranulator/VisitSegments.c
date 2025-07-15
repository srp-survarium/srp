void __thiscall Scaleform::HeapPT::SysAllocGranulator::VisitSegments(
        Scaleform::HeapPT::SysAllocGranulator *this,
        Scaleform::Heap::SegVisitor *visitor,
        unsigned int catSeg,
        unsigned int catUnused)
{
  Scaleform::HeapPT::Granulator::VisitSegments(this->pGranulator, visitor, catSeg, catUnused);
}
