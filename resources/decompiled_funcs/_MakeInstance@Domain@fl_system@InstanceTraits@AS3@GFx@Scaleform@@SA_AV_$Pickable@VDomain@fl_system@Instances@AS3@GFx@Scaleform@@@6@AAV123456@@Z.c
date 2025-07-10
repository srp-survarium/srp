Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_system::Domain> *__cdecl Scaleform::GFx::AS3::InstanceTraits::fl_system::Domain::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_system::Domain> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_system::Domain *t)
{
  Scaleform::GFx::AS3::Instances::fl::Catch *v2; // eax
  Scaleform::GFx::AS3::Instances::fl_system::Domain *v3; // esi
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_system::Domain> *v5; // eax

  v2 = (Scaleform::GFx::AS3::Instances::fl::Catch *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v3 = (Scaleform::GFx::AS3::Instances::fl_system::Domain *)v2;
  if ( v2 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v2, t);
    pObject = v3->pTraits.pObject;
    v3->__vftable = (Scaleform::GFx::AS3::Instances::fl_system::Domain_vtbl *)&Scaleform::GFx::AS3::Instances::fl_system::Domain::`vftable';
    v3->VMDomain = Scaleform::GFx::AS3::VM::GetFrameAppDomain(pObject->pVM);
    v5 = result;
    v3->Files.Data.Data = 0;
    v3->Files.Data.Size = 0;
    v3->Files.Data.Policy.Capacity = 0;
    v3->FileData.Data.Data = 0;
    v3->FileData.Data.Size = 0;
    v3->FileData.Data.Policy.Capacity = 0;
    result->pV = v3;
  }
  else
  {
    v5 = result;
    result->pV = 0;
  }
  return v5;
}
