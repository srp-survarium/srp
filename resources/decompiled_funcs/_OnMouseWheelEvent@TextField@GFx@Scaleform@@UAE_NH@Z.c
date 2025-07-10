char __thiscall Scaleform::GFx::TextField::OnMouseWheelEvent(Scaleform::GFx::TextField *this, int mwDelta)
{
  signed int MaxVScroll; // esi
  Scaleform::Render::TreeText *RenderNode; // eax

  if ( (this->Flags & 0x80) == 0 )
    return 0;
  MaxVScroll = Scaleform::Render::Text::DocView::GetVScrollOffset(this->pDocument.pObject) - mwDelta;
  if ( MaxVScroll < 0 )
    MaxVScroll = 0;
  if ( MaxVScroll > (int)Scaleform::Render::Text::DocView::GetMaxVScroll(this->pDocument.pObject) )
    MaxVScroll = Scaleform::Render::Text::DocView::GetMaxVScroll(this->pDocument.pObject);
  Scaleform::Render::Text::DocView::SetVScrollOffset(this->pDocument.pObject, MaxVScroll);
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
  return 1;
}
