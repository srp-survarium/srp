Scaleform::Render::Text::HighlightDesc *__thiscall Scaleform::Render::Text::DocView::GetSelectionHighlighterDesc(
        Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::DocView::HighlightDescLoc *pHighlight; // ecx
  Scaleform::Render::Text::HighlightDesc *result; // eax
  Scaleform::Render::Text::DocView::HighlightDescLoc *v4; // ecx
  Scaleform::Render::Text::HighlightDesc desc; // [esp+8h] [ebp-28h] BYREF

  pHighlight = this->pHighlight;
  if ( !pHighlight )
    return 0;
  result = Scaleform::Render::Text::Highlighter::GetHighlighterPtr(&pHighlight->HighlightManager, 0x7FFFFFFFu);
  if ( !result )
  {
    v4 = this->pHighlight;
    desc.Offset = -1;
    desc.Info.TextColor.Raw = -1;
    desc.AdjStartPos = 0;
    desc.GlyphNum = 0;
    desc.Info.UnderlineColor.Raw = 0;
    desc.StartPos = 0;
    desc.Length = 0;
    desc.Id = 0x7FFFFFFF;
    desc.Info.BackgroundColor.Raw = -16777216;
    desc.Info.Flags = 24;
    return Scaleform::Render::Text::Highlighter::CreateHighlighter(&v4->HighlightManager, &desc);
  }
  return result;
}
