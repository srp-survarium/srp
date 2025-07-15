void __thiscall Scaleform::Render::Text::SGMLCharIter<wchar_t>::operator++(
        Scaleform::Render::Text::SGMLCharIter<wchar_t> *this)
{
  bool v1; // zf
  const wchar_t *pNextChar; // eax

  v1 = !this->DoContentParsing;
  pNextChar = this->pNextChar;
  this->pCurChar = pNextChar;
  if ( v1 || *pNextChar != 38 )
  {
    if ( pNextChar < this->pEnd )
    {
      this->CurChar = *pNextChar;
      this->pNextChar = pNextChar + 1;
    }
  }
  else
  {
    Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(this);
  }
}
