void __thiscall Scaleform::Render::Texture::ApplyTexture(
        Scaleform::Render::Texture *this,
        unsigned int stage,
        const Scaleform::Render::ImageFillMode *fillMode)
{
  Scaleform::Render::TextureManagerLocks *pObject; // eax
  Scaleform::Render::TextureManager *pManager; // eax
  Scaleform::Render::TextureCache *v6; // ecx

  if ( this->State == (State_Dead|State_Valid) )
    this->Initialize(this);
  pObject = this->pManagerLocks.pObject;
  if ( pObject )
    pManager = pObject->pManager;
  else
    pManager = 0;
  v6 = pManager->pTextureCache.pObject;
  if ( v6 )
    v6->TextureReference(v6, this);
}
