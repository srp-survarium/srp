Scaleform::GFx::MovieDefImpl *__thiscall Scaleform::GFx::MovieImpl::CreateImageMovieDef(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::ImageResource *pimageResource,
        bool bilinear,
        char *purl,
        Scaleform::Log *pls)
{
  Scaleform::Log *v5; // ebx
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
  volatile int RefCount; // eax
  Scaleform::Log *GlobalLog; // eax
  Scaleform::GFx::ImageCreator *v20; // edi
  Scaleform::GFx::MovieDefImpl *v21; // ecx
  int v22; // eax
  Scaleform::RefCountVImpl *v23; // [esp+20h] [ebp-10h]
  Scaleform::GFx::ResourceKey result; // [esp+28h] [ebp-8h] BYREF
  bool pimageResourcea; // [esp+34h] [ebp+4h]
  Scaleform::Log *plog; // [esp+40h] [ebp+10h]

  v5 = pls;
  v6 = 0;
  v8 = 0;
  v23 = 0;
  if ( !pls )
  {
    v9 = (Scaleform::GFx::LoadStates *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 80, 0);
    if ( v9 )
    {
      pObject = this->pStateBag.pObject;
      if ( pObject )
        v6 = &pObject->Scaleform::GFx::StateBag;
      Scaleform::GFx::LoadStates::LoadStates(
        v9,
        (Scaleform::GFx::Resource *)this->pMainMovieDef.pObject->pLoaderImpl.pObject,
        v6,
        0);
    }
    else
    {
      v11 = 0;
    }
    v23 = v11;
    v5 = (Scaleform::Log *)v11;
  }
  if ( pimageResource )
  {
    Scaleform::GFx::MovieDataDef::CreateMovieFileKey(&result, purl, 0, 0, 0);
    pHeap = this->pHeap;
    v13 = pHeap;
    if ( !pHeap )
      v13 = Scaleform::Memory::pGlobalHeap;
    v14 = (Scaleform::GFx::MovieDataDef *)v13->Alloc(v13, 36u, 0);
    if ( !v14 )
      goto LABEL_13;
    Scaleform::GFx::MovieDataDef::MovieDataDef(v14, &result, MT_Image, purl, pHeap, 0, 0);
    v16 = v15;
    if ( !v15 )
      goto LABEL_13;
    RefCount = v5[1].RefCount;
    if ( RefCount )
    {
      GlobalLog = *(Scaleform::Log **)(RefCount + 16);
      if ( !GlobalLog )
        GlobalLog = Scaleform::Log::GetGlobalLog();
      plog = GlobalLog;
    }
    else
    {
      plog = 0;
    }
    v20 = (Scaleform::GFx::ImageCreator *)this->GetStateAddRef(&this->Scaleform::GFx::StateBag, 11);
    pimageResourcea = !Scaleform::GFx::MovieDataDef::LoadTaskData::InitImageFileMovieDef(
                         v16->pData.pObject,
                         0,
                         pimageResource,
                         v20,
                         plog,
                         bilinear);
    if ( v20 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v20);
    if ( pimageResourcea )
    {
      Scaleform::GFx::Resource::Release(v16);
LABEL_13:
      if ( result.pKeyInterface )
        result.pKeyInterface->Release(result.pKeyInterface, result.hKeyData);
      if ( v23 )
        Scaleform::RefCountImpl::Release(v23);
      return 0;
    }
    Scaleform::GFx::LoadStates::SetRelativePathForDataDef((Scaleform::GFx::LoadStates *)v5, v16);
    v21 = (Scaleform::GFx::MovieDefImpl *)pHeap->Alloc(pHeap, 32u, 0);
    if ( v21 )
    {
      Scaleform::GFx::MovieDefImpl::MovieDefImpl(
        v21,
        v16,
        (Scaleform::GFx::Resource *)v5[1].__vftable,
        (Scaleform::GFx::Resource *)v5[7].__vftable,
        0,
        (Scaleform::GFx::Resource *)this->pStateBag.pObject->pDelegate.pObject,
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
    if ( result.pKeyInterface )
      result.pKeyInterface->Release(result.pKeyInterface, result.hKeyData);
  }
  if ( v23 )
    Scaleform::RefCountImpl::Release(v23);
  return (Scaleform::GFx::MovieDefImpl *)v8;
}
