Scaleform::String *__thiscall Scaleform::GFx::FontDataBound::GetCharRanges(
        Scaleform::GFx::FontDataBound *this,
        Scaleform::String *result)
{
  this->pFont.pObject->GetCharRanges(this->pFont.pObject, result);
  return result;
}
