unsigned __int8 *__thiscall Scaleform::HeapPT::AllocBitSet2::Alloc(
        Scaleform::HeapPT::AllocBitSet2 *this,
        unsigned int bytes,
        unsigned int alignSize,
        Scaleform::Heap::HeapSegment **allocSeg)
{
  unsigned int v4; // ebp
  unsigned int MinAlignShift; // edi
  Scaleform::HeapPT::BinLNode *v6; // eax
  Scaleform::HeapPT::BinTNode *v7; // esi
  unsigned int *v8; // ebx
  unsigned int ShortSize; // eax
  unsigned int v10; // edx
  unsigned int v11; // eax
  unsigned int v12; // ebp
  unsigned int v13; // eax
  unsigned int v14; // esi
  unsigned int v15; // esi
  unsigned int v16; // esi
  Scaleform::HeapPT::BinTNode *v17; // eax
  unsigned int v18; // edx
  unsigned int v19; // eax
  unsigned __int8 v20; // al
  unsigned __int8 *result; // eax
  unsigned __int8 *aligned; // [esp+Ch] [ebp-14h]
  unsigned __int8 *base; // [esp+10h] [ebp-10h]
  Scaleform::Heap::HeapSegment *seg; // [esp+14h] [ebp-Ch]
  Scaleform::HeapPT::FreeBin *p_Bin; // [esp+18h] [ebp-8h]
  unsigned int tailBytes; // [esp+1Ch] [ebp-4h]

  v4 = bytes;
  MinAlignShift = this->MinAlignShift;
  p_Bin = &this->Bin;
  v6 = Scaleform::HeapPT::FreeBin::PullBest(&this->Bin, bytes >> MinAlignShift, MinAlignShift, alignSize - 1);
  v7 = (Scaleform::HeapPT::BinTNode *)v6;
  if ( !v6 )
    return 0;
  seg = v6->pSegment;
  v8 = (unsigned int *)&seg[1];
  base = seg->pData;
  aligned = Scaleform::HeapPT::ListBin::GetAlignedPtr((unsigned __int8 *)v6, alignSize - 1);
  ShortSize = v7->ShortSize;
  v10 = aligned - (unsigned __int8 *)v7;
  if ( ShortSize >= 0x21 )
    ShortSize = v7->Size;
  v11 = (unsigned int)v7 + (ShortSize << MinAlignShift) - (_DWORD)aligned - bytes;
  tailBytes = v11;
  if ( v10 )
  {
    v12 = v10 >> MinAlignShift;
    v13 = v10 >> MinAlignShift << MinAlignShift;
    if ( v10 >> MinAlignShift >= 0x21 )
    {
      *(_WORD *)((char *)v7 + v13 - 2) = 33;
      v7->ShortSize = 33;
      *(_DWORD *)((char *)v7 + v13 - 8) = v12;
      v7->Size = v12;
    }
    else
    {
      *(_WORD *)((char *)v7 + v13 - 2) = v12;
      v7->ShortSize = v12;
    }
    v7->pSegment = seg;
    Scaleform::HeapPT::FreeBin::Push(p_Bin, v7);
    v14 = ((char *)v7 - (char *)base) >> MinAlignShift;
    v8[v14 >> 4] &= ~(3 << ((2 * v14) & 0x1E));
    v15 = v14 + v12 - 1;
    v4 = bytes;
    v8[v15 >> 4] &= ~(3 << ((2 * v15) & 0x1E));
    v11 = tailBytes;
  }
  if ( v11 < 0x10 )
  {
    v4 += v11;
  }
  else
  {
    v16 = v11 >> MinAlignShift;
    v17 = (Scaleform::HeapPT::BinTNode *)&aligned[v4];
    v18 = v16 << MinAlignShift;
    if ( v16 >= 0x21 )
    {
      *(_WORD *)((char *)v17 + v18 - 2) = 33;
      v17->ShortSize = 33;
      *(_DWORD *)((char *)v17 + v18 - 8) = v16;
      v17->Size = v16;
    }
    else
    {
      *(_WORD *)((char *)v17 + v18 - 2) = v16;
      v17->ShortSize = v16;
    }
    v17->pSegment = seg;
    Scaleform::HeapPT::FreeBin::Push(p_Bin, v17);
    v19 = (int)(v4 + aligned - base) >> MinAlignShift;
    v8[v19 >> 4] &= ~(3 << ((2 * v19) & 0x1E));
    v8[(v16 + v19 - 1) >> 4] &= ~(3 << ((2 * (v16 + v19 - 1)) & 0x1E));
  }
  v20 = Scaleform::Alg::UpperBit(alignSize);
  Scaleform::Heap::BitSet2::MarkBusy(v8, (aligned - base) >> MinAlignShift, v4 >> MinAlignShift, v20 - MinAlignShift);
  result = aligned;
  *allocSeg = seg;
  return result;
}
