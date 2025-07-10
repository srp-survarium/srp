Scaleform::Render::Color *__thiscall Scaleform::GFx::DrawTextImpl::GetBorderColor(
        Scaleform::GFx::DrawTextImpl *this,
        Scaleform::Render::Color *result)
{
  Scaleform::Render::TreeText::GetBorderColor(this->pTextNode.pObject, result);
  return result;
}
