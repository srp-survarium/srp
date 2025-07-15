void __thiscall Scaleform::Render::DICommand::ExecuteRT(
        Scaleform::Render::DICommand *this,
        Scaleform::Render::DICommandContext *context)
{
  char v3; // al
  Scaleform::Render::DICommandQueue *pObject; // ecx
  unsigned int (__thiscall *GetSourceImages)(Scaleform::Render::DICommand *, Scaleform::Render::DISourceImages *); // edx
  unsigned int v6; // edi
  Scaleform::Render::DrawableImage *v7; // edi
  Scaleform::Render::DISourceImages v8; // [esp+8h] [ebp-8h] BYREF

  v3 = this->GetRenderCaps(this);
  pObject = this->pImage.pObject->pQueue.pObject;
  if ( (v3 & 5) == 1 )
  {
    Scaleform::Render::DICommandQueue::updateGPUModifiedImagesRT(pObject);
    GetSourceImages = this->GetSourceImages;
    v8.pImages[0] = 0;
    v8.pImages[1] = 0;
    v6 = GetSourceImages(this, &v8);
    if ( (this->pImage.pObject->DrawableImageState & 3) != 0
      || Scaleform::Render::DrawableImage::mapTextureRT(this->pImage.pObject, 0, 0) )
    {
      Scaleform::Render::DICommand::executeSWHelper(this, context, this->pImage.pObject, &v8, v6);
    }
  }
  else
  {
    Scaleform::Render::DICommandQueue::updateCPUModifiedImagesRT(pObject);
    v7 = this->pImage.pObject;
    Scaleform::Render::DrawableImage::unmapTextureRT(v7);
    this->ExecuteHW(this, context);
    if ( (this->GetRenderCaps(this) & 0xA) == 2 )
      Scaleform::Render::DrawableImage::addToGPUModifiedListRT(v7);
  }
}
