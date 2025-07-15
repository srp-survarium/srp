void __thiscall Scaleform::HeapPT::FreeBin::visitUnusedInTree(
        Scaleform::HeapPT::FreeBin *this,
        const Scaleform::HeapPT::BinTNode *root,
        Scaleform::Heap::SegVisitor *visitor,
        unsigned int shift,
        unsigned int cat)
{
  const Scaleform::HeapPT::BinTNode *i; // ebx
  const Scaleform::HeapPT::BinTNode *pNext; // esi
  unsigned int ShortSize; // eax
  unsigned int v8; // edx
  unsigned int v9; // eax

  for ( i = root; i; i = i->Child[1] )
  {
    Scaleform::HeapPT::FreeBin::visitUnusedInTree(this, i->Child[0], visitor, shift, cat);
    pNext = i;
    do
    {
      ShortSize = pNext->ShortSize;
      v8 = ((unsigned int)pNext[113].Child + 3) & 0xFFFFF000;
      if ( ShortSize >= 0x21 )
        ShortSize = pNext->Size;
      v9 = ((unsigned int)pNext + (ShortSize << shift)) & 0xFFFFF000;
      if ( v8 + 4096 <= v9 )
        visitor->Visit(visitor, cat, pNext->pSegment->pHeap, ((unsigned int)pNext[113].Child + 3) & 0xFFFFF000, v9 - v8);
      pNext = (const Scaleform::HeapPT::BinTNode *)pNext->pNext;
    }
    while ( pNext != i );
  }
}
