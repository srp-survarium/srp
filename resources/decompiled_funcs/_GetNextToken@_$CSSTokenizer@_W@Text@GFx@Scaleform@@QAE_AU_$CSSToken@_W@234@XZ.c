Scaleform::GFx::Text::CSSToken<wchar_t> *__thiscall Scaleform::GFx::Text::CSSTokenizer<wchar_t>::GetNextToken(
        Scaleform::GFx::Text::CSSTokenizer<wchar_t> *this,
        Scaleform::GFx::Text::CSSToken<wchar_t> *result)
{
  Scaleform::GFx::Text::CSSToken<wchar_t> *v3; // eax
  unsigned int Length; // eax
  unsigned int ColDev; // edx
  const wchar_t *pCurr; // eax
  const wchar_t *v7; // edi
  wchar_t v8; // bp
  int v9; // ecx
  int v10; // edx
  const wchar_t *v11; // edi
  char v12; // cl
  unsigned int v13; // ebp
  const wchar_t *v14; // edi
  wchar_t *v15; // edi
  wchar_t v16; // bp
  wchar_t *i; // edi
  wchar_t *v18; // edi
  wchar_t *v19; // edi
  wchar_t v20; // bp
  const wchar_t *pBase; // edx
  unsigned int v22; // ecx

  if ( this->CurrentToken.Type == TT_EOF )
  {
    v3 = result;
    result->Type = TT_EOF;
    result->pBase = 0;
    result->Length = 0;
  }
  else
  {
    Length = this->CurrentToken.Length;
    ColDev = this->ColDev;
    this->LineNo += this->LineDev;
    this->ColNo += ColDev;
    this->pCurr += Length;
    pCurr = this->pCurr;
    v7 = pCurr;
    this->CurrentToken.pBase = this->pCurr;
    this->CurrentToken.Length = 1;
    this->LineDev = 0;
    this->ColDev = 0;
    if ( pCurr == this->pEnd )
    {
      this->CurrentToken.Type = TT_EOF;
      this->CurrentToken.pBase = 0;
      this->CurrentToken.Length = 0;
    }
    else
    {
      v8 = *pCurr;
      if ( Scaleform::GFx::Text::CSSTokenizer<wchar_t>::IsSpace(this, *pCurr) )
      {
        while ( 1 )
        {
          if ( *v7 == 10 )
          {
            ++this->LineDev;
            this->ColDev = 0;
          }
          ++this->ColDev;
          if ( ++v7 == this->pEnd )
            break;
          v9 = HIBYTE(*v7);
          v10 = Scaleform::UnicodeSpaceBits[v9];
          if ( !Scaleform::UnicodeSpaceBits[v9]
            || v10 != 1 && (Scaleform::UnicodeSpaceBits[v10 + ((unsigned __int8)*v7 >> 4)] & (1 << (*v7 & 0xF))) == 0 )
          {
            break;
          }
          ++this->CurrentToken.Length;
        }
        this->CurrentToken.Type = TT_WhiteSpace;
      }
      else if ( v8 == 47 )
      {
        v11 = v7 + 1;
        this->CurrentToken.Type = TT_WhiteSpace;
        this->ColDev = 1;
        if ( *v11 == 42 )
        {
          this->CurrentToken.Length = 2;
          this->CurrentToken.Type = TT_WhiteSpace;
          v12 = 0;
          while ( 1 )
          {
            if ( *v11 == 10 )
            {
              ++this->LineDev;
              this->ColDev = 0;
            }
            ++this->ColDev;
            if ( ++v11 == this->pEnd )
              break;
            if ( *v11 == 42 )
            {
              ++this->CurrentToken.Length;
              v12 = 1;
            }
            else
            {
              if ( v12 && *v11 == 47 )
              {
                v13 = this->ColDev + 1;
                ++this->CurrentToken.Length;
                this->ColDev = v13;
                break;
              }
              v12 = 0;
              ++this->CurrentToken.Length;
            }
          }
        }
        else
        {
          this->pCurr = this->pEnd;
          this->CurrentToken.Type = TT_EOF;
        }
      }
      else if ( Scaleform::GFx::Text::CSSTokenizer<wchar_t>::IsAlpha(this, v8) || v8 == 95 || v8 == 46 || v8 == 36 )
      {
        v19 = (wchar_t *)(v7 + 1);
        for ( this->ColDev = 1; v19 != this->pEnd; ++v19 )
        {
          v20 = *v19;
          if ( !Scaleform::GFx::Text::CSSTokenizer<wchar_t>::IsAlNum(this, *v19) && v20 != 45 && v20 != 95 )
            break;
          ++this->CurrentToken.Length;
          ++this->ColDev;
        }
        this->CurrentToken.Type = TT_Name;
      }
      else if ( v8 == 34 )
      {
        v14 = v7 + 1;
        for ( this->ColDev = 1; v14 != this->pEnd; ++v14 )
        {
          if ( *v14 == 34 )
            break;
          ++this->CurrentToken.Length;
          ++this->ColDev;
        }
        ++this->ColDev;
        ++this->CurrentToken.Length;
        this->CurrentToken.Type = TT_QString;
      }
      else if ( Scaleform::GFx::Text::CSSTokenizer<wchar_t>::IsDigit(this, v8) )
      {
        v15 = (wchar_t *)(v7 + 1);
        for ( this->ColDev = 1; v15 != this->pEnd; ++v15 )
        {
          v16 = *v15;
          if ( !Scaleform::GFx::Text::CSSTokenizer<wchar_t>::IsDigit(this, *v15) && v16 != 46 )
            break;
          ++this->CurrentToken.Length;
          ++this->ColDev;
        }
        this->CurrentToken.Type = TT_Number;
        if ( *v15 == 46 )
        {
          ++this->CurrentToken.Length;
          this->ColDev += 2;
          for ( i = v15 + 2; i != this->pEnd; ++i )
          {
            if ( !Scaleform::GFx::Text::CSSTokenizer<wchar_t>::IsDigit(this, *i) )
              break;
            ++this->CurrentToken.Length;
            ++this->ColDev;
          }
        }
      }
      else if ( v8 == 35 )
      {
        v18 = (wchar_t *)(v7 + 1);
        for ( this->ColDev = 1; v18 != this->pEnd; ++v18 )
        {
          if ( !Scaleform::GFx::Text::CSSTokenizer<wchar_t>::IsXDigit(this, *v18) )
            break;
          ++this->CurrentToken.Length;
          ++this->ColDev;
        }
        this->CurrentToken.Type = TT_HexNumber;
      }
      else
      {
        switch ( v8 )
        {
          case ',':
            this->CurrentToken.Type = TT_Comma;
            this->ColDev = 1;
            break;
          case ':':
            this->CurrentToken.Type = TT_Colon;
            this->ColDev = 1;
            break;
          case ';':
            this->CurrentToken.Type = TT_SemiColon;
            this->ColDev = 1;
            break;
          case '{':
            this->CurrentToken.Type = TT_OpenBrace;
            this->ColDev = 1;
            break;
          case '}':
            this->CurrentToken.Type = TT_CloseBrace;
            this->ColDev = 1;
            break;
          default:
            this->CurrentToken.Type = TT_Unknown;
            this->ColDev = 1;
            break;
        }
      }
    }
    v3 = result;
    pBase = this->CurrentToken.pBase;
    result->Type = this->CurrentToken.Type;
    v22 = this->CurrentToken.Length;
    result->pBase = pBase;
    result->Length = v22;
  }
  return v3;
}
