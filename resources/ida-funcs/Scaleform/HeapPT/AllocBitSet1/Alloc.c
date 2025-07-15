Scaleform::HeapPT::BinTNode *__thiscall Scaleform::HeapPT::AllocBitSet1::Alloc(
        Scaleform::HeapPT::AllocBitSet1 *this,
        unsigned int bytes,
        Scaleform::Heap::HeapSegment **allocSeg)
{
  unsigned int v3; // ebp
  unsigned int MinAlignShift; // ecx
  unsigned int v6; // ebx
  Scaleform::HeapPT::BinTNode *result; // eax
  Scaleform::HeapPT::BinTNode *v8; // edi
  unsigned int ShortSize; // eax
  Scaleform::Heap::HeapSegment *pSegment; // esi
  unsigned int v11; // ebx
  unsigned int v12; // edx
  char *v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // eax
  char v16; // [esp+Ch] [ebp-4h]
  Scaleform::HeapPT::FreeBin *p_Bin; // [esp+14h] [ebp+4h]

  v3 = bytes;
  MinAlignShift = this->MinAlignShift;
  v6 = bytes >> MinAlignShift;
  v16 = MinAlignShift;
  p_Bin = &this->Bin;
  result = Scaleform::HeapPT::FreeBin::PullBest(&this->Bin, v6);
  v8 = result;
  if ( result )
  {
    ShortSize = result->ShortSize;
    pSegment = v8->pSegment;
    if ( ShortSize >= 0x21 )
      ShortSize = v8->Size;
    v11 = ShortSize - v6;
    v12 = v11 << v16;
    if ( v11 << v16 < 0x10 )
    {
      v3 += v12;
    }
    else
    {
      v13 = (char *)v8 + v3;
      if ( v11 >= 0x21 )
      {
        *(_WORD *)&v13[v12 - 2] = 33;
        *((_WORD *)v13 + 6) = 33;
        *(_DWORD *)&v13[v12 - 8] = v11;
        *((_DWORD *)v13 + 4) = v11;
      }
      else
      {
        *(_WORD *)&v13[v12 - 2] = v11;
        *((_WORD *)v13 + 6) = v11;
      }
      *((_DWORD *)v13 + 2) = pSegment;
      Scaleform::HeapPT::FreeBin::Push(p_Bin, (Scaleform::HeapPT::BinTNode *)((char *)v8 + v3));
      v14 = (v3 + (char *)v8 - (char *)pSegment->pData) >> v16;
      *((_DWORD *)&pSegment[1].pPrev + (v14 >> 5)) &= ~(1 << (v14 & 0x1F));
      *((_DWORD *)&pSegment[1].pPrev + ((v14 + v11 - 1) >> 5)) &= ~(1 << ((v14 + v11 - 1) & 0x1F));
    }
    v15 = ((char *)v8 - (char *)pSegment->pData) >> v16;
    *((_DWORD *)&pSegment[1].pPrev + (v15 >> 5)) |= 1 << (v15 & 0x1F);
    *((_DWORD *)&pSegment[1].pPrev + ((v15 + (v3 >> v16) - 1) >> 5)) |= 1 << ((v15 + (v3 >> v16) - 1) & 0x1F);
    *allocSeg = pSegment;
    return v8;
  }
  return result;
}
