void __cdecl Scaleform::GFx::AS3::Instances::fl_display::ExecuteCompleteEventCFunc(
        const Scaleform::GFx::AS3::MovieRoot::ActionEntry *ae)
{
  Scaleform::GFx::AS3::RefCountCollector<328> *pRCC; // ecx

  pRCC = ae->pAS3Obj.pObject[1]._pRCC;
  if ( pRCC )
    Scaleform::GFx::AS3::Instances::fl_net::URLLoader::ExecuteCompleteEvent((Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pRCC);
}
