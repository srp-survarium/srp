bool __thiscall Scaleform::GFx::DrawTextImpl::IsMultiline(Scaleform::GFx::DrawTextImpl *this)
{
  return Scaleform::Render::TreeText::IsMultiline(this->pTextNode.pObject);
}
