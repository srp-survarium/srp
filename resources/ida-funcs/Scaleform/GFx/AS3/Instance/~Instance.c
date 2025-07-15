void __thiscall Scaleform::GFx::AS3::Instance::~Instance(Scaleform::GFx::AS3::Instance *this)
{
  Scaleform::GFx::AS3::Traits *v2; // ecx

  v2 = (Scaleform::GFx::AS3::Traits *)((int)this->pTraits.pObject & 0xFFFFFFFE);
  this->__vftable = (Scaleform::GFx::AS3::Instance_vtbl *)&Scaleform::GFx::AS3::Instance::`vftable';
  Scaleform::GFx::AS3::Traits::DestructTail(v2, this);
  Scaleform::GFx::AS3::Object::~Object(this);
}
