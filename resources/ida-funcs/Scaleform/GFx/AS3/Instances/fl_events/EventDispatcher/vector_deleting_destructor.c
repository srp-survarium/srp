Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *__thiscall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::`vector deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *pObject; // edi

  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher_vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::`vftable';
  pObject = this->pImpl.pObject;
  if ( pObject )
  {
    if ( this->pImpl.Owner )
    {
      this->pImpl.Owner = 0;
      Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash::~ListenersHash(&pObject->Listeners);
      Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash::~ListenersHash(&pObject->CaptureListeners);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
    this->pImpl.pObject = 0;
  }
  this->pImpl.Owner = 0;
  Scaleform::GFx::AS3::Instance::~Instance(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
