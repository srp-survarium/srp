Scaleform::GFx::AS3::Instances::fl_net::Socket *__thiscall Scaleform::GFx::AS3::Instances::fl_media::SoundChannel::`vector deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  pObject = (Scaleform::RefCountVImpl *)this->SockMgr.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::~EventDispatcher(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
