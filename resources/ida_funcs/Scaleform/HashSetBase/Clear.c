void __thiscall Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor>>::Clear(
        Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor> > *this)
{
  Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor> > *v1; // esi
  int v2; // ebx
  _DWORD *v3; // edi
  volatile LONG *v4; // esi
  unsigned int v5; // [esp+4h] [ebp-8h]

  v1 = this;
  if ( this->pTable )
  {
    v2 = 0;
    v5 = this->pTable->SizeMask + 1;
    do
    {
      v3 = (unsigned int *)((char *)&v1->pTable[1].EntryCount + v2);
      if ( *v3 != -2 )
      {
        v4 = (volatile LONG *)(*(unsigned int *)((_BYTE *)&v1->pTable[2].EntryCount + v2) & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd(v4 + 1, -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
        v1 = this;
        *v3 = -2;
      }
      v2 += 12;
      --v5;
    }
    while ( v5 );
    if ( v1->pTable )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v1->pTable);
    v1->pTable = 0;
  }
}
