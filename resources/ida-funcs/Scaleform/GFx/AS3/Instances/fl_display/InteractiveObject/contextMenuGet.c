void __thiscall Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::contextMenuGet(
        Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)result,
    (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&this->RelatedObj);
}
