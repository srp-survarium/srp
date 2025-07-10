int __thiscall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::MayHaveDeactivateHandler(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *pObject; // eax

  pObject = this->pImpl.pObject;
  if ( pObject )
    return (pObject->Flags >> 2) & 1;
  else
    return 0;
}
