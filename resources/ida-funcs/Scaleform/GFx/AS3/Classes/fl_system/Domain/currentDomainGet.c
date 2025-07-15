void __thiscall Scaleform::GFx::AS3::Classes::fl_system::Domain::currentDomainGet(
        Scaleform::GFx::AS3::Classes::fl_system::Domain *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_system::Domain> *result)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_system::Domain> *Instance; // eax
  Scaleform::GFx::AS3::Instances::fl_system::Domain *pV; // esi
  Scaleform::GFx::AS3::Instances::fl_system::Domain *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_system::Domain> v7; // [esp+Ch] [ebp-4h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_system::Domain::MakeInstance(
               &v7,
               (Scaleform::GFx::AS3::InstanceTraits::fl_system::Domain *)this->pTraits.pObject[1].__vftable);
  pV = Instance->pV;
  pObject = result->pObject;
  if ( Instance->pV != result->pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_system::Domain *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
    result->pObject = pV;
  }
  result->pObject->VMDomain = this->pTraits.pObject->pVM->CurrentDomain;
}
