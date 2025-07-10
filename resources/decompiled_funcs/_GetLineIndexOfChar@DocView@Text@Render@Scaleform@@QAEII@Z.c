unsigned int __thiscall Scaleform::Render::Text::DocView::GetLineIndexOfChar(
        Scaleform::Render::Text::DocView *this,
        unsigned int indexOfChar)
{
  unsigned int result; // eax
  Scaleform::Render::Text::LineBuffer::Iterator it; // [esp+4h] [ebp-14h] BYREF

  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  Scaleform::Render::Text::LineBuffer::FindLineByTextPos(&this->mLineBuffer, &it, indexOfChar);
  if ( !it.pLineBuffer )
    return -1;
  result = it.CurrentPos;
  if ( it.CurrentPos >= it.pLineBuffer->Lines.Data.Size || (it.CurrentPos & 0x80000000) != 0 )
    return -1;
  return result;
}
