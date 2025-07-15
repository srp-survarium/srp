void __thiscall Scaleform::GFx::DrawTextImpl::SetBackgroundColor(
        Scaleform::GFx::DrawTextImpl *this,
        const Scaleform::Render::Color *bkgColor)
{
  Scaleform::Render::TreeText::SetBackgroundColor(this->pTextNode.pObject, bkgColor);
}
