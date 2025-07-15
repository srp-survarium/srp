int __thiscall Scaleform::Render::GlyphCache::GetTextureData(
        Scaleform::Render::GlyphCache *this,
        Scaleform::File *dataFile,
        unsigned int version)
{
  unsigned int v4; // ebx
  Scaleform::Ptr<Scaleform::Render::RawImage> *p_pRawImg; // esi
  Scaleform::Render::Image *pObject; // eax
  int v8; // [esp+8h] [ebp-4h]

  Scaleform::Render::AmpFileWriter::Instance.Version = version;
  this->pRQCaches->LockFlags |= 2u;
  v4 = 0;
  v8 = 0;
  if ( this->MaxNumTextures )
  {
    p_pRawImg = &this->Textures[0].pRawImg;
    do
    {
      if ( LOBYTE(p_pRawImg[-15].pObject) )
      {
        pObject = p_pRawImg->pObject;
        if ( !p_pRawImg->pObject )
          pObject = p_pRawImg[1].pObject;
        if ( Scaleform::Render::ImageFileWriter::writeImage(
               dataFile,
               &Scaleform::Render::AmpFileWriter::Instance,
               pObject,
               0) )
        {
          ++v8;
        }
      }
      ++v4;
      p_pRawImg += 20;
    }
    while ( v4 < this->MaxNumTextures );
  }
  this->pRQCaches->LockFlags &= ~2u;
  return v8;
}
