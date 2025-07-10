BOOL __thiscall Scaleform::Render::Text::LineBuffer::IsLineVisible(
        Scaleform::Render::Text::LineBuffer *this,
        unsigned int lineIndex)
{
  float yOffset; // [esp+8h] [ebp-4h]

  yOffset = -(double)(unsigned int)Scaleform::Render::Text::LineBuffer::GetVScrollOffsetInFixp(this);
  return Scaleform::Render::Text::LineBuffer::IsLineVisible(this, lineIndex, yOffset);
}
