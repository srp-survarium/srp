void __thiscall Scaleform::Render::Text::DocView::SetSelection(
        Scaleform::Render::Text::DocView *this,
        unsigned int startPos,
        unsigned int endPos,
        int highlightSelection)
{
  bool v4; // zf
  unsigned int v5; // ebp
  unsigned int v6; // edi
  Scaleform::Render::Text::Highlighter *v8; // eax
  Scaleform::Render::Text::DocView::HighlightDescLoc *v9; // ebx
  Scaleform::Render::Text::HighlightDesc *SelectionHighlighterDesc; // eax
  unsigned int v11; // edi
  Scaleform::Render::Text::DocView::HighlightDescLoc *pHighlight; // esi

  v4 = (_BYTE)highlightSelection == 0;
  v5 = startPos;
  v6 = endPos;
  this->BeginSelection = startPos;
  this->EndSelection = endPos;
  if ( !v4 )
  {
    if ( !this->pHighlight )
    {
      highlightSelection = 78;
      v8 = (Scaleform::Render::Text::Highlighter *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     this,
                                                     40,
                                                     &highlightSelection);
      v9 = (Scaleform::Render::Text::DocView::HighlightDescLoc *)v8;
      if ( v8 )
      {
        Scaleform::Render::Text::Highlighter::Highlighter(v8);
        v9->HScrollOffset = -1.0;
        v9->VScrollOffset = -1.0;
        v9->FormatCounter = 0;
      }
      else
      {
        v9 = 0;
      }
      this->pHighlight = v9;
    }
    if ( endPos < startPos )
    {
      v6 = startPos;
      v5 = endPos;
    }
    SelectionHighlighterDesc = Scaleform::Render::Text::DocView::GetSelectionHighlighterDesc(this);
    v11 = v6 - v5;
    if ( SelectionHighlighterDesc->StartPos != v5 || SelectionHighlighterDesc->Length != v11 )
    {
      SelectionHighlighterDesc->StartPos = v5;
      SelectionHighlighterDesc->Length = v11;
      pHighlight = this->pHighlight;
      pHighlight->HighlightManager.Valid = 0;
      pHighlight->HighlightManager.HasUnderline = 0;
    }
  }
}
