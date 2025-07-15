void __thiscall Scaleform::GFx::AMP::MovieFunctionStats::Print(
        Scaleform::GFx::AMP::MovieFunctionStats *this,
        Scaleform::Log *log)
{
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *pTable; // esi
  unsigned int v3; // ebp
  unsigned int v4; // edi
  Scaleform::GFx::AMP::MovieFunctionStats::FuncStats *v5; // edx
  int v6; // ecx
  int v7; // eax
  int v8; // ebx
  signed int SizeMask; // ebx
  signed int Index; // eax
  Scaleform::String::DataDesc *pData; // edx
  int v12; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v13; // eax
  int v14; // ecx
  int v15; // edx
  bool v16; // cf
  const Scaleform::GFx::AMP::MovieFunctionStats::FuncStats *v17; // edx
  int v18; // eax
  unsigned int v19; // ecx
  int v20; // esi
  unsigned int v21; // ebp
  unsigned int v22; // ebx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v23; // eax
  int v24; // eax
  int v25; // ecx
  _DWORD *v26; // eax
  int v27; // edx
  int v28; // ecx
  int v29; // edx
  int v30; // ecx
  int v31; // edx
  int v32; // eax
  unsigned int v33; // esi
  unsigned int v34; // esi
  unsigned int v35; // eax
  _DWORD *v36; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *Data; // ebx
  unsigned int *p_TimesCalled; // edi
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v39; // esi
  int v40; // eax
  int v41; // ecx
  int v42; // ebx
  signed int v43; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v44; // ecx
  void *v45; // esi
  void *v46; // esi
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v47; // edx
  int v48; // eax
  unsigned int v49; // ecx
  Scaleform::String v50; // [esp+10h] [ebp-35Ch] BYREF
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > pmemAddr; // [esp+14h] [ebp-358h] BYREF
  Scaleform::ArrayDataBase<Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::AllocatorGH<Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [esp+18h] [ebp-354h] BYREF
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [esp+24h] [ebp-348h] BYREF
  Scaleform::String v54; // [esp+2Ch] [ebp-340h] BYREF
  unsigned int v55; // [esp+30h] [ebp-33Ch]
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *v56; // [esp+34h] [ebp-338h]
  unsigned __int64 v; // [esp+38h] [ebp-334h] BYREF
  Scaleform::MsgFormat::Sink r; // [esp+40h] [ebp-32Ch] BYREF
  _DWORD v59[8]; // [esp+4Ch] [ebp-320h] BYREF
  Scaleform::MsgFormat v60; // [esp+6Ch] [ebp-300h] BYREF

  pTable = 0;
  v3 = 0;
  v50.pData = (Scaleform::String::DataDesc *)this;
  pmemAddr.pTable = 0;
  if ( this->FunctionTimings.Data.Size )
  {
    v4 = 0;
    while ( 1 )
    {
      v5 = &this->FunctionTimings.Data.Data[v4 / 0x20];
      if ( !pTable )
        goto LABEL_10;
      v6 = 8;
      v7 = 5381;
      do
      {
        v8 = *((unsigned __int8 *)v5 + --v6);
        v7 = v8 + 65599 * v7;
      }
      while ( v6 );
      SizeMask = pTable->SizeMask;
      Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorGH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexCore<unsigned __int64>(
                &pmemAddr,
                &v5->FunctionId,
                SizeMask & v7);
      if ( Index >= 0 && Index <= SizeMask )
      {
        pData = v50.pData;
        v12 = 6 * Index;
        ++pTable[v12 + 5].EntryCount;
        v13 = &pmemAddr.pTable[v12 + 6];
        v14 = *(_DWORD *)pData->Data;
        v15 = *(_DWORD *)(v4 + v14 + 24);
        v16 = __CFADD__(v15, v13->EntryCount);
        v13->EntryCount += v15;
        v13->SizeMask += *(_DWORD *)(v4 + v14 + 28) + v16;
      }
      else
      {
LABEL_10:
        v17 = (const Scaleform::GFx::AMP::MovieFunctionStats::FuncStats *)(v4 + *(_DWORD *)v50.pData->Data);
        key.pSecond = v17;
        key.pFirst = &v17->FunctionId;
        v18 = 8;
        v19 = 5381;
        do
        {
          v20 = *((unsigned __int8 *)v17 + --v18);
          v19 = v20 + 65599 * v19;
        }
        while ( v18 );
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorGH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::add<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
          &pmemAddr,
          &pmemAddr,
          &key,
          v19);
      }
      pTable = pmemAddr.pTable;
      ++v3;
      v4 += 32;
      if ( v3 >= v50.pData[1].Size )
        break;
      this = (Scaleform::GFx::AMP::MovieFunctionStats *)v50.pData;
    }
  }
  v21 = 0;
  v22 = 0;
  memset(&pheapAddr, 0, sizeof(pheapAddr));
  if ( pTable )
  {
    v23 = pTable + 1;
    do
    {
      if ( v23->EntryCount != -2 )
        break;
      ++v22;
      v23 += 6;
    }
    while ( v22 <= pTable->SizeMask );
    key.pFirst = (const unsigned __int64 *)&pmemAddr;
  }
  else
  {
    key.pFirst = 0;
  }
  while ( key.pFirst )
  {
    v24 = *(_DWORD *)key.pFirst;
    if ( !*(_DWORD *)key.pFirst || (signed int)v22 > *(_DWORD *)(v24 + 4) )
      break;
    v25 = *(_DWORD *)(v24 + 48 * v22 + 16);
    v26 = (_DWORD *)(48 * v22 + v24);
    v27 = v26[5];
    v59[0] = v25;
    v28 = v26[8];
    v59[1] = v27;
    v29 = v26[9];
    v59[2] = v28;
    v30 = v26[12];
    v59[3] = v29;
    v31 = v26[13];
    v32 = v26[10];
    v33 = v21 + 1;
    v59[6] = v30;
    v59[7] = v31;
    v59[4] = v32;
    if ( v21 + 1 >= v21 )
    {
      if ( v33 >= pheapAddr.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::AllocatorGH<Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &pheapAddr,
          &pheapAddr,
          v33 + (v33 >> 2));
    }
    else if ( v33 < pheapAddr.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::AllocatorGH<Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &pheapAddr,
        &pheapAddr,
        v21 + 1);
    }
    ++v21;
    v34 = v33;
    pheapAddr.Size = v21;
    if ( &pheapAddr.Data[v34] != (Scaleform::GFx::AMP::MovieFunctionStats::FuncStats *)32 )
      qmemcpy(&pheapAddr.Data[v34 - 1], v59, sizeof(pheapAddr.Data[v34 - 1]));
    v35 = *(_DWORD *)(*(_DWORD *)key.pFirst + 4);
    if ( (int)v22 <= (int)v35 && ++v22 <= v35 )
    {
      v36 = (_DWORD *)(48 * v22 + *(_DWORD *)key.pFirst + 8);
      do
      {
        if ( *v36 != -2 )
          break;
        ++v22;
        v36 += 12;
      }
      while ( v22 <= v35 );
    }
  }
  Scaleform::Alg::QuickSortSliced<Scaleform::Array<Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,2,Scaleform::ArrayDefaultPolicy>,bool (__cdecl *)(Scaleform::GFx::AMP::MovieFunctionStats::FuncStats const &,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats const &)>(
    (Scaleform::Array<Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,2,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
    0,
    v21,
    (bool (__cdecl *)(const Scaleform::GFx::AMP::MovieFunctionStats::FuncStats *, const Scaleform::GFx::AMP::MovieFunctionStats::FuncStats *))Scaleform::GFx::AMP::funcStatsLess);
  if ( v21 )
  {
    Data = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)v50.pData[1].Data;
    v55 = v21;
    v56 = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)v50.pData[1].Data;
    p_TimesCalled = &pheapAddr.Data->TimesCalled;
    do
    {
      Scaleform::String::String(&v54);
      Scaleform::String::String(&v50);
      v39 = Data->pTable;
      if ( Data->pTable )
      {
        v40 = 8;
        v41 = 5381;
        do
        {
          v42 = *((unsigned __int8 *)p_TimesCalled + v40 - 17);
          --v40;
          v41 = v42 + 65599 * v41;
        }
        while ( v40 );
        Data = v56;
        v43 = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexCore<unsigned __int64>(
                v56,
                (const unsigned __int64 *)p_TimesCalled - 2,
                v41 & v39->SizeMask);
        if ( v43 >= 0 )
        {
          v44 = Data->pTable;
          if ( Data->pTable )
          {
            if ( v43 <= (signed int)v44->SizeMask )
              Scaleform::String::operator=(&v50, (const Scaleform::String *)(v44[3 * v43 + 3].EntryCount + 8));
          }
        }
      }
      v = *((_QWORD *)p_TimesCalled + 1) / 0x3E8uLL;
      r.SinkData.pStr = &v54;
      key.pFirst = (const unsigned __int64 *)((v50.HeapTypeBits & 0xFFFFFFFC) + 8);
      r.Type = tStr;
      Scaleform::MsgFormat::MsgFormat(&v60, &r);
      Scaleform::MsgFormat::Parse(&v60, "{0}: {1} ms ({2} times)\n");
      Scaleform::MsgFormat::FormatD1<char const *>(&v60, (const char **)&key);
      Scaleform::MsgFormat::FormatD1<unsigned __int64>(&v60, &v);
      Scaleform::MsgFormat::FormatD1<unsigned int>(&v60, p_TimesCalled);
      Scaleform::MsgFormat::FinishFormatD(&v60);
      Scaleform::MsgFormat::~MsgFormat(&v60);
      Scaleform::Log::LogMessage(log, (const char *)&stru_7F9BE8.allocator, (v54.HeapTypeBits & 0xFFFFFFFC) + 8);
      v45 = (void *)(v50.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((v50.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v45);
      v46 = (void *)(v54.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((v54.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v46);
      p_TimesCalled += 8;
      --v55;
    }
    while ( v55 );
  }
  if ( pheapAddr.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pheapAddr.Data);
  v47 = pmemAddr.pTable;
  if ( pmemAddr.pTable )
  {
    v48 = 0;
    v49 = pmemAddr.pTable->SizeMask + 1;
    do
    {
      if ( v47[v48 + 1].EntryCount != -2 )
      {
        v47[v48 + 1].EntryCount = -2;
        v47 = pmemAddr.pTable;
      }
      v48 += 6;
      --v49;
    }
    while ( v49 );
    if ( v47 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v47);
  }
}
