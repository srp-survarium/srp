void __thiscall Scaleform::Render::Text::DocView::OnDocumentChanged(
        Scaleform::Render::Text::DocView *this,
        __int16 notifyMask)
{
  if ( (notifyMask & 0x100) != 0 )
    this->RTFlags |= 2u;
  else
    this->RTFlags |= 1u;
}
