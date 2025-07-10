Scaleform::Render::Text::Paragraph::FormatRunIterator *__thiscall Scaleform::Render::Text::Paragraph::GetIterator(
        Scaleform::Render::Text::Paragraph *this,
        Scaleform::Render::Text::Paragraph::FormatRunIterator *result)
{
  Scaleform::Render::Text::Paragraph::FormatRunIterator *v2; // eax

  v2 = result;
  result->PlaceHolder.pText = 0;
  result->PlaceHolder.Index = 0;
  result->PlaceHolder.Length = 0;
  result->PlaceHolder.pFormat.pObject = 0;
  result->pFormatInfo = &this->FormatInfo;
  result->FormatIterator.Index = 0;
  result->FormatIterator.pArray = &this->FormatInfo;
  result->CurTextIndex = 0;
  result->pText = (const Scaleform::Render::Text::Paragraph::TextBuffer *)this;
  return v2;
}
