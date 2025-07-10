void __thiscall Scaleform::GFx::AS3::InstanceTraits::Prototype::Prototype(
        Scaleform::GFx::AS3::InstanceTraits::Prototype *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::ASStringNode *ci,
        Scaleform::GFx::AS3::Class *c)
{
  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(this, vm, ci);
  this->__vftable = (Scaleform::GFx::AS3::InstanceTraits::Prototype_vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Prototype::`vftable';
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->pConstructor,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)c);
}
