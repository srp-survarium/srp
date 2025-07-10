Scaleform::Render::Text::LineBuffer::Line *__thiscall Scaleform::Render::Text::LineBuffer::Iterator::InsertNewLine(
        Scaleform::Render::Text::LineBuffer::Iterator *this,
        unsigned int glyphCount,
        unsigned int formatDataElementsCount,
        Scaleform::Render::Text::LineBuffer::LineType lineType)
{
  int CurrentPos; // eax
  Scaleform::Render::Text::LineBuffer::Line *result; // eax

  CurrentPos = this->CurrentPos;
  if ( CurrentPos < 0 )
    CurrentPos = this->pLineBuffer->Lines.Data.Size;
  result = Scaleform::Render::Text::LineBuffer::InsertNewLine(
             this->pLineBuffer,
             CurrentPos,
             glyphCount,
             formatDataElementsCount,
             lineType);
  ++this->CurrentPos;
  return result;
}
