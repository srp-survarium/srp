void __usercall Scaleform::GFx::AddSearchInfo_4(
        Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *psearchInfo@<eax>,
        const char *pfontname,
        unsigned int flags,
        bool fontlib_installed,
        const Scaleform::GFx::MovieDefImpl::SearchInfo *resSearchInfo)
{
  const Scaleform::GFx::MovieDefImpl::SearchInfo *v6; // ebx
  Scaleform::GFx::MovieDefImpl::SearchInfo::SearchStatus Status; // eax
  Scaleform::String::DataDesc *v8; // ecx
  Scaleform::String::DataDesc *v9; // ecx
  unsigned int v10; // esi
  Scaleform::String::DataDesc *v11; // ecx
  Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor> >::TableType *pTable; // eax
  const Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor> > *pHash; // ebx
  int Index; // esi
  const Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::ConstIterator *v15; // eax
  Scaleform::String *v16; // eax
  Scaleform::String *v17; // eax
  Scaleform::String *v18; // eax
  Scaleform::String::DataDesc *v19; // eax
  bool v20; // zf
  Scaleform::String::DataDesc *v21; // ecx
  const char *v22; // [esp-Ch] [ebp-43Ch]
  const Scaleform::String *v23; // [esp-Ch] [ebp-43Ch]
  const char **p_tmp; // [esp-4h] [ebp-434h]
  Scaleform::String tmp; // [esp+Ch] [ebp-424h] BYREF
  Scaleform::MsgFormat::Sink result; // [esp+10h] [ebp-420h] BYREF
  Scaleform::String v27; // [esp+1Ch] [ebp-414h] BYREF
  Scaleform::String v28; // [esp+20h] [ebp-410h] BYREF
  Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor> >::ConstIterator it; // [esp+24h] [ebp-40Ch] BYREF
  Scaleform::String v30; // [esp+2Ch] [ebp-404h] BYREF
  char buff[1024]; // [esp+30h] [ebp-400h] BYREF

  if ( psearchInfo )
  {
    v6 = resSearchInfo;
    Status = resSearchInfo->Status;
    if ( resSearchInfo->Status == FoundInResources )
    {
      tmp.pData = (Scaleform::String::DataDesc *)Scaleform::GFx::FontFlagsToString(flags);
      result.SinkData.pStr = (Scaleform::String *)buff;
      result.Type = tDataPtr;
      result.SinkData.DataPtr.Size = 1024;
      Scaleform::Format<char const *,char const *>(
        &result,
        "Movie resource: \"{0}\" {1} found.",
        &pfontname,
        (const char **)&tmp);
      Scaleform::GFx::AddSearchInfo(psearchInfo, (Scaleform::String::DataDesc *)buff, buff);
      return;
    }
    if ( Status == FoundInResourcesNeedFaux )
    {
      tmp.pData = (Scaleform::String::DataDesc *)Scaleform::GFx::FontFlagsToString(flags);
      p_tmp = (const char **)&tmp;
      v22 = "Movie resource: \"{0}\" {1} found, requires faux";
LABEL_6:
      result.SinkData.DataPtr.Size = 1024;
      result.Type = tDataPtr;
LABEL_7:
      result.SinkData.pStr = (Scaleform::String *)buff;
      Scaleform::Format<char const *,char const *>(&result, v22, &pfontname, p_tmp);
      Scaleform::GFx::AddSearchInfo(psearchInfo, v8, buff);
      return;
    }
    if ( Status == FoundInResourcesNoGlyphs )
    {
      tmp.pData = (Scaleform::String::DataDesc *)Scaleform::GFx::FontFlagsToString(flags);
      result.SinkData.pStr = (Scaleform::String *)buff;
      result.Type = tDataPtr;
      result.SinkData.DataPtr.Size = 1024;
      Scaleform::Format<char const *,char const *>(
        &result,
        "Movie resource: \"{0}\" {1} ref found, requires FontLib/Map/Provider.",
        &pfontname,
        (const char **)&tmp);
      Scaleform::GFx::AddSearchInfo(psearchInfo, v9, buff);
      return;
    }
    v10 = flags;
    tmp.pData = (Scaleform::String::DataDesc *)Scaleform::GFx::FontFlagsToString(flags);
    result.SinkData.pStr = (Scaleform::String *)buff;
    result.Type = tDataPtr;
    result.SinkData.DataPtr.Size = 1024;
    Scaleform::Format<char const *,char const *>(
      &result,
      "Movie resource: \"{0}\" {1} not found.",
      &pfontname,
      (const char **)&tmp);
    Scaleform::GFx::AddSearchInfo(psearchInfo, (Scaleform::String::DataDesc *)buff, buff);
    if ( v6->Status == FoundInImports )
      goto LABEL_28;
    if ( v6->Status == FoundInImportsFontLib )
    {
      if ( fontlib_installed )
      {
        tmp.pData = (Scaleform::String::DataDesc *)Scaleform::GFx::FontFlagsToString(v10);
        p_tmp = (const char **)&tmp;
        v22 = "Imports       : \"{0}\" {1} import delegates to font library.";
        goto LABEL_6;
      }
LABEL_28:
      v27.pData = (Scaleform::String::DataDesc *)Scaleform::GFx::FontFlagsToString(v10);
      result.SinkData.pStr = (Scaleform::String *)buff;
      result.Type = tDataPtr;
      result.SinkData.DataPtr.Size = 1024;
      Scaleform::Format<char const *,char const *,Scaleform::String>(
        &result,
        "Imports       : \"{0}\" {1} found in \"{2}\".",
        &pfontname,
        (const char **)&v27,
        (const Scaleform::StringLH *)&v6->ImportFoundUrl);
      Scaleform::GFx::AddSearchInfo(psearchInfo, (Scaleform::String::DataDesc *)buff, buff);
      return;
    }
    tmp.pData = (Scaleform::String::DataDesc *)Scaleform::GFx::FontFlagsToString(v10);
    result.SinkData.pStr = (Scaleform::String *)buff;
    result.Type = tDataPtr;
    result.SinkData.DataPtr.Size = 1024;
    Scaleform::Format<char const *,char const *>(
      &result,
      "Imports       : \"{0}\" {1} not found.",
      &pfontname,
      (const char **)&tmp);
    Scaleform::GFx::AddSearchInfo(psearchInfo, v11, buff);
    v28.pData = (Scaleform::String::DataDesc *)&v6->ImportSearchUrls;
    pTable = v6->ImportSearchUrls.pTable;
    if ( pTable && pTable->EntryCount )
    {
      Scaleform::String::String(&tmp);
      Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor>>::Begin(
        (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> > *)v28.pData,
        (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> >::ConstIterator *)&it);
      while ( 1 )
      {
        pHash = it.pHash;
        if ( !it.pHash || !it.pHash->pTable )
          break;
        Index = it.Index;
        if ( it.Index > (signed int)it.pHash->pTable->SizeMask )
        {
          v10 = flags;
          break;
        }
        v15 = (const Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::ConstIterator *)Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor>>::Begin((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> > *)&resSearchInfo->ImportSearchUrls, (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> >::ConstIterator *)&result);
        if ( !Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor>>::ConstIterator::operator==(
                (Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::ConstIterator *)&it,
                v15) )
          Scaleform::String::AppendString(&tmp, (char *)&stru_95AF78.m_key_bindings[32], 0xFFFFFFFF);
        v23 = (const Scaleform::String *)&pHash->pTable[2] + 3 * Index;
        Scaleform::String::String(&v27, "\"");
        v17 = Scaleform::String::operator+(v16, &v30, v23);
        v18 = Scaleform::String::operator+(v17, &v28, "\"");
        Scaleform::String::operator+=(&tmp, v18);
        Scaleform::String::~String(&v28);
        Scaleform::String::~String(&v30);
        Scaleform::String::~String(&v27);
        Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor>>::ConstIterator::operator++(&it);
        v10 = flags;
      }
      result.Type = tDataPtr;
      result.SinkData.pStr = (Scaleform::String *)buff;
      result.SinkData.DataPtr.Size = 1024;
      Scaleform::Format<Scaleform::String>(&result, "              : {0}.", (const Scaleform::StringLH *)&tmp);
      Scaleform::GFx::AddSearchInfo(psearchInfo, (Scaleform::String::DataDesc *)buff, buff);
      Scaleform::String::~String(&tmp);
      v6 = resSearchInfo;
    }
    v19 = (Scaleform::String::DataDesc *)Scaleform::GFx::FontFlagsToString(v10);
    v20 = v6->Status == FoundInExports;
    v27.pData = v19;
    result.Type = tDataPtr;
    result.SinkData.DataPtr.Size = 1024;
    if ( v20 )
    {
      p_tmp = (const char **)&v27;
      v22 = "Exported      : \"{0}\" {1} found.";
      goto LABEL_7;
    }
    result.SinkData.pStr = (Scaleform::String *)buff;
    Scaleform::Format<char const *,char const *>(
      &result,
      "Exported      : \"{0}\" {1} not found.",
      &pfontname,
      (const char **)&v27);
    Scaleform::GFx::AddSearchInfo(psearchInfo, v21, buff);
  }
}
