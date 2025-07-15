void __thiscall Scaleform::GFx::TextField::SetYScale(Scaleform::GFx::TextField *this, double yscale)
{
  Scaleform::Render::TreeText *RenderNode; // eax

  this->Flags |= 0x2000u;
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
  Scaleform::GFx::DisplayObjectBase::SetYScale(this, yscale);
}
