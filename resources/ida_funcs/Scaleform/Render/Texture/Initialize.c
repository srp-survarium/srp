char __thiscall Scaleform::Render::Texture::Initialize(Scaleform::Render::Texture *this)
{
  Scaleform::Render::TextureManagerLocks *pObject; // eax
  Scaleform::Render::TextureManager *pManager; // eax
  Scaleform::Render::TextureCache *v3; // eax

  pObject = this->pManagerLocks.pObject;
  if ( pObject )
    pManager = pObject->pManager;
  else
    pManager = 0;
  v3 = pManager->pTextureCache.pObject;
  if ( this->State == State_Dead && v3 )
    v3->TextureCreation(v3, this);
  return 1;
}
