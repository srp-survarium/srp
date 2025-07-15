void __thiscall Scaleform::GFx::AS2::SharedObject::~SharedObject(Scaleform::GFx::AS2::SharedObject *this)
{
  volatile LONG *v2; // esi
  volatile LONG *v3; // esi

  v2 = (volatile LONG *)(this->LocalPath.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v2 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v2);
  v3 = (volatile LONG *)(this->Name.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  Scaleform::GFx::AS2::Object::~Object(this);
}
