char __thiscall Scaleform::WStringBuffer::Resize(Scaleform::WStringBuffer *this, unsigned int size)
{
  unsigned __int8 *v3; // edi

  if ( size <= this->Length || size < this->Reserved.Size )
  {
    if ( this->pText )
      this->pText[size] = 0;
    this->Length = size;
    return 1;
  }
  else
  {
    v3 = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 2 * size + 2, 0);
    if ( v3 )
    {
      if ( this->pText )
        memcpy(v3, (unsigned __int8 *)this->pText, 2 * this->Length + 2);
      *(_WORD *)&v3[2 * size] = 0;
      if ( this->pText != this->Reserved.pBuffer )
      {
        if ( this->pText )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pText);
      }
      this->pText = (wchar_t *)v3;
      this->Length = size;
      return 1;
    }
    else
    {
      return 0;
    }
  }
}
