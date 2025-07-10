void __thiscall Scaleform::GFx::AS3::ClassTraits::Traits::Traits(
        Scaleform::GFx::AS3::ClassTraits::Traits *this,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::ClassTraits::Traits *pt)
{
  Scaleform::GFx::AS3::ClassTraits::ClassClass *pObject; // ecx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **v5; // edi

  Scaleform::GFx::AS3::Traits::Traits(&this->Scaleform::GFx::AS3::Traits, vm, pt, 1, 0);
  this->__vftable = (Scaleform::GFx::AS3::ClassTraits::Traits_vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_system::SecurityDomain::`vftable';
  this->ITraits.pObject = 0;
  pObject = vm->TraitsClassClass.pObject;
  v5 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)pObject->ITraits.pObject;
  if ( !v5[17] )
    ((void (__thiscall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *))(*v5)->V.ValueA.Data.Data)(pObject->ITraits.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->pConstructor,
    v5[17]);
  this->Flags |= 0x20u;
  if ( !this->pParent.pObject )
    Scaleform::GFx::AS3::ClassTraits::Traits::RegisterSlots(this);
}
