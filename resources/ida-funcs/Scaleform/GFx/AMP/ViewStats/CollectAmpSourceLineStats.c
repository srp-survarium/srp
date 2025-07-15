void __thiscall Scaleform::GFx::AMP::ViewStats::CollectAmpSourceLineStats(
        Scaleform::GFx::AMP::ViewStats *this,
        Scaleform::GFx::AMP::MovieProfile *movieProfile)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::FileLinePair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >::NodeHashF> >::TableType *pTable; // ecx
  Scaleform::HashLH<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair>,2,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >::NodeHashF> > *p_SourceLineTimingsMap; // esi
  unsigned int v5; // eax
  unsigned int SizeMask; // edx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::FileLinePair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >::NodeHashF> >::TableType *v7; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::FileLinePair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >::NodeHashF> >::TableType *v8; // ebp
  signed int v9; // ebx
  unsigned int EntryCount; // eax
  unsigned int v11; // esi
  unsigned __int64 v12; // rax
  Scaleform::GFx::AMP::MovieSourceLineStats *pObject; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v14; // edi
  int v15; // edx
  int v16; // eax
  int v17; // ebp
  signed int Index; // eax
  signed int v19; // ebp
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *p_SourceFileInfo; // esi
  signed int v21; // eax
  unsigned int v22; // eax
  _DWORD *v23; // ecx
  Scaleform::Lock *p_ViewLock; // [esp+18h] [ebp-2Ch]
  Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [esp+1Ch] [ebp-28h] BYREF
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::FileLinePair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::FileLinePair,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::FileLinePair> >::NodeHashF> >::TableType *v27; // [esp+24h] [ebp-20h]
  char v28; // [esp+2Bh] [ebp-19h]
  Scaleform::GFx::AMP::MovieSourceLineStats::SourceStats val; // [esp+2Ch] [ebp-18h] BYREF

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
  v27 = pTable;
  v9 = v5;
  while ( v8 )
  {
    EntryCount = v8->EntryCount;
    if ( !v8->EntryCount || v9 > *(_DWORD *)(EntryCount + 4) )
      break;
    v11 = 32 * v9 + EntryCount;
    if ( *(_DWORD *)(v11 + 36) || *(_DWORD *)(v11 + 32) )
    {
      val.FileId = *(_QWORD *)(v11 + 16);
      val.LineNumber = *(_DWORD *)(v11 + 24);
      LODWORD(v12) = Scaleform::Timer::GetRawFrequency();
      pObject = movieProfile->SourceLineStats.pObject;
      val.TotalTime = *(_QWORD *)(v11 + 32) * (unsigned __int64)(unsigned int)&loc_F4240 / v12;
      Scaleform::ArrayData<Scaleform::GFx::AMP::MovieSourceLineStats::SourceStats,Scaleform::AllocatorLH<Scaleform::GFx::AMP::MovieSourceLineStats::SourceStats,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        &pObject->SourceLineTimings.Data,
        &val);
      v14 = this->SourceLineInfoMap.mHash.pTable;
      if ( v14 )
      {
        v15 = 8;
        v16 = 5381;
        do
        {
          v17 = (unsigned __int8)*(&v28 + v15--);
          v16 = v17 + 65599 * v16;
        }
        while ( v15 );
        Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexCore<unsigned __int64>(
                  (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&this->SourceLineInfoMap,
                  &val.FileId,
                  v14->SizeMask & v16);
        v19 = Index;
        if ( Index >= 0 && Index <= (signed int)v14->SizeMask )
        {
          p_SourceFileInfo = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&movieProfile->SourceLineStats.pObject->SourceFileInfo;
          v21 = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                  p_SourceFileInfo,
                  &val.FileId);
          if ( v21 < 0
            || !p_SourceFileInfo
            || !p_SourceFileInfo->pTable
            || v21 > (signed int)p_SourceFileInfo->pTable->SizeMask )
          {
            key.pFirst = (const unsigned __int64 *)&val;
            key.pSecond = (const Scaleform::String *)&v14[3 * v19 + 3];
            Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
              (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)p_SourceFileInfo,
              p_SourceFileInfo,
              &key);
          }
        }
        v8 = v27;
      }
    }
    v22 = *(_DWORD *)(v8->EntryCount + 4);
    if ( v9 <= (int)v22 && ++v9 <= v22 )
    {
      v23 = (_DWORD *)(32 * v9 + v8->EntryCount + 8);
      do
      {
        if ( *v23 != -2 )
          break;
        ++v9;
        v23 += 8;
      }
      while ( v9 <= v22 );
    }
  }
  LeaveCriticalSection(&p_ViewLock->cs);
}
