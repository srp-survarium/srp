Scaleform::GFx::AS3::Classes::UDBase *__thiscall Scaleform::GFx::AS3::Classes::UDBase::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Classes::UDBase *this,
        char a2)
{
  Scaleform::GFx::AS3::Traits *v3; // ecx

  v3 = (Scaleform::GFx::AS3::Traits *)((int)this->pTraits.pObject & 0xFFFFFFFE);
  this->__vftable = (Scaleform::GFx::AS3::Classes::UDBase_vtbl *)&Scaleform::GFx::AS3::Classes::UDBase::`vftable';
  Scaleform::GFx::AS3::Traits::DestructTail(v3, this);
  Scaleform::GFx::AS3::Class::~Class(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
