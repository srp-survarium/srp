wchar_t *__thiscall Scaleform::Render::Text::Paragraph::CharactersIterator::GetRemainingTextPtr(
        Scaleform::Render::Text::Paragraph::CharactersIterator *this,
        unsigned int *plen)
{
  const Scaleform::Render::Text::Paragraph::TextBuffer *pText; // eax
  unsigned int Size; // eax
  unsigned int CurTextIndex; // edx

  pText = this->pText;
  if ( pText && (Size = pText->Size, CurTextIndex = this->CurTextIndex, CurTextIndex < Size) )
  {
    if ( plen )
      *plen = Size - CurTextIndex;
    return &this->pText->pText[this->CurTextIndex];
  }
  else
  {
    *plen = 0;
    return 0;
  }
}
