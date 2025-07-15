Scaleform::Render::Color *__thiscall Scaleform::GFx::DrawTextImpl::GetBackgroundColor(
        Scaleform::GFx::DrawTextImpl *this,
        Scaleform::Render::Color *result)
{
  Scaleform::Render::TreeText::GetBackgroundColor(this->pTextNode.pObject, result);
  return result;
}
