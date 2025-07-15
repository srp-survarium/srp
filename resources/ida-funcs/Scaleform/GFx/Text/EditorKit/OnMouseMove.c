void __thiscall Scaleform::GFx::Text::EditorKit::OnMouseMove(Scaleform::GFx::Text::EditorKit *this, float x, float y)
{
  const Scaleform::Render::Rect<float> *ViewRect; // edi
  double v5; // st7
  Scaleform::Render::Text::DocView *pObject; // ecx
  unsigned int CursorPosAtPoint; // eax
  unsigned int v8; // edi
  float v9; // [esp+10h] [ebp-4h]
  float v10; // [esp+18h] [ebp+4h]
  float v11; // [esp+18h] [ebp+4h]
  float v12; // [esp+18h] [ebp+4h]
  float v13; // [esp+18h] [ebp+4h]

  if ( (this->Flags & 0x20) != 0 )
  {
    ViewRect = Scaleform::Render::Text::DocView::GetViewRect(this->pDocView.pObject);
    v10 = x - ViewRect->x1;
    v11 = floor(v10);
    v9 = v11;
    v12 = y - ViewRect->y1;
    v5 = floor(v12);
    pObject = this->pDocView.pObject;
    v13 = v5;
    this->LastMousePos.x = v9;
    this->LastMousePos.y = v13;
    CursorPosAtPoint = Scaleform::Render::Text::DocView::GetCursorPosAtPoint(pObject, v9, v13);
    v8 = CursorPosAtPoint;
    if ( CursorPosAtPoint != -1 )
    {
      Scaleform::GFx::Text::EditorKit::SetCursorPos(this, CursorPosAtPoint, (this->Flags & 2) != 0);
      if ( (this->Flags & 2) != 0 )
        Scaleform::Render::Text::DocView::SetSelection(
          this->pDocView.pObject,
          this->pDocView.pObject->BeginSelection,
          v8,
          1);
    }
  }
}
