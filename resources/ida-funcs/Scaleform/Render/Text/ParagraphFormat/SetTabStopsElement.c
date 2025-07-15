void __thiscall Scaleform::Render::Text::ParagraphFormat::SetTabStopsElement(
        Scaleform::Render::Text::ParagraphFormat *this,
        unsigned int idx,
        unsigned int val)
{
  unsigned int *pTabStops; // eax

  pTabStops = this->pTabStops;
  if ( pTabStops )
  {
    if ( idx < *pTabStops )
      pTabStops[idx + 1] = val;
  }
}
