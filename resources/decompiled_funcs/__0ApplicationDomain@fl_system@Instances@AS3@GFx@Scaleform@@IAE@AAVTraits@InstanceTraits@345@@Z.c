void __thiscall Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain::ApplicationDomain(
        Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Traits *pObject; // ecx

  Scaleform::GFx::AS3::Instances::fl::Object::Object((Scaleform::GFx::AS3::Instances::fl::Catch *)this, t);
  pObject = this->pTraits.pObject;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain_vtbl *)&Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain::`vftable';
  this->VMDomain = Scaleform::GFx::AS3::VM::GetFrameAppDomain(pObject->pVM);
}
