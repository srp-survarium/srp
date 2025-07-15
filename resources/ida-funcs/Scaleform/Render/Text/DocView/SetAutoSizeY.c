void __thiscall Scaleform::Render::Text::DocView::SetAutoSizeY(Scaleform::Render::Text::DocView *this)
{
  unsigned __int8 Flags; // al

  Flags = this->Flags;
  if ( (Flags & 2) == 0 )
  {
    this->RTFlags |= 2u;
    this->Flags = Flags | 2;
  }
}
