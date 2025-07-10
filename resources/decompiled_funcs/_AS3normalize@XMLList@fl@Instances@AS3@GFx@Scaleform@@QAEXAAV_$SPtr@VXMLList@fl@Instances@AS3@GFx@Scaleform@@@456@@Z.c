void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3normalize(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  unsigned int Size; // ebx
  unsigned int i; // esi
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // ecx

  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)result,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
  Size = this->List.Data.Size;
  for ( i = 0; i < Size; ++i )
  {
    pObject = this->List.Data.Data[i].pObject;
    pObject->Normalize(pObject);
  }
}
