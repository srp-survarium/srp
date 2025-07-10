void __thiscall Scaleform::GFx::AMP::ViewStats::AddMarker(Scaleform::GFx::AMP::ViewStats *this, char *markerType)
{
  char *v2; // ebx
  Scaleform::StringHashLH<unsigned long,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *p_Markers; // edi
  void *v5; // esi
  unsigned int v6; // eax
  void *v7; // esi
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::Iterator it; // [esp+10h] [ebp-10h] BYREF
  Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeRef key; // [esp+18h] [ebp-8h] BYREF

  v2 = markerType;
  Scaleform::String::String((Scaleform::String *)&markerType, markerType);
  p_Markers = &this->Markers;
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::FindAlt<Scaleform::String>(
    &this->Markers.mHash,
    &it,
    (const Scaleform::String *)&markerType);
  v5 = (void *)((unsigned int)markerType & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)markerType & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v5);
  if ( it.pHash && it.pHash->pTable && it.Index <= (signed int)it.pHash->pTable->SizeMask )
  {
    ++it.pHash->pTable[2 * it.Index + 2].SizeMask;
  }
  else
  {
    it.pHash = (const Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)1;
    Scaleform::String::String((Scaleform::String *)&markerType, v2);
    key.pFirst = (const Scaleform::String *)&markerType;
    key.pSecond = (const unsigned int *)&it;
    v6 = Scaleform::String::BernsteinHashFunctionCIS(
           (char *)(((unsigned int)markerType & 0xFFFFFFFC) + 8),
           *(_DWORD *)((unsigned int)markerType & 0xFFFFFFFC) & 0x7FFFFFFF,
           0x1505u);
    Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::add<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
      &p_Markers->mHash,
      p_Markers,
      &key,
      v6);
    v7 = (void *)((unsigned int)markerType & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)markerType & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
  }
}
