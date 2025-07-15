unsigned int *__thiscall Scaleform::Render::Text::ParagraphFormat::GetTabStops(
        Scaleform::Render::Text::ParagraphFormat *this,
        unsigned int *pnum)
{
  unsigned int *pTabStops; // eax

  pTabStops = this->pTabStops;
  if ( !pTabStops )
    return 0;
  if ( pnum )
    *pnum = *pTabStops;
  return this->pTabStops + 1;
}
