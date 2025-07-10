void __thiscall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::RemoveListenersForMovieDef(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        Scaleform::GFx::MovieDefImpl *defimpl)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *pObject; // eax

  pObject = this->pImpl.pObject;
  if ( pObject )
  {
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::RemoveListenersForMovieDef(
      this,
      defimpl,
      &pObject->CaptureListeners);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::RemoveListenersForMovieDef(
      this,
      defimpl,
      &this->pImpl.pObject->Listeners);
  }
}
