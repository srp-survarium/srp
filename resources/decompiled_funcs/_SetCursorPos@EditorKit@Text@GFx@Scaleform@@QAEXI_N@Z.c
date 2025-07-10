void __thiscall Scaleform::GFx::Text::EditorKit::SetCursorPos(
        Scaleform::GFx::Text::EditorKit *this,
        unsigned int pos,
        bool selectionAllowed)
{
  unsigned int v3; // edi
  unsigned int Length; // eax
  Scaleform::Render::Text::DocView *pObject; // edx
  const Scaleform::Render::Text::LineBuffer::GlyphEntry *GlyphEntryAtIndex; // eax
  unsigned int CursorPos; // eax
  unsigned __int16 Flags; // ax
  Scaleform::Render::Text::DocView *v10; // ecx
  unsigned int v11; // edx
  unsigned int v12; // eax
  unsigned int v13; // edx
  Scaleform::Render::Text::DocView *v14; // ecx
  unsigned int EndSelection; // eax
  unsigned int BeginSelection; // edx
  unsigned int v17; // edi
  Scaleform::Render::Text::DocView::DocumentListener *v18; // ecx

  v3 = pos;
  if ( pos != -1 )
  {
    Length = Scaleform::Render::Text::StyledText::GetLength(this->pDocView.pObject->pDocument.pObject);
    if ( v3 > Length )
      v3 = Length;
    if ( this->IsReadOnly(this) )
      this->Flags &= ~8u;
    else
      this->Flags |= 8u;
    pObject = this->pDocView.pObject;
    this->CursorTimer = 0.0;
    if ( pObject->pImageSubstitutor )
    {
      GlyphEntryAtIndex = Scaleform::GFx::Text::EditorKit::GetGlyphEntryAtIndex(this, v3, &pos);
      if ( GlyphEntryAtIndex )
      {
        if ( (GlyphEntryAtIndex->LenAndFontSize & 0xF000) != 0x1000 && pos != v3 )
        {
          if ( v3 < this->CursorPos )
            v3 = pos;
          else
            v3 = pos + (GlyphEntryAtIndex->LenAndFontSize >> 12);
        }
      }
    }
  }
  this->CursorPos = v3;
  --this->CursorRect.FormatCounter;
  this->LastHorizCursorPos = -1.0;
  CursorPos = this->CursorPos;
  if ( CursorPos != -1 )
  {
    Scaleform::GFx::Text::EditorKit::ScrollToPosition(this, CursorPos, 1, this->Flags & 0x100);
    Scaleform::Render::Text::DocView::SetDefaultTextAndParaFormat(this->pDocView.pObject, this->CursorPos);
  }
  Flags = this->Flags;
  if ( (Flags & 2) != 0 )
  {
    if ( !selectionAllowed )
    {
      v12 = this->CursorPos;
      v10 = this->pDocView.pObject;
LABEL_32:
      Scaleform::Render::Text::DocView::SetSelection(v10, v12, v12, 1);
      goto LABEL_33;
    }
    if ( (Flags & 0x40) != 0 || (Flags & 0x20) != 0 )
    {
      v14 = this->pDocView.pObject;
      EndSelection = v14->EndSelection;
      BeginSelection = v14->BeginSelection;
      if ( EndSelection < BeginSelection )
        EndSelection = v14->BeginSelection;
      v17 = this->CursorPos;
      if ( EndSelection != v17 )
        Scaleform::Render::Text::DocView::SetSelection(v14, BeginSelection, v17, 1);
    }
    else
    {
      v10 = this->pDocView.pObject;
      v11 = v10->BeginSelection;
      if ( v11 >= v10->EndSelection )
        v11 = v10->EndSelection;
      v12 = this->CursorPos;
      if ( v11 != v12 )
        goto LABEL_32;
      v13 = v10->EndSelection;
      if ( v13 < v10->BeginSelection )
        v13 = v10->BeginSelection;
      if ( v13 != v12 )
        goto LABEL_32;
    }
  }
LABEL_33:
  v18 = this->pDocView.pObject->pDocumentListener.pObject;
  if ( v18 )
    v18->Editor_OnCursorMoved(v18, this);
}
