Scaleform::GFx::FontResource *__thiscall Scaleform::GFx::MovieDefImpl::GetFontResource(
        Scaleform::GFx::MovieDefImpl *this,
        char *pfontName,
        unsigned int styleFlags,
        Scaleform::GFx::MovieDefImpl::SearchInfo *psearchInfo)
{
  Scaleform::GFx::MovieDataDef *pObject; // edx
  Scaleform::GFx::FontDataUseNode *volatile Value; // edi
  _DWORD *v6; // ecx
  char *v7; // eax
  volatile unsigned int BindIndex; // eax
  Scaleform::GFx::ResourceBinding *p_ResourceBinding; // ecx
  Scaleform::GFx::ResourceBindData *v10; // ebp
  Scaleform::GFx::Resource *v11; // eax
  Scaleform::GFx::ImportData *volatile v12; // esi
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
  Scaleform::GFx::Resource *SizeMask; // ebx
  _DWORD **v29; // edi
  volatile bool Frozen; // dl
  Scaleform::GFx::ResourceBindData *v31; // edi
  Scaleform::GFx::Resource *v32; // ecx
  char *v33; // eax
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
  Scaleform::GFx::ImportData *v45; // [esp+18h] [ebp-24h]
  Scaleform::GFx::MovieDataDef *v46; // [esp+1Ch] [ebp-20h]
  unsigned int v47; // [esp+20h] [ebp-1Ch]
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::TableType v48; // [esp+24h] [ebp-18h] BYREF
  Scaleform::GFx::ResourceBindData pdata; // [esp+2Ch] [ebp-10h] BYREF
  Scaleform::GFx::ResourceBindData v50; // [esp+34h] [ebp-8h] BYREF

  pObject = this->pBindData.pObject->pDataDef.pObject;
  Value = pObject->pData.pObject->BindData.pFonts.Value;
  v43 = this;
  v46 = pObject;
  if ( Value )
  {
    do
    {
      v6 = &Value->pFontData.pObject->__vftable;
      if ( ((styleFlags & 0x10 | ((styleFlags & 0x300) != 0 ? 0x300 : 0) | 3) & v6[5]) == (styleFlags & 0x313) )
      {
        v7 = (char *)(*(int (__thiscall **)(_DWORD *))(*v6 + 4))(v6);
        if ( !Scaleform::String::CompareNoCase(v7, pfontName) )
        {
          BindIndex = Value->BindIndex;
          p_ResourceBinding = &v43->pBindData.pObject->ResourceBinding;
          pdata.pResource.pObject = 0;
          pdata.pBinding = 0;
          if ( p_ResourceBinding->Frozen && BindIndex < p_ResourceBinding->ResourceCount )
          {
            v10 = &p_ResourceBinding->pResources[BindIndex];
            if ( v10->pResource.pObject )
            {
              Scaleform::RefCountImpl::AddRef(v10->pResource.pObject);
              if ( pdata.pResource.pObject )
                Scaleform::GFx::Resource::Release(pdata.pResource.pObject);
            }
            v11 = v10->pResource.pObject;
            pdata = *v10;
          }
          else
          {
            Scaleform::GFx::ResourceBinding::GetResourceData_Locked(p_ResourceBinding, &pdata, BindIndex);
            v11 = pdata.pResource.pObject;
          }
          if ( v11 )
          {
            v16 = v11;
            if ( psearchInfo )
            {
              v17 = v11[1].__vftable;
              if ( ((int)v17[1].GetKey & 0x40) != 0 )
              {
                psearchInfo->Status = NonStaticFunction;
              }
              else if ( (styleFlags & 3) != 0
                     && (v18 = (*((unsigned __int8 (__thiscall **)(Scaleform::GFx::Resource_vtbl *))v17->~Scaleform::GFx::Resource
                                + 19))(v17) == 0,
                         v11 = pdata.pResource.pObject,
                         v18) )
              {
                psearchInfo->Status = NonStaticFunction|StaticFunction;
              }
              else
              {
                psearchInfo->Status = StaticFunction;
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
    pObject = v46;
    this = v43;
  }
  v12 = pObject->pData.pObject->BindData.pImports.Value;
  v45 = v12;
  if ( !v12 )
    goto LABEL_15;
  while ( 1 )
  {
    v47 = 0;
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
          v12 = v45;
        }
        v42.Id = v12->Imports.Data.Data[v44].CharacterId;
        v26 = v46->pData.pObject;
        v48.EntryCount = 0;
        v48.SizeMask = 0;
        if ( !Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(v26, &v48, v42) )
        {
          SizeMask = (Scaleform::GFx::Resource *)v48.SizeMask;
          goto LABEL_58;
        }
        v27 = &v43->pBindData.pObject->ResourceBinding;
        if ( !v48.EntryCount )
        {
          SizeMask = (Scaleform::GFx::Resource *)v48.SizeMask;
          v29 = (_DWORD **)v48.SizeMask;
          goto LABEL_53;
        }
        Frozen = v43->pBindData.pObject->ResourceBinding.Frozen;
        v50.pResource.pObject = 0;
        v50.pBinding = 0;
        if ( Frozen )
        {
          SizeMask = (Scaleform::GFx::Resource *)v48.SizeMask;
          if ( v48.SizeMask < v27->ResourceCount )
          {
            SizeMask = (Scaleform::GFx::Resource *)v48.SizeMask;
            v31 = &v27->pResources[v48.SizeMask];
            if ( v31->pResource.pObject )
            {
              Scaleform::RefCountImpl::AddRef(v31->pResource.pObject);
              if ( v50.pResource.pObject )
                Scaleform::GFx::Resource::Release(v50.pResource.pObject);
            }
            v32 = v31->pResource.pObject;
            v50 = *v31;
            goto LABEL_51;
          }
        }
        else
        {
          SizeMask = (Scaleform::GFx::Resource *)v48.SizeMask;
        }
        Scaleform::GFx::ResourceBinding::GetResourceData_Locked(v27, &v50, (volatile unsigned int)SizeMask);
        v32 = v50.pResource.pObject;
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
                    (char *)((v12->Imports.Data.Data[v44].SymbolName.HeapTypeBits & 0xFFFFFFFC) + 8),
                    pfontName)
              || (v33 = (char *)(*(int (__thiscall **)(_DWORD *))(*v29[3] + 4))(v29[3]),
                  !Scaleform::String::CompareNoCase(v33, pfontName)) )
            {
              if ( psearchInfo )
              {
                v34 = v12->SourceUrl.pData;
                v35 = &v12->SourceUrl;
                if ( (*(_DWORD *)((unsigned int)v34 & 0xFFFFFFFC) & 0x7FFFFFFFu) < 0xE
                  || Scaleform::String::CompareNoCase(
                       (char *)((v35->HeapTypeBits & 0xFFFFFFFC)
                              + (*(_DWORD *)(v35->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF)
                              - 6),
                       "gfxfontlib.swf") )
                {
                  psearchInfo->Status = 4;
                }
                else
                {
                  psearchInfo->Status = 5;
                }
                Scaleform::String::operator=(&psearchInfo->ImportFoundUrl, v35);
              }
              if ( !v48.EntryCount && SizeMask )
                Scaleform::GFx::Resource::Release(SizeMask);
              return (Scaleform::GFx::FontResource *)v29;
            }
          }
        }
LABEL_58:
        if ( !v48.EntryCount && SizeMask )
          Scaleform::GFx::Resource::Release(SizeMask);
        ++v44;
        ++v47;
      }
      while ( v47 < v12->Imports.Data.Size );
    }
    v45 = v12->pNext.Value;
    if ( !v45 )
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
        psearchInfo->Status = 6;
      return (Scaleform::GFx::FontResource *)v14;
    }
    goto LABEL_82;
  }
  v36 = v46->pData.pObject;
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
