void __thiscall Scaleform::GFx::Text::EditorKit::OnDocumentChanged(
        Scaleform::GFx::Text::EditorKit *this,
        __int16 notifyMask)
{
  unsigned int Length; // eax

  if ( (notifyMask & 0x102) != 0 )
  {
    if ( !this->IsReadOnly(this) || (this->Flags & 2) != 0 )
      Scaleform::GFx::Text::EditorKit::SetCursorPos(this, 0, (this->Flags & 2) != 0);
  }
  else if ( this->CursorPos > Scaleform::Render::Text::StyledText::GetLength(this->pDocView.pObject->pDocument.pObject) )
  {
    Length = Scaleform::Render::Text::StyledText::GetLength(this->pDocView.pObject->pDocument.pObject);
    Scaleform::GFx::Text::EditorKit::SetCursorPos(this, Length, (this->Flags & 2) != 0);
  }
}
