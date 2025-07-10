void __thiscall Scaleform::GFx::DrawTextImpl::SetAlignment(
        Scaleform::GFx::DrawTextImpl *this,
        Scaleform::GFx::DrawText::Alignment a)
{
  Scaleform::Render::TreeText::SetAlignment(this->pTextNode.pObject, a);
}
