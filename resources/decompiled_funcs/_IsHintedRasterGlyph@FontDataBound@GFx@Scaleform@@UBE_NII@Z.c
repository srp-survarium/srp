int __thiscall Scaleform::GFx::FontDataBound::IsHintedRasterGlyph(
        Scaleform::GFx::FontDataBound *this,
        unsigned int glyphIndex,
        unsigned int hintedSize)
{
  return ((int (__thiscall *)(Scaleform::Render::Font *, unsigned int, unsigned int))this->pFont.pObject->IsHintedRasterGlyph)(
           this->pFont.pObject,
           glyphIndex,
           hintedSize);
}
