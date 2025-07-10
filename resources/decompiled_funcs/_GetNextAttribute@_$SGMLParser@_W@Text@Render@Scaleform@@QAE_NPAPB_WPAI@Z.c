char __thiscall Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttribute(
        Scaleform::Render::Text::SGMLParser<wchar_t> *this,
        const wchar_t **ppattrName,
        unsigned int *pattrNameSz)
{
  int CurState; // eax
  char v6; // bl
  bool v7; // zf
  const wchar_t *pNextChar; // eax

  CurState = this->CurState;
  if ( CurState == 1 )
    return 0;
  if ( CurState == 8 )
    Scaleform::Render::Text::SGMLParser<wchar_t>::SkipAttribute(this);
  v6 = 0;
  while ( this->CurState == 7 )
  {
    if ( this->Iter.pCurChar >= this->Iter.pEnd )
      break;
    Scaleform::Render::Text::SGMLParser<wchar_t>::ParseName(this, ppattrName, pattrNameSz);
    Scaleform::Render::Text::SGMLParser<wchar_t>::SkipSpaces(this);
    if ( this->Iter.pCurChar < this->Iter.pEnd )
    {
      if ( this->Iter.CurChar == 61 )
      {
        v7 = !this->Iter.DoContentParsing;
        pNextChar = this->Iter.pNextChar;
        this->Iter.pCurChar = pNextChar;
        if ( v7 || *pNextChar != 38 )
        {
          if ( pNextChar < this->Iter.pEnd )
          {
            this->Iter.CurChar = *pNextChar;
            this->Iter.pNextChar = pNextChar + 1;
          }
        }
        else
        {
          Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
        }
        Scaleform::Render::Text::SGMLParser<wchar_t>::SkipSpaces(this);
        this->CurState = 8;
        v6 = 1;
      }
      else
      {
        Scaleform::Render::Text::SGMLParser<wchar_t>::SkipAttribute(this);
      }
    }
  }
  if ( this->Iter.pCurChar >= this->Iter.pEnd )
    this->CurState = 1;
  return v6;
}
