void __thiscall Scaleform::HeapPT::SysAllocWrapper::VisitSegments(
        Scaleform::HeapPT::SysAllocWrapper *this,
        Scaleform::Heap::SegVisitor *visitor,
        unsigned int catSeg,
        unsigned int catUnused)
{
  this->pSysAlloc->VisitSegments(this->pSysAlloc, visitor, catSeg, catUnused);
}
