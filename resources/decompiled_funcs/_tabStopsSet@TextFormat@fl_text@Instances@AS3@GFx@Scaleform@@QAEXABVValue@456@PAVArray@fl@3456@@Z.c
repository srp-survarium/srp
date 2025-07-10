void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextFormat::tabStopsSet(
        Scaleform::GFx::AS3::Instances::fl_text::TextFormat *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl::Array *value)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->mTabStops,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)value);
}
