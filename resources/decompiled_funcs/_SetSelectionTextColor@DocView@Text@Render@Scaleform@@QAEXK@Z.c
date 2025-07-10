void __thiscall Scaleform::Render::Text::DocView::SetSelectionTextColor(
        Scaleform::Render::Text::DocView *this,
        unsigned int color)
{
  Scaleform::Render::Text::HighlightDesc *SelectionHighlighterDesc; // eax
  unsigned int *p_Raw; // edi
  Scaleform::Render::Text::DocView::HighlightDescLoc *pHighlight; // eax
  _BYTE v6[4]; // [esp+8h] [ebp-4h] BYREF

  SelectionHighlighterDesc = Scaleform::Render::Text::DocView::GetSelectionHighlighterDesc(this);
  if ( (SelectionHighlighterDesc->Info.Flags & 0x10) != 0 )
  {
    p_Raw = &SelectionHighlighterDesc->Info.TextColor.Raw;
  }
  else
  {
    v6[2] = 0;
    v6[1] = 0;
    v6[0] = 0;
    v6[3] = 0;
    p_Raw = (unsigned int *)v6;
  }
  if ( *p_Raw != color )
  {
    SelectionHighlighterDesc->Info.Flags |= 0x10u;
    SelectionHighlighterDesc->Info.TextColor.Raw = color;
    pHighlight = this->pHighlight;
    pHighlight->HighlightManager.Valid = 0;
    pHighlight->HighlightManager.HasUnderline = 0;
  }
}
