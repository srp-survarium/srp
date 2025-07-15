void __thiscall Scaleform::GFx::Text::EditorKit::Advance(Scaleform::GFx::Text::EditorKit *this, long double timer)
{
  unsigned __int8 (*IsReadOnly)(void); // edx
  long double v5; // st7
  unsigned __int16 Flags; // ax
  unsigned __int16 v7; // ax
  Scaleform::Render::Text::DocView::DocumentListener *pObject; // ecx
  const Scaleform::Render::Rect<float> *ViewRect; // eax
  Scaleform::Render::Text::DocView *v10; // ecx
  unsigned int FirstVisibleLinePos; // eax
  unsigned int v12; // eax
  unsigned int v13; // edi
  unsigned int CursorPosInLine; // eax
  double v15; // [esp+18h] [ebp+4h]
  double y; // [esp+18h] [ebp+4h]
  double v17; // [esp+18h] [ebp+4h]

  IsReadOnly = (unsigned __int8 (*)(void))this->IsReadOnly;
  v15 = timer - this->LastAdvanceTime;
  this->LastAdvanceTime = timer;
  if ( !IsReadOnly() )
  {
    v5 = this->CursorTimer + v15;
    if ( v5 > 0.5 )
    {
      Flags = this->Flags;
      if ( (Flags & 0x10) == 0 )
      {
        v7 = (Flags & 8) != 0 ? Flags & 0xFFF7 : Flags | 8;
        this->Flags = v7;
        pObject = this->pDocView.pObject->pDocumentListener.pObject;
        if ( pObject )
          pObject->Editor_OnCursorBlink(pObject, this, (this->Flags & 8) != 0);
      }
      v5 = 0.0;
      this->Flags &= ~0x10u;
    }
    this->CursorTimer = v5;
  }
  if ( (this->Flags & 0x20) != 0 )
  {
    y = this->LastMousePos.y;
    ViewRect = Scaleform::Render::Text::DocView::GetViewRect(this->pDocView.pObject);
    v10 = this->pDocView.pObject;
    if ( ViewRect->y1 < y )
    {
      v17 = this->LastMousePos.y;
      if ( Scaleform::Render::Text::DocView::GetViewRect(v10)->y2 <= v17 )
      {
        v13 = Scaleform::Render::Text::DocView::GetBottomVScroll(this->pDocView.pObject) + 1;
        if ( v13 < Scaleform::Render::Text::DocView::GetLinesCount(this->pDocView.pObject) )
        {
          CursorPosInLine = Scaleform::Render::Text::DocView::GetCursorPosInLine(
                              this->pDocView.pObject,
                              v13,
                              this->LastMousePos.y);
          if ( CursorPosInLine != this->CursorPos )
            Scaleform::GFx::Text::EditorKit::SetCursorPos(this, CursorPosInLine);
        }
      }
    }
    else
    {
      FirstVisibleLinePos = v10->mLineBuffer.Geom.FirstVisibleLinePos;
      if ( FirstVisibleLinePos )
      {
        v12 = Scaleform::Render::Text::DocView::GetCursorPosInLine(v10, FirstVisibleLinePos - 1, this->LastMousePos.y);
        if ( v12 != this->CursorPos )
          Scaleform::GFx::Text::EditorKit::SetCursorPos(this, v12, (this->Flags & 2) != 0);
      }
    }
  }
}
