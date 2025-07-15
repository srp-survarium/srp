void __thiscall Scaleform::GFx::AMP::MovieFunctionStats::Write(
        Scaleform::GFx::AMP::MovieFunctionStats *this,
        Scaleform::File *str,
        unsigned int version)
{
  Scaleform::File *v3; // esi
  int (__thiscall *Write)(Scaleform::File *, const unsigned __int8 *, int); // edx
  unsigned int v6; // ebp
  int v7; // edi
  Scaleform::GFx::AMP::MovieFunctionStats::FuncStats *Data; // eax
  int FunctionId; // ecx
  int FunctionId_high; // edx
  Scaleform::File_vtbl *v11; // eax
  Scaleform::GFx::AMP::MovieFunctionStats::FuncStats *v12; // eax
  int CallerId; // ecx
  int CallerId_high; // edx
  Scaleform::File_vtbl *v15; // eax
  int (__thiscall *v16)(Scaleform::File *, const unsigned __int8 *, int); // edx
  Scaleform::GFx::AMP::MovieFunctionStats::FuncStats *v17; // eax
  unsigned int TotalTime; // ecx
  unsigned int TotalTime_high; // edx
  Scaleform::File_vtbl *v20; // eax
  Scaleform::File *pTable; // eax
  Scaleform::HashLH<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64>,2,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *p_FunctionInfo; // ebx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v23; // ecx
  Scaleform::HashLH<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64>,2,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *v24; // ebp
  unsigned int v25; // eax
  unsigned int SizeMask; // edx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v27; // ecx
  signed int v28; // ebx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v29; // eax
  int v30; // edi
  unsigned int EntryCount; // ecx
  unsigned int v32; // edx
  Scaleform::File_vtbl *v33; // eax
  int (__thiscall *v34)(Scaleform::File *, const unsigned __int8 *, int); // edx
  unsigned int v35; // eax
  int v36; // ecx
  int v37; // edx
  Scaleform::File_vtbl *v38; // eax
  Scaleform::File_vtbl *v39; // eax
  Scaleform::File_vtbl *v40; // eax
  unsigned int v41; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v42; // ecx
  _DWORD v43[2]; // [esp+38h] [ebp-18h] BYREF
  int v44; // [esp+40h] [ebp-10h] BYREF
  int v45; // [esp+44h] [ebp-Ch]
  unsigned int v46; // [esp+48h] [ebp-8h] BYREF
  unsigned int v47; // [esp+4Ch] [ebp-4h]

  v3 = str;
  Write = str->Write;
  v43[0] = this->FunctionTimings.Data.Size;
  Write(str, (const unsigned __int8 *)v43, 4);
  v6 = 0;
  if ( this->FunctionTimings.Data.Size )
  {
    v7 = 0;
    do
    {
      Data = this->FunctionTimings.Data.Data;
      FunctionId = Data[v7].FunctionId;
      FunctionId_high = HIDWORD(Data[v7].FunctionId);
      v11 = v3->__vftable;
      v43[0] = FunctionId;
      v43[1] = FunctionId_high;
      v11->Write(v3, (const unsigned __int8 *)v43, 8);
      v12 = this->FunctionTimings.Data.Data;
      CallerId = v12[v7].CallerId;
      CallerId_high = HIDWORD(v12[v7].CallerId);
      v15 = v3->__vftable;
      v44 = CallerId;
      v45 = CallerId_high;
      v15->Write(v3, (const unsigned __int8 *)&v44, 8);
      v16 = v3->Write;
      str = (Scaleform::File *)this->FunctionTimings.Data.Data[v7].TimesCalled;
      v16(v3, (const unsigned __int8 *)&str, 4);
      v17 = this->FunctionTimings.Data.Data;
      TotalTime = v17[v7].TotalTime;
      TotalTime_high = HIDWORD(v17[v7].TotalTime);
      v20 = v3->__vftable;
      v46 = TotalTime;
      v47 = TotalTime_high;
      v20->Write(v3, (const unsigned __int8 *)&v46, 8);
      ++v6;
      ++v7;
    }
    while ( v6 < this->FunctionTimings.Data.Size );
  }
  pTable = (Scaleform::File *)this->FunctionInfo.mHash.pTable;
  p_FunctionInfo = &this->FunctionInfo;
  if ( pTable )
    pTable = (Scaleform::File *)pTable->__vftable;
  str = pTable;
  v3->Write(v3, (const unsigned __int8 *)&str, 4);
  v23 = p_FunctionInfo->mHash.pTable;
  if ( p_FunctionInfo->mHash.pTable )
  {
    SizeMask = v23->SizeMask;
    v25 = 0;
    v27 = v23 + 1;
    do
    {
      if ( v27->EntryCount != -2 )
        break;
      ++v25;
      v27 += 3;
    }
    while ( v25 <= SizeMask );
    v24 = p_FunctionInfo;
  }
  else
  {
    v24 = 0;
    v25 = 0;
  }
  v28 = v25;
  while ( v24 )
  {
    v29 = v24->mHash.pTable;
    if ( !v24->mHash.pTable || v28 > (signed int)v29->SizeMask )
      break;
    v30 = 3 * v28;
    EntryCount = v29[3 * v28 + 2].EntryCount;
    v32 = v29[3 * v28 + 2].SizeMask;
    v33 = v3->__vftable;
    v46 = EntryCount;
    v47 = v32;
    v33->Write(v3, (const unsigned __int8 *)&v46, 8);
    Scaleform::GFx::AMP::writeString(v3, (Scaleform::String *)(v24->mHash.pTable[3 * v28 + 3].EntryCount + 8));
    v34 = v3->Write;
    str = *(Scaleform::File **)(v24->mHash.pTable[3 * v28 + 3].EntryCount + 12);
    v34(v3, (const unsigned __int8 *)&str, 4);
    if ( version >= 9 )
    {
      v35 = v24->mHash.pTable[v30 + 3].EntryCount;
      v36 = *(_DWORD *)(v35 + 16);
      v37 = *(_DWORD *)(v35 + 20);
      v38 = v3->__vftable;
      v44 = v36;
      v45 = v37;
      v38->Write(v3, (const unsigned __int8 *)&v44, 8);
      v39 = v3->__vftable;
      str = *(Scaleform::File **)(v24->mHash.pTable[v30 + 3].EntryCount + 24);
      v39->Write(v3, (const unsigned __int8 *)&str, 4);
      if ( version >= 0xD )
      {
        v40 = v3->__vftable;
        str = *(Scaleform::File **)(v24->mHash.pTable[v30 + 3].EntryCount + 28);
        v40->Write(v3, (const unsigned __int8 *)&str, 4);
      }
    }
    v41 = v24->mHash.pTable->SizeMask;
    if ( v28 <= (int)v41 && ++v28 <= v41 )
    {
      v42 = &v24->mHash.pTable[3 * v28 + 1];
      do
      {
        if ( v42->EntryCount != -2 )
          break;
        ++v28;
        v42 += 3;
      }
      while ( v28 <= v41 );
    }
  }
}
