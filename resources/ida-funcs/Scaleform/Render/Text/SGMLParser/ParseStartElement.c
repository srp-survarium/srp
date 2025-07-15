bool __thiscall Scaleform::Render::Text::SGMLParser<wchar_t>::ParseStartElement(
        Scaleform::Render::Text::SGMLParser<wchar_t> *this,
        wchar_t **ppelemName,
        unsigned int *pelemLen)
{
  bool result; // al
  unsigned int CurChar; // eax
  bool v6; // zf
  const wchar_t *pNextChar; // eax
  unsigned int v8; // edx

  result = 0;
  if ( this->CurState == 2 )
  {
    Scaleform::Render::Text::SGMLParser<wchar_t>::ParseName(this, (const __m128i **)ppelemName, pelemLen);
    CurChar = this->Iter.CurChar;
    if ( CurChar == 62 )
    {
      this->CurState = 32770;
      v6 = !this->Iter.DoContentParsing;
      pNextChar = this->Iter.pNextChar;
      this->Iter.pCurChar = pNextChar;
      if ( !v6 && *pNextChar == 38 )
      {
        Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
        return 1;
      }
      if ( pNextChar < this->Iter.pEnd )
      {
        v8 = *pNextChar;
        this->Iter.pNextChar = pNextChar + 1;
        result = 1;
        this->Iter.CurChar = v8;
        return result;
      }
    }
    else
    {
      if ( CurChar == 47 )
      {
        result = 1;
        this->CurState = 6;
        return result;
      }
      this->CurState = 7;
      Scaleform::Render::Text::SGMLParser<wchar_t>::SkipSpaces(this);
    }
    return 1;
  }
  return result;
}
