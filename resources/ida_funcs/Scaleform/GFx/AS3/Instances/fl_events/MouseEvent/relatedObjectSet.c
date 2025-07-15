void __thiscall Scaleform::GFx::AS3::Instances::fl_events::MouseEvent::relatedObjectSet(
        Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *value)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->RelatedObj,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)value);
}
