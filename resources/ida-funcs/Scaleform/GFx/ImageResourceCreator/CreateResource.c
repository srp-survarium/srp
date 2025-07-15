char __thiscall Scaleform::GFx::ImageResourceCreator::CreateResource(
        Scaleform::GFx::ImageResourceCreator *this,
        Scaleform::Render::ImageSource *hdata,
        Scaleform::GFx::ResourceBindData *pbindData,
        Scaleform::GFx::LoadStates *pls,
        Scaleform::MemoryHeap *pbindHeap)
{
  Scaleform::GFx::MovieDefBindStates *pObject; // eax
  Scaleform::GFx::ImageFileHandlerRegistry *v7; // ebx
  Scaleform::GFx::FileOpener *v8; // ecx
  Scaleform::GFx::LogState *v9; // eax
  Scaleform::Log *GlobalLog; // eax
  Scaleform::GFx::MovieDefBindStates *v11; // eax
  Scaleform::GFx::ImageCreator *v12; // ecx
  Scaleform::Render::Image *v13; // ebx
  Scaleform::GFx::ImageResource *v14; // eax
  Scaleform::GFx::Resource *v15; // eax
  Scaleform::GFx::Resource *v16; // esi
  int v18; // [esp+10h] [ebp-20h] BYREF
  Scaleform::MemoryHeap *v19; // [esp+14h] [ebp-1Ch]
  int v20; // [esp+18h] [ebp-18h]
  int v21; // [esp+1Ch] [ebp-14h]
  Scaleform::Log *v22; // [esp+20h] [ebp-10h]
  Scaleform::GFx::FileOpener *v23; // [esp+24h] [ebp-Ch]
  Scaleform::GFx::ImageFileHandlerRegistry *v24; // [esp+28h] [ebp-8h]
  int v25; // [esp+2Ch] [ebp-4h]
  Scaleform::GFx::FileOpener *v26; // [esp+40h] [ebp+10h]

  pObject = pls->pBindStates.pObject;
  v7 = pls->pImageFileHandlerRegistry.pObject;
  v18 = 1;
  v19 = pbindHeap;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  v23 = 0;
  v24 = 0;
  v25 = 0;
  v8 = pObject->pFileOpener.pObject;
  v9 = pls->pLog.pObject;
  v26 = v8;
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
  v22 = GlobalLog;
  v11 = pls->pBindStates.pObject;
  v23 = v26;
  v24 = v7;
  v19 = pbindHeap;
  v12 = v11->pImageCreator.pObject;
  if ( !v12 )
    return 0;
  v13 = v12->CreateImage(v12, (const Scaleform::GFx::ImageCreateInfo *)&v18, hdata);
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
