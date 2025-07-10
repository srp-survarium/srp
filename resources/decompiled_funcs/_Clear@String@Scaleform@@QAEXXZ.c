void __thiscall Scaleform::String::Clear(Scaleform::String *this)
{
  volatile LONG *v2; // esi

  InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1);
  v2 = (volatile LONG *)(this->HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v2 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v2);
  this->HeapTypeBits = (unsigned int)&Scaleform::String::NullData | this->HeapTypeBits & 3;
}
