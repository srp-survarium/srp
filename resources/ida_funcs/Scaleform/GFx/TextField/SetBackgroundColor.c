void __thiscall Scaleform::GFx::TextField::SetBackgroundColor(Scaleform::GFx::TextField *this, unsigned int rgb)
{
  Scaleform::Render::TreeText *RenderNode; // eax

  this->pDocument.pObject->BackgroundColor ^= (unsigned int)&vostok::memory::s_CRT_arena[5574199]
                                            & (rgb
                                             ^ this->pDocument.pObject->BackgroundColor);
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
}
