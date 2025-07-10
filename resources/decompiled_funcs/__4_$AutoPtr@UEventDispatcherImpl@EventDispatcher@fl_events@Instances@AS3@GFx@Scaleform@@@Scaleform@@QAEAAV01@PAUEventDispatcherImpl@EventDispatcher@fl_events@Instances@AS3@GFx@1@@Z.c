Scaleform::AutoPtr<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl> *__thiscall Scaleform::AutoPtr<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl>::operator=(
        Scaleform::AutoPtr<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl> *this,
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *p)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *pObject; // edi

  pObject = this->pObject;
  if ( this->pObject != p )
  {
    if ( pObject && this->Owner )
    {
      this->Owner = 0;
      Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash::~ListenersHash(&pObject->Listeners);
      Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash::~ListenersHash(&pObject->CaptureListeners);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
    this->pObject = p;
  }
  this->Owner = p != 0;
  return this;
}
