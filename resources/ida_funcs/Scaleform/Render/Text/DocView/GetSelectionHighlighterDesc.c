Scaleform::Render::Text::HighlightDesc *__thiscall Scaleform::Render::Text::DocView::GetSelectionHighlighterDesc(
        Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::Highlighter *v2; // eax
  Scaleform::Render::Text::DocView::HighlightDescLoc *v3; // esi
  int v5; // [esp+4h] [ebp-4h] BYREF

  if ( !this->pHighlight )
  {
    v5 = 78;
    v2 = (Scaleform::Render::Text::Highlighter *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   this,
                                                   40,
                                                   &v5);
    v3 = (Scaleform::Render::Text::DocView::HighlightDescLoc *)v2;
    if ( v2 )
    {
      Scaleform::Render::Text::Highlighter::Highlighter(v2);
      v3->HScrollOffset = -1.0;
      v3->FormatCounter = 0;
      v3->VScrollOffset = -1.0;
      this->pHighlight = v3;
      return Scaleform::Render::Text::DocView::GetSelectionHighlighterDesc(this);
    }
    this->pHighlight = 0;
  }
  return Scaleform::Render::Text::DocView::GetSelectionHighlighterDesc(this);
}


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
