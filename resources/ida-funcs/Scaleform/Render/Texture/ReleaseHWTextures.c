void __thiscall Scaleform::Render::Texture::ReleaseHWTextures(Scaleform::Render::Texture *this, bool __formal)
{
  Scaleform::Render::TextureManagerLocks *pObject; // eax
  Scaleform::Render::TextureManager *pManager; // eax
  Scaleform::Render::TextureCache *v4; // eax

  pObject = this->pManagerLocks.pObject;
  if ( pObject )
    pManager = pObject->pManager;
  else
    pManager = 0;
  v4 = pManager->pTextureCache.pObject;
  if ( v4 )
    v4->TextureEvicted(v4, this);
}
