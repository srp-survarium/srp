void __thiscall Scaleform::String::~String(Scaleform::String *this)
{
  volatile LONG *v1; // esi

  v1 = (volatile LONG *)(this->HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v1 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v1);
}
