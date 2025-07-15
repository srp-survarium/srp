void __thiscall Scaleform::HeapPT::Starter::VisitSegments(
        Scaleform::HeapPT::Starter *this,
        Scaleform::Heap::SegVisitor *visitor)
{
  Scaleform::HeapPT::Granulator::VisitSegments(&this->Allocator, visitor, 2u, 0x82u);
}
