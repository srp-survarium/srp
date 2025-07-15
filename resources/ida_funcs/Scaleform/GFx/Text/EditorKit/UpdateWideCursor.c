void __thiscall Scaleform::GFx::Text::EditorKit::UpdateWideCursor(Scaleform::GFx::Text::EditorKit *this)
{
  Scaleform::Render::Text::DocView::HighlightDescLoc *HighlighterManager; // edi
  Scaleform::Render::Text::HighlightDesc *HighlighterPtr; // eax
  bool v4; // bl
  unsigned int CursorPos; // edi
  Scaleform::Render::Text::HighlightDesc desc; // [esp+4h] [ebp-28h] BYREF

  if ( !this->IsReadOnly(this) && (this->Flags & 0x100) != 0 )
  {
    HighlighterManager = Scaleform::Render::Text::DocView::CreateHighlighterManager(this->pDocView.pObject);
    HighlighterPtr = Scaleform::Render::Text::Highlighter::GetHighlighterPtr(
                       &HighlighterManager->HighlightManager,
                       0x7FFFFFFEu);
    v4 = 0;
    if ( HighlighterPtr )
    {
      v4 = HighlighterPtr->Length != 0;
    }
    else
    {
      desc.Info.UnderlineColor.Raw = 0;
      memset(&desc, 0, 20);
      desc.Id = 2147483646;
      desc.Info.BackgroundColor.Raw = -16777216;
      desc.Info.Flags = 24;
      desc.Info.TextColor.Raw = -1;
      HighlighterPtr = Scaleform::Render::Text::Highlighter::CreateHighlighter(
                         &HighlighterManager->HighlightManager,
                         &desc);
    }
    CursorPos = this->CursorPos;
    if ( HighlighterPtr->StartPos != CursorPos || v4 != ((this->Flags & 8) != 0) )
    {
      HighlighterPtr->StartPos = CursorPos;
      HighlighterPtr->Length = (this->Flags >> 3) & 1;
      Scaleform::Render::Text::DocView::UpdateHighlight(this->pDocView.pObject, HighlighterPtr);
    }
  }
}
