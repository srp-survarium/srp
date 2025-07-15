void __thiscall Scaleform::GFx::MovieDefImpl::BindTaskData::ResolveImport(
        Scaleform::GFx::MovieDefImpl::BindTaskData *this,
        Scaleform::GFx::ImportData *pimport,
        Scaleform::GFx::MovieDefImpl *pdefImpl,
        Scaleform::GFx::LoadStates *pls,
        bool recursive)
{
  Scaleform::GFx::MovieDefImpl::BindTaskData *v6; // esi
  unsigned int v7; // edi
  Scaleform::GFx::ImportData::Symbol *v8; // esi
  Scaleform::GFx::MovieDefImpl *v9; // ebx
  Scaleform::GFx::LogState *pObject; // eax
  unsigned int Size; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,265>,Scaleform::ArrayDefaultPolicy> *p_Data; // edi
  unsigned int v13; // esi
  Scaleform::GFx::Resource **p_pObject; // ebx
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *Data; // ecx
  Scaleform::GFx::MovieDefImpl **v16; // esi
  int v17; // eax
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v18; // esi
  Scaleform::GFx::FontDataUseNode *volatile Value; // ebx
  _DWORD *v20; // ebp
  _DWORD *v21; // edi
  int v22; // esi
  int v23; // eax
  char *v24; // eax
  volatile unsigned int BindIndex; // eax
  Scaleform::GFx::ResourceBinding *p_ResourceBinding; // ecx
  Scaleform::GFx::ResourceBindData *v27; // esi
  void *v28; // esi
  char *v29; // [esp-4h] [ebp-2Ch]
  Scaleform::String result; // [esp+14h] [ebp-14h] BYREF
  Scaleform::GFx::ResourceBindData pdata; // [esp+18h] [ebp-10h] BYREF
  Scaleform::GFx::ResourceBindData v33; // [esp+20h] [ebp-8h] BYREF
  int v34; // [esp+2Ch] [ebp+4h]
  Scaleform::GFx::FontDataUseNode *volatile v35; // [esp+2Ch] [ebp+4h]
  Scaleform::GFx::FontDataUseNode *volatile v36; // [esp+34h] [ebp+Ch]
  int v37; // [esp+38h] [ebp+10h]
  char v38; // [esp+38h] [ebp+10h]

  v6 = this;
  v7 = 0;
  if ( pimport->Imports.Data.Size )
  {
    v34 = 0;
    do
    {
      v8 = &pimport->Imports.Data.Data[v34];
      v9 = pdefImpl;
      v33.pResource.pObject = 0;
      v33.pBinding = 0;
      if ( Scaleform::GFx::MovieDefImpl::GetExportedResource(pdefImpl, &v33, &v8->SymbolName, 0) )
      {
        Scaleform::GFx::MovieDefImpl::BindTaskData::SetResourceBindData(
          this,
          (int)pimport,
          (Scaleform::GFx::ResourceId)v8->CharacterId,
          &v33,
          (const char *)((v8->SymbolName.HeapTypeBits & 0xFFFFFFFC) + 8));
      }
      else
      {
        pObject = pls->pLog.pObject;
        if ( pObject )
          Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
            &pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
            "Import failed - resource '%s' is not exported from movie '%s'",
            (const char *)((v8->SymbolName.HeapTypeBits & 0xFFFFFFFC) + 8),
            (const char *)((pimport->SourceUrl.HeapTypeBits & 0xFFFFFFFC) + 8));
      }
      if ( v33.pResource.pObject )
        Scaleform::GFx::Resource::Release(v33.pResource.pObject);
      ++v34;
      ++v7;
    }
    while ( v7 < pimport->Imports.Data.Size );
    v6 = this;
  }
  else
  {
    v9 = pdefImpl;
  }
  if ( !recursive )
  {
    EnterCriticalSection(&v6->ImportSourceLock.cs);
    if ( v9 )
      Scaleform::RefCountImpl::AddRef(v9);
    Size = v6->ImportSourceMovies.Data.Size;
    p_Data = &v6->ImportSourceMovies.Data;
    v13 = Size + 1;
    if ( Size + 1 >= Size )
    {
      if ( v13 >= p_Data->Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,265>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_Data,
          p_Data,
          v13 + (v13 >> 2));
    }
    else
    {
      p_pObject = &p_Data->Data[Size - 1].pObject;
      v37 = -1;
      do
      {
        if ( *p_pObject )
          Scaleform::GFx::Resource::Release(*p_pObject);
        --p_pObject;
        --v37;
      }
      while ( v37 );
      if ( v13 < p_Data->Policy.Capacity >> 1 )
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,265>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_Data,
          p_Data,
          v13);
      v9 = pdefImpl;
    }
    Data = p_Data->Data;
    p_Data->Size = v13;
    v16 = &Data[v13 - 1].pObject;
    if ( v16 )
    {
      if ( v9 )
        Scaleform::RefCountImpl::AddRef(v9);
      *v16 = v9;
    }
    if ( v9 )
      Scaleform::GFx::Resource::Release(v9);
    LeaveCriticalSection(&this->ImportSourceLock.cs);
    v38 = 0;
    Scaleform::String::ToLower(&pimport->SourceUrl, &result);
    strstr((unsigned __int8 *)((result.HeapTypeBits & 0xFFFFFFFC) + 8), "_glyphs");
    if ( v17 )
    {
      v38 = 1;
      if ( v9 )
        Scaleform::RefCountImpl::AddRef(v9);
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &pls->SubstituteFontMovieDefs.Data,
        &pls->SubstituteFontMovieDefs,
        pls->SubstituteFontMovieDefs.Data.Size + 1);
      v18 = &pls->SubstituteFontMovieDefs.Data.Data[pls->SubstituteFontMovieDefs.Data.Size - 1];
      if ( &pls->SubstituteFontMovieDefs.Data.Data[pls->SubstituteFontMovieDefs.Data.Size] != (Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *)4 )
      {
        if ( v9 )
          Scaleform::RefCountImpl::AddRef(v9);
        v18->pObject = v9;
      }
      if ( v9 )
        Scaleform::GFx::Resource::Release(v9);
    }
    Value = v9->pBindData.pObject->pDataDef.pObject->pData.pObject->BindData.pFonts.Value;
    v36 = this->pDataDef.pObject->pData.pObject->BindData.pFonts.Value;
    v35 = Value;
    if ( v36 )
    {
      while ( 1 )
      {
        v20 = &v36->pFontData.pObject->__vftable;
        if ( (!(*(int (__thiscall **)(_DWORD *))(*v20 + 72))(v20) || v38) && Value )
        {
          while ( 1 )
          {
            v21 = &Value->pFontData.pObject->__vftable;
            if ( (*(int (__thiscall **)(_DWORD *))(*v21 + 72))(v21) )
            {
              v22 = v21[5] & 0x303;
              v23 = (*(int (__thiscall **)(_DWORD *))(*v21 + 4))(v21);
              if ( (v20[5] & (v22 & 0x10 | ((v22 & 0x300) != 0 ? 0x300 : 0) | 3)) == (v22 & 0x313) )
              {
                v29 = (char *)v23;
                v24 = (char *)(*(int (__thiscall **)(_DWORD *))(*v20 + 4))(v20);
                if ( !Scaleform::String::CompareNoCase(v24, v29) )
                  break;
              }
            }
            Value = Value->pNext.Value;
            if ( !Value )
              goto LABEL_61;
          }
          BindIndex = Value->BindIndex;
          p_ResourceBinding = &pdefImpl->pBindData.pObject->ResourceBinding;
          pdata.pResource.pObject = 0;
          pdata.pBinding = 0;
          if ( p_ResourceBinding->Frozen && BindIndex < p_ResourceBinding->ResourceCount )
          {
            v27 = &p_ResourceBinding->pResources[BindIndex];
            if ( v27->pResource.pObject )
            {
              Scaleform::RefCountImpl::AddRef(v27->pResource.pObject);
              if ( pdata.pResource.pObject )
                Scaleform::GFx::Resource::Release(pdata.pResource.pObject);
            }
            pdata = *v27;
          }
          else
          {
            Scaleform::GFx::ResourceBinding::GetResourceData_Locked(p_ResourceBinding, &pdata, BindIndex);
          }
          if ( pdata.pResource.pObject )
          {
            Scaleform::GFx::ResourceBinding::SetBindData(&this->ResourceBinding, (int)v20, v36->BindIndex, &pdata);
            if ( pdata.pResource.pObject )
              Scaleform::GFx::Resource::Release(pdata.pResource.pObject);
          }
        }
LABEL_61:
        v36 = v36->pNext.Value;
        if ( !v36 )
          break;
        Value = v35;
      }
    }
    v28 = (void *)(result.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((result.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v28);
  }
}
