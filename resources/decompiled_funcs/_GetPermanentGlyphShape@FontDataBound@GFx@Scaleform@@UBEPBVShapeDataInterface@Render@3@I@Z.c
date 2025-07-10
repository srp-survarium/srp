const Scaleform::Render::ShapeDataInterface *__thiscall Scaleform::GFx::FontDataBound::GetPermanentGlyphShape(
        Scaleform::GFx::FontDataBound *this,
        unsigned int glyphIndex)
{
  return this->pFont.pObject->GetPermanentGlyphShape(this->pFont.pObject, glyphIndex);
}
