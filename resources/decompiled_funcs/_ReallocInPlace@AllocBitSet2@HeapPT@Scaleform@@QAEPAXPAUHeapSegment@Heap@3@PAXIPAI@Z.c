char *__thiscall Scaleform::HeapPT::AllocBitSet2::ReallocInPlace(
        Scaleform::HeapPT::AllocBitSet2 *this,
        Scaleform::Heap::HeapSegment *seg,
        char *oldPtr,
        unsigned int newSize,
        unsigned int *oldSize)
{
  unsigned int MinAlignShift; // ebx
  unsigned __int8 *pData; // eax
  unsigned int v7; // esi
  unsigned int *v8; // ebp
  unsigned int v9; // edi
  unsigned int v10; // esi
  char *v11; // edx
  unsigned int v12; // eax
  unsigned int v13; // eax
  Scaleform::HeapPT::BinTNode *v14; // edi
  unsigned int v15; // eax
  unsigned int v16; // edx
  unsigned int v17; // edi
  unsigned int v19; // ecx
  Scaleform::HeapPT::BinTNode *v20; // edi
  unsigned int v21; // eax
  unsigned int ShortSize; // edx
  Scaleform::HeapPT::BinTNode *v23; // edi
  unsigned int v24; // eax
  unsigned int v25; // edx
  unsigned int v26; // edi
  unsigned int *v27; // ebp
  unsigned int start; // [esp+10h] [ebp-18h]
  unsigned __int8 *end; // [esp+18h] [ebp-10h]
  unsigned int blocks; // [esp+1Ch] [ebp-Ch]
  unsigned int alignSh; // [esp+20h] [ebp-8h]
  unsigned __int8 *base; // [esp+24h] [ebp-4h]
  unsigned int nextTail; // [esp+38h] [ebp+10h]
  unsigned int nextTaila; // [esp+38h] [ebp+10h]
  unsigned int nextTailb; // [esp+38h] [ebp+10h]
  unsigned int nextTailc; // [esp+38h] [ebp+10h]

  MinAlignShift = this->MinAlignShift;
  pData = seg->pData;
  v7 = (oldPtr - (char *)pData) >> this->MinAlignShift;
  v8 = (unsigned int *)&seg[1];
  base = pData;
  end = &pData[seg->DataSize];
  start = v7;
  blocks = Scaleform::Heap::BitSet2::GetBlockSize((const unsigned int *)&seg[1], v7);
  alignSh = Scaleform::Heap::BitSet2::GetAlignShift((const unsigned int *)&seg[1], v7, blocks);
  v9 = blocks << MinAlignShift;
  v10 = ~((1 << (MinAlignShift + alignSh)) - 1) & ((1 << (MinAlignShift + alignSh)) - 1 + newSize);
  *oldSize = blocks << MinAlignShift;
  if ( v10 <= blocks << MinAlignShift )
  {
    if ( v10 < v9 )
    {
      v19 = 0;
      v20 = (Scaleform::HeapPT::BinTNode *)&oldPtr[v9];
      v21 = (blocks << MinAlignShift) - v10;
      if ( v20 < (Scaleform::HeapPT::BinTNode *)end )
      {
        if ( ((v8[(start + blocks) >> 4] >> ((2 * (start + blocks)) & 0x1E)) & 3) != 0 )
        {
          v19 = 0;
        }
        else
        {
          ShortSize = v20->ShortSize;
          if ( ShortSize >= 0x21 )
            ShortSize = v20->Size;
          v19 = ShortSize << MinAlignShift;
        }
      }
      nextTailb = v19 + v21;
      if ( v19 + v21 >= 0x10 )
      {
        if ( v19 )
          Scaleform::HeapPT::FreeBin::Pull(&this->Bin, v20);
        v23 = (Scaleform::HeapPT::BinTNode *)&oldPtr[v10];
        v24 = nextTailb >> MinAlignShift;
        v25 = nextTailb >> MinAlignShift << MinAlignShift;
        nextTailc = v24;
        if ( v24 >= 0x21 )
        {
          *(_WORD *)((char *)v23 + v25 - 2) = 33;
          v23->ShortSize = 33;
          *(_DWORD *)((char *)v23 + v25 - 8) = v24;
          v23->Size = v24;
        }
        else
        {
          *(_WORD *)((char *)v23 + v25 - 2) = v24;
          v23->ShortSize = v24;
        }
        v23->pSegment = seg;
        Scaleform::HeapPT::FreeBin::Push(&this->Bin, v23);
        Scaleform::Heap::BitSet2::MarkBusy(v8, start, v10 >> MinAlignShift, alignSh);
        v26 = ((char *)v23 - (char *)base) >> MinAlignShift;
        v8[v26 >> 4] &= ~(3 << ((2 * v26) & 0x1E));
        v27 = &v8[(nextTailc + v26 - 1) >> 4];
        *v27 &= ~(3 << ((2 * (nextTailc + v26 - 1)) & 0x1E));
      }
    }
    return oldPtr;
  }
  else
  {
    v11 = &oldPtr[v9];
    if ( &oldPtr[v9] >= (char *)end || ((v8[(blocks + start) >> 4] >> ((2 * (blocks + start)) & 0x1E)) & 3) != 0 )
      return 0;
    v12 = *((unsigned __int16 *)v11 + 6);
    if ( v12 >= 0x21 )
      v12 = *((_DWORD *)v11 + 4);
    nextTail = v12 << MinAlignShift;
    if ( v10 > v9 + (v12 << MinAlignShift) )
    {
      return 0;
    }
    else
    {
      Scaleform::HeapPT::FreeBin::Pull(&this->Bin, (Scaleform::HeapPT::BinTNode *)&oldPtr[v9]);
      v13 = v9 + nextTail - v10;
      if ( v13 < 0x10 )
      {
        v10 = v9 + nextTail;
      }
      else
      {
        v14 = (Scaleform::HeapPT::BinTNode *)&oldPtr[v10];
        v15 = v13 >> MinAlignShift;
        v16 = v15 << MinAlignShift;
        nextTaila = v15;
        if ( v15 >= 0x21 )
        {
          *(_WORD *)((char *)v14 + v16 - 2) = 33;
          v14->ShortSize = 33;
          *(_DWORD *)((char *)v14 + v16 - 8) = v15;
          v14->Size = v15;
        }
        else
        {
          *(_WORD *)((char *)v14 + v16 - 2) = v15;
          v14->ShortSize = v15;
        }
        v14->pSegment = seg;
        Scaleform::HeapPT::FreeBin::Push(&this->Bin, v14);
        v17 = ((char *)v14 - (char *)base) >> MinAlignShift;
        v8[v17 >> 4] &= ~(3 << ((2 * v17) & 0x1E));
        v8[(nextTaila + v17 - 1) >> 4] &= ~(3 << ((2 * (nextTaila + v17 - 1)) & 0x1E));
      }
      Scaleform::Heap::BitSet2::MarkBusy(v8, start, v10 >> MinAlignShift, alignSh);
      return oldPtr;
    }
  }
}
