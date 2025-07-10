Scaleform::GFx::FontResource *__thiscall Scaleform::GFx::MovieDefImpl::GetFontResource(
        Scaleform::GFx::MovieDefImpl *this,
        const char *pfontName,
        unsigned int styleFlags,
        Scaleform::GFx::MovieDefImpl::SearchInfo *psearchInfo)
{
  Scaleform::GFx::MovieDataDef *pObject; // edx
  Scaleform::GFx::FontDataUseNode *volatile Value; // edi
  _DWORD *v6; // ecx
  const char *v7; // eax
  unsigned int BindIndex; // eax
  Scaleform::GFx::ResourceBinding *p_ResourceBinding; // ecx
  Scaleform::GFx::ResourceBindData *v10; // ebp
  Scaleform::GFx::Resource *v11; // eax
  Scaleform::GFx::ImportData *v12; // esi
  Scaleform::GFx::Resource *v13; // eax
  Scaleform::GFx::Resource *v14; // esi
  Scaleform::GFx::Resource *v16; // edi
  Scaleform::GFx::Resource_vtbl *v17; // ecx
  bool v18; // zf
  Scaleform::String::DataDesc *v19; // eax
  const Scaleform::StringLH *p_SourceUrl; // esi
  Scaleform::HashSet<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor> > *p_ImportSearchUrls; // edi
  unsigned int v22; // eax
  Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor> >::TableType *pTable; // ebp
  unsigned int v24; // ebx
  int v25; // eax
  Scaleform::GFx::MovieDataDef::LoadTaskData *v26; // ecx
  Scaleform::GFx::ResourceBinding *v27; // ecx
  Scaleform::GFx::Resource *pResource; // ebx
  _DWORD **v29; // edi
  volatile bool Frozen; // dl
  Scaleform::GFx::ResourceBindData *v31; // edi
  Scaleform::GFx::Resource *v32; // ecx
  const char *v33; // eax
  Scaleform::String::DataDesc *v34; // ecx
  const Scaleform::String *v35; // esi
  Scaleform::GFx::MovieDataDef::LoadTaskData *v36; // eax
  _RTL_CRITICAL_SECTION *p_cs; // ebp
  Scaleform::GFx::MovieDefImpl::BindTaskData *v38; // eax
  int v39; // edi
  Scaleform::GFx::MovieDefImpl *v40; // ecx
  int v41; // esi
  Scaleform::GFx::ResourceId v42; // [esp-4h] [ebp-40h]
  Scaleform::GFx::MovieDefImpl *v43; // [esp+10h] [ebp-2Ch]
  int v44; // [esp+14h] [ebp-28h]
  Scaleform::GFx::ImportData *pimport; // [esp+18h] [ebp-24h]
  Scaleform::GFx::MovieDataDef *pdataDef; // [esp+1Ch] [ebp-20h]
  unsigned int j; // [esp+20h] [ebp-1Ch]
  Scaleform::GFx::ResourceHandle rh; // [esp+24h] [ebp-18h] BYREF
  Scaleform::GFx::ResourceBindData rbd; // [esp+2Ch] [ebp-10h] BYREF
  Scaleform::GFx::ResourceBindData pdata; // [esp+34h] [ebp-8h] BYREF

  pObject = this->pBindData.pObject->pDataDef.pObject;
  Value = pObject->pData.pObject->BindData.pFonts.Value;
  v43 = this;
  pdataDef = pObject;
  if ( Value )
  {
    do
    {
      v6 = &Value->pFontData.pObject->__vftable;
      if ( ((styleFlags & 0x10 | ((styleFlags & 0x300) != 0 ? 0x300 : 0) | 3) & v6[5]) == (styleFlags & 0x313) )
      {
        v7 = (const char *)(*(int (__thiscall **)(_DWORD *))(*v6 + 4))(v6);
        if ( !Scaleform::String::CompareNoCase(v7, pfontName) )
        {
          BindIndex = Value->BindIndex;
          p_ResourceBinding = &v43->pBindData.pObject->ResourceBinding;
          rbd.pResource.pObject = 0;
          rbd.pBinding = 0;
          if ( p_ResourceBinding->Frozen && BindIndex < p_ResourceBinding->ResourceCount )
          {
            v10 = &p_ResourceBinding->pResources[BindIndex];
            if ( v10->pResource.pObject )
            {
              Scaleform::RefCountImpl::AddRef(v10->pResource.pObject);
              if ( rbd.pResource.pObject )
                Scaleform::GFx::Resource::Release(rbd.pResource.pObject);
            }
            v11 = v10->pResource.pObject;
            rbd = *v10;
          }
          else
          {
            Scaleform::GFx::ResourceBinding::GetResourceData_Locked(p_ResourceBinding, &rbd, BindIndex);
            v11 = rbd.pResource.pObject;
          }
          if ( v11 )
          {
            v16 = v11;
            if ( psearchInfo )
            {
              v17 = v11[1].__vftable;
              if ( ((int)v17[1].GetKey & 0x40) != 0 )
              {
                psearchInfo->Status = FoundInResourcesNoGlyphs;
              }
              else if ( (styleFlags & 3) != 0
                     && (v18 = (*((unsigned __int8 (__thiscall **)(Scaleform::GFx::Resource_vtbl *))v17->~Scaleform::GFx::Resource
                                + 19))(v17) == 0,
                         v11 = rbd.pResource.pObject,
                         v18) )
              {
                psearchInfo->Status = FoundInResourcesNeedFaux;
              }
              else
              {
                psearchInfo->Status = FoundInResources;
              }
            }
            if ( v11 )
              Scaleform::GFx::Resource::Release(v11);
            return (Scaleform::GFx::FontResource *)v16;
          }
        }
      }
      Value = Value->pNext.Value;
    }
    while ( Value );
    pObject = pdataDef;
    this = v43;
  }
  v12 = pObject->pData.pObject->BindData.pImports.Value;
  pimport = v12;
  if ( !v12 )
    goto LABEL_15;
  while ( 1 )
  {
    j = 0;
    if ( v12->Imports.Data.Size )
    {
      v44 = 0;
      do
      {
        if ( psearchInfo )
        {
          v19 = v12->SourceUrl.pData;
          p_SourceUrl = &v12->SourceUrl;
          p_ImportSearchUrls = &psearchInfo->ImportSearchUrls;
          v22 = Scaleform::String::BernsteinHashFunctionCIS(
                  (char *)(((unsigned int)v19 & 0xFFFFFFFC) + 8),
                  *(_DWORD *)((unsigned int)v19 & 0xFFFFFFFC) & 0x7FFFFFFF,
                  0x1505u);
          pTable = psearchInfo->ImportSearchUrls.pTable;
          v24 = v22;
          if ( pTable
            && (v25 = Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor>>::findIndexCore<Scaleform::StringLH>(
                        p_ImportSearchUrls,
                        p_SourceUrl,
                        v22 & pTable->SizeMask),
                v25 >= 0) )
          {
            Scaleform::String::operator=((Scaleform::String *)&pTable[2] + 3 * v25, p_SourceUrl);
          }
          else
          {
            Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor>>::add<Scaleform::StringLH>(
              p_ImportSearchUrls,
              p_ImportSearchUrls,
              p_SourceUrl,
              v24);
          }
          v12 = pimport;
        }
        v42.Id = v12->Imports.Data.Data[v44].CharacterId;
        v26 = pdataDef->pData.pObject;
        rh.HType = RH_Pointer;
        rh.BindIndex = 0;
        if ( !Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
                v26,
                (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::TableType *)&rh,
                v42) )
        {
          pResource = rh.pResource;
          goto LABEL_58;
        }
        v27 = &v43->pBindData.pObject->ResourceBinding;
        if ( rh.HType == RH_Pointer )
        {
          pResource = rh.pResource;
          v29 = (_DWORD **)rh.BindIndex;
          goto LABEL_53;
        }
        Frozen = v43->pBindData.pObject->ResourceBinding.Frozen;
        pdata.pResource.pObject = 0;
        pdata.pBinding = 0;
        if ( Frozen )
        {
          pResource = rh.pResource;
          if ( rh.BindIndex < v27->ResourceCount )
          {
            pResource = rh.pResource;
            v31 = &v27->pResources[rh.BindIndex];
            if ( v31->pResource.pObject )
            {
              Scaleform::RefCountImpl::AddRef(v31->pResource.pObject);
              if ( pdata.pResource.pObject )
                Scaleform::GFx::Resource::Release(pdata.pResource.pObject);
            }
            v32 = v31->pResource.pObject;
            pdata = *v31;
            goto LABEL_51;
          }
        }
        else
        {
          pResource = rh.pResource;
        }
        Scaleform::GFx::ResourceBinding::GetResourceData_Locked(v27, &pdata, (unsigned int)pResource);
        v32 = pdata.pResource.pObject;
LABEL_51:
        v29 = (_DWORD **)v32;
        if ( v32 )
          Scaleform::GFx::Resource::Release(v32);
LABEL_53:
        if ( v29 )
        {
          if ( (((int (__thiscall *)(_DWORD **))(*v29)[2])(v29) & 0xFF00) == 0x200
            && (v29[3][5] & (styleFlags & 0x10 | ((styleFlags & 0x300) != 0 ? 0x300 : 0) | 3)) == (styleFlags & 0x313) )
          {
            if ( !Scaleform::String::CompareNoCase(
                    (const char *)((v12->Imports.Data.Data[v44].SymbolName.HeapTypeBits & 0xFFFFFFFC) + 8),
                    pfontName)
              || (v33 = (const char *)(*(int (__thiscall **)(_DWORD *))(*v29[3] + 4))(v29[3]),
                  !Scaleform::String::CompareNoCase(v33, pfontName)) )
            {
              if ( psearchInfo )
              {
                v34 = v12->SourceUrl.pData;
                v35 = &v12->SourceUrl;
                if ( (*(_DWORD *)((unsigned int)v34 & 0xFFFFFFFC) & 0x7FFFFFFFu) < 0xE
                  || Scaleform::String::CompareNoCase(
                       (const char *)((v35->HeapTypeBits & 0xFFFFFFFC)
                                    + (*(_DWORD *)(v35->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF)
                                    - 6),
                       "gfxfontlib.swf") )
                {
                  psearchInfo->Status = FoundInImports;
                }
                else
                {
                  psearchInfo->Status = FoundInImportsFontLib;
                }
                Scaleform::String::operator=(&psearchInfo->ImportFoundUrl, v35);
              }
              if ( rh.HType == RH_Pointer && pResource )
                Scaleform::GFx::Resource::Release(pResource);
              return (Scaleform::GFx::FontResource *)v29;
            }
          }
        }
LABEL_58:
        if ( rh.HType == RH_Pointer && pResource )
          Scaleform::GFx::Resource::Release(pResource);
        ++v44;
        ++j;
      }
      while ( j < v12->Imports.Data.Size );
    }
    pimport = v12->pNext.Value;
    if ( !pimport )
      break;
    v12 = v12->pNext.Value;
  }
  this = v43;
LABEL_15:
  v13 = this->GetResource(this, pfontName);
  v14 = v13;
  if ( v13 )
  {
    if ( (v13->GetResourceTypeCode(v13) & 0xFF00) == 0x200
      && ((int)v14[1].__vftable[1].GetKey & (styleFlags & 0x10 | ((styleFlags & 0x300) != 0 ? 0x300 : 0) | 3)) == (styleFlags & 0x313) )
    {
      if ( psearchInfo )
        psearchInfo->Status = FoundInExports;
      return (Scaleform::GFx::FontResource *)v14;
    }
    goto LABEL_82;
  }
  v36 = pdataDef->pData.pObject;
  if ( (char)((v36->FileAttributes & 8 | 0x10) >> 3) < 3 || !v36->BindData.pImports.Value )
  {
LABEL_82:
    if ( psearchInfo )
      psearchInfo->Status = NotFound;
    return 0;
  }
  p_cs = &v43->pBindData.pObject->ImportSourceLock.cs;
  EnterCriticalSection(p_cs);
  v38 = v43->pBindData.pObject;
  v39 = 0;
  if ( !v38->ImportSourceMovies.Data.Size )
  {
LABEL_81:
    LeaveCriticalSection(p_cs);
    goto LABEL_82;
  }
  while ( 1 )
  {
    v40 = v38->ImportSourceMovies.Data.Data[v39].pObject;
    if ( v40 )
    {
      v41 = (int)v40->GetFontResource(v40, pfontName, styleFlags, psearchInfo);
      if ( v41 )
        break;
    }
    v38 = v43->pBindData.pObject;
    if ( ++v39 >= v38->ImportSourceMovies.Data.Size )
      goto LABEL_81;
  }
  LeaveCriticalSection(p_cs);
  return (Scaleform::GFx::FontResource *)v41;
}
