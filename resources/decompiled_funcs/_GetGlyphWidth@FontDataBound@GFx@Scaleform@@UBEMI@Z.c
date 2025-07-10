void __thiscall Scaleform::GFx::FontDataBound::GetGlyphWidth(
        Scaleform::GFx::FontDataBound *this,
        unsigned int glyphIndex)
{
  this->pFont.pObject->GetGlyphWidth(this->pFont.pObject, glyphIndex);
}
