const Scaleform::Render::Text::LineBuffer::Line *__thiscall Scaleform::Render::Text::LineBuffer::GetLine(
        Scaleform::Render::Text::LineBuffer *this,
        unsigned int lineIdx)
{
  if ( lineIdx < this->Lines.Data.Size )
    return this->Lines.Data.Data[lineIdx];
  else
    return 0;
}
