void __thiscall Scaleform::GFx::AS3::InstanceTraits::Function::Function(
        Scaleform::GFx::AS3::InstanceTraits::Function *this,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::ClassInfo *ci)
{
  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(this, vm, ci);
  this->__vftable = (Scaleform::GFx::AS3::InstanceTraits::Function_vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Function::`vftable';
  this->MethodInfoInd.Ind = 0;
  this->File.pObject = 0;
  this->GOS.pObject = 0;
  this->TraitsType = Traits_Function;
  this->MemSize = 72;
  Scaleform::GFx::AS3::InstanceTraits::Function::RegisterSlots(this);
}
