void __thiscall Scaleform::Render::TextureManager::BeginFrame(Scaleform::Render::TextureManager *this)
{
  Scaleform::Render::TextureCache *pObject; // ecx

  this->ProcessQueues(this);
  pObject = this->pTextureCache.pObject;
  if ( pObject )
    pObject->BeginFrame(pObject);
}
