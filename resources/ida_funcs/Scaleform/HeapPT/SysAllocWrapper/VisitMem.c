void __thiscall Scaleform::HeapPT::SysAllocWrapper::VisitMem(
        Scaleform::HeapPT::SysAllocWrapper *this,
        Scaleform::Heap::MemVisitor *visitor)
{
  this->pSysAlloc->VisitMem(this->pSysAlloc, visitor);
}
