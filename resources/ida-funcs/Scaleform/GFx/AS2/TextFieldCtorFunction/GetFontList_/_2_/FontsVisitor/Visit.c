void __thiscall Scaleform::GFx::AS2::TextFieldCtorFunction::GetFontList_::_2_::FontsVisitor::Visit(
        Scaleform::GFx::AS2::TextFieldCtorFunction::GetFontList::__l2::FontsVisitor *this,
        Scaleform::GFx::MovieDef *__formal,
        Scaleform::GFx::Resource *presource,
        Scaleform::GFx::ResourceId a4,
        const char *a5)
{
  Scaleform::GFx::Resource *v5; // esi
  const __m128i *v7; // eax
  Scaleform::StringHash<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2> > *pFontNames; // ecx
  void *v9; // esi
  Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeRef key; // [esp+8h] [ebp-8h] BYREF

  v5 = presource;
  if ( (presource->GetResourceTypeCode(presource) & 0xFF00) == 0x200 )
  {
    v7 = (const __m128i *)(*((int (__thiscall **)(Scaleform::GFx::Resource_vtbl *))v5[1].~Scaleform::GFx::Resource + 1))(v5[1].__vftable);
    Scaleform::String::String((Scaleform::String *)&presource, v7);
    pFontNames = this->pFontNames;
    key.pFirst = (const Scaleform::String *)&presource;
    key.pSecond = (const Scaleform::String *)&presource;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
      &pFontNames->mHash,
      pFontNames,
      &key);
    v9 = (void *)((unsigned int)presource & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)presource & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
  }
}
