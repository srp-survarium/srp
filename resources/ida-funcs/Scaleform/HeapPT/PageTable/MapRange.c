char __thiscall Scaleform::HeapPT::PageTable::MapRange(
        Scaleform::HeapPT::PageTable *this,
        unsigned int mem,
        unsigned int size)
{
  unsigned int v3; // ebp
  unsigned int v4; // ebx
  unsigned int v5; // edi
  Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader1,256> *i; // esi
  Scaleform::HeapPT::DualTNode *v7; // eax
  int v9; // esi
  unsigned int v10; // edi
  Scaleform::HeapPT::Starter *pStarter; // ecx
  Scaleform::HeapPT::PageTable *v13; // [esp+10h] [ebp-4h]

  v3 = mem >> 20;
  v4 = (mem + size - 1) >> 20;
  v13 = this;
  v5 = mem >> 20;
  if ( mem >> 20 > v4 )
    return 1;
  for ( i = &this->RootTable[v3]; i->pTable; ++i )
  {
LABEL_6:
    ++i->RefCount;
    if ( ++v5 > v4 )
      return 1;
  }
  v7 = Scaleform::HeapPT::Starter::Alloc(this->pStarter, 0x400u, 0x400u);
  i->pTable = (Scaleform::HeapPT::HeapHeader1 *)v7;
  if ( v7 )
  {
    memset((int)v7, 0, 1024);
    this = v13;
    goto LABEL_6;
  }
  if ( v5 > v3 )
  {
    v9 = (int)v13 + 8 * v5 - 4;
    v10 = v5 - v3;
    do
    {
      pStarter = v13->pStarter;
      if ( (*(_DWORD *)(v9 + 4))-- == 1 )
      {
        Scaleform::HeapPT::Starter::Free(pStarter, *(Scaleform::HeapPT::DualTNode **)v9, 0x400u, 0x400u);
        *(_DWORD *)v9 = 0;
      }
      v9 -= 8;
      --v10;
    }
    while ( v10 );
  }
  return 0;
}
