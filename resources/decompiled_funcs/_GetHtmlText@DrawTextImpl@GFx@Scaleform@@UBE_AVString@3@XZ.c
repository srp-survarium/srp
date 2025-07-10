Scaleform::String *__thiscall Scaleform::GFx::DrawTextImpl::GetHtmlText(
        Scaleform::GFx::DrawTextImpl *this,
        Scaleform::String *result)
{
  Scaleform::Render::TreeText::GetHtmlText(this->pTextNode.pObject, result);
  return result;
}
