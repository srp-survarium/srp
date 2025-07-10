Scaleform::GFx::MovieDefImpl *__thiscall Scaleform::GFx::MovieImpl::CreateImageMovieDef(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::ImageResource *pimageResource,
        bool bilinear,
        const char *purl,
        Scaleform::GFx::LoadStates *pls)
{
  Scaleform::GFx::LoadStates *v5; // ebx
  Scaleform::GFx::StateBag *v6; // esi
  int v8; // ebp
  Scaleform::GFx::LoadStates *v9; // eax
  Scaleform::GFx::StateBagImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v11; // eax
  Scaleform::MemoryHeap *pHeap; // ebp
  Scaleform::MemoryHeap *v13; // ecx
  Scaleform::GFx::MovieDataDef *v14; // eax
  Scaleform::GFx::MovieDataDef *v15; // eax
  Scaleform::GFx::MovieDataDef *v16; // esi
  Scaleform::GFx::LogState *v18; // eax
  Scaleform::Log *GlobalLog; // eax
  Scaleform::GFx::ImageCreator *v20; // edi
  Scaleform::GFx::MovieDefImpl *v21; // ecx
  int v22; // eax
  Scaleform::RefCountVImpl *plsRef; // [esp+20h] [ebp-10h]
  Scaleform::GFx::ResourceKey createKey; // [esp+28h] [ebp-8h] BYREF
  bool pimageResourcea; // [esp+34h] [ebp+4h]
  Scaleform::Log *plsa; // [esp+40h] [ebp+10h]

  v5 = pls;
  v6 = 0;
  v8 = 0;
  plsRef = 0;
  if ( !pls )
  {
    v9 = (Scaleform::GFx::LoadStates *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 80, 0);
    if ( v9 )
    {
      pObject = this->pStateBag.pObject;
      if ( pObject )
        v6 = &pObject->Scaleform::GFx::StateBag;
      Scaleform::GFx::LoadStates::LoadStates(v9, this->pMainMovieDef.pObject->pLoaderImpl.pObject, v6, 0);
    }
    else
    {
      v11 = 0;
    }
    plsRef = v11;
    v5 = (Scaleform::GFx::LoadStates *)v11;
  }
  if ( pimageResource )
  {
    Scaleform::GFx::MovieDataDef::CreateMovieFileKey(&createKey, purl, 0, 0, 0);
    pHeap = this->pHeap;
    v13 = pHeap;
    if ( !pHeap )
      v13 = Scaleform::Memory::pGlobalHeap;
    v14 = (Scaleform::GFx::MovieDataDef *)v13->Alloc(v13, 36u, 0);
    if ( !v14 )
      goto LABEL_13;
    Scaleform::GFx::MovieDataDef::MovieDataDef(v14, &createKey, MT_Image, purl, pHeap, 0, 0);
    v16 = v15;
    if ( !v15 )
      goto LABEL_13;
    v18 = v5->pLog.pObject;
    if ( v18 )
    {
      GlobalLog = v18->pLog.pObject;
      if ( !GlobalLog )
        GlobalLog = Scaleform::Log::GetGlobalLog();
      plsa = GlobalLog;
    }
    else
    {
      plsa = 0;
    }
    v20 = (Scaleform::GFx::ImageCreator *)this->GetStateAddRef(&this->Scaleform::GFx::StateBag, 11);
    pimageResourcea = !Scaleform::GFx::MovieDataDef::LoadTaskData::InitImageFileMovieDef(
                         v16->pData.pObject,
                         0,
                         pimageResource,
                         v20,
                         plsa,
                         bilinear);
    if ( v20 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v20);
    if ( pimageResourcea )
    {
      Scaleform::GFx::Resource::Release(v16);
LABEL_13:
      if ( createKey.pKeyInterface )
        createKey.pKeyInterface->Release(createKey.pKeyInterface, createKey.hKeyData);
      if ( plsRef )
        Scaleform::RefCountImpl::Release(plsRef);
      return 0;
    }
    Scaleform::GFx::LoadStates::SetRelativePathForDataDef(v5, v16);
    v21 = (Scaleform::GFx::MovieDefImpl *)pHeap->Alloc(pHeap, 32u, 0);
    if ( v21 )
    {
      Scaleform::GFx::MovieDefImpl::MovieDefImpl(
        v21,
        v16,
        v5->pBindStates.pObject,
        v5->pLoaderImpl.pObject,
        0,
        this->pStateBag.pObject->pDelegate.pObject,
        pHeap,
        1,
        0);
      v8 = v22;
    }
    else
    {
      v8 = 0;
    }
    Scaleform::GFx::Resource::Release(v16);
    if ( createKey.pKeyInterface )
      createKey.pKeyInterface->Release(createKey.pKeyInterface, createKey.hKeyData);
  }
  if ( plsRef )
    Scaleform::RefCountImpl::Release(plsRef);
  return (Scaleform::GFx::MovieDefImpl *)v8;
}
