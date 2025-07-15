void __thiscall Scaleform::GFx::AMP::MovieFunctionTreeStats::Write(
        Scaleform::GFx::AMP::MovieFunctionTreeStats *this,
        Scaleform::File *str,
        unsigned int version)
{
  Scaleform::File *v3; // esi
  int (__thiscall *Write)(Scaleform::File *, const unsigned __int8 *, int); // edx
  unsigned int v6; // ebx
  unsigned int v7; // ebp
  Scaleform::File *pTable; // eax
  Scaleform::HashLH<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64>,2,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *p_FunctionInfo; // edi
  int (__thiscall *v10)(Scaleform::File *, const unsigned __int8 *, int); // edx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v11; // ecx
  Scaleform::HashLH<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64>,2,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *v12; // ebp
  unsigned int v13; // eax
  unsigned int SizeMask; // edx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v15; // ecx
  signed int v16; // ebx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v17; // eax
  unsigned int EntryCount; // ecx
  unsigned int v19; // edx
  Scaleform::File_vtbl *v20; // eax
  int (__thiscall *v21)(Scaleform::File *, const unsigned __int8 *, int); // edx
  unsigned int v22; // eax
  int v23; // ecx
  int v24; // edx
  Scaleform::File_vtbl *v25; // eax
  Scaleform::File_vtbl *v26; // eax
  Scaleform::File_vtbl *v27; // eax
  unsigned int v28; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v29; // ecx
  _DWORD v30[2]; // [esp+1Ch] [ebp-10h] BYREF
  _DWORD v31[2]; // [esp+24h] [ebp-8h] BYREF

  v3 = str;
  Scaleform::GFx::AMP::writeString(str, &this->ViewName);
  Write = v3->Write;
  str = (Scaleform::File *)this->FunctionRoots.Data.Size;
  Write(v3, (const unsigned __int8 *)&str, 4);
  v6 = 0;
  if ( this->FunctionRoots.Data.Size )
  {
    v7 = version;
    do
      Scaleform::GFx::AMP::FuncTreeItem::Write(this->FunctionRoots.Data.Data[v6++].pObject, v3, v7);
    while ( v6 < this->FunctionRoots.Data.Size );
  }
  pTable = (Scaleform::File *)this->FunctionInfo.mHash.pTable;
  p_FunctionInfo = &this->FunctionInfo;
  if ( pTable )
    pTable = (Scaleform::File *)pTable->__vftable;
  v10 = v3->Write;
  str = pTable;
  v10(v3, (const unsigned __int8 *)&str, 4);
  v11 = p_FunctionInfo->mHash.pTable;
  if ( p_FunctionInfo->mHash.pTable )
  {
    SizeMask = v11->SizeMask;
    v13 = 0;
    v15 = v11 + 1;
    do
    {
      if ( v15->EntryCount != -2 )
        break;
      ++v13;
      v15 += 3;
    }
    while ( v13 <= SizeMask );
    v12 = p_FunctionInfo;
  }
  else
  {
    v12 = 0;
    v13 = 0;
  }
  v16 = v13;
  while ( v12 )
  {
    v17 = v12->mHash.pTable;
    if ( !v12->mHash.pTable || v16 > (signed int)v17->SizeMask )
      break;
    EntryCount = v17[3 * v16 + 2].EntryCount;
    v19 = v17[3 * v16 + 2].SizeMask;
    v20 = v3->__vftable;
    v30[0] = EntryCount;
    v30[1] = v19;
    v20->Write(v3, (const unsigned __int8 *)v30, 8);
    Scaleform::GFx::AMP::writeString(v3, (Scaleform::String *)(v12->mHash.pTable[3 * v16 + 3].EntryCount + 8));
    v21 = v3->Write;
    str = *(Scaleform::File **)(v12->mHash.pTable[3 * v16 + 3].EntryCount + 12);
    v21(v3, (const unsigned __int8 *)&str, 4);
    v22 = v12->mHash.pTable[3 * v16 + 3].EntryCount;
    v23 = *(_DWORD *)(v22 + 16);
    v24 = *(_DWORD *)(v22 + 20);
    v25 = v3->__vftable;
    v31[0] = v23;
    v31[1] = v24;
    v25->Write(v3, (const unsigned __int8 *)v31, 8);
    v26 = v3->__vftable;
    str = *(Scaleform::File **)(v12->mHash.pTable[3 * v16 + 3].EntryCount + 24);
    v26->Write(v3, (const unsigned __int8 *)&str, 4);
    v27 = v3->__vftable;
    str = *(Scaleform::File **)(v12->mHash.pTable[3 * v16 + 3].EntryCount + 28);
    v27->Write(v3, (const unsigned __int8 *)&str, 4);
    v28 = v12->mHash.pTable->SizeMask;
    if ( v16 <= (int)v28 && ++v16 <= v28 )
    {
      v29 = &v12->mHash.pTable[3 * v16 + 1];
      do
      {
        if ( v29->EntryCount != -2 )
          break;
        ++v16;
        v29 += 3;
      }
      while ( v16 <= v28 );
    }
  }
}
