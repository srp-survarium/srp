void __thiscall Scaleform::GFx::LoadProcess::AddImageResource(
        Scaleform::GFx::LoadProcess *this,
        Scaleform::GFx::ResourceId rid,
        Scaleform::Render::ImageSource *pimage)
{
  Scaleform::GFx::MovieDefBindStates *pObject; // eax
  Scaleform::GFx::ImageCreator *v5; // ecx
  Scaleform::Render::Image *(__thiscall *CreateImage)(Scaleform::GFx::ImageCreator *, const Scaleform::GFx::ImageCreateInfo *, Scaleform::Render::ImageSource *); // eax
  Scaleform::Render::Image *v7; // ebp
  Scaleform::GFx::ImageResource *v8; // eax
  Scaleform::GFx::Resource *v9; // eax
  Scaleform::GFx::Resource *v10; // edi
  Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::Render::Image *v12; // ebp
  Scaleform::Render::WrapperImageSource *v13; // eax
  Scaleform::Render::ImageSource *v14; // eax
  Scaleform::Render::ImageSource *v15; // edi
  Scaleform::GFx::ResourceData rdata; // [esp+10h] [ebp-50h] BYREF
  Scaleform::GFx::ResourceHandle result; // [esp+18h] [ebp-48h] BYREF
  Scaleform::GFx::ImageCreator imgCr; // [esp+20h] [ebp-40h] BYREF
  int v19; // [esp+30h] [ebp-30h]
  int v20; // [esp+34h] [ebp-2Ch]
  int v21; // [esp+38h] [ebp-28h]
  int v22; // [esp+3Ch] [ebp-24h]
  Scaleform::GFx::ImageCreateInfo icreateInfo; // [esp+40h] [ebp-20h] BYREF

  if ( pimage )
  {
    if ( SLOBYTE(this->LoadFlags) >= 0
      && (pObject = this->pLoadStates.pObject->pBindStates.pObject, pObject->pImageCreator.pObject)
      && (v5 = pObject->pImageCreator.pObject) != 0 )
    {
      imgCr.RefCount = (volatile int)this->pLoadData.pObject->pHeap;
      CreateImage = v5->CreateImage;
      imgCr.__vftable = (Scaleform::GFx::ImageCreator_vtbl *)1;
      imgCr.SType = State_Translator;
      imgCr.pTextureManager.pObject = (Scaleform::Render::TextureManager *)1;
      v19 = 0;
      v20 = 0;
      v21 = 0;
      v22 = 0;
      v7 = CreateImage(v5, (const Scaleform::GFx::ImageCreateInfo *)&imgCr, pimage);
      v8 = (Scaleform::GFx::ImageResource *)(*(int (__thiscall **)(volatile int, int, _DWORD))(*(_DWORD *)imgCr.RefCount
                                                                                             + 40))(
                                              imgCr.RefCount,
                                              52,
                                              0);
      if ( v8 )
      {
        Scaleform::GFx::ImageResource::ImageResource(v8, v7, Use_Bitmap);
        v10 = v9;
      }
      else
      {
        v10 = 0;
      }
      if ( this->LoadState == LS_LoadingRoot )
        Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(this->pLoadData.pObject, rid, v10);
      if ( v10 )
        Scaleform::GFx::Resource::Release(v10);
      if ( v7 )
        v7->Release(v7);
    }
    else
    {
      pHeap = this->pLoadData.pObject->pHeap;
      icreateInfo.Type = Create_FileImage;
      icreateInfo.pHeap = pHeap;
      icreateInfo.Use = 1;
      icreateInfo.RUse = Use_Bitmap;
      memset(&icreateInfo.pLog, 0, 16);
      Scaleform::GFx::ImageCreator::ImageCreator(&imgCr, 0);
      v12 = Scaleform::GFx::ImageCreator::CreateImage(&imgCr, &icreateInfo, pimage);
      v13 = (Scaleform::Render::WrapperImageSource *)icreateInfo.pHeap->Alloc(icreateInfo.pHeap, 12, 0);
      if ( v13 )
      {
        Scaleform::Render::WrapperImageSource::WrapperImageSource(v13, v12);
        v15 = v14;
      }
      else
      {
        v15 = 0;
      }
      Scaleform::GFx::ImageResourceCreator::CreateImageResourceData(&rdata, v15);
      Scaleform::GFx::LoadProcess::AddDataResource(this, &result, rid, &rdata);
      if ( result.HType == RH_Pointer && result.BindIndex )
        Scaleform::GFx::Resource::Release(result.pResource);
      if ( rdata.pInterface )
        rdata.pInterface->Release(rdata.pInterface, rdata.hData);
      if ( v15 )
        v15->Release(v15);
      if ( v12 )
        v12->Release(v12);
      if ( imgCr.pTextureManager.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)imgCr.pTextureManager.pObject);
      imgCr.__vftable = (Scaleform::GFx::ImageCreator_vtbl *)&Scaleform::GFx::State::`vftable';
      Scaleform::RefCountImplCore::~RefCountImplCore(&imgCr);
    }
  }
}
