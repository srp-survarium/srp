Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLAttr::GetQName(
        Scaleform::GFx::AS3::Instances::fl::XMLAttr *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *result)
{
  Scaleform::GFx::AS3::Instances::fl::QName *pV; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *v3; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::QName *pObject; // [esp-Ch] [ebp-10h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::QName> v5; // [esp+0h] [ebp-4h] BYREF

  v5.pV = (Scaleform::GFx::AS3::Instances::fl::QName *)this;
  pObject = (Scaleform::GFx::AS3::InstanceTraits::fl::QName *)this->pTraits.pObject->pVM->TraitsQName.pObject->ITraits.pObject;
  pV = Scaleform::GFx::AS3::InstanceTraits::fl::QName::MakeInstance(
         pObject,
         &v5,
         pObject,
         &this->Text,
         this->Ns.pObject)->pV;
  v3 = result;
  result->pObject = pV;
  return v3;
}
