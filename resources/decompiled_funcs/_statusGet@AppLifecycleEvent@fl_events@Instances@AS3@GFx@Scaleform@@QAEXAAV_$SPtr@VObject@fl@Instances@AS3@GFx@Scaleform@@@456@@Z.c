void __thiscall Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent::statusGet(
        Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *result)
{
  if ( (this->Status.Flags & 0x1F) - 12 <= 3 )
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)result,
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this->Status.value.VS._1.VInt);
}
