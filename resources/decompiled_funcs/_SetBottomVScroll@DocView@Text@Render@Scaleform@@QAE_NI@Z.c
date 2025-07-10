char __thiscall Scaleform::Render::Text::DocView::SetBottomVScroll(
        Scaleform::Render::Text::DocView *this,
        unsigned int newBottomMostLine)
{
  unsigned int Size; // eax
  unsigned int v3; // esi
  int v4; // edi
  Scaleform::Render::Text::LineBuffer::Line **Data; // eax
  Scaleform::Render::Text::LineBuffer::Line *v6; // edx
  Scaleform::Render::Text::LineBuffer::Line **v7; // ecx
  unsigned int Height; // ebp
  int v9; // ebx
  double v10; // st7
  int v11; // edx
  char v12; // bl
  unsigned int MaxVScroll; // eax
  Scaleform::Render::Text::DocView::DocumentListener *pObject; // ecx
  unsigned int v17; // [esp+Ch] [ebp-18h]
  float top; // [esp+28h] [ebp+4h]

  Size = this->mLineBuffer.Lines.Data.Size;
  v3 = newBottomMostLine;
  if ( newBottomMostLine >= Size )
    v3 = Size - 1;
  v4 = v3;
  if ( this == (Scaleform::Render::Text::DocView *)-48 )
    return 0;
  v17 = this->mLineBuffer.Lines.Data.Size;
  if ( v3 >= v17 || (v3 & 0x80000000) != 0 )
    return 0;
  Data = this->mLineBuffer.Lines.Data.Data;
  v6 = Data[v3];
  v7 = &Data[v3];
  if ( (v6->MemSize & 0x80000000) == 0 )
    Height = v6->Data32.Height;
  else
    Height = v6->Data8.Height;
  if ( (v6->MemSize & 0x80000000) == 0 )
  {
    LOWORD(v9) = v6->Data32.Leading;
    if ( (__int16)v9 > 0 )
    {
      v9 = (__int16)v9;
      goto LABEL_15;
    }
  }
  else
  {
    LOBYTE(v9) = v6->Data8.Leading;
    if ( (char)v9 > 0 )
    {
      v9 = (char)v9;
      goto LABEL_15;
    }
  }
  v9 = 0;
LABEL_15:
  v10 = (double)(int)(Height + v9 + v6->Data32.OffsetY);
  v11 = v3;
  do
  {
    if ( v11 >= v17 )
      break;
    if ( v11 < 0 )
      break;
    top = v10 - this->mLineBuffer.Geom.VisibleRect.y2 + this->mLineBuffer.Geom.VisibleRect.y1;
    if ( (double)(*v7)->Data32.OffsetY < top )
      break;
    v3 = v4--;
    --v11;
    --v7;
  }
  while ( v4 >= 0 );
  v12 = 0;
  MaxVScroll = Scaleform::Render::Text::DocView::GetMaxVScroll(this);
  if ( v3 > MaxVScroll )
    v3 = MaxVScroll;
  if ( this->mLineBuffer.Geom.FirstVisibleLinePos != v3 )
  {
    Scaleform::Render::Text::LineBuffer::SetFirstVisibleLine(&this->mLineBuffer, v3);
    pObject = this->pDocumentListener.pObject;
    if ( pObject )
      pObject->View_OnVScroll(pObject, this, v3);
    return 1;
  }
  return v12;
}
