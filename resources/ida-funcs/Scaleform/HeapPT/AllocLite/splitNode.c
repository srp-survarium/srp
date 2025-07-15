void __thiscall Scaleform::HeapPT::AllocLite::splitNode(
        Scaleform::HeapPT::AllocLite *this,
        Scaleform::HeapPT::DualTNode *node,
        Scaleform::HeapPT::DualTNode *start,
        unsigned int size)
{
  Scaleform::HeapPT::TreeSeg *ParentSeg; // ebp
  unsigned int MinShift; // ecx
  unsigned int v7; // esi

  ParentSeg = node->ParentSeg;
  MinShift = this->MinShift;
  v7 = (unsigned int)node + (node->Size << MinShift) - (_DWORD)start - size;
  if ( start != node )
    Scaleform::HeapPT::AllocLite::pushNode(
      this,
      node,
      ParentSeg,
      (unsigned int)((char *)start - (char *)node) >> MinShift);
  if ( v7 )
    Scaleform::HeapPT::AllocLite::pushNode(
      this,
      (Scaleform::HeapPT::DualTNode *)((char *)start + size),
      ParentSeg,
      v7 >> this->MinShift);
}
