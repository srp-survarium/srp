char __thiscall Scaleform::Render::Texture::Map(
        Scaleform::Render::Texture *this,
        Scaleform::Render::ImageData *pdata,
        unsigned int mipLevel,
        unsigned int levelCount)
{
  unsigned int v4; // ebx
  Scaleform::Render::TextureManagerLocks *pObject; // eax
  Scaleform::Render::TextureManager *pManager; // ecx
  Scaleform::Render::MappedTextureBase *pMap; // eax
  Scaleform::Render::ImagePlane *pPlanes; // ebp
  unsigned int mipLevela; // [esp+10h] [ebp+8h]
  Scaleform::Render::ImageFormat levelCounta; // [esp+14h] [ebp+Ch]

  v4 = levelCount;
  if ( !levelCount )
    v4 = this->MipLevels - mipLevel;
  pObject = this->pManagerLocks.pObject;
  if ( pObject )
    pManager = pObject->pManager;
  else
    pManager = 0;
  if ( !pManager->mapTexture(pManager, this, mipLevel, v4) )
    return 0;
  pMap = this->pMap;
  pPlanes = pMap->Data.pPlanes;
  mipLevela = pMap->Data.RawPlaneCount;
  levelCounta = this->GetImageFormat(this);
  Scaleform::Render::ImageData::Clear(pdata);
  pdata->Flags |= 1u;
  pdata->Format = levelCounta;
  pdata->LevelCount = v4;
  pdata->pPlanes = pPlanes;
  pdata->RawPlaneCount = mipLevela;
  if ( pPlanes )
  {
    if ( mipLevela == 1 )
      pdata->Plane0 = *pPlanes;
  }
  pdata->Use = this->Use;
  return 1;
}
