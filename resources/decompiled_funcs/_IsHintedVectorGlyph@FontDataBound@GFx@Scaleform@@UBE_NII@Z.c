int __thiscall Scaleform::GFx::FontDataBound::IsHintedVectorGlyph(
        Scaleform::GFx::FontDataBound *this,
        unsigned int glyphIndex,
        unsigned int hintedSize)
{
  return ((int (__thiscall *)(Scaleform::Render::Font *, unsigned int, unsigned int))this->pFont.pObject->IsHintedVectorGlyph)(
           this->pFont.pObject,
           glyphIndex,
           hintedSize);
}
