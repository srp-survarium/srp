void __thiscall Scaleform::GFx::TextField::SetBorder(Scaleform::GFx::TextField *this, bool b)
{
  Scaleform::Render::Text::DocView *pObject; // eax
  Scaleform::Render::TreeText *RenderNode; // eax
  Scaleform::Render::TreeText *v5; // eax
  unsigned int BorderColor; // [esp+4h] [ebp-4h]

  pObject = this->pDocument.pObject;
  BorderColor = pObject->BorderColor;
  HIBYTE(BorderColor) = -b;
  pObject->BorderColor = BorderColor;
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
  v5 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(v5);
}
