void __thiscall Scaleform::StatsUpdate::FileVisitor::Visit(
        Scaleform::StatsUpdate::FileVisitor *this,
        Scaleform::MemoryHeap *parent,
        Scaleform::MemoryHeap *heap)
{
  bool v3; // zf
  unsigned int Length; // eax
  unsigned int v5; // ebx
  int v6; // edx
  unsigned int v7; // esi
  Scaleform::StringHash<Scaleform::StatsUpdate::FileStats,Scaleform::AllocatorGH<Scaleform::StatsUpdate::FileStats,2> > *p_FileStatsMap; // esi
  void *v9; // esi
  void *v10; // esi
  Scaleform::String v11; // [esp+4h] [ebp-22Ch] BYREF
  Scaleform::String result; // [esp+8h] [ebp-228h] BYREF
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::StatsUpdate::FileStats,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::Iterator v13; // [esp+Ch] [ebp-224h] BYREF
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::ConstIterator key; // [esp+14h] [ebp-21Ch] BYREF
  Scaleform::StatsUpdate::FileVisitor *v15; // [esp+1Ch] [ebp-214h]
  Scaleform::StatsUpdate::FileStats v16; // [esp+20h] [ebp-210h] BYREF

  v3 = (heap->Info.Desc.Flags & 0x1000) == 0;
  v15 = this;
  if ( !v3 || heap->Info.Desc.HeapId - 2 > 2 )
    return;
  Scaleform::String::String(&v11, (const __m128i *)heap->Info.pName);
  Length = Scaleform::String::GetLength(&v11);
  v5 = 0;
  v6 = 0;
  v7 = Length;
  if ( !Length )
    goto LABEL_10;
  while ( *(_BYTE *)((v11.HeapTypeBits & 0xFFFFFFFC) + 8 + Length - v6 - 1) != 34 )
  {
LABEL_7:
    if ( ++v6 >= Length )
      goto LABEL_10;
  }
  if ( v7 == Length )
  {
    v7 = Length - v6 - 1;
    goto LABEL_7;
  }
  v5 = Length - v6;
LABEL_10:
  Scaleform::String::Substring(&v11, &result, v5, v7);
  p_FileStatsMap = &v15->FileStatsMap;
  key.pHash = (const Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> > *)&result;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::StatsUpdate::FileStats,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::FindAlt<Scaleform::String::NoCaseKey>(
    &v15->FileStatsMap.mHash,
    &v13,
    (const Scaleform::String::NoCaseKey *)&key);
  key.pHash = 0;
  key.Index = 0;
  if ( Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF>>::ConstIterator::operator==(
         (Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::ConstIterator *)&v13,
         &key) )
  {
    Scaleform::StatBag::StatBag(&v16.Bag, 0, 0x2000u);
    v16.TotalMemory = 0;
    Scaleform::StringHash<Scaleform::StatsUpdate::FileStats,Scaleform::AllocatorGH<Scaleform::StatsUpdate::FileStats,2>>::SetCaseInsensitive(
      p_FileStatsMap,
      &result,
      &v16);
    Scaleform::StatBag::~StatBag(&v16.Bag);
    key.pHash = (const Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> > *)&result;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::StatsUpdate::FileStats,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::FindAlt<Scaleform::String::NoCaseKey>(
      &p_FileStatsMap->mHash,
      &v13,
      (const Scaleform::String::NoCaseKey *)&key);
  }
  Scaleform::StatsUpdate::FileVisitor::UpdateMovieHeap(
    v15,
    heap,
    (Scaleform::StatBag *)(&v13.pHash->pTable[2].SizeMask + 135 * v13.Index));
  v9 = (void *)(result.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((result.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
  v10 = (void *)(v11.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v11.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v10);
}
