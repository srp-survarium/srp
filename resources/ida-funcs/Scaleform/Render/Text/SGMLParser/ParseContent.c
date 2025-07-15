BOOL __thiscall Scaleform::Render::Text::SGMLParser<wchar_t>::ParseContent(
        Scaleform::Render::Text::SGMLParser<wchar_t> *this,
        const __m128i **ppContent,
        unsigned int *pcontentSize)
{
  unsigned int *v4; // ebp
  const __m128i **p_Iter; // edi
  bool DoContentParsing; // al
  char v7; // bl
  unsigned int CurChar; // eax
  int v9; // edx
  unsigned int BufSize; // eax
  unsigned int v11; // ebp
  wchar_t *pBuffer; // edx
  unsigned int v13; // eax
  unsigned int v14; // eax
  wchar_t *v15; // eax
  bool v16; // zf
  const wchar_t *pNextChar; // eax
  char v19; // [esp+9h] [ebp-5h]

  if ( this->CurState == 3 )
  {
    v4 = pcontentSize;
    p_Iter = (const __m128i **)&this->Iter;
    *ppContent = (const __m128i *)this->Iter.pCurChar;
    *pcontentSize = 0;
    DoContentParsing = this->Iter.DoContentParsing;
    v7 = 0;
    v19 = 0;
    this->Iter.DoContentParsing = 1;
    if ( !DoContentParsing && (*p_Iter)->m128i_i16[0] == 38 )
      Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
    if ( this->Iter.pCurChar < this->Iter.pEnd )
    {
      do
      {
        CurChar = this->Iter.CurChar;
        if ( CurChar == 60 && (!this->Iter.DoContentParsing || (*p_Iter)->m128i_i16[0] != 38) )
          break;
        if ( (v9 = Scaleform::UnicodeSpaceBits[BYTE1(CurChar)]) != 0
          && (v9 == 1
           || (v4 = pcontentSize,
               (Scaleform::UnicodeSpaceBits[v9 + ((unsigned __int8)CurChar >> 4)] & (1 << (CurChar & 0xF))) != 0))
          && this->CondenseWhite )
        {
          if ( !v7 )
          {
            this->BufPos = 0;
            Scaleform::Render::Text::SGMLParser<wchar_t>::AppendToBuf(this, *ppContent, *v4);
            v7 = 1;
            v19 = 1;
          }
          Scaleform::Render::Text::SGMLParser<wchar_t>::AppendCharToBuf(this, 0x20u);
          Scaleform::Render::Text::SGMLParser<wchar_t>::SkipSpaces(this);
        }
        else
        {
          if ( this->Iter.DoContentParsing && (*p_Iter)->m128i_i16[0] == 38 )
          {
            if ( !v7 )
            {
              this->BufPos = 0;
              Scaleform::Render::Text::SGMLParser<wchar_t>::AppendToBuf(this, *ppContent, *v4);
              v7 = 1;
              v19 = 1;
            }
            BufSize = this->BufSize;
            v11 = this->Iter.CurChar;
            if ( this->BufPos + 6 > BufSize )
            {
              pBuffer = this->pBuffer;
              v13 = BufSize + 6;
              this->BufSize = v13;
              v14 = 2 * v13;
              if ( pBuffer )
              {
                v15 = (wchar_t *)Scaleform::Memory::pGlobalHeap->Realloc(Scaleform::Memory::pGlobalHeap, pBuffer, v14);
                v7 = v19;
              }
              else
              {
                v15 = (wchar_t *)this->pHeap->Alloc(this->pHeap, v14, 0);
              }
              this->pBuffer = v15;
            }
            this->pBuffer[this->BufPos++] = v11;
            v4 = pcontentSize;
          }
          else if ( v7 )
          {
            Scaleform::Render::Text::SGMLParser<wchar_t>::AppendToBuf(
              this,
              *p_Iter,
              this->Iter.pNextChar - this->Iter.pCurChar);
          }
          else
          {
            *v4 += this->Iter.pNextChar - this->Iter.pCurChar;
          }
          v16 = !this->Iter.DoContentParsing;
          pNextChar = this->Iter.pNextChar;
          *p_Iter = (const __m128i *)pNextChar;
          if ( v16 || *pNextChar != 38 )
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
      while ( this->Iter.pCurChar < this->Iter.pEnd );
      if ( v7 )
      {
        *ppContent = (const __m128i *)this->pBuffer;
        *v4 = this->BufPos;
      }
    }
    if ( this->Iter.pCurChar < this->Iter.pEnd
      && (this->Iter.CurChar != 60 || this->Iter.DoContentParsing && (*p_Iter)->m128i_i16[0] == 38) )
    {
      this->CurState = 1;
    }
    else
    {
      this->CurState |= 0x8000u;
    }
    this->Iter.DoContentParsing = 0;
  }
  return this->CurState != 1;
}
