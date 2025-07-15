void __thiscall Scaleform::GFx::MovieDefImpl::BindTaskData::ResolveImport(
        Scaleform::GFx::MovieDefImpl::BindTaskData *this,
        Scaleform::GFx::FontDataUseNode *pimport,
        Scaleform::GFx::MovieDefImpl *pdefImpl,
        Scaleform::GFx::FontDataUseNode *pls,
        bool recursive)
{
  Scaleform::GFx::MovieDefImpl::BindTaskData *v6; // esi
  unsigned int v7; // edi
  Scaleform::GFx::ImportData::Symbol *v8; // esi
  Scaleform::GFx::MovieDefImpl *v9; // ebx
  Scaleform::GFx::LogState *Value; // eax
  unsigned int Size; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,265>,Scaleform::ArrayDefaultPolicy> *p_Data; // edi
  unsigned int v13; // esi
  Scaleform::GFx::Resource **p_pObject; // ebx
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *Data; // ecx
  Scaleform::GFx::MovieDefImpl **v16; // esi
  int v17; // eax
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v18; // esi
  Scaleform::GFx::FontDataUseNode *v19; // ebx
  _DWORD *v20; // ebp
  _DWORD *v21; // edi
  int v22; // esi
  int v23; // eax
  const char *v24; // eax
  unsigned int BindIndex; // eax
  Scaleform::GFx::ResourceBinding *p_ResourceBinding; // ecx
  Scaleform::GFx::ResourceBindData *v27; // esi
  void *v28; // esi
  const char *v29; // [esp-4h] [ebp-2Ch]
  Scaleform::String lowerURL; // [esp+14h] [ebp-14h] BYREF
  Scaleform::GFx::ResourceBindData sourceBindData; // [esp+18h] [ebp-10h] BYREF
  Scaleform::GFx::ResourceBindData bindData; // [esp+20h] [ebp-8h] BYREF
  Scaleform::GFx::FontDataUseNode *psourceFont; // [esp+2Ch] [ebp+4h]
  Scaleform::GFx::FontDataUseNode *psourceFonta; // [esp+2Ch] [ebp+4h]
  Scaleform::GFx::FontDataUseNode *pfont; // [esp+34h] [ebp+Ch]
  int forceFontSubstitution; // [esp+38h] [ebp+10h]
  char forceFontSubstitutiona; // [esp+38h] [ebp+10h]

  v6 = this;
  v7 = 0;
  if ( pimport->pFontData.pObject )
  {
    psourceFont = 0;
    do
    {
      v8 = (Scaleform::GFx::ImportData::Symbol *)((char *)psourceFont + pimport->Id.Id);
      v9 = pdefImpl;
      bindData.pResource.pObject = 0;
      bindData.pBinding = 0;
      if ( Scaleform::GFx::MovieDefImpl::GetExportedResource(pdefImpl, &bindData, &v8->SymbolName, 0) )
      {
        Scaleform::GFx::MovieDefImpl::BindTaskData::SetResourceBindData(
          this,
          (Scaleform::GFx::ResourceId)v8->CharacterId,
          &bindData,
          (const char *)((v8->SymbolName.HeapTypeBits & 0xFFFFFFFC) + 8));
      }
      else
      {
        Value = (Scaleform::GFx::LogState *)pls->pNext.Value;
        if ( Value )
          Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
            &Value->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
            "Import failed - resource '%s' is not exported from movie '%s'",
            (const char *)((v8->SymbolName.HeapTypeBits & 0xFFFFFFFC) + 8),
            (const char *)(((int)pimport->pNext.Value & 0xFFFFFFFC) + 8));
      }
      if ( bindData.pResource.pObject )
        Scaleform::GFx::Resource::Release(bindData.pResource.pObject);
      psourceFont = (Scaleform::GFx::FontDataUseNode *)((char *)psourceFont + 12);
      ++v7;
    }
    while ( (Scaleform::Render::Font *)v7 < pimport->pFontData.pObject );
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
      forceFontSubstitution = -1;
      do
      {
        if ( *p_pObject )
          Scaleform::GFx::Resource::Release(*p_pObject);
        --p_pObject;
        --forceFontSubstitution;
      }
      while ( forceFontSubstitution );
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
    forceFontSubstitutiona = 0;
    Scaleform::String::ToLower((Scaleform::String *)&pimport->pNext, &lowerURL);
    strstr((unsigned __int8 *)((lowerURL.HeapTypeBits & 0xFFFFFFFC) + 8), "_glyphs");
    if ( v17 )
    {
      forceFontSubstitutiona = 1;
      if ( v9 )
        Scaleform::RefCountImpl::AddRef(v9);
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,2>,Scaleform::ArrayDefaultPolicy> *)&pls[4].pFontData,
        &pls[4].pFontData,
        pls[4].BindIndex + 1);
      v18 = (Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *)((char *)pls[4].pFontData.pObject + 4 * pls[4].BindIndex - 4);
      if ( (Scaleform::Render::Font *)((char *)pls[4].pFontData.pObject + 4 * pls[4].BindIndex) != (Scaleform::Render::Font *)4 )
      {
        if ( v9 )
          Scaleform::RefCountImpl::AddRef(v9);
        v18->pObject = v9;
      }
      if ( v9 )
        Scaleform::GFx::Resource::Release(v9);
    }
    v19 = v9->pBindData.pObject->pDataDef.pObject->pData.pObject->BindData.pFonts.Value;
    pfont = this->pDataDef.pObject->pData.pObject->BindData.pFonts.Value;
    psourceFonta = v19;
    if ( pfont )
    {
      while ( 1 )
      {
        v20 = &pfont->pFontData.pObject->__vftable;
        if ( (!(*(int (__thiscall **)(_DWORD *))(*v20 + 72))(v20) || forceFontSubstitutiona) && v19 )
        {
          while ( 1 )
          {
            v21 = &v19->pFontData.pObject->__vftable;
            if ( (*(int (__thiscall **)(_DWORD *))(*v21 + 72))(v21) )
            {
              v22 = v21[5] & 0x303;
              v23 = (*(int (__thiscall **)(_DWORD *))(*v21 + 4))(v21);
              if ( (v20[5] & (v22 & 0x10 | ((v22 & 0x300) != 0 ? 0x300 : 0) | 3)) == (v22 & 0x313) )
              {
                v29 = (const char *)v23;
                v24 = (const char *)(*(int (__thiscall **)(_DWORD *))(*v20 + 4))(v20);
                if ( !Scaleform::String::CompareNoCase(v24, v29) )
                  break;
              }
            }
            v19 = v19->pNext.Value;
            if ( !v19 )
              goto LABEL_61;
          }
          BindIndex = v19->BindIndex;
          p_ResourceBinding = &pdefImpl->pBindData.pObject->ResourceBinding;
          sourceBindData.pResource.pObject = 0;
          sourceBindData.pBinding = 0;
          if ( p_ResourceBinding->Frozen && BindIndex < p_ResourceBinding->ResourceCount )
          {
            v27 = &p_ResourceBinding->pResources[BindIndex];
            if ( v27->pResource.pObject )
            {
              Scaleform::RefCountImpl::AddRef(v27->pResource.pObject);
              if ( sourceBindData.pResource.pObject )
                Scaleform::GFx::Resource::Release(sourceBindData.pResource.pObject);
            }
            sourceBindData = *v27;
          }
          else
          {
            Scaleform::GFx::ResourceBinding::GetResourceData_Locked(p_ResourceBinding, &sourceBindData, BindIndex);
          }
          if ( sourceBindData.pResource.pObject )
          {
            Scaleform::GFx::ResourceBinding::SetBindData(&this->ResourceBinding, pfont->BindIndex, &sourceBindData);
            if ( sourceBindData.pResource.pObject )
              Scaleform::GFx::Resource::Release(sourceBindData.pResource.pObject);
          }
        }
LABEL_61:
        pfont = pfont->pNext.Value;
        if ( !pfont )
          break;
        v19 = psourceFonta;
      }
    }
    v28 = (void *)(lowerURL.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((lowerURL.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v28);
  }
}
