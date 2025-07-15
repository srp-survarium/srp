void __thiscall Scaleform::GFx::AS3::Instances::fl_events::Event::targetGet(
        Scaleform::GFx::AS3::Instances::fl_events::Event *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)result,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this->Target.pObject);
}
