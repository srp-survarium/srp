char __thiscall Scaleform::Render::Text::DocView::SetVScrollOffset(
        Scaleform::Render::Text::DocView *this,
        unsigned int vscroll)
{
  unsigned int MaxVScroll; // eax
  unsigned int v4; // edi
  Scaleform::Render::Text::DocView::DocumentListener *pObject; // ecx

  MaxVScroll = Scaleform::Render::Text::DocView::GetMaxVScroll(this);
  v4 = vscroll;
  if ( vscroll > MaxVScroll )
    v4 = MaxVScroll;
  if ( this->mLineBuffer.Geom.FirstVisibleLinePos == v4 )
    return 0;
  Scaleform::Render::Text::LineBuffer::SetFirstVisibleLine(&this->mLineBuffer, v4);
  pObject = this->pDocumentListener.pObject;
  if ( pObject )
    pObject->View_OnVScroll(pObject, this, v4);
  return 1;
}
