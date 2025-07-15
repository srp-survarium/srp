void __thiscall Scaleform::GFx::AS2::NumberObject::Finalize_GC(Scaleform::GFx::AS2::NumberObject *this)
{
  volatile LONG *v2; // esi

  v2 = (volatile LONG *)(this->StringValue.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v2 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v2);
  Scaleform::GFx::AS2::Object::Finalize_GC(this);
}
