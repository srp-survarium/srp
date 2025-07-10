void __thiscall Scaleform::GFx::Text::EditorKit::OnKillFocus(Scaleform::GFx::Text::EditorKit *this)
{
  Scaleform::Render::Text::DocView::SetSelectionTextColor(this->pDocView.pObject, this->InactiveSelectionTextColor);
  Scaleform::Render::Text::DocView::SetSelectionBackgroundColor(this->pDocView.pObject, this->InactiveSelectionBkColor);
  this->Flags &= 0xFB9Fu;
}
