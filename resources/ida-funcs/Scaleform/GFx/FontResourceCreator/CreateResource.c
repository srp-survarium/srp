bool __thiscall Scaleform::GFx::FontResourceCreator::CreateResource(
        Scaleform::GFx::FontResourceCreator *this,
        Scaleform::Render::Font *hdata,
        Scaleform::GFx::ResourceBindData *pbindData,
        Scaleform::GFx::LoadStates *pls,
        Scaleform::MemoryHeap *pbindHeap)
{
  Scaleform::GFx::LoadStates *v5; // edx
  unsigned int v7; // ecx
  _DWORD *v8; // ebx
  _DWORD *v9; // edi
  int v10; // esi
  int v11; // eax
  char *v12; // eax
  Scaleform::GFx::FontResource *v13; // eax
  Scaleform::GFx::Resource *v14; // eax
  Scaleform::GFx::Resource *v15; // edi
  Scaleform::Render::FontCacheHandleManager *volatile Value; // ecx
  char RefCount; // dl
  volatile unsigned int v18; // ebx
  Scaleform::GFx::ResourceBinding *p_LockSemaphore; // ecx
  Scaleform::GFx::Resource **p_pObject; // esi
  char *v22; // [esp-4h] [ebp-18h]
  unsigned int v23; // [esp+10h] [ebp-4h]
  Scaleform::Render::Font *pfont; // [esp+18h] [ebp+4h]

  v5 = pls;
  v7 = 0;
  v23 = 0;
  if ( pls->SubstituteFontMovieDefs.Data.Size )
  {
    while ( 1 )
    {
      pfont = (Scaleform::Render::Font *)v5->SubstituteFontMovieDefs.Data.Data[v7].pObject;
      v8 = *(_DWORD **)(*(_DWORD *)(pfont->hRef.pManager.Value->FontLock.cs.LockCount + 32) + 192);
      if ( v8 )
        break;
LABEL_8:
      v23 = ++v7;
      if ( v7 >= v5->SubstituteFontMovieDefs.Data.Size )
        goto LABEL_9;
    }
    while ( 1 )
    {
      v9 = (_DWORD *)v8[1];
      if ( (*(int (__thiscall **)(_DWORD *))(*v9 + 72))(v9) )
      {
        v10 = v9[5] & 0x303;
        v11 = (*(int (__thiscall **)(_DWORD *))(*v9 + 4))(v9);
        if ( (hdata->Flags & (v10 & 0x10 | ((v10 & 0x300) != 0 ? 0x300 : 0) | 3)) == (v10 & 0x313) )
        {
          v22 = (char *)v11;
          v12 = (char *)hdata->GetName(hdata);
          if ( !Scaleform::String::CompareNoCase(v12, v22) )
            break;
        }
      }
      v8 = (_DWORD *)v8[3];
      if ( !v8 )
      {
        v5 = pls;
        v7 = v23;
        goto LABEL_8;
      }
    }
    Value = pfont->hRef.pManager.Value;
    RefCount = Value[1].RefCount;
    v18 = v8[2];
    p_LockSemaphore = (Scaleform::GFx::ResourceBinding *)&Value->FontLock.cs.LockSemaphore;
    if ( RefCount && v18 < p_LockSemaphore->ResourceCount )
    {
      p_pObject = &p_LockSemaphore->pResources[v18].pResource.pObject;
      if ( *p_pObject )
        Scaleform::RefCountImpl::AddRef(*p_pObject);
      if ( pbindData->pResource.pObject )
        Scaleform::GFx::Resource::Release(pbindData->pResource.pObject);
      *pbindData = *(Scaleform::GFx::ResourceBindData *)p_pObject;
      return 1;
    }
    else
    {
      Scaleform::GFx::ResourceBinding::GetResourceData_Locked(p_LockSemaphore, pbindData, v18);
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
        Scaleform::GFx::FontResource::FontResource(v13, (Scaleform::GFx::Resource *)hdata, pbindData->pBinding);
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
