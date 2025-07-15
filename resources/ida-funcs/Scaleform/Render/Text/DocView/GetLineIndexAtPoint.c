unsigned int __thiscall Scaleform::Render::Text::DocView::GetLineIndexAtPoint(
        Scaleform::Render::Text::DocView *this,
        float x,
        float y)
{
  Scaleform::Render::Text::LineBuffer *p_mLineBuffer; // esi
  unsigned int CurrentPos; // eax
  Scaleform::Render::Text::LineBuffer::Iterator result; // [esp+Ch] [ebp-14h] BYREF
  int yoff; // [esp+28h] [ebp+8h]

  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  p_mLineBuffer = &this->mLineBuffer;
  *(float *)&yoff = (double)(unsigned int)Scaleform::Render::Text::LineBuffer::GetVScrollOffsetInFixp(p_mLineBuffer) + y;
  Scaleform::Render::Text::LineBuffer::FindLineAtYOffset(p_mLineBuffer, &result, yoff);
  if ( !result.pLineBuffer )
    return -1;
  CurrentPos = result.CurrentPos;
  if ( result.CurrentPos >= result.pLineBuffer->Lines.Data.Size || (result.CurrentPos & 0x80000000) != 0 )
    return -1;
  return CurrentPos;
}
