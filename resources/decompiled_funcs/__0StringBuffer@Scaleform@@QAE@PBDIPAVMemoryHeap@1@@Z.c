void __thiscall Scaleform::StringBuffer::StringBuffer(
        Scaleform::StringBuffer *this,
        char *data,
        unsigned int dataSize,
        Scaleform::MemoryHeap *pheap)
{
  unsigned int v5; // edi

  v5 = dataSize;
  this->pData = 0;
  this->Size = 0;
  this->BufferSize = 0;
  this->GrowSize = 512;
  this->LengthIsSize = 0;
  this->pHeap = pheap;
  if ( data && dataSize )
  {
    if ( dataSize == -1 )
      v5 = strlen(data);
    Scaleform::StringBuffer::Resize(this, v5);
    memcpy((unsigned __int8 *)this->pData, (unsigned __int8 *)data, v5);
  }
}
