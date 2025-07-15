void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::Socket(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Traits *pObject; // edx
  Scaleform::GFx::Resource *v4; // eax
  Scaleform::GFx::AS3::SocketThreadMgr *v5; // edi
  Scaleform::RefCountVImpl *v6; // ecx

  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcher(this, t);
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_net::Socket_vtbl *)&Scaleform::GFx::AS3::Instances::fl_net::Socket::`vftable';
  this->SockMgr.pObject = 0;
  pObject = this->pTraits.pObject;
  *((_DWORD *)this + 12) = *((_DWORD *)this + 12) & 0xFFFFFFE0 | 3;
  v4 = (Scaleform::GFx::Resource *)Scaleform::GFx::AS3::MovieRoot::AddSocket(
                                     (Scaleform::GFx::AS3::MovieRoot *)pObject->pVM[1].__vftable,
                                     1,
                                     0,
                                     this);
  v5 = (Scaleform::GFx::AS3::SocketThreadMgr *)v4;
  if ( v4 )
    Scaleform::RefCountImpl::AddRef(v4);
  v6 = (Scaleform::RefCountVImpl *)this->SockMgr.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  this->SockMgr.pObject = v5;
}
