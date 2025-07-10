void __thiscall Scaleform::Render::Text::SGMLParser<wchar_t>::SkipComment(
        Scaleform::Render::Text::SGMLParser<wchar_t> *this)
{
  Scaleform::Render::Text::SGMLCharIter<wchar_t> *p_Iter; // esi
  int v3; // edi
  bool v4; // zf
  const wchar_t *pNextChar; // eax
  unsigned int CurChar; // eax
  const wchar_t *v7; // eax

  p_Iter = &this->Iter;
  v3 = 0;
  if ( this->Iter.pCurChar < this->Iter.pEnd )
  {
    do
    {
      if ( !this->Iter.CurChar || v3 == 3 )
        break;
      v4 = !p_Iter->DoContentParsing;
      pNextChar = p_Iter->pNextChar;
      p_Iter->pCurChar = pNextChar;
      if ( v4 || *pNextChar != 38 )
      {
        if ( pNextChar < p_Iter->pEnd )
        {
          p_Iter->CurChar = *pNextChar;
          p_Iter->pNextChar = pNextChar + 1;
        }
      }
      else
      {
        Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(p_Iter);
      }
      CurChar = this->Iter.CurChar;
      if ( CurChar == 45 )
      {
        if ( v3 < 2 )
          ++v3;
      }
      else if ( CurChar == 62 )
      {
        if ( v3 == 2 )
          v3 = 3;
      }
      else
      {
        v3 = 0;
      }
    }
    while ( p_Iter->pCurChar < p_Iter->pEnd );
  }
  if ( p_Iter->pCurChar < p_Iter->pEnd && v3 == 3 )
  {
    v4 = !p_Iter->DoContentParsing;
    v7 = p_Iter->pNextChar;
    p_Iter->pCurChar = v7;
    if ( v4 || *v7 != 38 )
    {
      if ( v7 < p_Iter->pEnd )
      {
        p_Iter->CurChar = *v7;
        p_Iter->pNextChar = v7 + 1;
      }
    }
    else
    {
      Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(p_Iter);
    }
  }
}
