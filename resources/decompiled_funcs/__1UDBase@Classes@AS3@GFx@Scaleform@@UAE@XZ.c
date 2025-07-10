void __thiscall Scaleform::GFx::AS3::Classes::UDBase::~UDBase(Scaleform::GFx::AS3::Classes::UDBase *this)
{
  Scaleform::GFx::AS3::Traits *v2; // ecx

  v2 = (Scaleform::GFx::AS3::Traits *)((int)this->pTraits.pObject & 0xFFFFFFFE);
  this->__vftable = (Scaleform::GFx::AS3::Classes::UDBase_vtbl *)&Scaleform::GFx::AS3::Classes::UDBase::`vftable';
  Scaleform::GFx::AS3::Traits::DestructTail(v2, this);
  Scaleform::GFx::AS3::Class::~Class(this);
}
