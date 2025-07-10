char __thiscall Scaleform::GFx::ImageResourceCreator::CreateResource(
        Scaleform::GFx::ImageResourceCreator *this,
        Scaleform::Render::ImageSource *hdata,
        Scaleform::GFx::ResourceBindData *pbindData,
        Scaleform::GFx::LoadStates *pls,
        Scaleform::MemoryHeap *pbindHeap)
{
  Scaleform::GFx::MovieDefBindStates *pObject; // eax
  Scaleform::GFx::ImageFileHandlerRegistry *v7; // ebx
  Scaleform::MemoryHeap *v8; // ecx
  Scaleform::GFx::LogState *v9; // eax
  Scaleform::Log *GlobalLog; // eax
  Scaleform::GFx::MovieDefBindStates *v11; // eax
  Scaleform::GFx::ImageCreator *v12; // ecx
  Scaleform::Render::Image *v13; // ebx
  Scaleform::GFx::ImageResource *v14; // eax
  Scaleform::GFx::Resource *v15; // eax
  Scaleform::GFx::Resource *v16; // esi
  Scaleform::GFx::ImageCreateInfo icreateInfo; // [esp+10h] [ebp-20h] BYREF
  Scaleform::MemoryHeap *pbindHeapa; // [esp+40h] [ebp+10h]

  pObject = pls->pBindStates.pObject;
  v7 = pls->pImageFileHandlerRegistry.pObject;
  icreateInfo.Type = Create_FileImage;
  icreateInfo.pHeap = pbindHeap;
  memset(&icreateInfo.Use, 0, 24);
  v8 = (Scaleform::MemoryHeap *)pObject->pFileOpener.pObject;
  v9 = pls->pLog.pObject;
  pbindHeapa = v8;
  if ( v9 )
  {
    GlobalLog = v9->pLog.pObject;
    if ( !GlobalLog )
      GlobalLog = Scaleform::Log::GetGlobalLog();
  }
  else
  {
    GlobalLog = 0;
  }
  icreateInfo.pLog = GlobalLog;
  v11 = pls->pBindStates.pObject;
  icreateInfo.pFileOpener = (Scaleform::GFx::FileOpener *)pbindHeapa;
  icreateInfo.pIFHRegistry = v7;
  icreateInfo.pHeap = pbindHeap;
  v12 = v11->pImageCreator.pObject;
  if ( !v12 )
    return 0;
  v13 = v12->CreateImage(v12, &icreateInfo, hdata);
  if ( !v13 )
    return 0;
  v14 = (Scaleform::GFx::ImageResource *)pbindHeap->Alloc(pbindHeap, 52, 0);
  if ( !v14 || (Scaleform::GFx::ImageResource::ImageResource(v14, v13, Use_Bitmap), (v16 = v15) == 0) )
  {
    v13->Release(v13);
    return 0;
  }
  Scaleform::RefCountImpl::AddRef(v15);
  if ( pbindData->pResource.pObject )
    Scaleform::GFx::Resource::Release(pbindData->pResource.pObject);
  pbindData->pResource.pObject = v16;
  Scaleform::GFx::Resource::Release(v16);
  v13->Release(v13);
  return 1;
}
