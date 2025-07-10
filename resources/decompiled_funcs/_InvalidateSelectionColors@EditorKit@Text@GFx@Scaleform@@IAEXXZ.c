void __thiscall Scaleform::GFx::Text::EditorKit::InvalidateSelectionColors(Scaleform::GFx::Text::EditorKit *this)
{
  if ( (this->Flags & 0x400) != 0 )
  {
    Scaleform::Render::Text::DocView::SetSelectionTextColor(this->pDocView.pObject, this->ActiveSelectionTextColor);
    Scaleform::Render::Text::DocView::SetSelectionBackgroundColor(this->pDocView.pObject, this->ActiveSelectionBkColor);
  }
  else
  {
    Scaleform::Render::Text::DocView::SetSelectionTextColor(this->pDocView.pObject, this->InactiveSelectionTextColor);
    Scaleform::Render::Text::DocView::SetSelectionBackgroundColor(
      this->pDocView.pObject,
      this->InactiveSelectionBkColor);
  }
}
