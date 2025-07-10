char __thiscall Scaleform::Render::Text::SGMLParser<wchar_t>::ParseEndElement(
        Scaleform::Render::Text::SGMLParser<wchar_t> *this,
        const wchar_t **ppelemName,
        unsigned int *pelemLen)
{
  const wchar_t *pNextChar; // eax

  if ( this->CurState != 4 )
    return 0;
  Scaleform::Render::Text::SGMLParser<wchar_t>::ParseName(this, ppelemName, pelemLen);
  if ( this->Iter.CurChar != 62 )
  {
    this->CurState = 1;
    return 0;
  }
  this->CurState = 32772;
  pNextChar = this->Iter.pNextChar;
  this->Iter.pCurChar = pNextChar;
  if ( this->Iter.DoContentParsing && *pNextChar == 38 )
  {
    Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
    return 1;
  }
  else
  {
    if ( pNextChar < this->Iter.pEnd )
    {
      this->Iter.CurChar = *pNextChar;
      this->Iter.pNextChar = pNextChar + 1;
    }
    return 1;
  }
}
