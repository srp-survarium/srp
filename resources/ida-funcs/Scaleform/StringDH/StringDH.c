void __thiscall Scaleform::StringDH::StringDH(Scaleform::StringDH *this, Scaleform::MemoryHeap *pheap)
{
  this->pHeap = pheap;
  InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1);
  this->HeapTypeBits = (unsigned int)&Scaleform::String::NullData.Size + 2;
}
