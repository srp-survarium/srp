void __thiscall Scaleform::GFx::TextureGlyphData::TextureGlyphData(
        Scaleform::GFx::TextureGlyphData *this,
        unsigned int glyphCount,
        bool isLoadedFromFile)
{
  Scaleform::ArrayLH<Scaleform::Render::TextureGlyph,261,Scaleform::ArrayDefaultPolicy> *p_TextureGlyphs; // edi
  unsigned int Size; // ebx

  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::TextureGlyphData_vtbl *)&Scaleform::GFx::TextureGlyphData::`vftable';
  this->PackTextureConfig.NominalSize = 48;
  this->PackTextureConfig.PadPixels = 3;
  this->PackTextureConfig.TextureWidth = 1024;
  this->PackTextureConfig.TextureHeight = 1024;
  p_TextureGlyphs = &this->TextureGlyphs;
  this->TextureGlyphs.Data.Data = 0;
  this->TextureGlyphs.Data.Size = 0;
  this->TextureGlyphs.Data.Policy.Capacity = 0;
  this->GlyphsTextures.mHash.pTable = 0;
  this->FileCreation = isLoadedFromFile;
  Size = this->TextureGlyphs.Data.Size;
  Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorLH<Scaleform::Render::TextureGlyph,261>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->TextureGlyphs.Data,
    &this->TextureGlyphs,
    glyphCount);
  if ( glyphCount > Size )
    Scaleform::ConstructorMov<Scaleform::Render::TextureGlyph>::ConstructArray(
      (char *)&p_TextureGlyphs->Data.Data[Size],
      glyphCount - Size);
}
