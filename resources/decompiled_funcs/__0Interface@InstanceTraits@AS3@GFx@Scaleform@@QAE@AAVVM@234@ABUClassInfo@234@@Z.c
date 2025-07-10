void __thiscall Scaleform::GFx::AS3::InstanceTraits::Interface::Interface(
        Scaleform::GFx::AS3::InstanceTraits::Interface *this,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::ClassInfo *ci)
{
  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(this, vm, ci);
  this->Flags |= 4u;
  this->__vftable = (Scaleform::GFx::AS3::InstanceTraits::Interface_vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
  this->MemSize = 32;
}
