void __thiscall Scaleform::Render::Text::DocView::SetSelectionBackgroundColor(
        Scaleform::Render::Text::DocView *this,
        unsigned int color)
{
  Scaleform::Render::Text::HighlightInfo *p_Info; // eax
  Scaleform::Render::Text::HighlightInfo *v4; // edi
  Scaleform::Render::Text::DocView::HighlightDescLoc *pHighlight; // eax
  _BYTE v6[4]; // [esp+8h] [ebp-4h] BYREF

  p_Info = &Scaleform::Render::Text::DocView::GetSelectionHighlighterDesc(this)->Info;
  if ( (p_Info->Flags & 8) != 0 )
  {
    v4 = p_Info;
  }
  else
  {
    v6[2] = 0;
    v6[1] = 0;
    v6[0] = 0;
    v6[3] = 0;
    v4 = (Scaleform::Render::Text::HighlightInfo *)v6;
  }
  if ( v4->BackgroundColor.Raw != color )
  {
    p_Info->Flags |= 8u;
    p_Info->BackgroundColor.Raw = color;
    pHighlight = this->pHighlight;
    pHighlight->HighlightManager.Valid = 0;
    pHighlight->HighlightManager.HasUnderline = 0;
  }
}
