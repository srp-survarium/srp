char __thiscall Scaleform::Render::Text::LineBuffer::IsPartiallyVisible(
        Scaleform::Render::Text::LineBuffer *this,
        float yOffset)
{
  unsigned int FirstVisibleLinePos; // eax
  Scaleform::Render::Text::LineBuffer::Line *v3; // edx
  int v4; // esi
  unsigned int Height; // esi
  int v6; // esi
  float v8; // [esp+4h] [ebp-Ch]
  float vrectH; // [esp+8h] [ebp-8h]
  float lh; // [esp+Ch] [ebp-4h]
  float yf; // [esp+14h] [ebp+4h]

  FirstVisibleLinePos = this->Geom.FirstVisibleLinePos;
  if ( FirstVisibleLinePos >= this->Lines.Data.Size )
    return 0;
  v3 = this->Lines.Data.Data[FirstVisibleLinePos];
  v4 = (v3->MemSize & 0x80000000) == 0 ? v3->Data32.Width : v3->Data8.Width;
  if ( v4
    && ((v3->MemSize & 0x80000000) == 0 ? (Height = v3->Data32.Height) : (Height = v3->Data8.Height),
        Height
     && ((v3->MemSize & 0x80000000) == 0 ? (v6 = v3->Data32.Height) : (v6 = v3->Data8.Height),
         (v8 = this->Geom.VisibleRect.y2 - this->Geom.VisibleRect.y1,
          vrectH = v8 + 20.0,
          yf = (double)v3->Data32.OffsetY + yOffset,
          vrectH >= (double)yf)
      && (lh = (float)v6, vrectH < yf + lh))) )
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
