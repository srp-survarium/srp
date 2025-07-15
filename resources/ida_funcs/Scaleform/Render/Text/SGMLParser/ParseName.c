void __thiscall Scaleform::Render::Text::SGMLParser<wchar_t>::ParseName(
        Scaleform::Render::Text::SGMLParser<wchar_t> *this,
        const wchar_t **ppname,
        unsigned int *plen)
{
  unsigned int *v3; // ebp
  Scaleform::Render::Text::SGMLCharIter<wchar_t> *p_Iter; // edi
  char v6; // bl
  unsigned int CurChar; // eax
  int v8; // ecx
  int v9; // edx
  unsigned int BufSize; // eax
  unsigned int v11; // ebp
  wchar_t *pBuffer; // edx
  unsigned int v13; // eax
  unsigned int v14; // eax
  wchar_t *v15; // eax
  bool v16; // zf
  const wchar_t *pNextChar; // eax
  bool isInBuf; // [esp+13h] [ebp-5h]

  v3 = plen;
  p_Iter = &this->Iter;
  *ppname = this->Iter.pCurChar;
  *plen = 0;
  v6 = 0;
  isInBuf = 0;
  if ( this->Iter.pCurChar < this->Iter.pEnd )
  {
    do
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
      v8 = BYTE1(CurChar);
      v9 = Scaleform::UnicodeSpaceBits[v8];
      if ( Scaleform::UnicodeSpaceBits[v8] )
      {
        if ( v9 == 1 )
          break;
        v3 = plen;
        if ( (Scaleform::UnicodeSpaceBits[v9 + ((unsigned __int8)CurChar >> 4)] & (1 << (CurChar & 0xF))) != 0 )
          break;
      }
      if ( this->Iter.DoContentParsing && *p_Iter->pCurChar == 38 )
      {
        if ( !v6 )
        {
          this->BufPos = 0;
          Scaleform::Render::Text::SGMLParser<wchar_t>::AppendToBuf(this, (wchar_t *)*ppname, *v3);
          v6 = 1;
          isInBuf = 1;
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
            v6 = isInBuf;
          }
          else
          {
            v15 = (wchar_t *)this->pHeap->Alloc(this->pHeap, v14, 0);
          }
          this->pBuffer = v15;
        }
        this->pBuffer[this->BufPos++] = v11;
        v3 = plen;
      }
      else if ( v6 )
      {
        Scaleform::Render::Text::SGMLParser<wchar_t>::AppendToBuf(
          this,
          (wchar_t *)p_Iter->pCurChar,
          this->Iter.pNextChar - this->Iter.pCurChar);
      }
      else
      {
        *v3 += this->Iter.pNextChar - this->Iter.pCurChar;
      }
      v16 = !this->Iter.DoContentParsing;
      pNextChar = this->Iter.pNextChar;
      p_Iter->pCurChar = pNextChar;
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
    while ( this->Iter.pCurChar < this->Iter.pEnd );
    if ( v6 )
    {
      *ppname = this->pBuffer;
      *v3 = this->BufPos;
    }
  }
}
