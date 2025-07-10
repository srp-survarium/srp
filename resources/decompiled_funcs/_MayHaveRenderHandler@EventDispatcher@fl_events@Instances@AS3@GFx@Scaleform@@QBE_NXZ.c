int __thiscall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::MayHaveRenderHandler(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *pObject; // eax

  pObject = this->pImpl.pObject;
  if ( pObject )
    return (pObject->Flags >> 3) & 1;
  else
    return 0;
}
