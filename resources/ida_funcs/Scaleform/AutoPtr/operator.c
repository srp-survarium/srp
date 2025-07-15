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


Scaleform::AutoPtr<Scaleform::GFx::AS3::VTable> *__thiscall Scaleform::AutoPtr<Scaleform::GFx::AS3::VTable>::operator=(
        Scaleform::AutoPtr<Scaleform::GFx::AS3::VTable> *this,
        Scaleform::GFx::AS3::VTable *p)
{
  Scaleform::GFx::AS3::VTable *pObject; // esi

  pObject = this->pObject;
  if ( this->pObject != p )
  {
    if ( pObject && this->Owner )
    {
      this->Owner = 0;
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
        pObject->VTMethods.Data.Data,
        pObject->VTMethods.Data.Size);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject->VTMethods.Data.Data);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
    this->pObject = p;
  }
  this->Owner = p != 0;
  return this;
}


Scaleform::AutoPtr<Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *__thiscall Scaleform::AutoPtr<Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::operator=(
        Scaleform::AutoPtr<Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *p)
{
  Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *pObject; // edi

  pObject = this->pObject;
  if ( this->pObject != p )
  {
    if ( pObject && this->Owner )
    {
      this->Owner = 0;
      if ( pObject->Data.Data )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject->Data.Data);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)pObject);
    }
    this->pObject = p;
  }
  this->Owner = p != 0;
  return this;
}
