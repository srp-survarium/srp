void __thiscall Scaleform::Render::Text::SGMLParser<wchar_t>::AppendToBuf(
        Scaleform::Render::Text::SGMLParser<wchar_t> *this,
        wchar_t *pstr,
        unsigned int sz)
{
  unsigned int BufSize; // eax
  wchar_t *pBuffer; // edx
  unsigned int v6; // eax
  unsigned int v7; // eax
  wchar_t *v8; // eax

  BufSize = this->BufSize;
  if ( sz + this->BufPos > BufSize )
  {
    pBuffer = this->pBuffer;
    v6 = sz + BufSize;
    this->BufSize = v6;
    v7 = 2 * v6;
    if ( pBuffer )
      v8 = (wchar_t *)Scaleform::Memory::pGlobalHeap->Realloc(Scaleform::Memory::pGlobalHeap, pBuffer, v7);
    else
      v8 = (wchar_t *)this->pHeap->Alloc(this->pHeap, v7, 0);
    this->pBuffer = v8;
  }
  memcpy((unsigned __int8 *)&this->pBuffer[this->BufPos], (unsigned __int8 *)pstr, 2 * sz);
  this->BufPos += sz;
}
