void __thiscall Scaleform::GFx::TextField::SetDirtyFlag(Scaleform::GFx::TextField *this)
{
  Scaleform::Render::TreeText *RenderNode; // eax

  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
}
