void __thiscall Scaleform::HeapPT::PageTable::UnmapRange(
        Scaleform::HeapPT::PageTable *this,
        unsigned int mem,
        unsigned int size)
{
  unsigned int v4; // eax
  unsigned int v5; // ecx
  Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader1,256> *v6; // esi
  int v7; // ebx
  Scaleform::HeapPT::Starter *pStarter; // ecx

  v4 = (mem + size - 1) >> 20;
  v5 = mem >> 20;
  if ( mem >> 20 <= v4 )
  {
    v6 = &this->RootTable[v5];
    v7 = v4 - v5 + 1;
    do
    {
      pStarter = this->pStarter;
      if ( v6->RefCount-- == 1 )
      {
        Scaleform::HeapPT::Starter::Free(pStarter, v6->pTable, 0x400u, 0x400u);
        v6->pTable = 0;
      }
      ++v6;
      --v7;
    }
    while ( v7 );
  }
}
