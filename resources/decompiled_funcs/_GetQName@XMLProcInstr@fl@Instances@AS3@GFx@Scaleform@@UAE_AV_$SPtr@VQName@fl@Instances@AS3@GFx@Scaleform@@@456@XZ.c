Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLProcInstr::GetQName(
        Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *result)
{
  Scaleform::GFx::AS3::Instances::fl::QName *pV; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *v3; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::QName> v4; // [esp+0h] [ebp-4h] BYREF

  v4.pV = (Scaleform::GFx::AS3::Instances::fl::QName *)this;
  pV = Scaleform::GFx::AS3::InstanceTraits::fl::QName::MakeInstance(
         (Scaleform::GFx::AS3::InstanceTraits::fl::QName *)this->pTraits.pObject->pVM->TraitsQName.pObject->ITraits.pObject,
         &v4,
         this->pTraits.pObject->pVM->TraitsQName.pObject->ITraits.pObject,
         &this->Text,
         this->pTraits.pObject->pVM->PublicNamespace.pObject)->pV;
  v3 = result;
  result->pObject = pV;
  return v3;
}
