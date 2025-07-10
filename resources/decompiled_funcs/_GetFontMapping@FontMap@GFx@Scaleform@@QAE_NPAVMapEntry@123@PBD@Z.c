char __thiscall Scaleform::GFx::FontMap::GetFontMapping(
        Scaleform::GFx::FontMap *this,
        Scaleform::GFx::FontMap::MapEntry *pentry,
        char *pfontName)
{
  Scaleform::GFx::FontMapImpl *pImpl; // ecx
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::FontMap::MapEntry,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v6; // eax
  unsigned int *p_SizeMask; // esi
  void *v8; // edi
  Scaleform::String::NoCaseKey key; // [esp+4h] [ebp-4h] BYREF

  if ( !this->pImpl )
    return 0;
  Scaleform::String::String((Scaleform::String *)&pfontName, pfontName);
  pImpl = this->pImpl;
  key.pStr = (const Scaleform::String *)&pfontName;
  v6 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::FontMap::MapEntry,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::GetAlt<Scaleform::String::NoCaseKey>(
         &pImpl->FontMapValue.mHash,
         &key);
  if ( v6 )
    p_SizeMask = &v6->SizeMask;
  else
    p_SizeMask = 0;
  v8 = (void *)((unsigned int)pfontName & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)pfontName & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
  if ( !p_SizeMask )
    return 0;
  Scaleform::String::operator=(&pentry->Name, (const Scaleform::String *)p_SizeMask);
  pentry->ScaleFactor = *((float *)p_SizeMask + 1);
  pentry->Flags = p_SizeMask[2];
  return 1;
}
