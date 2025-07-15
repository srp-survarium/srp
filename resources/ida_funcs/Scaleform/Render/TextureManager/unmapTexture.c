void __thiscall Scaleform::Render::TextureManager::unmapTexture(
        Scaleform::Render::TextureManager *this,
        Scaleform::Render::Texture *ptexture,
        BOOL applyUpdate)
{
  Scaleform::Render::MappedTextureBase *pMap; // esi

  pMap = ptexture->pMap;
  pMap->Unmap(pMap, applyUpdate);
  if ( pMap != this->getDefaultMappedTexture(this) )
    ((void (__thiscall *)(Scaleform::Render::MappedTextureBase *, int))pMap->~Scaleform::Render::MappedTextureBase)(
      pMap,
      1);
}
