void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript::GlobalObjectScript(
        Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript *this,
        Scaleform::GFx::AS3::VMAbcFile *file,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Abc::ScriptInfo *script)
{
  Scaleform::GFx::AS3::VM *v4; // edi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *Constructor; // eax
  const Scaleform::GFx::AS3::Abc::ScriptInfo *v7; // [esp-Ch] [ebp-14h]

  v4 = vm;
  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(
    this,
    vm,
    &Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject::CInfo);
  this->__vftable = (Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript_vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject::`vftable';
  Constructor = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)Scaleform::GFx::AS3::Traits::GetConstructor(v4->TraitsObject.pObject->ITraits.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->pConstructor,
    Constructor);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->InitScope.Data,
    0);
  this->__vftable = (Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript_vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript::`vftable';
  this->File.pObject = file;
  if ( file )
    file->RefCount = (file->RefCount + 1) & 0x8FBFFFFF;
  v7 = script;
  this->Script = script;
  Scaleform::GFx::AS3::Traits::AddSlots(this, (Scaleform::GFx::AS3::CheckResult *)&vm, v7, file, 0x24u);
}
