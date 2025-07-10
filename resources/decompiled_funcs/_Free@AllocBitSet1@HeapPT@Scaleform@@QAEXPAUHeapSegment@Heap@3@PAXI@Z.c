void __thiscall Scaleform::HeapPT::AllocBitSet1::Free(
        Scaleform::HeapPT::AllocBitSet1 *this,
        Scaleform::Heap::HeapSegment *seg,
        char *ptr,
        unsigned int bytes)
{
  unsigned int MinAlignShift; // ecx
  unsigned __int8 *pData; // edx
  unsigned int v7; // eax
  unsigned __int8 *v8; // edi
  unsigned int v9; // edx
  _DWORD *v10; // ecx
  bool v11; // bl
  bool v12; // bl
  unsigned int v13; // eax
  unsigned int ptra; // [esp+1Ch] [ebp+8h]
  bool left; // [esp+20h] [ebp+Ch]

  MinAlignShift = this->MinAlignShift;
  pData = seg->pData;
  v7 = (ptr - (char *)pData) >> MinAlignShift;
  v8 = &pData[seg->DataSize];
  v9 = bytes >> MinAlignShift;
  *((_DWORD *)&seg[1].pPrev + (v7 >> 5)) &= ~(1 << (v7 & 0x1F));
  ptra = (bytes >> MinAlignShift) + v7;
  v10 = &seg[1].pPrev + ((ptra - 1) >> 5);
  *v10 &= ~(1 << ((v9 + v7 - 1) & 0x1F));
  v11 = &ptr[bytes] < (char *)v8;
  if ( !v7 || (left = 1, ((1 << ((v7 - 1) & 0x1F)) & (int)*(&seg[1].pPrev + ((v7 - 1) >> 5))) != 0) )
    left = 0;
  v12 = v11 && ((1 << (ptra & 0x1F)) & (int)*(&seg[1].pPrev + (ptra >> 5))) == 0;
  v13 = v9 << this->MinAlignShift;
  if ( v9 >= 0x21 )
  {
    *(_WORD *)&ptr[v13 - 2] = 33;
    *((_WORD *)ptr + 6) = 33;
    *(_DWORD *)&ptr[v13 - 8] = v9;
    *((_DWORD *)ptr + 4) = v9;
  }
  else
  {
    *(_WORD *)&ptr[v13 - 2] = v9;
    *((_WORD *)ptr + 6) = v9;
  }
  *((_DWORD *)ptr + 2) = seg;
  if ( left || v12 )
    Scaleform::HeapPT::FreeBin::Merge(&this->Bin, (Scaleform::HeapPT::BinTNode *)ptr, this->MinAlignShift, left, v12);
  else
    Scaleform::HeapPT::FreeBin::Push(&this->Bin, (Scaleform::HeapPT::BinTNode *)ptr);
}
