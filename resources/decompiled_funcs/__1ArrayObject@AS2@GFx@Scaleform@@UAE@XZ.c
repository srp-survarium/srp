void __thiscall Scaleform::GFx::AS2::ArrayObject::~ArrayObject(Scaleform::GFx::AS2::ArrayObject *this)
{
  volatile LONG *v2; // edi

  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::ArrayObject_vtbl *)&Scaleform::GFx::AS2::ArrayObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::ArrayObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  Scaleform::GFx::AS2::ArrayObject::Resize(this, 0);
  v2 = (volatile LONG *)(this->StringValue.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v2 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v2);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Elements.Data.Data);
  Scaleform::GFx::AS2::Object::~Object(this);
}
