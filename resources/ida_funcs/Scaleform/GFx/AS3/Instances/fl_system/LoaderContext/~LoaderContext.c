void __thiscall Scaleform::GFx::AS3::Instances::fl_system::LoaderContext::~LoaderContext(
        Scaleform::GFx::AS3::Instances::fl_system::LoaderContext *this)
{
  Scaleform::GFx::AS3::Instances::fl_system::SecurityDomain *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *v4; // ecx
  unsigned int v5; // eax

  pObject = this->securityDomain.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->securityDomain.pObject = (Scaleform::GFx::AS3::Instances::fl_system::SecurityDomain *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  v4 = this->applicationDomain.pObject;
  if ( v4 )
  {
    if ( ((unsigned __int8)v4 & 1) != 0 )
    {
      this->applicationDomain.pObject = (Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *)((char *)v4 - 1);
      Scaleform::GFx::AS3::Instance::~Instance(this);
      return;
    }
    v5 = v4->RefCount;
    if ( ((unsigned int)&byte_3FFFFF & v5) != 0 )
    {
      v4->RefCount = v5 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
    }
  }
  Scaleform::GFx::AS3::Instance::~Instance(this);
}
