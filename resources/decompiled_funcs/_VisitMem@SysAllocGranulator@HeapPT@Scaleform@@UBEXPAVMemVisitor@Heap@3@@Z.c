void __thiscall Scaleform::HeapPT::SysAllocGranulator::VisitMem(
        Scaleform::HeapPT::SysAllocGranulator *this,
        Scaleform::Heap::MemVisitor *visitor)
{
  Scaleform::HeapPT::Granulator::VisitMem(this->pGranulator, visitor, Cat_SysAlloc, Cat_SysAllocFree);
}
