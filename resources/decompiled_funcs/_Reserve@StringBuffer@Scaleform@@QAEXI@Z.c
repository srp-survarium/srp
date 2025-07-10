void __thiscall Scaleform::StringBuffer::Reserve(Scaleform::StringBuffer *this, unsigned int _size)
{
  char *pData; // edx
  unsigned int v3; // eax

  if ( _size >= this->BufferSize )
  {
    pData = this->pData;
    v3 = ~(this->GrowSize - 1) & (this->GrowSize + _size);
    this->BufferSize = v3;
    if ( pData )
      this->pData = (char *)Scaleform::Memory::pGlobalHeap->Realloc(Scaleform::Memory::pGlobalHeap, pData, v3);
    else
      this->pData = (char *)this->pHeap->Alloc(this->pHeap, v3, 0);
  }
}
