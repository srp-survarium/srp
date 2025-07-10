Scaleform::Pickable<Scaleform::GFx::AS3::Object> *__thiscall Scaleform::GFx::AS3::Classes::fl::RegExp::MakePrototype(
        Scaleform::GFx::AS3::Classes::fl::RegExp *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::Instances::fl::RegExp *pV; // edx
  Scaleform::Pickable<Scaleform::GFx::AS3::Object> *v3; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::RegExp> v4; // [esp+0h] [ebp-4h] BYREF

  v4.pV = (Scaleform::GFx::AS3::Instances::fl::RegExp *)this;
  pV = Scaleform::GFx::AS3::InstanceTraits::fl::RegExp::MakeInstance(
         &v4,
         (Scaleform::GFx::AS3::InstanceTraits::fl::RegExp *)this->pTraits.pObject[1].__vftable)->pV;
  v3 = result;
  result->pV = pV;
  return v3;
}
