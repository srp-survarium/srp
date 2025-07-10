void __cdecl Scaleform::GFx::AS3::Instances::fl_display::ExecuteInitEventCFunc(
        const Scaleform::GFx::AS3::MovieRoot::ActionEntry *ae)
{
  Scaleform::GFx::AS3::RefCountCollector<328> *pRCC; // ecx
  Scaleform::GFx::AS3::NotifyLoadInitC *pObject; // ecx

  pRCC = ae->pAS3Obj.pObject[1]._pRCC;
  if ( pRCC )
    Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteInitEvent(
      (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)pRCC,
      (Scaleform::GFx::AS3::Instances::fl_events::Event *)ae->pCharacter.pObject);
  pObject = ae->pNLoadInitCL.pObject;
  if ( pObject )
    pObject->InitEventCallback(pObject);
}
