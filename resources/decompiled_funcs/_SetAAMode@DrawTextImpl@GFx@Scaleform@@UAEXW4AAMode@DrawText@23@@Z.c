void __thiscall Scaleform::GFx::DrawTextImpl::SetAAMode(
        Scaleform::GFx::DrawTextImpl *this,
        Scaleform::GFx::DrawText::AAMode aa)
{
  Scaleform::Render::TreeText::SetAAMode(this->pTextNode.pObject, aa);
}
