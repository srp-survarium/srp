Scaleform::Render::RawImage *__thiscall Scaleform::Render::GlyphCache::GetImage(
        Scaleform::Render::GlyphCache *this,
        unsigned int textureId)
{
  Scaleform::Render::GlyphTextureMapper *v2; // ecx
  Scaleform::Render::RawImage *result; // eax

  v2 = &this->Textures[textureId];
  result = v2->pRawImg.pObject;
  if ( !result )
    return (Scaleform::Render::RawImage *)v2->pTexImg.pObject;
  return result;
}
