void __thiscall Scaleform::HeapPT::FreeBin::VisitMem(
        Scaleform::HeapPT::FreeBin *this,
        Scaleform::Heap::MemVisitor *visitor,
        unsigned int shift,
        Scaleform::Heap::MemVisitor::Category cat)
{
  unsigned int v4; // ebx
  unsigned int v5; // esi
  Scaleform::HeapPT::BinLNode *v6; // ebx
  unsigned int v7; // esi
  unsigned int v8; // eax
  Scaleform::HeapPT::BinLNode **Roots; // [esp+20h] [ebp-Ch]
  int v10; // [esp+24h] [ebp-8h]

  Roots = this->ListBin2.Roots;
  v10 = 32;
  do
  {
    v4 = (unsigned int)*(Roots - 33);
    v5 = v4;
    if ( v4 )
    {
      do
      {
        visitor->Visit(
          visitor,
          *(const Scaleform::Heap::HeapSegment **)(v5 + 8),
          v5,
          *(unsigned __int16 *)(v5 + 12) << shift,
          cat);
        v5 = *(_DWORD *)(v5 + 4);
      }
      while ( v5 != v4 );
    }
    v6 = *Roots;
    v7 = (unsigned int)*Roots;
    if ( *Roots )
    {
      do
      {
        v8 = *(unsigned __int16 *)(v7 + 12);
        if ( v8 >= 0x21 )
          v8 = *(_DWORD *)(v7 + 16);
        visitor->Visit(visitor, *(const Scaleform::Heap::HeapSegment **)(v7 + 8), v7, v8 << shift, cat);
        v7 = *(_DWORD *)(v7 + 4);
      }
      while ( (Scaleform::HeapPT::BinLNode *)v7 != v6 );
    }
    Scaleform::HeapPT::FreeBin::visitTree(this, (const Scaleform::HeapPT::BinTNode *)Roots[33], visitor, shift, cat);
    ++Roots;
    --v10;
  }
  while ( v10 );
}
