void __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::NumberObject,Scaleform::GFx::AS2::Environment>::Finalize_GC(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::NumberObject,Scaleform::GFx::AS2::Environment> *this)
{
  Scaleform::GFx::AS2::GASPrototypeBase::InterfacesArray *pInterfaces; // eax
  volatile LONG *v3; // esi

  pInterfaces = this->pInterfaces;
  if ( pInterfaces )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pInterfaces->Data.Data);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pInterfaces);
  }
  v3 = (volatile LONG *)(this->StringValue.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  Scaleform::GFx::AS2::Object::Finalize_GC(this);
}
