Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::FontDataBound::GetGlyphBounds(
        Scaleform::GFx::FontDataBound *this,
        unsigned int glyphIndex,
        Scaleform::Render::Rect<float> *prect)
{
  return this->pFont.pObject->GetGlyphBounds(this->pFont.pObject, glyphIndex, prect);
}
