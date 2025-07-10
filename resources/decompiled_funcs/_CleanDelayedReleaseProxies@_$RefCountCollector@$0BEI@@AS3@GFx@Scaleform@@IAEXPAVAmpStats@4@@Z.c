void __thiscall Scaleform::GFx::AS3::RefCountCollector<328>::CleanDelayedReleaseProxies(
        Scaleform::GFx::AS3::RefCountCollector<328> *this,
        Scaleform::AmpStats *ampStats)
{
  Scaleform::GFx::Resource *pObject; // ecx
  Scaleform::RefCountVImpl *v4; // esi
  Scaleform::GFx::Resource *v5; // ecx
  Scaleform::RefCountVImpl *v6; // edi

  pObject = (Scaleform::GFx::Resource *)this->HeadDelayedPtrRelease.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::AddRef(pObject);
  v4 = (Scaleform::RefCountVImpl *)this->HeadDelayedPtrRelease.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  this->HeadDelayedPtrRelease.pObject = 0;
  if ( v4 )
  {
    this->Flags |= 0x10u;
    while ( 1 )
    {
      v5 = (Scaleform::GFx::Resource *)v4[2].__vftable;
      if ( v5 )
        Scaleform::RefCountImpl::AddRef(v5);
      v6 = (Scaleform::RefCountVImpl *)v4[2].__vftable;
      if ( v6 )
        Scaleform::RefCountImpl::Release(v6);
      v4[2].__vftable = 0;
      if ( v6 )
        Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6);
      if ( v4 )
        Scaleform::RefCountImpl::Release(v4);
      v4 = v6;
      if ( !v6 )
        break;
      Scaleform::RefCountImpl::Release(v6);
    }
  }
}
