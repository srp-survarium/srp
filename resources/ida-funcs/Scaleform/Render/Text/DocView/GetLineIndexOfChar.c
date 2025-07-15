unsigned int __thiscall Scaleform::Render::Text::DocView::GetLineIndexOfChar(
        Scaleform::Render::Text::DocView *this,
        unsigned int indexOfChar)
{
  unsigned int CurrentPos; // eax
  Scaleform::Render::Text::LineBuffer::Iterator result; // [esp+4h] [ebp-14h] BYREF

  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  Scaleform::Render::Text::LineBuffer::FindLineByTextPos(&this->mLineBuffer, &result, indexOfChar);
  if ( !result.pLineBuffer )
    return -1;
  CurrentPos = result.CurrentPos;
  if ( result.CurrentPos >= result.pLineBuffer->Lines.Data.Size || (result.CurrentPos & 0x80000000) != 0 )
    return -1;
  return CurrentPos;
}
