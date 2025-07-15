void __thiscall Scaleform::StatsUpdate::MemReportFile(
        Scaleform::StatsUpdate *this,
        Scaleform::MemItem *rootItem,
        Scaleform::MemoryHeap::MemReportType reportType)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::StatsUpdate::FileStats,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *v3; // edi
  unsigned int v4; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::StatsUpdate::FileStats,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v5; // ecx
  signed int v6; // ebx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::StatsUpdate::FileStats,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *pTable; // edx
  const Scaleform::StringLH *v8; // ebp
  Scaleform::StatsUpdate *v9; // ebp
  const Scaleform::StatDesc *Desc; // eax
  void *v11; // esi
  unsigned int SizeMask; // eax
  unsigned int *v13; // ecx
  int v14; // [esp-Ch] [ebp-33Ch]
  unsigned int v15; // [esp-8h] [ebp-338h]
  int v16; // [esp-8h] [ebp-338h]
  const __m128i *v17; // [esp-4h] [ebp-334h]
  Scaleform::String v18; // [esp+10h] [ebp-320h] BYREF
  Scaleform::MemoryHeap::HeapVisitor visitor; // [esp+14h] [ebp-31Ch] BYREF
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::StatsUpdate::FileStats,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > v20; // [esp+18h] [ebp-318h] BYREF
  Scaleform::StringLH *v21; // [esp+1Ch] [ebp-314h]
  Scaleform::StatsUpdate *v22; // [esp+20h] [ebp-310h]
  Scaleform::MsgFormat::Sink r; // [esp+24h] [ebp-30Ch] BYREF
  Scaleform::MsgFormat v24; // [esp+30h] [ebp-300h] BYREF

  v22 = this;
  v3 = 0;
  visitor.__vftable = (Scaleform::MemoryHeap::HeapVisitor_vtbl *)&Scaleform::StatsUpdate::FileVisitor::`vftable';
  v20.pTable = 0;
  Scaleform::MemoryHeap::VisitChildHeaps(Scaleform::Memory::pGlobalHeap, &visitor);
  v4 = 0;
  if ( v20.pTable )
  {
    v5 = v20.pTable + 1;
    do
    {
      if ( v5->EntryCount != -2 )
        break;
      ++v4;
      v5 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::StatsUpdate::FileStats,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *)((char *)v5 + 540);
    }
    while ( v4 <= v20.pTable->SizeMask );
    v3 = &v20;
  }
  v6 = v4;
  while ( v3 && v3->pTable && v6 <= (signed int)v3->pTable->SizeMask )
  {
    Scaleform::String::String(&v18);
    pTable = v3->pTable;
    r.SinkData.pStr = &v18;
    r.Type = tStr;
    v8 = (const Scaleform::StringLH *)&pTable[2] + 135 * v6;
    Scaleform::MsgFormat::MsgFormat(&v24, &r);
    Scaleform::MsgFormat::Parse(&v24, "Movie File {0}");
    Scaleform::MsgFormat::FormatD1<Scaleform::StringLH>(&v24, v8);
    Scaleform::MsgFormat::FinishFormatD(&v24);
    Scaleform::MsgFormat::~MsgFormat(&v24);
    v9 = v22;
    v17 = (const __m128i *)((v18.HeapTypeBits & 0xFFFFFFFC) + 8);
    v15 = v22->NextHandle++;
    v21 = Scaleform::MemItem::AddChild(rootItem, v15, v17);
    Scaleform::StatBag::UpdateGroups((Scaleform::StatBag *)(&v3->pTable[2].SizeMask + 135 * v6));
    v16 = (int)v21;
    v14 = (int)(&v3->pTable[2].SizeMask + 135 * v6);
    Desc = Scaleform::StatDesc::GetDesc(1u);
    Scaleform::StatsUpdate::GetFileMemory(v9, (Scaleform::StatDesc::Iterator)Desc, v14, v16, reportType);
    v11 = (void *)(v18.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((v18.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
    SizeMask = v3->pTable->SizeMask;
    if ( v6 <= (int)SizeMask && ++v6 <= SizeMask )
    {
      v13 = &v3->pTable[1].EntryCount + 135 * v6;
      do
      {
        if ( *v13 != -2 )
          break;
        ++v6;
        v13 += 135;
      }
      while ( v6 <= SizeMask );
    }
  }
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::StatsUpdate::FileStats,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::Clear(&v20);
}
