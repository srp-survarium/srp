void __thiscall Scaleform::GFx::AS3::RefCountCollector<328>::AddDelayedReleaseProxy(
        Scaleform::GFx::AS3::RefCountCollector<328> *this,
        Scaleform::GFx::Resource *preleaseProxy)
{
  Scaleform::RefCountVImpl *v3; // ecx
  Scaleform::RefCountVImpl *v4; // ecx
  Scaleform::GFx::Resource *pObject; // ecx
  Scaleform::RefCountVImpl *Value; // ecx
  Scaleform::RefCountVImpl *v7; // ecx

  if ( preleaseProxy )
  {
    if ( this->HeadDelayedPtrRelease.pObject )
    {
      pObject = (Scaleform::GFx::Resource *)this->HeadDelayedPtrRelease.pObject;
      if ( pObject )
        Scaleform::RefCountImpl::AddRef(pObject);
      Value = (Scaleform::RefCountVImpl *)preleaseProxy[1].RefCount.Value;
      if ( Value )
        Scaleform::RefCountImpl::Release(Value);
      preleaseProxy[1].RefCount.Value = (volatile int)this->HeadDelayedPtrRelease.pObject;
      Scaleform::RefCountImpl::AddRef(preleaseProxy);
      v7 = (Scaleform::RefCountVImpl *)this->HeadDelayedPtrRelease.pObject;
      if ( v7 )
        Scaleform::RefCountImpl::Release(v7);
      this->HeadDelayedPtrRelease.pObject = (Scaleform::GFx::AS3::PtrReleaseProxy<328> *)preleaseProxy;
    }
    else
    {
      Scaleform::RefCountImpl::AddRef(preleaseProxy);
      v3 = (Scaleform::RefCountVImpl *)this->HeadDelayedPtrRelease.pObject;
      if ( v3 )
        Scaleform::RefCountImpl::Release(v3);
      this->HeadDelayedPtrRelease.pObject = (Scaleform::GFx::AS3::PtrReleaseProxy<328> *)preleaseProxy;
      v4 = (Scaleform::RefCountVImpl *)preleaseProxy[1].RefCount.Value;
      if ( v4 )
        Scaleform::RefCountImpl::Release(v4);
      preleaseProxy[1].RefCount.Value = 0;
    }
  }
}
