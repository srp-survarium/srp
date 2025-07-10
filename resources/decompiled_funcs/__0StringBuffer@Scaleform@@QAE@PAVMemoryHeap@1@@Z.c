void __thiscall Scaleform::StringBuffer::StringBuffer(Scaleform::StringBuffer *this, Scaleform::MemoryHeap *pheap)
{
  this->pData = 0;
  this->Size = 0;
  this->BufferSize = 0;
  this->LengthIsSize = 0;
  this->GrowSize = 512;
  this->pHeap = pheap;
}
