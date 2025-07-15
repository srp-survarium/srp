char __thiscall Scaleform::GFx::Text::EditorKit::CalcCursorRectOnScreen(
        Scaleform::GFx::Text::EditorKit *this,
        unsigned int charIndex,
        Scaleform::Render::Rect<float> *pcursorRect,
        unsigned int *plineIndex,
        unsigned int *pglyphIndex,
        bool avoidComposStr,
        Scaleform::Render::Text::LineBuffer::Line::Alignment *plineAlignment)
{
  char v8; // bl
  Scaleform::Render::Text::DocView *pObject; // eax
  const Scaleform::Render::Rect<float> *ViewRect; // eax
  double v11; // st6
  double x1; // st7
  float v14; // [esp+Ch] [ebp-10h]
  float v15; // [esp+Ch] [ebp-10h]
  float v16; // [esp+10h] [ebp-Ch]
  float v17; // [esp+10h] [ebp-Ch]
  float v18; // [esp+14h] [ebp-8h]
  float v19; // [esp+18h] [ebp-4h]
  float y1; // [esp+18h] [ebp-4h]

  v8 = Scaleform::GFx::Text::EditorKit::CalcCursorRectInLineBuffer(
         this,
         charIndex,
         pcursorRect,
         plineIndex,
         pglyphIndex,
         avoidComposStr,
         plineAlignment);
  if ( v8 )
  {
    pObject = this->pDocView.pObject;
    v14 = -(double)pObject->mLineBuffer.Geom.HScrollOffset;
    v16 = -(double)(unsigned int)Scaleform::Render::Text::LineBuffer::GetVScrollOffsetInFixp(&pObject->mLineBuffer);
    pcursorRect->x1 = pcursorRect->x1 + v14;
    pcursorRect->x2 = v14 + pcursorRect->x2;
    pcursorRect->y1 = v16 + pcursorRect->y1;
    pcursorRect->y2 = v16 + pcursorRect->y2;
    ViewRect = Scaleform::Render::Text::DocView::GetViewRect(this->pDocView.pObject);
    v18 = this->pDocView.pObject->mLineBuffer.Geom.VisibleRect.x1 - ViewRect->x1 + pcursorRect->x1;
    v19 = this->pDocView.pObject->mLineBuffer.Geom.VisibleRect.y1 - ViewRect->y1 + pcursorRect->y1;
    pcursorRect->x1 = v18;
    v11 = v19;
    pcursorRect->y1 = v19;
    v15 = this->pDocView.pObject->mLineBuffer.Geom.VisibleRect.x1 - ViewRect->x1 + pcursorRect->x2;
    v17 = this->pDocView.pObject->mLineBuffer.Geom.VisibleRect.y1 - ViewRect->y1 + pcursorRect->y2;
    pcursorRect->x2 = v15;
    pcursorRect->y2 = v17;
    y1 = ViewRect->y1;
    x1 = ViewRect->x1;
    pcursorRect->x1 = v18 + x1;
    pcursorRect->x2 = v15 + x1;
    pcursorRect->y1 = v11 + y1;
    pcursorRect->y2 = v17 + y1;
  }
  return v8;
}
