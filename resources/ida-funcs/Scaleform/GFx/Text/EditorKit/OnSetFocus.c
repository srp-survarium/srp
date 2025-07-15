void __thiscall Scaleform::GFx::Text::EditorKit::OnSetFocus(Scaleform::GFx::Text::EditorKit *this)
{
  Scaleform::Render::Text::DocView::SetSelectionTextColor(this->pDocView.pObject, this->ActiveSelectionTextColor);
  Scaleform::Render::Text::DocView::SetSelectionBackgroundColor(this->pDocView.pObject, this->ActiveSelectionBkColor);
  this->Flags |= 0x400u;
}
