Scaleform::String *__thiscall Scaleform::GFx::DrawTextImpl::GetText(
        Scaleform::GFx::DrawTextImpl *this,
        Scaleform::String *result)
{
  Scaleform::Render::TreeText::GetText(this->pTextNode.pObject, result);
  return result;
}
