void __thiscall Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::applicationDomainGet(
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> *result)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *ITraitsApplicationDomain; // esi
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *v4; // eax
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *v5; // eax
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *v6; // edi
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *pObject; // ecx
  unsigned int RefCount; // eax

  ITraitsApplicationDomain = Scaleform::GFx::AS3::VM::GetITraitsApplicationDomain(this->pTraits.pObject->pVM);
  v4 = (Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *)Scaleform::GFx::AS3::Traits::Alloc(ITraitsApplicationDomain);
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain::ApplicationDomain(v4, ITraitsApplicationDomain);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  pObject = result->pObject;
  if ( v6 != result->pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *)((char *)pObject - 1);
        result->pObject = v6;
        Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain::SetAppDomain(v6, this->AppDomain);
        return;
      }
      RefCount = pObject->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
    result->pObject = v6;
  }
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain::SetAppDomain(result->pObject, this->AppDomain);
}


Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> *__thiscall Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::applicationDomainGet(
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> *result)
{
  result->pObject = 0;
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::applicationDomainGet(this, result);
  return result;
}
