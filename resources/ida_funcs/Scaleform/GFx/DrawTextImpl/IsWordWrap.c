bool __thiscall Scaleform::GFx::DrawTextImpl::IsWordWrap(Scaleform::GFx::DrawTextImpl *this)
{
  return Scaleform::Render::TreeText::IsWordWrap(this->pTextNode.pObject);
}
