void __thiscall Scaleform::GFx::AS3::Instances::fl::XML::AS3removeNamespace(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *result,
        const Scaleform::GFx::AS3::Value *ns)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v3; // eax

  v3 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this->RemoveNamespace(this, ns);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)result,
    v3);
}
