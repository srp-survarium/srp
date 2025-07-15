Scaleform::Render::Texture *__thiscall Scaleform::Render::GradientImage::GetTexture(
        Scaleform::Render::GradientImage *this,
        Scaleform::Render::TextureManager *pmanager)
{
  Scaleform::AtomicPtr<Scaleform::Render::Texture> *p_pTexture; // eax
  Scaleform::Render::TextureManagerLocks *pObject; // ecx
  Scaleform::Render::TextureManager *v5; // ecx
  Scaleform::Render::TextureManager_vtbl *v7; // edi
  int v8; // eax
  Scaleform::Render::Texture *v9; // edi

  p_pTexture = &this->pTexture;
  if ( this->pTexture.Value )
  {
    pObject = p_pTexture->Value->pManagerLocks.pObject;
    v5 = pObject ? pObject->pManager : 0;
    if ( v5 == pmanager )
      return p_pTexture->Value;
  }
  if ( !pmanager )
    return 0;
  InterlockedExchange((volatile LONG *)&this->pTexture, 0);
  v7 = pmanager->Scaleform::RefCountBase<Scaleform::Render::TextureManager,75>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable;
  v8 = ((int (__thiscall *)(Scaleform::Render::GradientImage *, int, Scaleform::Render::Size<unsigned long> *, int, Scaleform::Render::GradientImage *, _DWORD))this->GetFormat)(
         this,
         1,
         &this->Size,
         1,
         this,
         0);
  v9 = (Scaleform::Render::Texture *)((int (__thiscall *)(Scaleform::Render::TextureManager *, int))v7->CreateTexture)(
                                       pmanager,
                                       v8);
  Scaleform::Render::Image::initTexture_NoAddRef(this, v9);
  return v9;
}
