char __thiscall Scaleform::Render::MeshStagingBuffer::Initialize(
        Scaleform::Render::MeshStagingBuffer *this,
        Scaleform::MemoryHeap *pheap,
        unsigned int size)
{
  unsigned __int8 *v4; // eax

  if ( this->pBuffer && size != this->BufferSize )
    Scaleform::Render::MeshStagingBuffer::Reset(this);
  v4 = (unsigned __int8 *)pheap->Alloc(pheap, size, 0);
  this->pBuffer = v4;
  if ( !v4 )
    return 0;
  this->BufferSize = size;
  this->PinSizeLimit = size >> 1;
  this->TotalPinnedSize = 0;
  return 1;
}
