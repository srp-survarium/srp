void __thiscall Scaleform::HeapPT::FreeBin::visitTree(
        Scaleform::HeapPT::FreeBin *this,
        const Scaleform::HeapPT::BinTNode *root,
        Scaleform::Heap::MemVisitor *visitor,
        unsigned int shift,
        Scaleform::Heap::MemVisitor::Category cat)
{
  const Scaleform::HeapPT::BinTNode *i; // edi
  unsigned int v6; // esi

  for ( i = root; i; i = i->Child[1] )
  {
    Scaleform::HeapPT::FreeBin::visitTree(this, i->Child[0], visitor, shift, cat);
    v6 = (unsigned int)i;
    do
    {
      visitor->Visit(visitor, *(const Scaleform::Heap::HeapSegment **)(v6 + 8), v6, *(_DWORD *)(v6 + 16) << shift, cat);
      v6 = *(_DWORD *)(v6 + 4);
    }
    while ( (const Scaleform::HeapPT::BinTNode *)v6 != i );
  }
}
