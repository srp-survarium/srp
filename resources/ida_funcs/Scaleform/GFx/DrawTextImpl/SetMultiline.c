void __thiscall Scaleform::GFx::DrawTextImpl::SetMultiline(Scaleform::GFx::DrawTextImpl *this, bool multiline)
{
  Scaleform::Render::TreeText::SetMultiline(this->pTextNode.pObject, multiline);
}
