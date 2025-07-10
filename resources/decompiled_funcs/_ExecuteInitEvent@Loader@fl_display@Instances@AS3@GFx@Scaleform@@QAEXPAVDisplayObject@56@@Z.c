void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteInitEvent(
        Scaleform::GFx::AS3::Instances::fl_display::Loader *this,
        Scaleform::GFx::DisplayObject *obj)
{
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *pObject; // ecx

  pObject = this->pContentLoaderInfo.pObject;
  if ( pObject )
    Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteInitEvent(
      pObject,
      (Scaleform::GFx::AS3::Instances::fl_events::Event *)obj);
}
