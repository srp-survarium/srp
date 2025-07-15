void __thiscall Scaleform::GFx::AMP::ViewStats::ClearAmpSourceLineStats(Scaleform::GFx::AMP::ViewStats *this)
{
  Scaleform::Lock *p_ViewLock; // ebx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::FileLinePair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >::NodeHashF> >::TableType *pTable; // ecx
  Scaleform::HashLH<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair>,2,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >::NodeHashF> > *p_SourceLineTimingsMap; // esi
  unsigned int v5; // eax
  unsigned int SizeMask; // edx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::FileLinePair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >::NodeHashF> >::TableType *v7; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::FileLinePair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >::NodeHashF> >::TableType *v8; // esi
  unsigned int EntryCount; // edx
  int v10; // ecx
  unsigned int v11; // ecx
  _DWORD *v12; // edx

  p_ViewLock = &this->ViewLock;
  EnterCriticalSection(&this->ViewLock.cs);
  pTable = this->SourceLineTimingsMap.mHash.pTable;
  p_SourceLineTimingsMap = &this->SourceLineTimingsMap;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v5 = 0;
    v7 = pTable + 1;
    do
    {
      if ( v7->EntryCount != -2 )
        break;
      ++v5;
      v7 += 4;
    }
    while ( v5 <= SizeMask );
    pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::FileLinePair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >::NodeHashF> >::TableType *)p_SourceLineTimingsMap;
  }
  else
  {
    v5 = 0;
  }
  v8 = pTable;
  while ( v8 )
  {
    EntryCount = v8->EntryCount;
    if ( !v8->EntryCount || (signed int)v5 > *(_DWORD *)(EntryCount + 4) )
      break;
    v10 = 32 * (v5 + 1);
    *(_DWORD *)(v10 + EntryCount) = 0;
    *(_DWORD *)(v10 + EntryCount + 4) = 0;
    v11 = *(_DWORD *)(v8->EntryCount + 4);
    if ( (int)v5 <= (int)v11 && ++v5 <= v11 )
    {
      v12 = (_DWORD *)(v8->EntryCount + 32 * v5 + 8);
      do
      {
        if ( *v12 != -2 )
          break;
        ++v5;
        v12 += 8;
      }
      while ( v5 <= v11 );
    }
  }
  LeaveCriticalSection(&p_ViewLock->cs);
}
