void __thiscall Scaleform::Render::TextureManager::EndFrame(Scaleform::Render::TextureManager *this)
{
  Scaleform::Render::TextureCache *pObject; // ecx

  pObject = this->pTextureCache.pObject;
  if ( pObject )
    pObject->EndFrame(pObject);
}
