void __thiscall Scaleform::GFx::TextField::SetBackgroundColor(Scaleform::GFx::TextField *this, unsigned int rgb)
{
  Scaleform::Render::TreeText *RenderNode; // eax

  this->pDocument.pObject->BackgroundColor ^= (rgb ^ this->pDocument.pObject->BackgroundColor) & 0xFFFFFF;
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
}
