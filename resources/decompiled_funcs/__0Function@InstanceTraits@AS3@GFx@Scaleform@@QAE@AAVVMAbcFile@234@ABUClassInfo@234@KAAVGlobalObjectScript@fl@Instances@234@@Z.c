void __thiscall Scaleform::GFx::AS3::InstanceTraits::Function::Function(
        Scaleform::GFx::AS3::InstanceTraits::Function *this,
        Scaleform::GFx::AS3::VMAbcFile *file,
        const Scaleform::GFx::AS3::ClassInfo *ci,
        unsigned int mi,
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *gos)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *Constructor; // eax

  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(this, file->VMRef, ci);
  this->__vftable = (Scaleform::GFx::AS3::InstanceTraits::Function_vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Function::`vftable';
  this->MethodInfoInd.Ind = mi;
  this->File.pObject = file;
  file->RefCount = (file->RefCount + 1) & 0x8FBFFFFF;
  this->GOS.pObject = gos;
  if ( gos )
    gos->RefCount = (gos->RefCount + 1) & 0x8FBFFFFF;
  Constructor = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)Scaleform::GFx::AS3::Traits::GetConstructor(file->VMRef->TraitsFunction.pObject->ITraits.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->pConstructor,
    Constructor);
  this->TraitsType = Traits_Function;
  this->MemSize = 72;
  Scaleform::GFx::AS3::InstanceTraits::Function::RegisterSlots(this);
}
