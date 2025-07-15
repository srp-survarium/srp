void __thiscall Scaleform::GFx::TextField::SetRotation(Scaleform::GFx::TextField *this, long double rotation)
{
  Scaleform::Render::TreeText *RenderNode; // eax

  this->Flags |= 0x2000u;
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
  Scaleform::GFx::DisplayObjectBase::SetRotation(this, rotation);
}
