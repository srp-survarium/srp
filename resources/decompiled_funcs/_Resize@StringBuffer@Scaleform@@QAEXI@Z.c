void __thiscall Scaleform::StringBuffer::Resize(Scaleform::StringBuffer *this, unsigned int _size)
{
  char *pData; // edx
  unsigned int v4; // eax
  char *v5; // eax
  char *v6; // esi

  if ( _size >= this->BufferSize )
  {
    pData = this->pData;
    v4 = ~(this->GrowSize - 1) & (this->GrowSize + _size);
    this->BufferSize = v4;
    if ( pData )
      v5 = (char *)Scaleform::Memory::pGlobalHeap->Realloc(Scaleform::Memory::pGlobalHeap, pData, v4);
    else
      v5 = (char *)this->pHeap->Alloc(this->pHeap, v4, 0);
    this->pData = v5;
  }
  this->LengthIsSize = 0;
  this->Size = _size;
  v6 = this->pData;
  if ( v6 )
    v6[_size] = 0;
}
