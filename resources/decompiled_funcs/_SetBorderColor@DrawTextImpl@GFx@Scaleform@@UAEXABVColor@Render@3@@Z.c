void __thiscall Scaleform::GFx::DrawTextImpl::SetBorderColor(
        Scaleform::GFx::DrawTextImpl *this,
        const Scaleform::Render::Color *borderColor)
{
  Scaleform::Render::TreeText::SetBorderColor(this->pTextNode.pObject, borderColor);
}
