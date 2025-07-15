void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::SetLoaderInfo(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        const Scaleform::GFx::AS3::Instances::fl_display::Loader *loader)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->pLoaderInfo,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)loader->pContentLoaderInfo.pObject);
}


void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::SetLoaderInfo(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *loaderInfo)
{
  unsigned int RefCount; // eax

  if ( this )
    this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->pLoaderInfo,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)loaderInfo);
  if ( this && ((unsigned __int8)this & 1) == 0 )
  {
    RefCount = this->RefCount;
    if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
    {
      this->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(this);
    }
  }
}
