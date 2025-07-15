void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteProgressEvent(
        Scaleform::GFx::AS3::Instances::fl_display::Loader *this,
        unsigned int bytesLoaded,
        unsigned int totalBytes)
{
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *pObject; // ecx

  pObject = this->pContentLoaderInfo.pObject;
  if ( pObject )
    Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteProgressEvent(pObject, bytesLoaded, totalBytes);
}
