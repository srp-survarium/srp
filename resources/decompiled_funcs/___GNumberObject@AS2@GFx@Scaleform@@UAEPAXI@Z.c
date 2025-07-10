Scaleform::GFx::AS2::NumberObject *__thiscall Scaleform::GFx::AS2::NumberObject::`scalar deleting destructor'(
        Scaleform::GFx::AS2::NumberObject *this,
        char a2)
{
  volatile LONG *v3; // esi

  v3 = (volatile LONG *)(this->StringValue.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  Scaleform::GFx::AS2::Object::~Object(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
