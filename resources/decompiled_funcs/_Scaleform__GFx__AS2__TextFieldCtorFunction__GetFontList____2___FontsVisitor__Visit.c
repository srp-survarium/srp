void __thiscall Scaleform::GFx::AS2::TextFieldCtorFunction::GetFontList_::_2_::FontsVisitor::Visit(
        Scaleform::GFx::AS2::TextFieldCtorFunction::GetFontList::__l2::FontsVisitor *this,
        Scaleform::GFx::MovieDef *__formal,
        Scaleform::String presource,
        Scaleform::GFx::ResourceId a4,
        const char *a5)
{
  Scaleform::String v5; // esi
  char *v7; // eax
  Scaleform::StringHash<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2> > *pFontNames; // ecx
  void *v9; // esi
  Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeRef key; // [esp+8h] [ebp-8h] BYREF

  v5.pData = presource.pData;
  if ( ((*(int (__thiscall **)(Scaleform::String::DataDesc *))(*(_DWORD *)presource.HeapTypeBits + 8))(presource.pData)
      & 0xFF00) == 0x200 )
  {
    v7 = (char *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)v5.pData[1].Size + 4))(v5.pData[1].Size);
    Scaleform::String::String(&presource, v7);
    pFontNames = this->pFontNames;
    key.pFirst = &presource;
    key.pSecond = &presource;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
      &pFontNames->mHash,
      pFontNames,
      &key);
    v9 = (void *)(presource.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((presource.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
  }
}
