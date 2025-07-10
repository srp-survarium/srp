Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLText::DeepCopy(
        Scaleform::GFx::AS3::Instances::fl::XMLText *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *result,
        Scaleform::GFx::AS3::Instances::fl::XML *parent)
{
  Scaleform::GFx::AS3::Instances::fl::XMLText *pV; // ecx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *v4; // eax

  pV = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(
         (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)this->pTraits.pObject,
         (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> *)&parent,
         (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject,
         &this->Text,
         parent)->pV;
  v4 = result;
  result->pV = pV;
  return v4;
}
