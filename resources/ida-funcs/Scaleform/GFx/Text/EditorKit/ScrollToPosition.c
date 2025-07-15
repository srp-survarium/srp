char __thiscall Scaleform::GFx::Text::EditorKit::ScrollToPosition(
        Scaleform::GFx::Text::EditorKit *this,
        unsigned int pos,
        bool avoidComposStr,
        bool wideCursor)
{
  char v5; // bl
  Scaleform::Render::Text::DocView *pObject; // edi
  float *p_x1; // ebx
  signed int HScrollOffset; // esi
  double v9; // st7
  Scaleform::GFx::Text::EditorKit *v10; // edi
  Scaleform::Render::Text::DocView *v11; // ecx
  Scaleform::Render::Text::DocView *v12; // ecx
  unsigned int v13; // esi
  int v15; // [esp+18h] [ebp-24h]
  int v16; // [esp+1Ch] [ebp-20h] BYREF
  Scaleform::GFx::Text::EditorKit *v17; // [esp+20h] [ebp-1Ch]
  signed int v18; // [esp+24h] [ebp-18h]
  unsigned int v19; // [esp+28h] [ebp-14h] BYREF
  Scaleform::Render::Rect<float> v20; // [esp+2Ch] [ebp-10h] BYREF

  v20.x1 = 0.0;
  v20.y1 = 0.0;
  v20.x2 = 0.0;
  v20.y2 = 0.0;
  v5 = 0;
  v17 = this;
  if ( !Scaleform::GFx::Text::EditorKit::CalcCursorRectOnScreen(
          this,
          pos,
          &v20,
          &v19,
          0,
          avoidComposStr,
          (Scaleform::Render::Text::LineBuffer::Line::Alignment *)&v16) )
    return v5;
  pObject = this->pDocView.pObject;
  p_x1 = &pObject->mLineBuffer.Geom.VisibleRect.x1;
  if ( !wideCursor )
    v20.x2 = v20.x1 + 20.0;
  if ( Scaleform::Render::Rect<float>::Contains(&pObject->mLineBuffer.Geom.VisibleRect, &v20)
    || (pObject->AlignProps & 0x30) != 0
    || (pObject->Flags & 1) != 0 )
  {
    return 0;
  }
  HScrollOffset = pObject->mLineBuffer.Geom.HScrollOffset;
  v18 = HScrollOffset;
  v15 = 1200;
  if ( v16 )
    v15 = 0;
  if ( pObject->mLineBuffer.Geom.VisibleRect.x2 >= (double)v20.x2 )
  {
    if ( *p_x1 > (double)v20.x1 )
    {
      HScrollOffset -= v15 + (int)(*p_x1 - v20.x1);
      if ( HScrollOffset < 0 )
        HScrollOffset = 0;
    }
  }
  else
  {
    HScrollOffset += (int)(v20.x1 - pObject->mLineBuffer.Geom.VisibleRect.x2 + (double)v15);
    v20.x1 = 0.0;
    v20.y1 = 0.0;
    v20.x2 = 0.0;
    v20.y2 = 0.0;
    if ( pos )
    {
      if ( Scaleform::Render::Text::DocView::GetExactCharBoundaries(pObject, &v20, pos - 1) )
      {
        v9 = v20.x1 - 40.0;
        if ( (int)v9 < HScrollOffset )
          HScrollOffset = (int)v9;
      }
    }
    if ( HScrollOffset < 0 )
      HScrollOffset = 0;
  }
  v10 = v17;
  v11 = v17->pDocView.pObject;
  if ( (v11->Flags & 8) != 0 && HScrollOffset >= v18 )
    v5 = 0;
  else
    v5 = Scaleform::Render::Text::DocView::SetHScrollOffset(v11, HScrollOffset);
  v12 = v10->pDocView.pObject;
  v13 = v19;
  if ( v19 < v12->mLineBuffer.Geom.FirstVisibleLinePos )
    return Scaleform::Render::Text::DocView::SetVScrollOffset(v12, v19) | v5;
  if ( v13 <= Scaleform::Render::Text::DocView::GetBottomVScroll(v12) )
    return v5;
  return Scaleform::Render::Text::DocView::SetBottomVScroll(v10->pDocView.pObject, v13) | v5;
}
