double __thiscall Scaleform::GFx::FontData::GetTextureGlyphHeight(Scaleform::GFx::FontData *this)
{
  Scaleform::GFx::TextureGlyphData *pObject; // eax

  pObject = this->pTGData.pObject;
  if ( !pObject )
    return (float)0.0;
  return (float)((double)pObject->PackTextureConfig.NominalSize * 1024.0 / 1536.0);
}
