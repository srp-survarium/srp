void Scaleform::GFx::TextureGlyphData::GetTextureGlyph_::_5_::_dynamic_atexit_destructor_for__dummyTextureGlyph__()
{
  if ( dummyTextureGlyph.pImage.pObject )
    dummyTextureGlyph.pImage.pObject->Release(dummyTextureGlyph.pImage.pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(&dummyTextureGlyph.Scaleform::RefCountBase<Scaleform::Render::TextureGlyph,2>);
}
