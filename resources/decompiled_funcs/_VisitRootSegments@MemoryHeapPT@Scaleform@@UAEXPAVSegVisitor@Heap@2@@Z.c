void __thiscall Scaleform::MemoryHeapPT::VisitRootSegments(
        Scaleform::MemoryHeapPT *this,
        Scaleform::Heap::SegVisitor *visitor)
{
  Scaleform::HeapPT::HeapRoot::VisitSegments(Scaleform::HeapPT::GlobalRoot, visitor);
}
