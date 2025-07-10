char __thiscall Scaleform::Render::Text::DocView::GetLineMetrics(
        Scaleform::Render::Text::DocView *this,
        int lineIndex,
        Scaleform::Render::Text::DocView::LineMetrics *pmetrics)
{
  Scaleform::Render::Text::LineBuffer::Line *v5; // esi
  unsigned int Width; // eax
  unsigned int Height; // eax
  int Leading; // eax
  Scaleform::Render::Text::DocView::LineMetrics *pmetricsa; // [esp+18h] [ebp+8h]
  float pmetricsb; // [esp+18h] [ebp+8h]

  if ( !pmetrics )
    return 0;
  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  if ( this == (Scaleform::Render::Text::DocView *)-48
    || lineIndex >= this->mLineBuffer.Lines.Data.Size
    || lineIndex < 0 )
  {
    return 0;
  }
  v5 = this->mLineBuffer.Lines.Data.Data[lineIndex];
  if ( (v5->MemSize & 0x80000000) == 0 )
    pmetricsa = (Scaleform::Render::Text::DocView::LineMetrics *)v5->Data32.BaseLineOffset;
  else
    pmetricsa = (Scaleform::Render::Text::DocView::LineMetrics *)v5->Data8.BaseLineOffset;
  pmetricsb = (float)(int)pmetricsa;
  pmetrics->Ascent = (__int64)pmetricsb;
  pmetrics->Descent = (__int64)Scaleform::Render::Text::LineBuffer::Line::GetDescent(v5);
  if ( (v5->MemSize & 0x80000000) == 0 )
    Width = v5->Data32.Width;
  else
    Width = v5->Data8.Width;
  pmetrics->Width = Width;
  if ( (v5->MemSize & 0x80000000) == 0 )
    Height = v5->Data32.Height;
  else
    Height = v5->Data8.Height;
  pmetrics->Height = Height;
  if ( (v5->MemSize & 0x80000000) == 0 )
    Leading = v5->Data32.Leading;
  else
    Leading = v5->Data8.Leading;
  pmetrics->Leading = Leading;
  pmetrics->FirstCharXOff = v5->Data32.OffsetX;
  return 1;
}
