void __thiscall Scaleform::GFx::AS3::LoadQueueEntry::SetNotifyLoadInitCInterface(
        Scaleform::GFx::AS3::LoadQueueEntry *this,
        Scaleform::Ptr<Scaleform::GFx::AS3::NotifyLoadInitC> pinterface)
{
  Scaleform::GFx::AS3::NotifyLoadInitC *pObject; // ecx

  pObject = pinterface.pObject;
  if ( pinterface.pObject )
  {
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)pinterface.pObject);
    pObject = pinterface.pObject;
  }
  if ( this->NotifyLoadInitCInterface.pObject )
  {
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)this->NotifyLoadInitCInterface.pObject);
    pObject = pinterface.pObject;
  }
  this->NotifyLoadInitCInterface.pObject = pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pObject);
}
