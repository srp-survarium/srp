void __thiscall Scaleform::GFx::AS3::Classes::fl_system::ApplicationDomain::currentDomainGet(
        Scaleform::GFx::AS3::Classes::fl_system::ApplicationDomain *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> *result)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v3; // edi
  Scaleform::GFx::AS3::Instances::fl::Object *v4; // eax
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *v5; // esi
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *v7; // ecx
  unsigned int RefCount; // eax

  v3 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject[1].__vftable;
  v4 = (Scaleform::GFx::AS3::Instances::fl::Object *)Scaleform::GFx::AS3::Traits::Alloc(v3);
  v5 = (Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v4, v3);
    pObject = v5->pTraits.pObject;
    v5->__vftable = (Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain_vtbl *)&Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain::`vftable';
    v5->VMDomain = Scaleform::GFx::AS3::VM::GetFrameAppDomain(pObject->pVM);
  }
  else
  {
    v5 = 0;
  }
  v7 = result->pObject;
  if ( v5 != result->pObject )
  {
    if ( v7 )
    {
      if ( ((unsigned __int8)v7 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *)((char *)v7 - 1);
      }
      else
      {
        RefCount = v7->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v7->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
        }
      }
    }
    result->pObject = v5;
  }
  result->pObject->VMDomain = this->pTraits.pObject->pVM->CurrentDomain;
}
