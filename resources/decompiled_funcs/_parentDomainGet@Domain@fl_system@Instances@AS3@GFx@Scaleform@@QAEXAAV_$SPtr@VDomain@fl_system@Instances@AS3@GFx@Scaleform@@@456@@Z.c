void __thiscall Scaleform::GFx::AS3::Instances::fl_system::Domain::parentDomainGet(
        Scaleform::GFx::AS3::Instances::fl_system::Domain *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_system::Domain> *result)
{
  Scaleform::GFx::AS3::VMAppDomain *UsedSpace; // ebx
  Scaleform::GFx::AS3::Instances::fl_system::Domain *v4; // ecx
  unsigned int v5; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_system::Domain> *Instance; // eax
  Scaleform::GFx::AS3::Instances::fl_system::Domain *pV; // esi
  Scaleform::GFx::AS3::Instances::fl_system::Domain *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_system::Domain> v10; // [esp+8h] [ebp-4h] BYREF

  UsedSpace = (Scaleform::GFx::AS3::VMAppDomain *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((Scaleform::GFx::AS3::SoundObject *)this->VMDomain);
  if ( UsedSpace )
  {
    Instance = Scaleform::GFx::AS3::InstanceTraits::fl_system::Domain::MakeInstance(
                 &v10,
                 (Scaleform::GFx::AS3::InstanceTraits::fl_system::Domain *)this->pTraits.pObject);
    pV = Instance->pV;
    pObject = result->pObject;
    if ( Instance->pV != result->pObject )
    {
      if ( pObject )
      {
        if ( ((unsigned __int8)pObject & 1) != 0 )
        {
          result->pObject = (Scaleform::GFx::AS3::Instances::fl_system::Domain *)((char *)pObject - 1);
          result->pObject = pV;
          pV->VMDomain = UsedSpace;
          return;
        }
        RefCount = pObject->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
      result->pObject = pV;
    }
    result->pObject->VMDomain = UsedSpace;
  }
  else
  {
    v4 = result->pObject;
    if ( result->pObject )
    {
      if ( ((unsigned __int8)v4 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_system::Domain *)((char *)v4 - 1);
        result->pObject = 0;
      }
      else
      {
        v5 = v4->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & v5) != 0 )
        {
          v4->RefCount = v5 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
        }
        result->pObject = 0;
      }
    }
  }
}
