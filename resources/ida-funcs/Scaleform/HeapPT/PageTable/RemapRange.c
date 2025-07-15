char __thiscall Scaleform::HeapPT::PageTable::RemapRange(
        Scaleform::HeapPT::PageTable *this,
        unsigned int mem,
        unsigned int newSize,
        unsigned int oldSize)
{
  unsigned int v4; // eax
  unsigned int v6; // ecx
  unsigned int v9; // edi
  unsigned int v10; // ebx
  unsigned int v11; // ebx
  unsigned int v12; // esi
  Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader1,256> *v13; // edi
  Scaleform::HeapPT::DualTNode *v14; // eax
  unsigned int v15; // esi
  int v16; // edi
  unsigned int v17; // esi
  Scaleform::HeapPT::Starter *pStarter; // ecx
  bool v19; // zf
  unsigned int v20; // eax
  unsigned int v21; // ecx
  Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader1,256> *v22; // esi
  unsigned int v23; // edi
  Scaleform::HeapPT::Starter *v24; // ecx
  Scaleform::HeapPT::PageTable *v25; // [esp+0h] [ebp-8h]
  unsigned int v26; // [esp+4h] [ebp-4h]
  unsigned int v27; // [esp+Ch] [ebp+4h]

  v4 = oldSize;
  v6 = newSize;
  v25 = this;
  if ( newSize == oldSize )
    return 1;
  if ( newSize > oldSize )
  {
    v9 = oldSize + mem;
    v10 = newSize + mem - 1;
    v27 = (oldSize + mem - 1) >> 20;
    v11 = v10 >> 20;
    v12 = v27 + 1;
    v26 = v9;
    if ( v27 + 1 > v11 )
    {
LABEL_11:
      Scaleform::HeapPT::PageTable::SetSegmentInRange(
        this,
        v9,
        v6 - v4,
        this->RootTable[mem >> 20].pTable[(unsigned __int8)(mem >> 12)].pSegment);
      return 1;
    }
    v13 = &this->RootTable[v12];
    while ( 1 )
    {
      if ( !v13->pTable )
      {
        v14 = Scaleform::HeapPT::Starter::Alloc(this->pStarter, 0x400u, 0x400u);
        v13->pTable = (Scaleform::HeapPT::HeapHeader1 *)v14;
        if ( !v14 )
        {
          v15 = v12 - 1;
          if ( v15 > v27 )
          {
            v16 = (int)&v25->RootTable[v15];
            v17 = v15 - v27;
            do
            {
              pStarter = v25->pStarter;
              v19 = (*(_DWORD *)(v16 + 4))-- == 1;
              if ( v19 )
              {
                Scaleform::HeapPT::Starter::Free(pStarter, *(Scaleform::HeapPT::DualTNode **)v16, 0x400u, 0x400u);
                *(_DWORD *)v16 = 0;
              }
              v16 -= 8;
              --v17;
            }
            while ( v17 );
          }
          return 0;
        }
        memset((int)v14, 0, 1024);
        this = v25;
        v6 = newSize;
      }
      ++v13->RefCount;
      ++v12;
      ++v13;
      if ( v12 > v11 )
      {
        v9 = v26;
        v4 = oldSize;
        goto LABEL_11;
      }
    }
  }
  v20 = (mem + oldSize - 1) >> 20;
  v21 = ((mem + newSize - 1) >> 20) + 1;
  if ( v21 <= v20 )
  {
    v22 = &this->RootTable[v21];
    v23 = v20 - ((mem + newSize - 1) >> 20);
    do
    {
      v24 = this->pStarter;
      v19 = v22->RefCount-- == 1;
      if ( v19 )
      {
        Scaleform::HeapPT::Starter::Free(v24, (Scaleform::HeapPT::DualTNode *)v22->pTable, 0x400u, 0x400u);
        this = v25;
        v22->pTable = 0;
      }
      ++v22;
      --v23;
    }
    while ( v23 );
  }
  return 1;
}
