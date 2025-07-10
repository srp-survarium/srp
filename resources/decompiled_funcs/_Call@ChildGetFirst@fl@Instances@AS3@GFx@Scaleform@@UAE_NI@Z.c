char __thiscall Scaleform::GFx::AS3::Instances::fl::ChildGetFirst::Call(
        Scaleform::GFx::AS3::Instances::fl::ChildGetFirst *this,
        unsigned int ind)
{
  bool v3; // zf
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *p_First; // ecx

  v3 = this->First.pObject == 0;
  p_First = &this->First;
  if ( v3 )
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)p_First,
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this->Element->Children.Data.Data[ind].pObject);
  return 1;
}
