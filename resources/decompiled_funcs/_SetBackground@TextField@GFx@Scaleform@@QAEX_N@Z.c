void __thiscall Scaleform::GFx::TextField::SetBackground(Scaleform::GFx::TextField *this, bool b)
{
  Scaleform::Render::Text::DocView *pObject; // eax
  Scaleform::Render::TreeText *RenderNode; // eax
  Scaleform::Render::TreeText *v5; // eax
  Scaleform::Render::Color c; // [esp+4h] [ebp-4h]

  pObject = this->pDocument.pObject;
  c = (Scaleform::Render::Color)pObject->BackgroundColor;
  c.Channels.Alpha = -b;
  pObject->BackgroundColor = c.Raw;
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
  v5 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(v5);
}
