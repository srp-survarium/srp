void __thiscall Scaleform::SysAllocStatic::VisitMem(
        Scaleform::SysAllocStatic *this,
        Scaleform::Heap::MemVisitor *visitor)
{
  Scaleform::HeapPT::AllocLite::VisitMem(this->pAllocator, visitor, Cat_SysAllocFree);
}
