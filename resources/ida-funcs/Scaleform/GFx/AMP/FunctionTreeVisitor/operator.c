void __thiscall Scaleform::GFx::AMP::FunctionTreeVisitor::operator()(
        Scaleform::GFx::AMP::FunctionTreeVisitor *this,
        const Scaleform::GFx::AMP::FuncTreeItem *root)
{
  signed int Index; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *pTable; // ecx
  int v5; // eax
  unsigned __int64 v6; // kr00_8
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v7; // eax
  bool v8; // cf
  int FunctionId_high; // eax
  unsigned int EndTime; // ecx
  unsigned int v11; // ecx
  int v12; // edx
  Scaleform::GFx::AMP::MovieFunctionStats::FuncStats value; // [esp+8h] [ebp-20h] BYREF

  if ( this->IncludeActionScript || HIDWORD(root->FunctionId) == 1 )
  {
    Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorGH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
              &this->FuncMap.mHash,
              &root->FunctionId);
    if ( Index >= 0 && (pTable = this->FuncMap.mHash.pTable) != 0 && Index <= (signed int)pTable->SizeMask )
    {
      v5 = 6 * Index;
      ++pTable[v5 + 5].EntryCount;
      v7 = &this->FuncMap.mHash.pTable[v5 + 6];
      v6 = root->EndTime - root->BeginTime;
      v8 = __CFADD__((_DWORD)v6, v7->EntryCount);
      v7->EntryCount += v6;
      v7->SizeMask += HIDWORD(v6) + v8;
    }
    else
    {
      FunctionId_high = HIDWORD(root->FunctionId);
      EndTime = root->EndTime;
      v8 = EndTime < LODWORD(root->BeginTime);
      v11 = EndTime - LODWORD(root->BeginTime);
      LODWORD(value.FunctionId) = root->FunctionId;
      v12 = HIDWORD(root->EndTime) - (v8 + HIDWORD(root->BeginTime));
      HIDWORD(value.FunctionId) = FunctionId_high;
      value.TotalTime = __PAIR64__(v12, v11);
      value.CallerId = 0;
      value.TimesCalled = 1;
      Scaleform::Hash<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64>,Scaleform::AllocatorGH<unsigned __int64,2>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorGH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>>::Add(
        &this->FuncMap,
        &root->FunctionId,
        &value);
    }
  }
}
