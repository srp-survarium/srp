void __thiscall Scaleform::GFx::Text::EditorKit::SetSelection(
        Scaleform::GFx::Text::EditorKit *this,
        unsigned int startPos,
        unsigned int endPos)
{
  if ( !this->IsReadOnly(this) || (this->Flags & 2) != 0 )
    Scaleform::GFx::Text::EditorKit::SetCursorPos(this, endPos, (this->Flags & 2) != 0);
  Scaleform::Render::Text::DocView::SetSelection(this->pDocView.pObject, startPos, endPos, (this->Flags & 2) != 0);
}
