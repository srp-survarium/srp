void __thiscall Scaleform::GFx::TextField::SetXScale(Scaleform::GFx::TextField *this, long double xscale)
{
  Scaleform::Render::TreeText *RenderNode; // eax

  this->Flags |= 0x2000u;
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
  Scaleform::GFx::DisplayObjectBase::SetXScale(this, xscale);
}
