void __thiscall Scaleform::Render::Text::SGMLParser<wchar_t>::SkipName(
        Scaleform::Render::Text::SGMLParser<wchar_t> *this)
{
  Scaleform::Render::Text::SGMLCharIter<wchar_t> *p_Iter; // esi
  unsigned int CurChar; // eax
  int v4; // ecx
  int v5; // edx
  bool v6; // zf
  const wchar_t *pNextChar; // eax

  if ( this->CurState == 2 )
  {
    p_Iter = &this->Iter;
    while ( this->Iter.pCurChar < this->Iter.pEnd )
    {
      CurChar = this->Iter.CurChar;
      if ( CurChar == 61 )
        break;
      if ( CurChar == 62 )
        break;
      if ( CurChar == 60 )
        break;
      if ( CurChar == 47 )
        break;
      v4 = BYTE1(CurChar);
      v5 = Scaleform::UnicodeSpaceBits[v4];
      if ( Scaleform::UnicodeSpaceBits[v4] )
      {
        if ( v5 == 1
          || (Scaleform::UnicodeSpaceBits[v5 + ((unsigned __int8)CurChar >> 4)] & (1 << (CurChar & 0xF))) != 0 )
        {
          break;
        }
      }
      v6 = !this->Iter.DoContentParsing;
      pNextChar = this->Iter.pNextChar;
      p_Iter->pCurChar = pNextChar;
      if ( v6 || *pNextChar != 38 )
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
    }
  }
}
