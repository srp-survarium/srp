bool __thiscall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::HasButtonHandlers(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *pObject; // eax

  pObject = this->pImpl.pObject;
  if ( !pObject )
    return 0;
  return pObject->CaptureButtonHandlersCnt || pObject->ButtonHandlersCnt;
}
