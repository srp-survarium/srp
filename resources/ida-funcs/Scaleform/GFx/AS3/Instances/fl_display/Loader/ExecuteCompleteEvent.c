void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteCompleteEvent(
        Scaleform::GFx::AS3::Instances::fl_display::Loader *this)
{
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *pObject; // ecx

  pObject = this->pContentLoaderInfo.pObject;
  if ( pObject )
    Scaleform::GFx::AS3::Instances::fl_net::URLLoader::ExecuteCompleteEvent((Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pObject);
}
