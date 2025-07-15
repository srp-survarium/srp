void __thiscall Scaleform::Render::Text::DocView::UpdateHighlight(
        Scaleform::Render::Text::DocView *this,
        const Scaleform::Render::Text::HighlightDesc *desc)
{
  Scaleform::Render::Text::DocView::HighlightDescLoc *pHighlight; // eax

  pHighlight = this->pHighlight;
  if ( pHighlight )
  {
    pHighlight->HighlightManager.Valid = 0;
    pHighlight->HighlightManager.HasUnderline = 0;
  }
}
