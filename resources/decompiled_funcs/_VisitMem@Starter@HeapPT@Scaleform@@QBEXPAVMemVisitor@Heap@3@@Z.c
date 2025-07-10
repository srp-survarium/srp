void __thiscall Scaleform::HeapPT::Starter::VisitMem(
        Scaleform::HeapPT::Starter *this,
        Scaleform::Heap::MemVisitor *visitor)
{
  Scaleform::HeapPT::Granulator::VisitMem(&this->Allocator, visitor, Cat_Starter, Cat_StarterFree);
}
