void __userpurge Scaleform::GFx::AMP::MovieSourceLineStats::Write(
        Scaleform::GFx::AMP::MovieSourceLineStats *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        Scaleform::File *str,
        unsigned int version,
        int a6,
        unsigned int LineNumber)
{
  int (__thiscall *Write)(Scaleform::File *, const unsigned __int8 *, int); // edx
  unsigned int v9; // ebp
  int v10; // edi
  Scaleform::GFx::AMP::MovieSourceLineStats::SourceStats *Data; // eax
  unsigned int FileId; // ecx
  unsigned int FileId_high; // edx
  Scaleform::File_vtbl *v14; // eax
  int (__thiscall *v15)(Scaleform::File *, const unsigned __int8 *, int); // edx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *pTable; // eax
  Scaleform::HashLH<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64>,2,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *p_SourceFileInfo; // ebx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v18; // ecx
  Scaleform::HashLH<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64>,2,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *v19; // ebp
  unsigned int v20; // eax
  unsigned int SizeMask; // edx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v22; // ecx
  signed int v23; // edi
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v24; // eax
  unsigned int EntryCount; // ecx
  unsigned int v26; // edx
  Scaleform::File_vtbl *v27; // eax
  unsigned int v28; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v29; // ecx
  unsigned int v30; // [esp+28h] [ebp-8h] BYREF
  unsigned int v31; // [esp+2Ch] [ebp-4h]
  _UNKNOWN *TotalTime; // [esp+30h] [ebp+0h] BYREF

  if ( version >= 9 )
  {
    Write = str->Write;
    version = this->SourceLineTimings.Data.Size;
    ((void (__thiscall *)(Scaleform::File *, unsigned int *, int, int, int))Write)(str, &version, 4, a2, a3);
    v9 = 0;
    if ( this->SourceLineTimings.Data.Size )
    {
      v10 = 0;
      do
      {
        Data = this->SourceLineTimings.Data.Data;
        FileId = Data[v10].FileId;
        FileId_high = HIDWORD(Data[v10].FileId);
        v14 = str->__vftable;
        v30 = FileId;
        v31 = FileId_high;
        v14->Write(str, (const unsigned __int8 *)&v30, 8);
        v15 = str->Write;
        LineNumber = this->SourceLineTimings.Data.Data[v10].LineNumber;
        v15(str, (const unsigned __int8 *)&LineNumber, 4);
        TotalTime = (_UNKNOWN *)this->SourceLineTimings.Data.Data[v10].TotalTime;
        str->Write(str, (const unsigned __int8 *)&TotalTime, 8);
        ++v9;
        ++v10;
      }
      while ( v9 < this->SourceLineTimings.Data.Size );
    }
    pTable = this->SourceFileInfo.mHash.pTable;
    p_SourceFileInfo = &this->SourceFileInfo;
    if ( pTable )
      pTable = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *)pTable->EntryCount;
    LineNumber = (unsigned int)pTable;
    str->Write(str, (const unsigned __int8 *)&LineNumber, 4);
    v18 = p_SourceFileInfo->mHash.pTable;
    if ( p_SourceFileInfo->mHash.pTable )
    {
      SizeMask = v18->SizeMask;
      v20 = 0;
      v22 = v18 + 1;
      do
      {
        if ( v22->EntryCount != -2 )
          break;
        ++v20;
        v22 += 3;
      }
      while ( v20 <= SizeMask );
      v19 = p_SourceFileInfo;
    }
    else
    {
      v19 = 0;
      v20 = 0;
    }
    v23 = v20;
    while ( v19 )
    {
      v24 = v19->mHash.pTable;
      if ( !v19->mHash.pTable || v23 > (signed int)v24->SizeMask )
        break;
      EntryCount = v24[3 * v23 + 2].EntryCount;
      v26 = v24[3 * v23 + 2].SizeMask;
      v27 = str->__vftable;
      v30 = EntryCount;
      v31 = v26;
      v27->Write(str, (const unsigned __int8 *)&v30, 8);
      Scaleform::GFx::AMP::writeString(str, (Scaleform::String *)&v19->mHash.pTable[3 * v23 + 3]);
      v28 = v19->mHash.pTable->SizeMask;
      if ( v23 <= (int)v28 && ++v23 <= v28 )
      {
        v29 = &v19->mHash.pTable[3 * v23 + 1];
        do
        {
          if ( v29->EntryCount != -2 )
            break;
          ++v23;
          v29 += 3;
        }
        while ( v23 <= v28 );
      }
    }
  }
}
