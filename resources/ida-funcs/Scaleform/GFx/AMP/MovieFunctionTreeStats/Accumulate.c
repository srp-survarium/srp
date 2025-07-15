Scaleform::GFx::AMP::MovieFunctionStats *__thiscall Scaleform::GFx::AMP::MovieFunctionTreeStats::Accumulate(
        Scaleform::GFx::AMP::MovieFunctionTreeStats *this,
        bool includeActionscipt)
{
  _DWORD *v3; // eax
  unsigned int v4; // ebp
  Scaleform::GFx::AMP::FuncTreeItem *pObject; // esi
  unsigned int i; // edi
  Scaleform::GFx::AMP::FunctionTreeVisitor *v7; // edx
  unsigned int v8; // ebx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v9; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *pTable; // eax
  unsigned int v11; // edi
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v12; // ebp
  int v13; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v14; // edi
  unsigned int SizeMask; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v16; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v17; // edx
  int v18; // eax
  unsigned int v19; // ecx
  _DWORD *v21; // [esp+10h] [ebp-18h]
  int v22; // [esp+14h] [ebp-14h] BYREF
  Scaleform::GFx::AMP::FunctionTreeVisitor visitor; // [esp+18h] [ebp-10h] BYREF
  Scaleform::GFx::AMP::FunctionTreeVisitor *p_visitor; // [esp+20h] [ebp-8h]

  v22 = 578;
  v3 = Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 24, &v22);
  v4 = 0;
  if ( v3 )
  {
    *v3 = &Scaleform::RefCountImplCore::`vftable';
    v3[1] = 1;
    *v3 = &Scaleform::GFx::AMP::MovieFunctionStats::`vftable';
    v3[2] = 0;
    v3[3] = 0;
    v3[4] = 0;
    v3[5] = 0;
    v21 = v3;
  }
  else
  {
    v21 = 0;
  }
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Assign(
    (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)v21
  + 5,
    v21 + 5,
    &this->FunctionInfo.mHash);
  visitor.FuncMap.mHash.pTable = 0;
  visitor.IncludeActionScript = includeActionscipt;
  if ( !this->FunctionRoots.Data.Size )
    goto LABEL_9;
  do
  {
    pObject = this->FunctionRoots.Data.Data[v4].pObject;
    Scaleform::GFx::AMP::FunctionTreeVisitor::operator()(&visitor, pObject);
    for ( i = 0; i < pObject->Children.Data.Size; ++i )
      Scaleform::GFx::AMP::FuncTreeItem::Visit<Scaleform::GFx::AMP::FunctionTreeVisitor>(
        pObject->Children.Data.Data[i].pObject,
        &visitor);
    ++v4;
  }
  while ( v4 < this->FunctionRoots.Data.Size );
  if ( visitor.FuncMap.mHash.pTable )
  {
    v8 = 0;
    v9 = visitor.FuncMap.mHash.pTable + 1;
    do
    {
      if ( v9->EntryCount != -2 )
        break;
      ++v8;
      v9 += 6;
    }
    while ( v8 <= visitor.FuncMap.mHash.pTable->SizeMask );
    p_visitor = &visitor;
    v7 = &visitor;
  }
  else
  {
LABEL_9:
    v7 = 0;
    p_visitor = 0;
    v8 = 0;
  }
  while ( v7 )
  {
    pTable = v7->FuncMap.mHash.pTable;
    if ( !v7->FuncMap.mHash.pTable || (signed int)v8 > (signed int)pTable->SizeMask )
      break;
    v11 = v21[3] + 1;
    v12 = &pTable[6 * v8 + 3];
    if ( v11 >= v21[3] )
    {
      if ( v11 < v21[4] )
        goto LABEL_23;
      Scaleform::ArrayDataBase<Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::AllocatorLH<Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Render::ExternalFontWinAPI::GlyphType,Scaleform::AllocatorLH<Scaleform::Render::ExternalFontWinAPI::GlyphType,2>,Scaleform::ArrayDefaultPolicy> *)(v21 + 2),
        v21 + 2,
        v11 + (v11 >> 2));
    }
    else
    {
      if ( v11 >= v21[4] >> 1 )
        goto LABEL_23;
      Scaleform::ArrayDataBase<Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::AllocatorLH<Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Render::ExternalFontWinAPI::GlyphType,Scaleform::AllocatorLH<Scaleform::Render::ExternalFontWinAPI::GlyphType,2>,Scaleform::ArrayDefaultPolicy> *)(v21 + 2),
        v21 + 2,
        v21[3] + 1);
    }
    v7 = p_visitor;
LABEL_23:
    v13 = v21[2];
    v21[3] = v11;
    v14 = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *)(32 * v11 + v13 - 32);
    if ( v14 )
      qmemcpy(v14, v12, 0x20u);
    SizeMask = v7->FuncMap.mHash.pTable->SizeMask;
    if ( (int)v8 <= (int)SizeMask && ++v8 <= SizeMask )
    {
      v16 = &v7->FuncMap.mHash.pTable[6 * v8 + 1];
      do
      {
        if ( v16->EntryCount != -2 )
          break;
        ++v8;
        v16 += 6;
      }
      while ( v8 <= SizeMask );
    }
  }
  v17 = visitor.FuncMap.mHash.pTable;
  if ( visitor.FuncMap.mHash.pTable )
  {
    v18 = 0;
    v19 = visitor.FuncMap.mHash.pTable->SizeMask + 1;
    do
    {
      if ( v17[v18 + 1].EntryCount != -2 )
      {
        v17[v18 + 1].EntryCount = -2;
        v17 = visitor.FuncMap.mHash.pTable;
      }
      v18 += 6;
      --v19;
    }
    while ( v19 );
    if ( v17 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v17);
  }
  return (Scaleform::GFx::AMP::MovieFunctionStats *)v21;
}
