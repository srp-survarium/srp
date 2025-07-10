void __thiscall Scaleform::Render::Text::SGMLParser<wchar_t>::SkipSpaces(
        Scaleform::Render::Text::SGMLParser<wchar_t> *this)
{
  Scaleform::Render::Text::SGMLCharIter<wchar_t> *p_Iter; // esi
  unsigned __int16 CurChar; // ax
  int v4; // ecx
  int v5; // edx
  bool v6; // zf
  const wchar_t *pNextChar; // eax

  p_Iter = &this->Iter;
  if ( this->Iter.pCurChar < this->Iter.pEnd )
  {
    do
    {
      CurChar = this->Iter.CurChar;
      v4 = HIBYTE(CurChar);
      v5 = Scaleform::UnicodeSpaceBits[v4];
      if ( !Scaleform::UnicodeSpaceBits[v4]
        || v5 != 1 && (Scaleform::UnicodeSpaceBits[v5 + ((unsigned __int8)CurChar >> 4)] & (1 << (CurChar & 0xF))) == 0 )
      {
        break;
      }
      v6 = !p_Iter->DoContentParsing;
      pNextChar = p_Iter->pNextChar;
      p_Iter->pCurChar = pNextChar;
      if ( v6 || *pNextChar != 38 )
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
    }
    while ( p_Iter->pCurChar < p_Iter->pEnd );
  }
}
