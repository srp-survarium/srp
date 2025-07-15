void __thiscall Scaleform::GFx::TextField::SetBorderColor(Scaleform::GFx::TextField *this, unsigned int rgb)
{
  Scaleform::Render::TreeText *RenderNode; // eax

  this->pDocument.pObject->BorderColor ^= (unsigned int)&vostok::memory::s_CRT_arena[5574199]
                                        & (rgb
                                         ^ this->pDocument.pObject->BorderColor);
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
}
