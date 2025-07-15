unsigned __int8 *__thiscall Scaleform::HeapMH::AllocBitSet2MH::Alloc(
        Scaleform::HeapMH::AllocBitSet2MH *this,
        unsigned int bytes,
        unsigned int alignSize,
        Scaleform::HeapMH::MagicHeadersInfo *headers)
{
  Scaleform::HeapMH::BinNodeMH *v4; // eax
  Scaleform::HeapMH::BinNodeMH *v5; // esi
  Scaleform::HeapMH::PageMH *Page; // ebp
  unsigned __int8 *AlignedPtr; // ebx
  unsigned int v8; // eax
  unsigned int v9; // ebp
  unsigned int v10; // ebx
  unsigned int *BitSet; // eax
  unsigned int v12; // esi
  unsigned int v13; // ebx
  unsigned int *v14; // eax
  char v15; // cl
  unsigned __int8 *v16; // eax
  unsigned int *v17; // edx
  unsigned int v18; // eax
  Scaleform::HeapMH::PageMH *v20; // [esp+8h] [ebp-Ch]
  unsigned __int8 *v22; // [esp+1Ch] [ebp+8h]

  v4 = Scaleform::HeapMH::ListBinMH::PullBest(&this->Bin, bytes >> 4, alignSize - 1);
  v5 = v4;
  if ( !v4 )
    return 0;
  Page = v4->Page;
  v20 = Page;
  AlignedPtr = Scaleform::HeapMH::ListBinMH::GetAlignedPtr((unsigned __int8 *)v4, alignSize - 1);
  v22 = AlignedPtr;
  Scaleform::HeapMH::GetMagicHeaders((unsigned int)Page->Start, headers);
  headers->Page = Page;
  v8 = AlignedPtr - (unsigned __int8 *)v5;
  v9 = (unsigned int)v5 + 16 * LOBYTE(v5[1].Prev) - (_DWORD)AlignedPtr - bytes;
  if ( AlignedPtr != (unsigned __int8 *)v5 )
  {
    v10 = v8 >> 4;
    *((_BYTE *)v5 + v8 - 1) = v8 >> 4;
    LOBYTE(v5[1].Prev) = v8 >> 4;
    v5->Page = v20;
    Scaleform::HeapMH::ListBinMH::Push(&this->Bin, v5);
    BitSet = headers->BitSet;
    v12 = ((char *)v5 - (char *)headers->AlignedStart) >> 4;
    v13 = v10 + v12 - 1;
    BitSet[v12 >> 4] &= ~(3 << ((2 * v12) & 0x1E));
    v14 = &BitSet[v13 >> 4];
    v15 = 2 * v13;
    AlignedPtr = v22;
    *v14 &= ~(3 << (v15 & 0x1E));
  }
  if ( v9 )
  {
    v16 = &AlignedPtr[bytes];
    v16[v9 - 1] = v9 >> 4;
    v16[12] = v9 >> 4;
    *((_DWORD *)v16 + 2) = v20;
    Scaleform::HeapMH::ListBinMH::Push(&this->Bin, (Scaleform::HeapMH::BinNodeMH *)&AlignedPtr[bytes]);
    v17 = headers->BitSet;
    v18 = (int)(bytes + v22 - headers->AlignedStart) >> 4;
    AlignedPtr = v22;
    v17[v18 >> 4] &= ~(3 << ((2 * v18) & 0x1E));
    v17[((v9 >> 4) + v18 - 1) >> 4] &= ~(3 << ((2 * ((v9 >> 4) + v18 - 1)) & 0x1E));
  }
  Scaleform::Heap::BitSet2::MarkBusy(headers->BitSet, (AlignedPtr - headers->AlignedStart) >> 4, bytes >> 4);
  return AlignedPtr;
}


Scaleform::HeapMH::BinNodeMH *__thiscall Scaleform::HeapMH::AllocBitSet2MH::Alloc(
        Scaleform::HeapMH::AllocBitSet2MH *this,
        unsigned int bytes,
        Scaleform::HeapMH::MagicHeadersInfo *headers)
{
  unsigned int v4; // ebx
  Scaleform::HeapMH::BinNodeMH *v5; // esi
  Scaleform::HeapMH::BinNodeMH *result; // eax
  unsigned int v7; // ecx
  char *v8; // eax
  unsigned int v9; // ebx
  unsigned int *BitSet; // edx
  unsigned int v11; // eax
  int v12; // ebp
  unsigned int v13; // eax
  unsigned int v15; // [esp+10h] [ebp-4h]
  Scaleform::HeapMH::PageMH *Page; // [esp+18h] [ebp+4h]
  unsigned int *v17; // [esp+18h] [ebp+4h]

  v4 = bytes >> 4;
  v15 = bytes >> 4;
  v5 = Scaleform::HeapMH::ListBinMH::PullBest(&this->Bin, bytes >> 4);
  result = 0;
  if ( v5 )
  {
    Page = v5->Page;
    Scaleform::HeapMH::GetMagicHeaders((unsigned int)Page->Start, headers);
    headers->Page = Page;
    v7 = 16 * LOBYTE(v5[1].Prev) - bytes;
    if ( v7 )
    {
      v8 = (char *)v5 + bytes;
      v9 = v7 >> 4;
      v8[v7 - 1] = v7 >> 4;
      v8[12] = v7 >> 4;
      *((_DWORD *)v8 + 2) = Page;
      Scaleform::HeapMH::ListBinMH::Push(&this->Bin, (Scaleform::HeapMH::BinNodeMH *)((char *)v5 + bytes));
      BitSet = headers->BitSet;
      v11 = (int)(bytes + (char *)v5 - (char *)headers->AlignedStart) >> 4;
      v17 = &BitSet[v11 >> 4];
      v12 = 3 << ((2 * v11) & 0x1E);
      v13 = v9 + v11 - 1;
      v4 = v15;
      *v17 &= ~v12;
      BitSet[v13 >> 4] &= ~(3 << ((2 * v13) & 0x1E));
    }
    Scaleform::Heap::BitSet2::MarkBusy(headers->BitSet, ((char *)v5 - (char *)headers->AlignedStart) >> 4, v4);
    return v5;
  }
  return result;
}
