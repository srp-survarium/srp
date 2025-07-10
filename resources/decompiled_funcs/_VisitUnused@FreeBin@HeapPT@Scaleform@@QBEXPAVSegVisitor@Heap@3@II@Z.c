void __thiscall Scaleform::HeapPT::FreeBin::VisitUnused(
        Scaleform::HeapPT::FreeBin *this,
        Scaleform::Heap::SegVisitor *visitor,
        unsigned int shift,
        unsigned int cat)
{
  int v4; // ebx
  int v5; // esi
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // edx
  unsigned int v9; // eax
  Scaleform::HeapPT::BinLNode *v10; // ebx
  Scaleform::HeapPT::BinLNode *v11; // esi
  unsigned int ShortSize; // eax
  unsigned int pPrev; // eax
  unsigned int v14; // edx
  unsigned int v15; // eax
  Scaleform::HeapPT::BinLNode **Roots; // [esp+20h] [ebp-Ch]
  int v17; // [esp+24h] [ebp-8h]

  Roots = this->ListBin2.Roots;
  v17 = 32;
  do
  {
    v4 = (int)*(Roots - 33);
    v5 = v4;
    if ( v4 )
    {
      v6 = *(unsigned __int16 *)(v4 + 12);
      if ( v6 >= 0x21 )
        v6 = *(_DWORD *)(v4 + 16);
      if ( v6 << shift >= 0x1000 )
      {
        do
        {
          v7 = *(unsigned __int16 *)(v5 + 12);
          v8 = (v5 + 4095) & 0xFFFFF000;
          if ( v7 >= 0x21 )
            v7 = *(_DWORD *)(v5 + 16);
          v9 = (v5 + (v7 << shift)) & 0xFFFFF000;
          if ( v8 + 4096 <= v9 )
            visitor->Visit(
              visitor,
              cat,
              *(const Scaleform::MemoryHeap **)(*(_DWORD *)(v5 + 8) + 20),
              (v5 + 4095) & 0xFFFFF000,
              v9 - v8);
          v5 = *(_DWORD *)(v5 + 4);
        }
        while ( v5 != v4 );
      }
    }
    v10 = *Roots;
    v11 = *Roots;
    if ( *Roots )
    {
      ShortSize = v10->ShortSize;
      if ( ShortSize >= 0x21 )
        ShortSize = (unsigned int)v10[1].pPrev;
      if ( ShortSize << shift >= 0x1000 )
      {
        do
        {
          pPrev = v11->ShortSize;
          v14 = ((unsigned int)&v11[255].Filler + 1) & 0xFFFFF000;
          if ( pPrev >= 0x21 )
            pPrev = (unsigned int)v11[1].pPrev;
          v15 = ((unsigned int)v11 + (pPrev << shift)) & 0xFFFFF000;
          if ( v14 + 4096 <= v15 )
            visitor->Visit(
              visitor,
              cat,
              v11->pSegment->pHeap,
              ((unsigned int)&v11[255].Filler + 1) & 0xFFFFF000,
              v15 - v14);
          v11 = v11->pNext;
        }
        while ( v11 != v10 );
      }
    }
    Scaleform::HeapPT::FreeBin::visitUnusedInTree(
      this,
      (const Scaleform::HeapPT::BinTNode *)Roots[33],
      visitor,
      shift,
      cat);
    ++Roots;
    --v17;
  }
  while ( v17 );
}
