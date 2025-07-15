Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLComment::DeepCopy(
        Scaleform::GFx::AS3::Instances::fl::XMLComment *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *result,
        Scaleform::GFx::AS3::Instances::fl::XML *parent)
{
  Scaleform::GFx::AS3::Instances::fl::XMLComment *pV; // ecx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *v4; // eax

  pV = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceComment(
         (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)this->pTraits.pObject,
         (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLComment> *)&parent,
         (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject,
         &this->Text,
         parent)->pV;
  v4 = result;
  result->pV = pV;
  return v4;
}
