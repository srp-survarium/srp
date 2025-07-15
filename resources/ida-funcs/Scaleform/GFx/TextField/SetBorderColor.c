void __thiscall Scaleform::GFx::TextField::SetBorderColor(Scaleform::GFx::TextField *this, unsigned int rgb)
{
  Scaleform::Render::TreeText *RenderNode; // eax

  this->pDocument.pObject->BorderColor ^= (rgb ^ this->pDocument.pObject->BorderColor) & 0xFFFFFF;
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
}
