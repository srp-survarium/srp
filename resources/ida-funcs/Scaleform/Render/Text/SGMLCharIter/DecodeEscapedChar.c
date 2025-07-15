unsigned int __thiscall Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(
        Scaleform::Render::Text::SGMLCharIter<wchar_t> *this)
{
  const wchar_t *pCurChar; // eax
  const wchar_t *pEnd; // ecx
  const wchar_t *v4; // eax
  const wchar_t *pNextChar; // eax
  const wchar_t *v7; // eax
  const wchar_t *v8; // eax
  const wchar_t *v9; // ebp
  const wchar_t *v10; // eax
  unsigned int v11; // edi
  const wchar_t *v12; // eax
  __int16 v13; // ax
  int v14; // eax
  wchar_t v15; // ax
  const wchar_t *v16; // eax
  int v17; // edx

  pCurChar = this->pCurChar;
  pEnd = this->pEnd;
  if ( pCurChar >= pEnd )
    return 0;
  this->pNextChar = pCurChar;
  if ( *pCurChar != 38 )
    return this->CurChar;
  v4 = pCurChar + 1;
  this->CurChar = 38;
  this->pNextChar = v4;
  if ( v4 + 5 <= pEnd )
  {
    if ( !Scaleform::Render::Text::SGMLCharIter<wchar_t>::StrCompare(v4, "quot;", 5u) )
    {
      this->pNextChar += 5;
      this->CurChar = 34;
      return this->CurChar;
    }
    if ( !Scaleform::Render::Text::SGMLCharIter<wchar_t>::StrCompare(this->pNextChar, "apos;", 5u) )
    {
      this->pNextChar += 5;
      this->CurChar = 39;
      return this->CurChar;
    }
    if ( !Scaleform::Render::Text::SGMLCharIter<wchar_t>::StrCompare(this->pNextChar, "nbsp;", 5u) )
    {
      this->pNextChar += 5;
      this->CurChar = 160;
      return this->CurChar;
    }
  }
  pNextChar = this->pNextChar;
  if ( pNextChar + 4 <= this->pEnd && !Scaleform::Render::Text::SGMLCharIter<wchar_t>::StrCompare(pNextChar, "amp;", 4u) )
  {
    this->pNextChar += 4;
    this->CurChar = 38;
    return 38;
  }
  v7 = this->pNextChar;
  if ( v7 + 3 <= this->pEnd )
  {
    if ( !Scaleform::Render::Text::SGMLCharIter<wchar_t>::StrCompare(v7, "lt;", 3u) )
    {
      this->pNextChar += 3;
      this->CurChar = 60;
      return this->CurChar;
    }
    if ( !Scaleform::Render::Text::SGMLCharIter<wchar_t>::StrCompare(this->pNextChar, "gt;", 3u) )
    {
      this->pNextChar += 3;
      this->CurChar = 62;
      return this->CurChar;
    }
  }
  v8 = this->pNextChar;
  if ( v8 + 2 > this->pEnd || *v8 != 35 )
    return this->CurChar;
  v9 = this->pNextChar;
  v10 = v8 + 1;
  this->pNextChar = v10;
  v11 = 0;
  if ( !Scaleform::SFtowlower(*v10 == 120) )
  {
    if ( Scaleform::Render::Text::SGMLCharIter<wchar_t>::IsDigit(*this->pNextChar) )
    {
      if ( this->pNextChar >= this->pEnd )
        goto LABEL_39;
      do
      {
        v15 = *this->pNextChar;
        if ( v15 == 59 )
          break;
        if ( !Scaleform::Render::Text::SGMLCharIter<wchar_t>::IsDigit(v15) )
          goto LABEL_31;
        v16 = this->pNextChar;
        v17 = *v16++;
        this->pNextChar = v16;
        v11 = v17 + 10 * v11 - 48;
      }
      while ( v16 < this->pEnd );
      if ( v11 != -1 )
      {
LABEL_39:
        v12 = this->pNextChar;
        goto LABEL_40;
      }
    }
LABEL_31:
    this->pNextChar = v9;
    return this->CurChar;
  }
  v12 = ++this->pNextChar;
  if ( v12 >= this->pEnd )
    goto LABEL_40;
  while ( *v12 != 59 )
  {
    if ( !isxdigit(*v12) )
      goto LABEL_31;
    v11 *= 16;
    v13 = Scaleform::SFtowlower(*this->pNextChar);
    if ( (unsigned __int16)(v13 - 48) <= 9u )
    {
      v14 = v13 & 0xF;
LABEL_28:
      v11 |= v14;
      goto LABEL_29;
    }
    if ( (unsigned __int16)(v13 - 97) <= 5u )
    {
      v14 = (((_BYTE)v13 - 1) & 0xF) + 10;
      goto LABEL_28;
    }
LABEL_29:
    v12 = ++this->pNextChar;
    if ( v12 >= this->pEnd )
      break;
  }
  if ( v11 == -1 )
    goto LABEL_31;
LABEL_40:
  if ( *v12 == 59 )
    this->pNextChar = v12 + 1;
  this->CurChar = v11;
  return v11;
}
