void __thiscall Scaleform::Render::DrawableImage::DrawableImage(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::ImageFormat format,
        Scaleform::Render::Size<unsigned long> size,
        bool transparent,
        Scaleform::Render::Color fillColor,
        Scaleform::Render::DrawableImageContext *dicontext)
{
  bool v7; // cl
  Scaleform::Render::DrawableImageContext *v8; // eax
  unsigned int Raw; // edi
  Scaleform::Render::DICommand_Clear cmd; // [esp+Ch] [ebp-Ch] BYREF

  this->__vftable = (Scaleform::Render::DrawableImage_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::DrawableImage_vtbl *)&Scaleform::Render::Image::`vftable';
  InterlockedExchange((volatile LONG *)&this->pTexture, 0);
  v7 = transparent;
  this->pUpdateSync = 0;
  this->pInverseMatrix = 0;
  this->__vftable = (Scaleform::Render::DrawableImage_vtbl *)&Scaleform::Render::DrawableImage::`vftable';
  this->Transparent = v7;
  this->DrawableImageState = 0;
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
  v8 = dicontext;
  this->pCPUModifiedNext.pObject = 0;
  this->pGPUModifiedNext.pObject = 0;
  this->pDelegateImage.pObject = 0;
  this->pContext.pObject = 0;
  this->pRT.pObject = 0;
  this->pFence.pObject = 0;
  Scaleform::Render::DrawableImage::initialize(this, format, &size, (int)v8);
  if ( !this->Transparent )
    fillColor.Channels.Alpha = -1;
  Raw = fillColor.Raw;
  this->AddRef(this);
  cmd.pImage.pObject = this;
  cmd.__vftable = (Scaleform::Render::DICommand_Clear_vtbl *)&Scaleform::Render::DICommand_Clear::`vftable';
  cmd.FillColor.Raw = Raw;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Clear>(this, &cmd);
  cmd.__vftable = (Scaleform::Render::DICommand_Clear_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( cmd.pImage.pObject )
    cmd.pImage.pObject->Release(cmd.pImage.pObject);
}
