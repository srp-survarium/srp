void __thiscall Scaleform::Render::DrawableImage::DrawableImage(
        Scaleform::Render::DrawableImage *this,
        bool transparent,
        Scaleform::Render::ImageBase *originalData,
        Scaleform::GFx::Resource *dicontext)
{
  int v5; // eax
  Scaleform::Render::ImageFormat v6; // eax
  Scaleform::Render::Size<unsigned long> size; // [esp+10h] [ebp-8h] BYREF

  this->__vftable = (Scaleform::Render::DrawableImage_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::DrawableImage_vtbl *)&Scaleform::Render::Image::`vftable';
  InterlockedExchange((volatile LONG *)&this->pTexture, 0);
  this->pUpdateSync = 0;
  this->pInverseMatrix = 0;
  this->__vftable = (Scaleform::Render::DrawableImage_vtbl *)&Scaleform::Render::DrawableImage::`vftable';
  this->DrawableImageState = 0;
  this->Transparent = transparent;
  this->pQueue.pObject = 0;
  this->MappedData.Format = Image_None;
  this->MappedData.Use = 0;
  this->MappedData.Flags = 0;
  this->MappedData.LevelCount = 0;
  this->MappedData.pPlanes = &this->MappedData.Plane0;
  this->MappedData.RawPlaneCount = 1;
  this->MappedData.pPalette.pObject = 0;
  this->MappedData.Plane0.Width = 0;
  this->MappedData.Plane0.Height = 0;
  this->MappedData.Plane0.Pitch = 0;
  this->MappedData.Plane0.DataSize = 0;
  this->MappedData.Plane0.pData = 0;
  this->pCPUModifiedNext.pObject = 0;
  this->pGPUModifiedNext.pObject = 0;
  if ( originalData )
    originalData->AddRef(originalData);
  this->pDelegateImage.pObject = originalData;
  if ( dicontext )
    Scaleform::RefCountImpl::AddRef(dicontext);
  this->pContext.pObject = (Scaleform::Render::DrawableImageContext *)dicontext;
  this->pRT.pObject = 0;
  this->pFence.pObject = 0;
  v5 = ((int (__thiscall *)(Scaleform::Render::ImageBase *))originalData->GetSize)(originalData);
  v6 = ((int (__thiscall *)(Scaleform::Render::ImageBase *, int))originalData->GetFormat)(originalData, v5);
  Scaleform::Render::DrawableImage::initialize(this, v6, &size, (int)dicontext);
}
