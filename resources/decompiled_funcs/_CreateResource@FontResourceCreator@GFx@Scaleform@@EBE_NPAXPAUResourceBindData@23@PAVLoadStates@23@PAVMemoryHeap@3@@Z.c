bool __thiscall Scaleform::GFx::FontResourceCreator::CreateResource(
        Scaleform::GFx::FontResourceCreator *this,
        Scaleform::Render::Font *hdata,
        Scaleform::GFx::ResourceBindData *pbindData,
        Scaleform::GFx::LoadStates *pls,
        Scaleform::MemoryHeap *pbindHeap)
{
  Scaleform::GFx::LoadStates *v5; // edx
  unsigned int v7; // ecx
  Scaleform::GFx::FontDataUseNode *volatile Value; // ebx
  _DWORD *v9; // edi
  int v10; // esi
  int v11; // eax
  const char *v12; // eax
  Scaleform::GFx::FontResource *v13; // eax
  Scaleform::GFx::Resource *v14; // eax
  Scaleform::GFx::Resource *v15; // edi
  Scaleform::GFx::MovieDefImpl::BindTaskData *pObject; // ecx
  volatile bool Frozen; // dl
  unsigned int BindIndex; // ebx
  Scaleform::GFx::ResourceBinding *p_ResourceBinding; // ecx
  Scaleform::GFx::Resource **p_pObject; // esi
  const char *v22; // [esp-4h] [ebp-18h]
  unsigned int ifontDef; // [esp+10h] [ebp-4h]
  Scaleform::GFx::MovieDefImpl *pdefImpl; // [esp+18h] [ebp+4h]

  v5 = pls;
  v7 = 0;
  ifontDef = 0;
  if ( pls->SubstituteFontMovieDefs.Data.Size )
  {
    while ( 1 )
    {
      pdefImpl = v5->SubstituteFontMovieDefs.Data.Data[v7].pObject;
      Value = pdefImpl->pBindData.pObject->pDataDef.pObject->pData.pObject->BindData.pFonts.Value;
      if ( Value )
        break;
LABEL_8:
      ifontDef = ++v7;
      if ( v7 >= v5->SubstituteFontMovieDefs.Data.Size )
        goto LABEL_9;
    }
    while ( 1 )
    {
      v9 = &Value->pFontData.pObject->__vftable;
      if ( (*(int (__thiscall **)(_DWORD *))(*v9 + 72))(v9) )
      {
        v10 = v9[5] & 0x303;
        v11 = (*(int (__thiscall **)(_DWORD *))(*v9 + 4))(v9);
        if ( (hdata->Flags & (v10 & 0x10 | ((v10 & 0x300) != 0 ? 0x300 : 0) | 3)) == (v10 & 0x313) )
        {
          v22 = (const char *)v11;
          v12 = hdata->GetName(hdata);
          if ( !Scaleform::String::CompareNoCase(v12, v22) )
            break;
        }
      }
      Value = Value->pNext.Value;
      if ( !Value )
      {
        v5 = pls;
        v7 = ifontDef;
        goto LABEL_8;
      }
    }
    pObject = pdefImpl->pBindData.pObject;
    Frozen = pObject->ResourceBinding.Frozen;
    BindIndex = Value->BindIndex;
    p_ResourceBinding = &pObject->ResourceBinding;
    if ( Frozen && BindIndex < p_ResourceBinding->ResourceCount )
    {
      p_pObject = &p_ResourceBinding->pResources[BindIndex].pResource.pObject;
      if ( *p_pObject )
        Scaleform::RefCountImpl::AddRef(*p_pObject);
      if ( pbindData->pResource.pObject )
        Scaleform::GFx::Resource::Release(pbindData->pResource.pObject);
      *pbindData = *(Scaleform::GFx::ResourceBindData *)p_pObject;
      return 1;
    }
    else
    {
      Scaleform::GFx::ResourceBinding::GetResourceData_Locked(p_ResourceBinding, pbindData, BindIndex);
      return 1;
    }
  }
  else
  {
LABEL_9:
    if ( !hdata->HasVectorOrRasterGlyphs(hdata) && hdata->GetName(hdata) )
      hdata->Flags |= 0x40u;
    if ( !pbindData->pResource.pObject )
    {
      v13 = (Scaleform::GFx::FontResource *)pbindHeap->Alloc(pbindHeap, 32, 0);
      if ( v13 )
      {
        Scaleform::GFx::FontResource::FontResource(v13, hdata, pbindData->pBinding);
        v15 = v14;
      }
      else
      {
        v15 = 0;
      }
      if ( pbindData->pResource.pObject )
        Scaleform::GFx::Resource::Release(pbindData->pResource.pObject);
      pbindData->pResource.pObject = v15;
    }
    return pbindData->pResource.pObject != 0;
  }
}
