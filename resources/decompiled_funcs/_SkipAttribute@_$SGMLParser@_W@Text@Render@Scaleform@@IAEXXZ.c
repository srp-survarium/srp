void __thiscall Scaleform::Render::Text::SGMLParser<wchar_t>::SkipAttribute(
        Scaleform::Render::Text::SGMLParser<wchar_t> *this)
{
  unsigned int CurChar; // ebx
  int v3; // ecx
  int v4; // edx
  bool v5; // zf
  const wchar_t *pNextChar; // eax
  unsigned int v7; // eax
  unsigned int v8; // ebx
  Scaleform::Render::Text::SGMLCharIter<wchar_t> *p_Iter; // esi
  const wchar_t *v10; // eax
  const wchar_t *v11; // eax
  unsigned int v12; // eax

  if ( this->CurState == 7 )
  {
    Scaleform::Render::Text::SGMLParser<wchar_t>::SkipSpaces(this);
    while ( this->Iter.pCurChar < this->Iter.pEnd )
    {
      CurChar = this->Iter.CurChar;
      v3 = BYTE1(CurChar);
      v4 = Scaleform::UnicodeAlnumBits[v3];
      if ( !Scaleform::UnicodeAlnumBits[v3]
        || v4 != 1
        && (Scaleform::UnicodeAlnumBits[v4 + ((unsigned __int8)this->Iter.CurChar >> 4)]
          & (1 << (this->Iter.CurChar & 0xF))) == 0
        || CurChar == 61 )
      {
        break;
      }
      v5 = !this->Iter.DoContentParsing;
      pNextChar = this->Iter.pNextChar;
      this->Iter.pCurChar = pNextChar;
      if ( v5 || *pNextChar != 38 )
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
    if ( this->Iter.pCurChar >= this->Iter.pEnd )
      goto LABEL_14;
    v7 = this->Iter.CurChar;
    if ( v7 == 61 )
    {
      Scaleform::Render::Text::SGMLCharIter<wchar_t>::operator++(&this->Iter);
      Scaleform::Render::Text::SGMLParser<wchar_t>::SkipSpaces(this);
      this->CurState = 8;
    }
    else if ( v7 == 47 || v7 == 62 )
    {
      this->CurState = 9;
    }
    else
    {
      this->CurState = 1;
    }
  }
  if ( this->CurState == 8 )
  {
    v8 = this->Iter.CurChar;
    if ( v8 != 34 && v8 != 39 )
      goto LABEL_14;
    p_Iter = &this->Iter;
    do
    {
      v5 = !this->Iter.DoContentParsing;
      v10 = this->Iter.pNextChar;
      p_Iter->pCurChar = v10;
      if ( v5 || *v10 != 38 )
      {
        if ( v10 < this->Iter.pEnd )
        {
          this->Iter.CurChar = *v10;
          this->Iter.pNextChar = v10 + 1;
        }
      }
      else
      {
        Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
      }
    }
    while ( this->Iter.pCurChar < this->Iter.pEnd && this->Iter.CurChar != v8 );
    if ( p_Iter->pCurChar >= this->Iter.pEnd )
    {
LABEL_14:
      this->CurState = 1;
      return;
    }
    v5 = !this->Iter.DoContentParsing;
    v11 = this->Iter.pNextChar;
    p_Iter->pCurChar = v11;
    if ( v5 || *v11 != 38 )
    {
      if ( v11 < this->Iter.pEnd )
      {
        this->Iter.CurChar = *v11;
        this->Iter.pNextChar = v11 + 1;
      }
    }
    else
    {
      Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
    }
    Scaleform::Render::Text::SGMLParser<wchar_t>::SkipSpaces(this);
    v12 = this->Iter.CurChar;
    if ( v12 == 62 || v12 == 47 )
      this->CurState = 9;
    else
      this->CurState = 7;
  }
}
