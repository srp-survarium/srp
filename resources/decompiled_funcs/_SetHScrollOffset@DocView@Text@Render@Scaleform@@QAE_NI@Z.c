char __thiscall Scaleform::Render::Text::DocView::SetHScrollOffset(
        Scaleform::Render::Text::DocView *this,
        unsigned int hscroll)
{
  unsigned int MaxHScrollValue; // eax
  unsigned int v4; // edi
  Scaleform::Render::Text::DocView::DocumentListener *pObject; // ecx

  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  MaxHScrollValue = Scaleform::Render::Text::DocView::GetMaxHScrollValue(this);
  v4 = hscroll;
  if ( hscroll > MaxHScrollValue )
    v4 = MaxHScrollValue;
  if ( this->mLineBuffer.Geom.HScrollOffset == v4 )
    return 0;
  Scaleform::Render::Text::LineBuffer::SetHScrollOffset(&this->mLineBuffer, v4);
  pObject = this->pDocumentListener.pObject;
  if ( pObject )
    pObject->View_OnHScroll(pObject, this, v4);
  return 1;
}
