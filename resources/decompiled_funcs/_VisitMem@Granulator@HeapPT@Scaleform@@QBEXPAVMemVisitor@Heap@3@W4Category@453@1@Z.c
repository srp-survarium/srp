void __thiscall Scaleform::HeapPT::Granulator::VisitMem(
        Scaleform::HeapPT::Granulator *this,
        Scaleform::Heap::MemVisitor *visitor,
        Scaleform::Heap::MemVisitor::Category catSegm,
        Scaleform::Heap::MemVisitor::Category catFree)
{
  Scaleform::HeapPT::AllocLite::VisitMem(&this->Allocator, visitor, catFree);
}
