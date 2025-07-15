void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject::GlobalObject(
        Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject *this,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *Constructor; // eax

  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(
    this,
    vm,
    &Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject::CInfo);
  this->__vftable = (Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject_vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject::`vftable';
  Constructor = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)Scaleform::GFx::AS3::Traits::GetConstructor(vm->TraitsObject.pObject->ITraits.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->pConstructor,
    Constructor);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->InitScope.Data,
    0);
}
