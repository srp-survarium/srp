void __thiscall Scaleform::GFx::DrawTextImpl::SetVAlignment(
        Scaleform::GFx::DrawTextImpl *this,
        Scaleform::GFx::DrawText::VAlignment a)
{
  Scaleform::Render::TreeText::SetVAlignment(this->pTextNode.pObject, a);
}
