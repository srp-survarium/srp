Scaleform::GFx::DrawText::Alignment __thiscall Scaleform::GFx::DrawTextImpl::GetAlignment(
        Scaleform::GFx::DrawTextImpl *this)
{
  return Scaleform::Render::TreeText::GetAlignment(this->pTextNode.pObject);
}
