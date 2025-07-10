void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::SetNamespace(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  unsigned int Size; // ebx
  unsigned int i; // esi
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *pObject; // ecx

  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->Ns,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)ns);
  Size = this->Attrs.Data.Size;
  for ( i = 0; i < Size; ++i )
  {
    pObject = this->Attrs.Data.Data[i].pObject;
    pObject->SetNamespace(pObject, ns);
  }
}
