Scaleform::HeapMH::BinNodeMH *__thiscall Scaleform::HeapMH::AllocBitSet2MH::Alloc(
        Scaleform::HeapMH::AllocBitSet2MH *this,
        Scaleform::HeapMH::PageMH *bytes,
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
  Scaleform::HeapMH::PageMH *page; // [esp+18h] [ebp+4h]
  Scaleform::HeapMH::PageMH *pagea; // [esp+18h] [ebp+4h]

  v4 = (unsigned int)bytes >> 4;
  v15 = (unsigned int)bytes >> 4;
  v5 = Scaleform::HeapMH::ListBinMH::PullBest(&this->Bin, (unsigned int)bytes >> 4);
  result = 0;
  if ( v5 )
  {
    page = v5->Page;
    Scaleform::HeapMH::GetMagicHeaders((unsigned int)page->Start, headers);
    headers->Page = page;
    v7 = 16 * LOBYTE(v5[1].Prev) - (_DWORD)bytes;
    if ( v7 )
    {
      v8 = (char *)bytes + (_DWORD)v5;
      v9 = v7 >> 4;
      v8[v7 - 1] = v7 >> 4;
      v8[12] = v7 >> 4;
      *((_DWORD *)v8 + 2) = page;
      Scaleform::HeapMH::ListBinMH::Push(&this->Bin, (unsigned __int8 *)bytes + (_DWORD)v5);
      BitSet = headers->BitSet;
      v11 = ((int)bytes + (char *)v5 - (char *)headers->AlignedStart) >> 4;
      pagea = (Scaleform::HeapMH::PageMH *)&BitSet[v11 >> 4];
      v12 = 3 << ((2 * v11) & 0x1E);
      v13 = v9 + v11 - 1;
      v4 = v15;
      pagea->pPrev = (Scaleform::HeapMH::PageMH *)((int)pagea->pPrev & ~v12);
      BitSet[v13 >> 4] &= ~(3 << ((2 * v13) & 0x1E));
    }
    Scaleform::Heap::BitSet2::MarkBusy(headers->BitSet, ((char *)v5 - (char *)headers->AlignedStart) >> 4, v4);
    return v5;
  }
  return result;
}
