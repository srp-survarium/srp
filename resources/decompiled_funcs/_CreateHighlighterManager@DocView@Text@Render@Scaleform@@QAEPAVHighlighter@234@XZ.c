Scaleform::Render::Text::DocView::HighlightDescLoc *__thiscall Scaleform::Render::Text::DocView::CreateHighlighterManager(
        Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::Highlighter *v2; // eax
  Scaleform::Render::Text::DocView::HighlightDescLoc *v3; // esi
  int v5; // [esp+4h] [ebp-4h] BYREF

  if ( this->pHighlight )
    return this->pHighlight;
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
    v3->VScrollOffset = -1.0;
    v3->FormatCounter = 0;
    this->pHighlight = v3;
    return v3;
  }
  else
  {
    this->pHighlight = 0;
    return 0;
  }
}
