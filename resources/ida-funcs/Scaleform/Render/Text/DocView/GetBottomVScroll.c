unsigned int __thiscall Scaleform::Render::Text::DocView::GetBottomVScroll(Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::LineBuffer *p_mLineBuffer; // esi
  int VScrollOffsetInFixp; // eax
  unsigned int FirstVisibleLinePos; // edi
  bool v5; // bl
  unsigned int v6; // ebp
  float yOffset; // [esp+14h] [ebp-4h]

  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  p_mLineBuffer = &this->mLineBuffer;
  VScrollOffsetInFixp = Scaleform::Render::Text::LineBuffer::GetVScrollOffsetInFixp(p_mLineBuffer);
  FirstVisibleLinePos = p_mLineBuffer->Geom.FirstVisibleLinePos;
  yOffset = -(double)(unsigned int)VScrollOffsetInFixp;
  v5 = (p_mLineBuffer->Geom.Flags & 4) != 0;
  v6 = 0;
  while ( FirstVisibleLinePos < p_mLineBuffer->Lines.Data.Size
       && (FirstVisibleLinePos & 0x80000000) == 0
       && (v5 || Scaleform::Render::Text::LineBuffer::IsLineVisible(p_mLineBuffer, FirstVisibleLinePos, yOffset)) )
  {
    v6 = FirstVisibleLinePos;
    if ( FirstVisibleLinePos >= p_mLineBuffer->Lines.Data.Size )
      break;
    ++FirstVisibleLinePos;
  }
  return v6;
}
