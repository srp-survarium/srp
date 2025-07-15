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
  unsigned __int8 *v30; // [esp+18h] [ebp-10h]
  unsigned int BlockSize; // [esp+1Ch] [ebp-Ch]
  unsigned int alignShift; // [esp+20h] [ebp-8h]
  unsigned __int8 *v33; // [esp+24h] [ebp-4h]
  unsigned int v34; // [esp+38h] [ebp+10h]
  unsigned int v35; // [esp+38h] [ebp+10h]
  unsigned int v36; // [esp+38h] [ebp+10h]
  unsigned int v37; // [esp+38h] [ebp+10h]

  MinAlignShift = this->MinAlignShift;
  pData = seg->pData;
  v7 = (oldPtr - (char *)pData) >> this->MinAlignShift;
  v8 = (unsigned int *)&seg[1];
  v33 = pData;
  v30 = &pData[seg->DataSize];
  start = v7;
  BlockSize = Scaleform::Heap::BitSet2::GetBlockSize((const unsigned int *)&seg[1], v7);
  alignShift = Scaleform::Heap::BitSet2::GetAlignShift((const unsigned int *)&seg[1], v7, BlockSize);
  v9 = BlockSize << MinAlignShift;
  v10 = ~((1 << (MinAlignShift + alignShift)) - 1) & ((1 << (MinAlignShift + alignShift)) - 1 + newSize);
  *oldSize = BlockSize << MinAlignShift;
  if ( v10 <= BlockSize << MinAlignShift )
  {
    if ( v10 < v9 )
    {
      v19 = 0;
      v20 = (Scaleform::HeapPT::BinTNode *)&oldPtr[v9];
      v21 = (BlockSize << MinAlignShift) - v10;
      if ( v20 < (Scaleform::HeapPT::BinTNode *)v30 )
      {
        if ( ((v8[(start + BlockSize) >> 4] >> ((2 * (start + BlockSize)) & 0x1E)) & 3) != 0 )
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
      v36 = v19 + v21;
      if ( v19 + v21 >= 0x10 )
      {
        if ( v19 )
          Scaleform::HeapPT::FreeBin::Pull(&this->Bin, v20);
        v23 = (Scaleform::HeapPT::BinTNode *)&oldPtr[v10];
        v24 = v36 >> MinAlignShift;
        v25 = v36 >> MinAlignShift << MinAlignShift;
        v37 = v24;
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
        Scaleform::Heap::BitSet2::MarkBusy(v8, start, v10 >> MinAlignShift, alignShift);
        v26 = ((char *)v23 - (char *)v33) >> MinAlignShift;
        v8[v26 >> 4] &= ~(3 << ((2 * v26) & 0x1E));
        v27 = &v8[(v37 + v26 - 1) >> 4];
        *v27 &= ~(3 << ((2 * (v37 + v26 - 1)) & 0x1E));
      }
    }
    return oldPtr;
  }
  else
  {
    v11 = &oldPtr[v9];
    if ( &oldPtr[v9] >= (char *)v30 || ((v8[(BlockSize + start) >> 4] >> ((2 * (BlockSize + start)) & 0x1E)) & 3) != 0 )
      return 0;
    v12 = *((unsigned __int16 *)v11 + 6);
    if ( v12 >= 0x21 )
      v12 = *((_DWORD *)v11 + 4);
    v34 = v12 << MinAlignShift;
    if ( v10 > v9 + (v12 << MinAlignShift) )
    {
      return 0;
    }
    else
    {
      Scaleform::HeapPT::FreeBin::Pull(&this->Bin, (Scaleform::HeapPT::BinTNode *)&oldPtr[v9]);
      v13 = v9 + v34 - v10;
      if ( v13 < 0x10 )
      {
        v10 = v9 + v34;
      }
      else
      {
        v14 = (Scaleform::HeapPT::BinTNode *)&oldPtr[v10];
        v15 = v13 >> MinAlignShift;
        v16 = v15 << MinAlignShift;
        v35 = v15;
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
        v17 = ((char *)v14 - (char *)v33) >> MinAlignShift;
        v8[v17 >> 4] &= ~(3 << ((2 * v17) & 0x1E));
        v8[(v35 + v17 - 1) >> 4] &= ~(3 << ((2 * (v35 + v17 - 1)) & 0x1E));
      }
      Scaleform::Heap::BitSet2::MarkBusy(v8, start, v10 >> MinAlignShift, alignShift);
      return oldPtr;
    }
  }
}
