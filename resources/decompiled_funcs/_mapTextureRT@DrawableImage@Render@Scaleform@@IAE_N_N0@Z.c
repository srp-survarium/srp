bool __thiscall Scaleform::Render::DrawableImage::mapTextureRT(
        Scaleform::Render::DrawableImage *this,
        bool readOnly,
        bool forceRemap)
{
  Scaleform::Lock *p_QueueLock; // edi
  volatile unsigned int DrawableImageState; // ebx

  p_QueueLock = &this->pQueue.pObject->QueueLock;
  EnterCriticalSection(&p_QueueLock->cs);
  if ( readOnly
    && Scaleform::Render::DrawableImage::MapImageSource(
         &this->MappedData,
         (Scaleform::Render::DrawableImage *)this->pDelegateImage.pObject) )
  {
    this->DrawableImageState |= 2u;
  }
  else
  {
    if ( this->pDelegateImage.pObject && !Scaleform::Render::DrawableImage::ensureRenderableRT(this) )
    {
      LeaveCriticalSection(&p_QueueLock->cs);
      return 0;
    }
    if ( this->pTexture.Value && this->pTexture.Value->Map(this->pTexture.Value, &this->MappedData, 0, 0) )
      this->DrawableImageState |= 3u;
    if ( forceRemap )
      this->DrawableImageState |= 0x40u;
  }
  DrawableImageState = this->DrawableImageState;
  LeaveCriticalSection(&p_QueueLock->cs);
  return (DrawableImageState & 3) != 0;
}
