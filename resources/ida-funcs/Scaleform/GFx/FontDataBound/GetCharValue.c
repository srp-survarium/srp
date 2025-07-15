int __thiscall Scaleform::GFx::FontDataBound::GetCharValue(
        Scaleform::GFx::FontDataBound *this,
        unsigned int glyphIndex)
{
  return this->pFont.pObject->GetCharValue(this->pFont.pObject, glyphIndex);
}
