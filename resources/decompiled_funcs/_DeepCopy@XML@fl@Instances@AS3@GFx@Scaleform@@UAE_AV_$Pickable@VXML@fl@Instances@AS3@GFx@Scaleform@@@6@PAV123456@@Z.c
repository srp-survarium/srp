Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *__thiscall Scaleform::GFx::AS3::Instances::fl::XML::DeepCopy(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *result,
        Scaleform::GFx::AS3::Instances::fl::XML *parent)
{
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstance(
    (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)this->pTraits.pObject,
    result,
    (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject,
    &this->Text,
    parent);
  return result;
}
