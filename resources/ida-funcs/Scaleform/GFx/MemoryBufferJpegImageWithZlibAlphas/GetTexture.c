Scaleform::Render::Texture *__thiscall Scaleform::GFx::MemoryBufferJpegImageWithZlibAlphas::GetTexture(
        Scaleform::GFx::MemoryBufferJpegImageWithZlibAlphas *this,
        Scaleform::Render::TextureManager *pmanager)
{
  Scaleform::AtomicPtr<Scaleform::Render::Texture> *p_pTexture; // eax
  Scaleform::Render::TextureManagerLocks *pObject; // ecx
  Scaleform::Render::TextureManager *v5; // ecx
  Scaleform::Render::TextureManager_vtbl *v7; // edi
  int v8; // eax
  int v9; // eax
  int v10; // eax
  Scaleform::Render::Texture *v11; // edi
  _UNKNOWN *retaddr; // [esp+10h] [ebp+0h] BYREF

  p_pTexture = &this->pTexture;
  if ( this->pTexture.Value )
  {
    pObject = p_pTexture->Value->pManagerLocks.pObject;
    v5 = pObject ? pObject->pManager : 0;
    if ( v5 == pmanager )
      return p_pTexture->Value;
  }
  InterlockedExchange((volatile LONG *)&this->pTexture, 0);
  v7 = pmanager->Scaleform::RefCountBase<Scaleform::Render::TextureManager,75>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable;
  v8 = ((int (__thiscall *)(Scaleform::GFx::MemoryBufferJpegImageWithZlibAlphas *, Scaleform::GFx::MemoryBufferJpegImageWithZlibAlphas *, _DWORD))this->GetUse)(
         this,
         this,
         0);
  v9 = ((int (__thiscall *)(Scaleform::GFx::MemoryBufferJpegImageWithZlibAlphas *, _UNKNOWN **, int))this->GetSize)(
         this,
         &retaddr,
         v8);
  v10 = ((int (__thiscall *)(Scaleform::GFx::MemoryBufferJpegImageWithZlibAlphas *, int, int))this->GetFormat)(
          this,
          1,
          v9);
  v11 = (Scaleform::Render::Texture *)((int (__thiscall *)(Scaleform::Render::TextureManager *, int))v7->CreateTexture)(
                                        pmanager,
                                        v10);
  Scaleform::Render::Image::initTexture_NoAddRef(this, v11);
  return v11;
}
