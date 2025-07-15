void __thiscall Scaleform::WStringBuffer::~WStringBuffer(Scaleform::WStringBuffer *this)
{
  wchar_t *pText; // eax

  pText = this->pText;
  if ( this->pText != this->Reserved.pBuffer )
  {
    if ( pText )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pText);
  }
}
