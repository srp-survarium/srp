Scaleform::Render::Text::ParagraphFormat *__thiscall Scaleform::Render::Text::ParagraphFormat::Intersection(
        Scaleform::Render::Text::ParagraphFormat *this,
        Scaleform::Render::Text::ParagraphFormat *result,
        const Scaleform::Render::Text::ParagraphFormat *fmt)
{
  unsigned __int16 BlockIndent; // ax
  __int16 Indent; // ax
  __int16 Leading; // ax
  unsigned __int16 LeftMargin; // ax
  unsigned __int16 RightMargin; // ax
  unsigned int *pTabStops; // ebx

  result->RefCount = 1;
  result->pTabStops = 0;
  result->BlockIndent = 0;
  result->Indent = 0;
  result->Leading = 0;
  result->LeftMargin = 0;
  result->RightMargin = 0;
  result->PresentMask = 0;
  if ( (this->PresentMask & 1) != 0
    && (fmt->PresentMask & 1) != 0
    && ((fmt->PresentMask ^ this->PresentMask) & 0x600) == 0 )
  {
    result->PresentMask = (((fmt->PresentMask >> 9) & 3) << 9) | 1;
  }
  if ( (this->PresentMask & 0x80u) != 0
    && (fmt->PresentMask & 0x80u) != 0
    && ((this->PresentMask & 0x8000) != 0) == ((fmt->PresentMask & 0x8000) != 0) )
  {
    Scaleform::Render::Text::ParagraphFormat::SetBullet(result, (fmt->PresentMask & 0x8000u) != 0);
  }
  if ( (this->PresentMask & 2) != 0 && (fmt->PresentMask & 2) != 0 )
  {
    BlockIndent = fmt->BlockIndent;
    if ( this->BlockIndent == BlockIndent )
    {
      result->PresentMask |= 2u;
      result->BlockIndent = BlockIndent;
    }
  }
  if ( (this->PresentMask & 4) != 0 && (fmt->PresentMask & 4) != 0 )
  {
    Indent = fmt->Indent;
    if ( this->Indent == Indent )
    {
      result->PresentMask |= 4u;
      result->Indent = Indent;
    }
  }
  if ( (this->PresentMask & 8) != 0 && (fmt->PresentMask & 8) != 0 )
  {
    Leading = fmt->Leading;
    if ( this->Leading == Leading )
    {
      result->PresentMask |= 8u;
      result->Leading = Leading;
    }
  }
  if ( (this->PresentMask & 0x10) != 0 && (fmt->PresentMask & 0x10) != 0 )
  {
    LeftMargin = fmt->LeftMargin;
    if ( this->LeftMargin == LeftMargin )
    {
      result->PresentMask |= 0x10u;
      result->LeftMargin = LeftMargin;
    }
  }
  if ( (this->PresentMask & 0x20) != 0 && (fmt->PresentMask & 0x20) != 0 )
  {
    RightMargin = fmt->RightMargin;
    if ( this->RightMargin == RightMargin )
    {
      result->PresentMask |= 0x20u;
      result->RightMargin = RightMargin;
    }
  }
  if ( (this->PresentMask & 0x40) != 0 && (fmt->PresentMask & 0x40) != 0 )
  {
    pTabStops = fmt->pTabStops;
    if ( Scaleform::Render::Text::ParagraphFormat::TabStopsEqual(this, pTabStops) )
      Scaleform::Render::Text::ParagraphFormat::SetTabStops(result, pTabStops);
  }
  if ( (this->PresentMask & 0x100) != 0
    && (fmt->PresentMask & 0x100) != 0
    && ((fmt->PresentMask ^ this->PresentMask) & 0x1800) == 0 )
  {
    result->PresentMask = result->PresentMask ^ (result->PresentMask ^ (((fmt->PresentMask >> 11) & 3) << 11)) & 0x1800
                        | 0x100;
  }
  return result;
}
