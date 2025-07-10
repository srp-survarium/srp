void __thiscall Scaleform::Render::Texture::LoseTextureData(Scaleform::Render::Texture *this)
{
  Scaleform::Render::ImageBase *pImage; // ecx
  Scaleform::Lock *p_ImageLock; // edi
  Scaleform::Render::ImageBase *v4; // ecx

  pImage = this->pImage;
  if ( pImage && pImage->GetImageType(pImage) == Type_DrawableImage )
    Scaleform::Render::DrawableImage::unmapTextureRT((Scaleform::Render::DrawableImage *)this->pImage);
  p_ImageLock = &this->pManagerLocks.pObject->ImageLock;
  EnterCriticalSection(&p_ImageLock->cs);
  this->ReleaseHWTextures(this, 0);
  v4 = this->pImage;
  this->State = State_Dead|State_Valid;
  if ( v4 )
    ((void (__thiscall *)(Scaleform::Render::ImageBase *, int))v4->__vftable[2].Release)(v4, 1);
  LeaveCriticalSection(&p_ImageLock->cs);
}
