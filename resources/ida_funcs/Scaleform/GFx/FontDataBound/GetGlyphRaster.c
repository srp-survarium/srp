int __thiscall Scaleform::GFx::FontDataBound::GetGlyphRaster(
        Scaleform::GFx::FontDataBound *this,
        unsigned int glyphIndex,
        unsigned int hintedSize,
        Scaleform::Render::GlyphRaster *raster)
{
  return ((int (__thiscall *)(Scaleform::Render::Font *, unsigned int, unsigned int, Scaleform::Render::GlyphRaster *))this->pFont.pObject->GetGlyphRaster)(
           this->pFont.pObject,
           glyphIndex,
           hintedSize,
           raster);
}
