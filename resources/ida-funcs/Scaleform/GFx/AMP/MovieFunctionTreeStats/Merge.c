void __thiscall Scaleform::GFx::AMP::MovieFunctionTreeStats::Merge(
        Scaleform::GFx::AMP::MovieFunctionTreeStats *this,
        const Scaleform::GFx::AMP::MovieFunctionTreeStats *other)
{
  const Scaleform::GFx::AMP::MovieFunctionTreeStats *v2; // ebx
  Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem> *Data; // ebp
  unsigned int Size; // esi
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem>,2,Scaleform::ArrayDefaultPolicy> *p_FunctionRoots; // edi
  unsigned int v6; // ebx
  unsigned int i; // esi
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *pTable; // ecx
  Scaleform::HashLH<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64>,2,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *p_FunctionInfo; // ebx
  unsigned int v10; // eax
  unsigned int SizeMask; // edx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v12; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v13; // edi
  signed int v14; // esi
  unsigned int EntryCount; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  _DWORD *v18; // ecx
  Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [esp+14h] [ebp-8h] BYREF

  v2 = other;
  Data = other->FunctionRoots.Data.Data;
  Size = other->FunctionRoots.Data.Size;
  p_FunctionRoots = &this->FunctionRoots;
  if ( Size )
  {
    v6 = this->FunctionRoots.Data.Size;
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->FunctionRoots,
      &this->FunctionRoots,
      v6 + Size);
    Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem>>::ConstructArray(
      &p_FunctionRoots->Data.Data[v6],
      Size,
      Data);
    v2 = other;
  }
  for ( i = 1; i < this->FunctionRoots.Data.Size; ++i )
    Scaleform::GFx::AMP::FuncTreeItem::ResetTreeIds(
      p_FunctionRoots->Data.Data[i].pObject,
      p_FunctionRoots->Data.Data[i - 1].pObject);
  pTable = v2->FunctionInfo.mHash.pTable;
  p_FunctionInfo = &v2->FunctionInfo;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v10 = 0;
    v12 = pTable + 1;
    do
    {
      if ( v12->EntryCount != -2 )
        break;
      ++v10;
      v12 += 3;
    }
    while ( v10 <= SizeMask );
    pTable = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *)p_FunctionInfo;
  }
  else
  {
    v10 = 0;
  }
  v13 = pTable;
  v14 = v10;
  while ( v13 )
  {
    EntryCount = v13->EntryCount;
    if ( !v13->EntryCount || v14 > *(_DWORD *)(EntryCount + 4) )
      break;
    v16 = EntryCount + 24 * v14;
    key.pSecond = (const Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes> *)(v16 + 24);
    key.pFirst = (const unsigned __int64 *)(v16 + 16);
    Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
      (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&this->FunctionInfo,
      &this->FunctionInfo,
      &key);
    v17 = *(_DWORD *)(v13->EntryCount + 4);
    if ( v14 <= (int)v17 && ++v14 <= v17 )
    {
      v18 = (_DWORD *)(v13->EntryCount + 24 * v14 + 8);
      do
      {
        if ( *v18 != -2 )
          break;
        ++v14;
        v18 += 6;
      }
      while ( v14 <= v17 );
    }
  }
}
