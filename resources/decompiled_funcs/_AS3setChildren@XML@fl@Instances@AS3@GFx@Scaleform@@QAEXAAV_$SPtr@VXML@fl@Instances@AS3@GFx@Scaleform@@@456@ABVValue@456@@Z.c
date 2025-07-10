void __thiscall Scaleform::GFx::AS3::Instances::fl::XML::AS3setChildren(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *result,
        const Scaleform::GFx::AS3::Value *value)
{
  this->SetChildren(this, value);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)result,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
}
