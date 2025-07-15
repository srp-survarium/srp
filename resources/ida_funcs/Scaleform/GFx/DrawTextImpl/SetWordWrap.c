void __thiscall Scaleform::GFx::DrawTextImpl::SetWordWrap(Scaleform::GFx::DrawTextImpl *this, bool wordWrap)
{
  Scaleform::Render::TreeText::SetWordWrap(this->pTextNode.pObject, wordWrap);
}
