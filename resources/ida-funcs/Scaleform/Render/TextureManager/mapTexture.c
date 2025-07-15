Scaleform::Render::MappedTextureBase *__thiscall Scaleform::Render::TextureManager::mapTexture(
        Scaleform::Render::TextureManager *this,
        Scaleform::Render::Texture *p)
{
  return this->mapTexture(this, p, 0, p->MipLevels);
}


Scaleform::Render::MappedTextureBase *__thiscall Scaleform::Render::TextureManager::mapTexture(
        Scaleform::Render::TextureManager *this,
        Scaleform::Render::Texture *ptexture,
        unsigned int mipLevel,
        unsigned int levelCount)
{
  Scaleform::Render::MappedTextureBase *v5; // ebx
  Scaleform::Render::MappedTextureBase *v6; // esi

  v5 = this->getDefaultMappedTexture(this);
  InterlockedCompareExchange(&v5->LevelCount, -1, 0);
  if ( v5->LevelCount == -1 )
  {
    v6 = v5;
  }
  else
  {
    v6 = this->createMappedTexture(this);
    if ( !v6 )
      return 0;
  }
  if ( v6->Map(v6, ptexture, mipLevel, levelCount) )
    return v6;
  if ( v6 != v5 )
    ((void (__thiscall *)(Scaleform::Render::MappedTextureBase *, int))v6->~Scaleform::Render::MappedTextureBase)(v6, 1);
  return 0;
}
