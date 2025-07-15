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
  int RawPlaneCount; // [esp+10h] [ebp+8h]
  Scaleform::Render::ImageFormat v12; // [esp+14h] [ebp+Ch]

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
  RawPlaneCount = pMap->Data.RawPlaneCount;
  v12 = this->GetImageFormat(this);
  Scaleform::Render::ImageData::Clear(pdata);
  pdata->Flags |= 1u;
  pdata->Format = v12;
  pdata->LevelCount = v4;
  pdata->pPlanes = pPlanes;
  pdata->RawPlaneCount = RawPlaneCount;
  if ( pPlanes )
  {
    if ( RawPlaneCount == 1 )
      pdata->Plane0 = *pPlanes;
  }
  pdata->Use = this->Use;
  return 1;
}
