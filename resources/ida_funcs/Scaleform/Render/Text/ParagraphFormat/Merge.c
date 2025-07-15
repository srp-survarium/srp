Scaleform::Render::Text::ParagraphFormat *__thiscall Scaleform::Render::Text::ParagraphFormat::Merge(
        Scaleform::Render::Text::ParagraphFormat *this,
        Scaleform::Render::Text::ParagraphFormat *result,
        const Scaleform::Render::Text::ParagraphFormat *fmt)
{
  unsigned __int16 BlockIndent; // ax
  __int16 Indent; // ax
  __int16 Leading; // ax
  unsigned __int16 LeftMargin; // ax
  unsigned __int16 RightMargin; // ax
  unsigned int *pTabStops; // eax

  Scaleform::Render::Text::ParagraphFormat::ParagraphFormat(result, this);
  if ( (fmt->PresentMask & 1) != 0 )
    result->PresentMask = result->PresentMask ^ (result->PresentMask ^ (((fmt->PresentMask >> 9) & 3) << 9)) & 0x600 | 1;
  if ( (fmt->PresentMask & 0x80u) != 0 )
  {
    if ( (fmt->PresentMask & 0x8000) != 0 )
      result->PresentMask |= 0x8000u;
    else
      result->PresentMask &= ~0x8000u;
    result->PresentMask |= 0x80u;
  }
  if ( (fmt->PresentMask & 2) != 0 )
  {
    BlockIndent = fmt->BlockIndent;
    result->PresentMask |= 2u;
    result->BlockIndent = BlockIndent;
  }
  if ( (fmt->PresentMask & 4) != 0 )
  {
    Indent = fmt->Indent;
    result->PresentMask |= 4u;
    result->Indent = Indent;
  }
  if ( (fmt->PresentMask & 8) != 0 )
  {
    Leading = fmt->Leading;
    result->PresentMask |= 8u;
    result->Leading = Leading;
  }
  if ( (fmt->PresentMask & 0x10) != 0 )
  {
    LeftMargin = fmt->LeftMargin;
    result->PresentMask |= 0x10u;
    result->LeftMargin = LeftMargin;
  }
  if ( (fmt->PresentMask & 0x20) != 0 )
  {
    RightMargin = fmt->RightMargin;
    result->PresentMask |= 0x20u;
    result->RightMargin = RightMargin;
  }
  if ( (fmt->PresentMask & 0x40) != 0 )
  {
    pTabStops = fmt->pTabStops;
    if ( pTabStops && *pTabStops )
    {
      Scaleform::Render::Text::ParagraphFormat::CopyTabStops(result, fmt->pTabStops);
      result->PresentMask |= 0x40u;
    }
    else
    {
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, result->pTabStops);
      result->PresentMask &= ~0x40u;
      result->pTabStops = 0;
    }
  }
  if ( (fmt->PresentMask & 0x100) != 0 )
    result->PresentMask = result->PresentMask ^ (result->PresentMask ^ (((fmt->PresentMask >> 11) & 3) << 11)) & 0x1800
                        | 0x100;
  return result;
}
