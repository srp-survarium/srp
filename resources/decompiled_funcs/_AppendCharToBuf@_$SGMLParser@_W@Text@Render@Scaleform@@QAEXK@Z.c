void __thiscall Scaleform::Render::Text::SGMLParser<wchar_t>::AppendCharToBuf(
        Scaleform::Render::Text::SGMLParser<wchar_t> *this,
        wchar_t uniChar)
{
  unsigned int BufSize; // eax
  wchar_t *pBuffer; // edx
  unsigned int v5; // eax
  unsigned int v6; // eax
  wchar_t *v7; // eax

  BufSize = this->BufSize;
  if ( this->BufPos + 6 > BufSize )
  {
    pBuffer = this->pBuffer;
    v5 = BufSize + 6;
    this->BufSize = v5;
    v6 = 2 * v5;
    if ( pBuffer )
      v7 = (wchar_t *)Scaleform::Memory::pGlobalHeap->Realloc(Scaleform::Memory::pGlobalHeap, pBuffer, v6);
    else
      v7 = (wchar_t *)this->pHeap->Alloc(this->pHeap, v6, 0);
    this->pBuffer = v7;
  }
  this->pBuffer[this->BufPos++] = uniChar;
}
