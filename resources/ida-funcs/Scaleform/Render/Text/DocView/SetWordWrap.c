void __thiscall Scaleform::Render::Text::DocView::SetWordWrap(Scaleform::Render::Text::DocView *this)
{
  unsigned __int8 Flags; // al

  Flags = this->Flags;
  if ( (Flags & 8) == 0 )
  {
    this->RTFlags |= 2u;
    this->Flags = Flags | 8;
  }
}
