int __thiscall Scaleform::Render::Text::SGMLParser<wchar_t>::GetNext(
        Scaleform::Render::Text::SGMLParser<wchar_t> *this)
{
  int result; // eax
  int CurState; // eax
  Scaleform::Render::Text::SGMLCharIter<wchar_t> *p_Iter; // esi
  bool v5; // zf
  const wchar_t *pNextChar; // eax
  Scaleform::Render::Text::SGMLCharIter<wchar_t> *v7; // esi
  const wchar_t *v8; // eax
  Scaleform::Render::Text::SGMLCharIter<wchar_t> *v9; // esi
  int v10; // edi
  unsigned int CurChar; // eax
  const wchar_t *v12; // eax
  unsigned int v13; // eax
  int v14; // eax
  const wchar_t *v15; // eax
  const wchar_t *v16; // eax

  result = this->CurState;
  if ( result != 1 )
  {
    if ( (result & 0x8000) == 0 )
    {
      switch ( result )
      {
        case 2:
          Scaleform::Render::Text::SGMLParser<wchar_t>::SkipName(this);
          goto $LL34;
        case 3:
          p_Iter = &this->Iter;
          while ( this->Iter.pCurChar < this->Iter.pEnd )
          {
            if ( this->Iter.CurChar == 60 )
              break;
            v5 = !this->Iter.DoContentParsing;
            pNextChar = this->Iter.pNextChar;
            p_Iter->pCurChar = pNextChar;
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
          this->CurState = 32771;
          goto LABEL_30;
        case 4:
          v7 = &this->Iter;
          if ( this->Iter.pCurChar >= this->Iter.pEnd )
            goto LABEL_27;
          break;
        case 7:
        case 8:
$LL34:
          while ( 1 )
          {
            CurState = this->CurState;
            if ( CurState != 7 && CurState != 8 )
              break;
            Scaleform::Render::Text::SGMLParser<wchar_t>::SkipAttribute(this);
          }
          goto $LN33_6;
        case 9:
$LN33_6:
          if ( this->Iter.CurChar == 62 )
          {
            Scaleform::Render::Text::SGMLCharIter<wchar_t>::operator++(&this->Iter);
            this->CurState = 32770;
          }
          goto LABEL_30;
        default:
          goto LABEL_30;
      }
      do
      {
        if ( this->Iter.CurChar == 62 )
          goto LABEL_28;
        v5 = !this->Iter.DoContentParsing;
        v8 = this->Iter.pNextChar;
        v7->pCurChar = v8;
        if ( v5 || *v8 != 38 )
        {
          if ( v8 < this->Iter.pEnd )
          {
            this->Iter.CurChar = *v8;
            this->Iter.pNextChar = v8 + 1;
          }
        }
        else
        {
          Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
        }
      }
      while ( this->Iter.pCurChar < this->Iter.pEnd );
LABEL_27:
      if ( this->Iter.CurChar == 62 )
      {
LABEL_28:
        Scaleform::Render::Text::SGMLCharIter<wchar_t>::operator++(&this->Iter);
        this->CurState = 32772;
      }
      else
      {
        this->CurState = 1;
      }
    }
LABEL_30:
    result = 1;
    if ( this->CurState == 1 )
      return result;
    v9 = &this->Iter;
    v10 = 0;
    if ( this->Iter.pCurChar >= this->Iter.pEnd )
    {
LABEL_65:
      this->CurState = 0x8000;
      return this->CurState;
    }
    while ( 1 )
    {
      if ( v10 )
      {
LABEL_66:
        this->CurState = v10;
        return v10;
      }
      CurChar = this->Iter.CurChar;
      if ( !CurChar )
        goto LABEL_62;
      if ( CurChar != 47 )
      {
        if ( CurChar == 60 )
        {
          v5 = !this->Iter.DoContentParsing;
          v12 = this->Iter.pNextChar;
          v9->pCurChar = v12;
          if ( v5 || *v12 != 38 )
          {
            if ( v12 < this->Iter.pEnd )
            {
              this->Iter.CurChar = *v12;
              this->Iter.pNextChar = v12 + 1;
            }
          }
          else
          {
            Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
          }
          v13 = this->Iter.CurChar;
          if ( v13 == 33 )
          {
            Scaleform::Render::Text::SGMLParser<wchar_t>::SkipComment(this);
          }
          else if ( v13 == 47 )
          {
            Scaleform::Render::Text::SGMLCharIter<wchar_t>::operator++(&this->Iter);
            v10 = 4;
          }
          else
          {
            v10 = 2;
          }
        }
        else
        {
          v10 = 3;
        }
        goto LABEL_63;
      }
      v14 = this->CurState;
      if ( v14 == 9 || v14 == 6 )
        break;
      v10 = 3;
LABEL_63:
      if ( this->Iter.pCurChar >= this->Iter.pEnd )
      {
        if ( !v10 )
          goto LABEL_65;
        goto LABEL_66;
      }
    }
    v5 = !this->Iter.DoContentParsing;
    v15 = this->Iter.pNextChar;
    v9->pCurChar = v15;
    if ( v5 || *v15 != 38 )
    {
      if ( v15 < this->Iter.pEnd )
      {
        this->Iter.CurChar = *v15;
        this->Iter.pNextChar = v15 + 1;
      }
    }
    else
    {
      Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
    }
    if ( this->Iter.CurChar == 62 )
    {
      v5 = !this->Iter.DoContentParsing;
      v16 = this->Iter.pNextChar;
      v9->pCurChar = v16;
      if ( v5 || *v16 != 38 )
      {
        if ( v16 < this->Iter.pEnd )
        {
          this->Iter.CurChar = *v16;
          this->Iter.pNextChar = v16 + 1;
        }
        v10 = 32773;
      }
      else
      {
        Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
        v10 = 32773;
      }
      goto LABEL_63;
    }
LABEL_62:
    v10 = 1;
    goto LABEL_63;
  }
  return result;
}
