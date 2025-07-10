Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> *__thiscall Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain::MakeInstanceS(
        Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain *t)
{
  Scaleform::GFx::AS3::Instances::fl::Catch *v3; // eax
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *v4; // esi
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> *v6; // eax

  v3 = (Scaleform::GFx::AS3::Instances::fl::Catch *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v4 = (Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *)v3;
  if ( v3 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v3, t);
    pObject = v4->pTraits.pObject;
    v4->__vftable = (Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain_vtbl *)&Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain::`vftable';
    v4->VMDomain = Scaleform::GFx::AS3::VM::GetFrameAppDomain(pObject->pVM);
    v6 = result;
    result->pObject = v4;
  }
  else
  {
    v6 = result;
    result->pObject = 0;
  }
  return v6;
}
