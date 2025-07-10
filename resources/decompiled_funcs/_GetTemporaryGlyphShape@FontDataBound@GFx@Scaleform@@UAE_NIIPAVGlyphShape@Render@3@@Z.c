int __thiscall Scaleform::GFx::FontDataBound::GetTemporaryGlyphShape(
        Scaleform::GFx::FontDataBound *this,
        unsigned int glyphIndex,
        unsigned int hintedSize,
        Scaleform::Render::GlyphShape *shape)
{
  return ((int (__thiscall *)(Scaleform::Render::Font *, unsigned int, unsigned int, Scaleform::Render::GlyphShape *))this->pFont.pObject->GetTemporaryGlyphShape)(
           this->pFont.pObject,
           glyphIndex,
           hintedSize,
           shape);
}
