void __thiscall Scaleform::GFx::AMP::ViewStats::CollectAmpInstructionStats(
        Scaleform::GFx::AMP::ViewStats *this,
        Scaleform::GFx::AMP::MovieProfile *movieProfile)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator *v3; // eax
  const Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *pHash; // esi
  int Index; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // edi
  int v7; // ebx
  unsigned int EntryCount; // ecx
  int v9; // edx
  unsigned int v10; // ebp
  _QWORD *v11; // ecx
  _DWORD *v12; // eax
  _DWORD *v13; // ebp
  const Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v14; // esi
  unsigned int v15; // eax
  unsigned int v16; // ecx
  unsigned int v17; // eax
  int v18; // esi
  __int64 *v19; // edi
  unsigned int RawFrequency; // ebp
  unsigned int v21; // edx
  unsigned __int64 v22; // rax
  Scaleform::GFx::AMP::MovieInstructionStats *pObject; // esi
  unsigned int Size; // edi
  unsigned int v25; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_BufferStatsArray; // esi
  unsigned int v27; // edi
  unsigned int v28; // eax
  Scaleform::RefCountVImpl **v29; // ebx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *Data; // edx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v31; // edi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v32; // edx
  unsigned int SizeMask; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v34; // edx
  __int64 v35; // [esp-14h] [ebp-4Ch]
  unsigned int v36; // [esp+Ch] [ebp-2Ch]
  int v37; // [esp+Ch] [ebp-2Ch]
  _DWORD *v38; // [esp+10h] [ebp-28h]
  int v39; // [esp+14h] [ebp-24h]
  unsigned int v40; // [esp+14h] [ebp-24h]
  _DWORD v41[2]; // [esp+18h] [ebp-20h] BYREF
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v42; // [esp+20h] [ebp-18h]
  Scaleform::Mutex *p_InstructionTimingMutex; // [esp+24h] [ebp-14h]
  const Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v44; // [esp+28h] [ebp-10h]
  int v45; // [esp+2Ch] [ebp-Ch]
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator result; // [esp+30h] [ebp-8h] BYREF

  p_InstructionTimingMutex = &this->InstructionTimingMutex;
  if ( Scaleform::Mutex::TryLock(&this->InstructionTimingMutex) )
  {
    v3 = Scaleform::Hash<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>>::Begin(
           (Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > > *)&this->InstructionTimingsMap,
           &result);
    pHash = v3->pHash;
    Index = v3->Index;
    v44 = pHash;
    v45 = Index;
    while ( 1 )
    {
      if ( !pHash || (pTable = pHash->pTable, (v42 = pTable) == 0) || Index > (signed int)pTable->SizeMask )
      {
        Scaleform::Mutex::Unlock(p_InstructionTimingMutex);
        return;
      }
      v7 = 3 * Index;
      EntryCount = pTable[3 * Index + 3].EntryCount;
      v9 = *(_DWORD *)(EntryCount + 12);
      v10 = 0;
      if ( v9 )
        break;
LABEL_40:
      v32 = pHash->pTable;
      SizeMask = pHash->pTable->SizeMask;
      if ( Index <= (int)SizeMask )
      {
        v45 = ++Index;
        if ( Index <= SizeMask )
        {
          v34 = &v32[3 * Index + 1];
          do
          {
            if ( v34->EntryCount != -2 )
              break;
            ++Index;
            v34 += 3;
            v45 = Index;
          }
          while ( Index <= SizeMask );
        }
      }
    }
    v11 = *(_QWORD **)(EntryCount + 8);
    do
    {
      if ( *v11 )
        ++v10;
      ++v11;
      --v9;
    }
    while ( v9 );
    v36 = v10;
    if ( !v10 )
    {
LABEL_39:
      pHash = v44;
      goto LABEL_40;
    }
    v41[0] = 578;
    v12 = Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, movieProfile, 32, v41);
    if ( v12 )
    {
      *v12 = &Scaleform::RefCountImplCore::`vftable';
      v12[1] = 1;
      *v12 = &Scaleform::GFx::AMP::MovieInstructionStats::ScriptBufferStats::`vftable';
      v12[5] = 0;
      v12[6] = 0;
      v12[7] = 0;
      v13 = v12;
      v38 = v12;
    }
    else
    {
      v13 = 0;
      v38 = 0;
    }
    v14 = v44;
    v13[2] = v44->pTable[v7 + 2].SizeMask;
    v13[3] = v14->pTable[v7 + 2].EntryCount;
    v15 = v36;
    v13[4] = *(_DWORD *)(pTable[v7 + 3].EntryCount + 12);
    if ( v36 >= v13[6] )
    {
      if ( v36 >= v13[7] )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)(v13 + 5),
          v13 + 5,
          v36 + (v36 >> 2));
        goto LABEL_20;
      }
    }
    else if ( v36 < v13[7] >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)(v13 + 5),
        v13 + 5,
        v36);
LABEL_20:
      v15 = v36;
    }
    v13[6] = v15;
    v16 = pTable[v7 + 3].EntryCount;
    v17 = 0;
    v39 = 0;
    if ( *(_DWORD *)(v16 + 12) )
    {
      v37 = 0;
      do
      {
        if ( *(_QWORD *)(8 * v17 + *(_DWORD *)(v16 + 8)) )
        {
          v18 = v37 + v13[5];
          *(_DWORD *)v18 = v17;
          v19 = (__int64 *)(8 * v17 + *(_DWORD *)(pTable[v7 + 3].EntryCount + 8));
          RawFrequency = Scaleform::Timer::GetRawFrequency();
          v35 = *v19;
          v41[1] = v21;
          v22 = v35 * (unsigned __int64)(unsigned int)&loc_F4240 / __PAIR64__(v21, RawFrequency);
          v37 += 16;
          v13 = v38;
          pTable = v42;
          *(_QWORD *)(v18 + 8) = v22;
          v17 = v39;
        }
        v16 = pTable[v7 + 3].EntryCount;
        v39 = ++v17;
      }
      while ( v17 < *(_DWORD *)(v16 + 12) );
    }
    pObject = movieProfile->InstructionStats.pObject;
    Size = pObject->BufferStatsArray.Data.Size;
    v25 = Size;
    p_BufferStatsArray = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&pObject->BufferStatsArray;
    v27 = Size + 1;
    if ( v27 >= v25 )
    {
      if ( v27 >= p_BufferStatsArray->Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_BufferStatsArray,
          p_BufferStatsArray,
          v27 + (v27 >> 2));
    }
    else
    {
      v28 = v25 - v27;
      v29 = (Scaleform::RefCountVImpl **)&p_BufferStatsArray->Data[v28 - 1 + v27];
      if ( v28 )
      {
        v40 = v28;
        do
        {
          if ( *v29 )
            Scaleform::RefCountImpl::Release(*v29);
          --v29;
          --v40;
        }
        while ( v40 );
      }
      if ( v27 < p_BufferStatsArray->Policy.Capacity >> 1 )
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_BufferStatsArray,
          p_BufferStatsArray,
          v27);
    }
    Data = p_BufferStatsArray->Data;
    p_BufferStatsArray->Size = v27;
    v31 = &Data[v27 - 1];
    if ( v31 )
    {
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v13);
      v31->pObject = (Scaleform::GFx::AS3::ClassTraits::Traits *)v13;
    }
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v13);
    Index = v45;
    goto LABEL_39;
  }
}
