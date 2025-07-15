unsigned int __thiscall Scaleform::Render::Text::DocView::GetLineIndexAtPoint(
        Scaleform::Render::Text::DocView *this,
        float x,
        float y)
{
  Scaleform::Render::Text::LineBuffer *p_mLineBuffer; // esi
  unsigned int result; // eax
  Scaleform::Render::Text::LineBuffer::Iterator it; // [esp+Ch] [ebp-14h] BYREF
  float ya; // [esp+28h] [ebp+8h]

  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  p_mLineBuffer = &this->mLineBuffer;
  ya = (double)Scaleform::Render::Text::LineBuffer::GetVScrollOffsetInFixp(p_mLineBuffer) + y;
  Scaleform::Render::Text::LineBuffer::FindLineAtYOffset(p_mLineBuffer, &it, ya);
  if ( !it.pLineBuffer )
    return -1;
  result = it.CurrentPos;
  if ( it.CurrentPos >= it.pLineBuffer->Lines.Data.Size || (it.CurrentPos & 0x80000000) != 0 )
    return -1;
  return result;
}
