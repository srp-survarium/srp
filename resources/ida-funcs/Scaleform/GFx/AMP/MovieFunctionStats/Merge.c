void __thiscall Scaleform::GFx::AMP::MovieFunctionStats::Merge(
        Scaleform::GFx::AMP::MovieFunctionStats *this,
        const Scaleform::GFx::AMP::MovieFunctionStats *other)
{
  const Scaleform::GFx::AMP::MovieFunctionStats *v2; // esi
  int v3; // ebp
  Scaleform::ArrayDataBase<Scaleform::Render::ExternalFontWinAPI::GlyphType,Scaleform::AllocatorLH<Scaleform::Render::ExternalFontWinAPI::GlyphType,2>,Scaleform::ArrayDefaultPolicy> *p_FunctionTimings; // ebx
  unsigned int v5; // eax
  Scaleform::GFx::AMP::MovieFunctionStats::FuncStats *v6; // edx
  Scaleform::Render::ExternalFontWinAPI::GlyphType *Data; // ecx
  Scaleform::GFx::AMP::MovieFunctionStats::FuncStats *v8; // eax
  unsigned int v9; // edi
  int v10; // eax
  Scaleform::Render::ExternalFontWinAPI::GlyphType *p_x2; // eax
  Scaleform::GFx::AMP::MovieFunctionStats::FuncStats *v12; // ecx
  int TotalTime; // edx
  bool v14; // cf
  Scaleform::Render::ExternalFontWinAPI::GlyphType *v15; // ecx
  Scaleform::Render::ExternalFontWinAPI::GlyphType *v16; // edi
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *pTable; // ecx
  Scaleform::HashLH<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64>,2,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *p_FunctionInfo; // esi
  unsigned int v19; // eax
  unsigned int SizeMask; // edx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v21; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v22; // edi
  signed int v23; // esi
  unsigned int EntryCount; // eax
  unsigned int v25; // eax
  unsigned int v26; // eax
  _DWORD *v27; // ecx
  unsigned int Size; // [esp+Ch] [ebp-10h]
  Scaleform::GFx::AMP::MovieFunctionStats::FuncStats *v29; // [esp+Ch] [ebp-10h]
  Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [esp+10h] [ebp-Ch] BYREF
  Scaleform::GFx::AMP::MovieFunctionStats *v31; // [esp+18h] [ebp-4h]

  v2 = other;
  v3 = 0;
  v31 = this;
  key.pFirst = 0;
  if ( other->FunctionTimings.Data.Size )
  {
    p_FunctionTimings = (Scaleform::ArrayDataBase<Scaleform::Render::ExternalFontWinAPI::GlyphType,Scaleform::AllocatorLH<Scaleform::Render::ExternalFontWinAPI::GlyphType,2>,Scaleform::ArrayDefaultPolicy> *)&this->FunctionTimings;
    while ( 1 )
    {
      v5 = 0;
      Size = this->FunctionTimings.Data.Size;
      if ( !Size )
        break;
      v6 = &v2->FunctionTimings.Data.Data[v3];
      Data = p_FunctionTimings->Data;
      while ( Data->Code != LODWORD(v6->FunctionId)
           || LODWORD(Data->Advance) != HIDWORD(v6->FunctionId)
           || *((_DWORD *)&Data->Advance + 1) != LODWORD(v6->CallerId)
           || *((_DWORD *)&Data->Advance + 2) != HIDWORD(v6->CallerId) )
      {
        ++v5;
        ++Data;
        if ( v5 >= Size )
        {
          v2 = other;
          goto LABEL_12;
        }
      }
      v2 = other;
      v10 = v5;
      LODWORD(p_FunctionTimings->Data[v10].Bounds.x1) += other->FunctionTimings.Data.Data[v3].TimesCalled;
      p_x2 = (Scaleform::Render::ExternalFontWinAPI::GlyphType *)&p_FunctionTimings->Data[v10].Bounds.x2;
      v12 = other->FunctionTimings.Data.Data;
      TotalTime = v12[v3].TotalTime;
      v14 = __CFADD__(TotalTime, p_x2->Code);
      p_x2->Code += TotalTime;
      LODWORD(p_x2->Advance) += HIDWORD(v12[v3].TotalTime) + v14;
LABEL_21:
      ++v3;
      if ( ++key.pFirst >= (const unsigned __int64 *)v2->FunctionTimings.Data.Size )
        goto LABEL_22;
      this = v31;
    }
LABEL_12:
    v8 = &v2->FunctionTimings.Data.Data[v3];
    v9 = p_FunctionTimings->Size + 1;
    v29 = v8;
    if ( v9 >= p_FunctionTimings->Size )
    {
      if ( v9 < p_FunctionTimings->Policy.Capacity )
        goto LABEL_19;
      Scaleform::ArrayDataBase<Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::AllocatorLH<Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_FunctionTimings,
        p_FunctionTimings,
        v9 + (v9 >> 2));
    }
    else
    {
      if ( v9 >= p_FunctionTimings->Policy.Capacity >> 1 )
        goto LABEL_19;
      Scaleform::ArrayDataBase<Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::AllocatorLH<Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_FunctionTimings,
        p_FunctionTimings,
        v9);
    }
    v8 = v29;
LABEL_19:
    v15 = p_FunctionTimings->Data;
    p_FunctionTimings->Size = v9;
    v16 = &v15[v9 - 1];
    if ( v16 )
    {
      qmemcpy(v16, v8, sizeof(Scaleform::Render::ExternalFontWinAPI::GlyphType));
      v2 = other;
    }
    goto LABEL_21;
  }
LABEL_22:
  pTable = v2->FunctionInfo.mHash.pTable;
  p_FunctionInfo = &v2->FunctionInfo;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v19 = 0;
    v21 = pTable + 1;
    do
    {
      if ( v21->EntryCount != -2 )
        break;
      ++v19;
      v21 += 3;
    }
    while ( v19 <= SizeMask );
    pTable = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *)p_FunctionInfo;
  }
  else
  {
    v19 = 0;
  }
  v22 = pTable;
  v23 = v19;
  while ( v22 )
  {
    EntryCount = v22->EntryCount;
    if ( !v22->EntryCount || v23 > *(_DWORD *)(EntryCount + 4) )
      break;
    v25 = EntryCount + 24 * v23;
    key.pSecond = (const Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes> *)(v25 + 24);
    key.pFirst = (const unsigned __int64 *)(v25 + 16);
    Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
      (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v31->FunctionInfo,
      &v31->FunctionInfo,
      &key);
    v26 = *(_DWORD *)(v22->EntryCount + 4);
    if ( v23 <= (int)v26 && ++v23 <= v26 )
    {
      v27 = (_DWORD *)(v22->EntryCount + 24 * v23 + 8);
      do
      {
        if ( *v27 != -2 )
          break;
        ++v23;
        v27 += 6;
      }
      while ( v23 <= v26 );
    }
  }
}
