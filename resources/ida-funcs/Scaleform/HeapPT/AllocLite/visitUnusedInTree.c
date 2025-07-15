void __thiscall Scaleform::HeapPT::AllocLite::visitUnusedInTree(
        Scaleform::HeapPT::AllocLite *this,
        const Scaleform::HeapPT::DualTNode *root,
        Scaleform::Heap::SegVisitor *visitor,
        unsigned int cat)
{
  const Scaleform::HeapPT::DualTNode *i; // ebx
  const Scaleform::HeapPT::DualTNode *pNext; // esi
  unsigned int v7; // edx
  unsigned int v8; // eax

  for ( i = root; i; i = i->Child[1] )
  {
    Scaleform::HeapPT::AllocLite::visitUnusedInTree(this, i->Child[0], visitor, cat);
    pNext = i;
    do
    {
      v7 = ((unsigned int)pNext[102].Child + 3) & 0xFFFFF000;
      v8 = ((unsigned int)pNext + (pNext->Size << this->MinShift)) & 0xFFFFF000;
      if ( v7 + 4096 <= v8 )
        visitor->Visit(visitor, cat, 0, ((unsigned int)pNext[102].Child + 3) & 0xFFFFF000, v8 - v7);
      pNext = pNext->pNext;
    }
    while ( pNext != i );
  }
}
