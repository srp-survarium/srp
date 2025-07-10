unsigned __int8 *__thiscall Scaleform::HeapMH::AllocBitSet2MH::Alloc(
        Scaleform::HeapMH::AllocBitSet2MH *this,
        unsigned int bytes,
        unsigned __int8 *alignSize,
        Scaleform::HeapMH::MagicHeadersInfo *headers)
{
  Scaleform::HeapMH::BinNodeMH *v4; // eax
  Scaleform::HeapMH::BinNodeMH *v5; // esi
  Scaleform::HeapMH::PageMH *v6; // ebp
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
  Scaleform::HeapMH::PageMH *page; // [esp+8h] [ebp-Ch]
  unsigned __int8 *aligned; // [esp+1Ch] [ebp+8h]

  v4 = Scaleform::HeapMH::ListBinMH::PullBest(&this->Bin, bytes >> 4, (unsigned int)(alignSize - 1));
  v5 = v4;
  if ( !v4 )
    return 0;
  v6 = v4->Page;
  page = v6;
  AlignedPtr = Scaleform::HeapMH::ListBinMH::GetAlignedPtr((unsigned __int8 *)v4, (unsigned int)(alignSize - 1));
  aligned = AlignedPtr;
  Scaleform::HeapMH::GetMagicHeaders((unsigned int)v6->Start, headers);
  headers->Page = v6;
  v8 = AlignedPtr - (unsigned __int8 *)v5;
  v9 = (unsigned int)v5 + 16 * LOBYTE(v5[1].Prev) - (_DWORD)AlignedPtr - bytes;
  if ( AlignedPtr != (unsigned __int8 *)v5 )
  {
    v10 = v8 >> 4;
    *((_BYTE *)v5 + v8 - 1) = v8 >> 4;
    LOBYTE(v5[1].Prev) = v8 >> 4;
    v5->Page = page;
    Scaleform::HeapMH::ListBinMH::Push(&this->Bin, (unsigned __int8 *)v5);
    BitSet = headers->BitSet;
    v12 = ((char *)v5 - (char *)headers->AlignedStart) >> 4;
    v13 = v10 + v12 - 1;
    BitSet[v12 >> 4] &= ~(3 << ((2 * v12) & 0x1E));
    v14 = &BitSet[v13 >> 4];
    v15 = 2 * v13;
    AlignedPtr = aligned;
    *v14 &= ~(3 << (v15 & 0x1E));
  }
  if ( v9 )
  {
    v16 = &AlignedPtr[bytes];
    v16[v9 - 1] = v9 >> 4;
    v16[12] = v9 >> 4;
    *((_DWORD *)v16 + 2) = page;
    Scaleform::HeapMH::ListBinMH::Push(&this->Bin, &AlignedPtr[bytes]);
    v17 = headers->BitSet;
    v18 = (int)(bytes + aligned - headers->AlignedStart) >> 4;
    AlignedPtr = aligned;
    v17[v18 >> 4] &= ~(3 << ((2 * v18) & 0x1E));
    v17[((v9 >> 4) + v18 - 1) >> 4] &= ~(3 << ((2 * ((v9 >> 4) + v18 - 1)) & 0x1E));
  }
  Scaleform::Heap::BitSet2::MarkBusy(headers->BitSet, (AlignedPtr - headers->AlignedStart) >> 4, bytes >> 4);
  return AlignedPtr;
}
