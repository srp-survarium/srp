bool __thiscall Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttributeValue(
        Scaleform::Render::Text::SGMLParser<wchar_t> *this,
        const __m128i **ppattrValue,
        unsigned int *pattrValueSz)
{
  unsigned int CurChar; // eax
  bool v5; // zf
  const wchar_t *pNextChar; // eax
  const __m128i **p_Iter; // edi
  unsigned int *v8; // ebp
  bool DoContentParsing; // al
  char v10; // bl
  unsigned int BufSize; // eax
  unsigned int v12; // ebp
  wchar_t *pBuffer; // edx
  unsigned int v14; // eax
  unsigned int v15; // eax
  wchar_t *v16; // eax
  const wchar_t *v17; // eax
  const wchar_t *v18; // eax
  unsigned int v19; // eax
  bool result; // al
  bool v21; // [esp+8h] [ebp-6h]
  char v22; // [esp+9h] [ebp-5h]
  unsigned int v23; // [esp+Ah] [ebp-4h]

  v21 = 0;
  if ( this->CurState == 8 )
  {
    CurChar = this->Iter.CurChar;
    v23 = CurChar;
    if ( CurChar == 34 || CurChar == 39 )
    {
      v5 = !this->Iter.DoContentParsing;
      pNextChar = this->Iter.pNextChar;
      p_Iter = (const __m128i **)&this->Iter;
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
      v8 = pattrValueSz;
      *ppattrValue = *p_Iter;
      *pattrValueSz = 0;
      DoContentParsing = this->Iter.DoContentParsing;
      v10 = 0;
      v22 = 0;
      this->Iter.DoContentParsing = 1;
      if ( !DoContentParsing && (*p_Iter)->m128i_i16[0] == 38 )
        Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
      while ( this->Iter.pCurChar < this->Iter.pEnd )
      {
        if ( this->Iter.CurChar == v23 )
          break;
        if ( this->Iter.DoContentParsing && (*p_Iter)->m128i_i16[0] == 38 )
        {
          if ( !v10 )
          {
            this->BufPos = 0;
            Scaleform::Render::Text::SGMLParser<wchar_t>::AppendToBuf(this, *ppattrValue, *v8);
            v10 = 1;
            v22 = 1;
          }
          BufSize = this->BufSize;
          v12 = this->Iter.CurChar;
          if ( this->BufPos + 6 > BufSize )
          {
            pBuffer = this->pBuffer;
            v14 = BufSize + 6;
            this->BufSize = v14;
            v15 = 2 * v14;
            if ( pBuffer )
            {
              v16 = (wchar_t *)Scaleform::Memory::pGlobalHeap->Realloc(Scaleform::Memory::pGlobalHeap, pBuffer, v15);
              v10 = v22;
            }
            else
            {
              v16 = (wchar_t *)this->pHeap->Alloc(this->pHeap, v15, 0);
            }
            this->pBuffer = v16;
          }
          this->pBuffer[this->BufPos++] = v12;
          v8 = pattrValueSz;
        }
        else if ( v10 )
        {
          Scaleform::Render::Text::SGMLParser<wchar_t>::AppendToBuf(
            this,
            *p_Iter,
            this->Iter.pNextChar - this->Iter.pCurChar);
        }
        else
        {
          *v8 += this->Iter.pNextChar - this->Iter.pCurChar;
        }
        v5 = !this->Iter.DoContentParsing;
        v17 = this->Iter.pNextChar;
        *p_Iter = (const __m128i *)v17;
        if ( v5 || *v17 != 38 )
        {
          if ( v17 < this->Iter.pEnd )
          {
            this->Iter.CurChar = *v17;
            this->Iter.pNextChar = v17 + 1;
          }
        }
        else
        {
          Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
        }
      }
      this->Iter.DoContentParsing = 0;
      if ( v10 )
      {
        *ppattrValue = (const __m128i *)this->pBuffer;
        *v8 = this->BufPos;
      }
      if ( this->Iter.pCurChar < this->Iter.pEnd )
      {
        v5 = !this->Iter.DoContentParsing;
        v18 = this->Iter.pNextChar;
        v21 = 1;
        *p_Iter = (const __m128i *)v18;
        if ( v5 || *v18 != 38 )
        {
          if ( v18 < this->Iter.pEnd )
          {
            this->Iter.CurChar = *v18;
            this->Iter.pNextChar = v18 + 1;
          }
        }
        else
        {
          Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
        }
        Scaleform::Render::Text::SGMLParser<wchar_t>::SkipSpaces(this);
        v19 = this->Iter.CurChar;
        if ( v19 == 62 || v19 == 47 )
          this->CurState = 9;
        else
          this->CurState = 7;
      }
      else
      {
        this->CurState = 1;
      }
    }
    else
    {
      this->CurState = 1;
    }
  }
  result = v21;
  if ( this->Iter.pCurChar >= this->Iter.pEnd )
    this->CurState = 1;
  return result;
}
