BOOL __thiscall Scaleform::Render::Text::LineBuffer::IsLineVisible(
        Scaleform::Render::Text::LineBuffer *this,
        unsigned int lineIndex,
        float yOffset)
{
  Scaleform::Render::Text::LineBuffer::Line *v3; // eax
  unsigned int FirstVisibleLinePos; // esi
  double v5; // st7
  double v6; // st6
  int OffsetY; // esi
  unsigned int Height; // eax
  float yOffseta; // [esp+Ch] [ebp+8h]
  float yOffsetb; // [esp+Ch] [ebp+8h]

  v3 = this->Lines.Data.Data[lineIndex];
  FirstVisibleLinePos = this->Geom.FirstVisibleLinePos;
  if ( lineIndex == FirstVisibleLinePos )
  {
    v5 = (double)v3->Data32.OffsetY + yOffset;
    yOffseta = this->Geom.VisibleRect.y2 - this->Geom.VisibleRect.y1;
    v6 = yOffseta;
  }
  else
  {
    if ( lineIndex <= FirstVisibleLinePos )
      return 0;
    OffsetY = v3->Data32.OffsetY;
    if ( (v3->MemSize & 0x80000000) == 0 )
      Height = v3->Data32.Height;
    else
      Height = v3->Data8.Height;
    v5 = (double)(int)(OffsetY + Height) + yOffset;
    yOffsetb = this->Geom.VisibleRect.y2 - this->Geom.VisibleRect.y1;
    v6 = yOffsetb;
  }
  return v6 + 20.0 >= v5;
}
