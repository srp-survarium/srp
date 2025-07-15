void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::AppendChild(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *child)
{
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2,Scaleform::ArrayDefaultPolicy> *p_Children; // esi
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // eax

  p_Children = &this->Children;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Children,
    &this->Children,
    this->Children.Data.Size + 1);
  if ( &p_Children->Data.Data[p_Children->Data.Size] != (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)4 )
  {
    pObject = child->pObject;
    p_Children->Data.Data[p_Children->Data.Size - 1] = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>)child->pObject;
    if ( pObject )
      pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  }
}


Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::AppendChild(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Value *child)
{
  ((void (__stdcall *)(Scaleform::GFx::AS3::CheckResult *, unsigned int, const Scaleform::GFx::AS3::Value *))this->InsertChildAt)(
    result,
    this->Children.Data.Size,
    child);
  return result;
}
