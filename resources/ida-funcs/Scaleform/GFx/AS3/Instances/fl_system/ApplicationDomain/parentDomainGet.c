void __thiscall Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain::parentDomainGet(
        Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> *result)
{
  Scaleform::GFx::AS3::VMAppDomain *UsedSpace; // ebx
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *v4; // ecx
  unsigned int v5; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // edi
  Scaleform::GFx::AS3::Instances::fl::Object *v7; // eax
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *v8; // esi
  Scaleform::GFx::AS3::Traits *v9; // eax
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *v10; // ecx
  unsigned int RefCount; // eax

  UsedSpace = (Scaleform::GFx::AS3::VMAppDomain *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((Scaleform::GFx::AS3::SoundObject *)this->VMDomain);
  if ( UsedSpace )
  {
    pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject;
    v7 = (Scaleform::GFx::AS3::Instances::fl::Object *)Scaleform::GFx::AS3::Traits::Alloc(pObject);
    v8 = (Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *)v7;
    if ( v7 )
    {
      Scaleform::GFx::AS3::Instances::fl::Object::Object(v7, pObject);
      v9 = v8->pTraits.pObject;
      v8->__vftable = (Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain_vtbl *)&Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain::`vftable';
      v8->VMDomain = Scaleform::GFx::AS3::VM::GetFrameAppDomain(v9->pVM);
    }
    else
    {
      v8 = 0;
    }
    v10 = result->pObject;
    if ( v8 != result->pObject )
    {
      if ( v10 )
      {
        if ( ((unsigned __int8)v10 & 1) != 0 )
        {
          result->pObject = (Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *)((char *)v10 - 1);
          result->pObject = v8;
          v8->VMDomain = UsedSpace;
          return;
        }
        RefCount = v10->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v10->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v10);
        }
      }
      result->pObject = v8;
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
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *)((char *)v4 - 1);
        result->pObject = 0;
      }
      else
      {
        v5 = v4->RefCount;
        if ( (v5 & 0x3FFFFF) != 0 )
        {
          v4->RefCount = v5 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
        }
        result->pObject = 0;
      }
    }
  }
}
