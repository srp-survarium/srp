void __thiscall Scaleform::GFx::FontDataBound::GetGlyphHeight(
        Scaleform::GFx::FontDataBound *this,
        unsigned int glyphIndex)
{
  this->pFont.pObject->GetGlyphHeight(this->pFont.pObject, glyphIndex);
}
