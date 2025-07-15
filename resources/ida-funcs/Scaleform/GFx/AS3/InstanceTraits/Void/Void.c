void __thiscall Scaleform::GFx::AS3::InstanceTraits::Void::Void(
        Scaleform::GFx::AS3::InstanceTraits::Void *this,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **pObject; // edi

  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(
    this,
    vm,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::InstanceTraits::Void::CInfo);
  this->__vftable = (Scaleform::GFx::AS3::InstanceTraits::Void_vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Prototype::`vftable';
  pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)vm->TraitsObject.pObject->ITraits.pObject;
  if ( !pObject[17] )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **))(*pObject)->V.ValueA.Data.pHeap)(pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->pConstructor,
    pObject[17]);
  this->__vftable = (Scaleform::GFx::AS3::InstanceTraits::Void_vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Prototype::`vftable';
}
