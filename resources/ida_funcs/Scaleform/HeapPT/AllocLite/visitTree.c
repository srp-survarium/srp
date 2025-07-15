void __thiscall Scaleform::HeapPT::AllocLite::visitTree(
        Scaleform::HeapPT::AllocLite *this,
        const Scaleform::HeapPT::DualTNode *root,
        Scaleform::Heap::HeapSegment *seg,
        Scaleform::Heap::MemVisitor *visitor,
        Scaleform::Heap::MemVisitor::Category cat)
{
  const Scaleform::HeapPT::DualTNode *i; // ebx
  const Scaleform::HeapPT::DualTNode *pNext; // esi

  for ( i = root; i; i = i->Child[1] )
  {
    Scaleform::HeapPT::AllocLite::visitTree(this, i->Child[0], seg, visitor, cat);
    pNext = i;
    do
    {
      seg->DataSize = pNext->ParentSeg->Size;
      seg->pData = pNext->ParentSeg->Buffer;
      visitor->Visit(visitor, seg, (unsigned int)pNext, pNext->Size << this->MinShift, cat);
      pNext = pNext->pNext;
    }
    while ( pNext != i );
  }
}
