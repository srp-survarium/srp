void __thiscall Scaleform::StringBuffer::StringBuffer(Scaleform::StringBuffer *this, Scaleform::MemoryHeap *pheap)
{
  this->pData = 0;
  this->Size = 0;
  this->BufferSize = 0;
  this->LengthIsSize = 0;
  this->GrowSize = 512;
  this->pHeap = pheap;
}


void __thiscall Scaleform::StringBuffer::StringBuffer(
        Scaleform::StringBuffer *this,
        const __m128i *data,
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
      v5 = strlen(data->m128i_i8);
    Scaleform::StringBuffer::Resize(this, v5);
    memcpy((int)this->pData, data, v5);
  }
}


void __thiscall Scaleform::StringBuffer::StringBuffer(
        Scaleform::StringBuffer *this,
        const __m128i *data,
        Scaleform::MemoryHeap *pheap)
{
  const __m128i *v3; // ebx
  unsigned int v5; // edi

  v3 = data;
  this->pData = 0;
  this->Size = 0;
  this->BufferSize = 0;
  this->GrowSize = 512;
  this->LengthIsSize = 0;
  this->pHeap = pheap;
  if ( !data )
    v3 = (const __m128i *)uri;
  v5 = strlen(v3->m128i_i8);
  Scaleform::StringBuffer::Resize(this, v5);
  memcpy((int)this->pData, v3, v5);
}
