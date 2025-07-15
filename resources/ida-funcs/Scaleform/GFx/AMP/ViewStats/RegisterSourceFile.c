void __thiscall Scaleform::GFx::AMP::ViewStats::RegisterSourceFile(
        Scaleform::GFx::AMP::ViewStats *this,
        Scaleform::String swdHandle,
        unsigned int index,
        const char *name)
{
  Scaleform::HashLH<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64>,2,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *p_SourceLineInfoMap; // ebx
  signed int v6; // eax
  const char *v7; // ebp
  unsigned int v8; // edi
  unsigned int i; // esi
  char v10; // al
  Scaleform::AmpServer *Instance; // eax
  void *v12; // esi
  unsigned __int64 key; // [esp+Ch] [ebp-10h] BYREF
  Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef v14; // [esp+14h] [ebp-8h] BYREF

  p_SourceLineInfoMap = &this->SourceLineInfoMap;
  key = index + ((unsigned __int64)swdHandle.HeapTypeBits << 32);
  v6 = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
         (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&this->SourceLineInfoMap,
         &key);
  if ( v6 < 0
    || this == (Scaleform::GFx::AMP::ViewStats *)-120
    || !p_SourceLineInfoMap->mHash.pTable
    || v6 > (signed int)p_SourceLineInfoMap->mHash.pTable->SizeMask )
  {
    v7 = name;
    v8 = strlen(name);
    Scaleform::String::String(&swdHandle);
    for ( i = 0; i < v8; ++i )
    {
      v10 = v7[i];
      if ( v10 == 59 )
        Scaleform::String::AppendChar(&swdHandle, 0x5Cu);
      else
        Scaleform::String::AppendChar(&swdHandle, v10);
    }
    v14.pFirst = &key;
    v14.pSecond = &swdHandle;
    Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
      &p_SourceLineInfoMap->mHash,
      p_SourceLineInfoMap,
      &v14);
    Instance = Scaleform::AmpServer::GetInstance();
    ((void (__thiscall *)(Scaleform::AmpServer *, _DWORD, _DWORD, unsigned int))Instance->AddSourceFile)(
      Instance,
      key,
      HIDWORD(key),
      (swdHandle.HeapTypeBits & 0xFFFFFFFC) + 8);
    v12 = (void *)(swdHandle.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((swdHandle.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v12);
  }
}
