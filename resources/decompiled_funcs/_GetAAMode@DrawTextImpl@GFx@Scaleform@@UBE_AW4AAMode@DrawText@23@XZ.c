Scaleform::GFx::DrawText::AAMode __thiscall Scaleform::GFx::DrawTextImpl::GetAAMode(Scaleform::GFx::DrawTextImpl *this)
{
  return Scaleform::Render::TreeText::GetAAMode(this->pTextNode.pObject);
}
