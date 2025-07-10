void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::SetLoaderInfo(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        const Scaleform::GFx::AS3::Instances::fl_display::Loader *loader)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->pLoaderInfo,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)loader->pContentLoaderInfo.pObject);
}
