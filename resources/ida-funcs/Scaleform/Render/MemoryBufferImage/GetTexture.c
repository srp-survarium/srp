Scaleform::Render::Texture *__thiscall Scaleform::Render::MemoryBufferImage::GetTexture(
        Scaleform::Render::MemoryBufferImage *this,
        Scaleform::Render::TextureManager *pmanager)
{
  Scaleform::AtomicPtr<Scaleform::Render::Texture> *p_pTexture; // eax
  Scaleform::Render::TextureManagerLocks *pObject; // ecx
  Scaleform::Render::TextureManager *v5; // ecx
  Scaleform::Render::Texture *v7; // edi

  p_pTexture = &this->pTexture;
  if ( this->pTexture.Value )
  {
    pObject = p_pTexture->Value->pManagerLocks.pObject;
    v5 = pObject ? pObject->pManager : 0;
    if ( v5 == pmanager )
      return p_pTexture->Value;
  }
  InterlockedExchange((volatile LONG *)&this->pTexture, 0);
  v7 = pmanager->CreateTexture(pmanager, this->Format, 1, &this->Size, this->Use, this, 0);
  Scaleform::Render::Image::initTexture_NoAddRef(this, v7);
  return v7;
}
