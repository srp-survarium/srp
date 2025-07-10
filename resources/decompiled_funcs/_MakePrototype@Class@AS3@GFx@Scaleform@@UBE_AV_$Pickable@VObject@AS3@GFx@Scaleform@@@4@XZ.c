Scaleform::Pickable<Scaleform::GFx::AS3::Object> *__thiscall Scaleform::GFx::AS3::Class::MakePrototype(
        Scaleform::GFx::AS3::Class *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::Instances::fl::Object *pV; // ecx
  Scaleform::Pickable<Scaleform::GFx::AS3::Object> *v3; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> v4; // [esp+0h] [ebp-4h] BYREF

  v4.pV = (Scaleform::GFx::AS3::Instances::fl::Object *)this;
  pV = Scaleform::GFx::AS3::VM::MakeObject(this->pTraits.pObject->pVM, &v4)->pV;
  v3 = result;
  result->pV = pV;
  return v3;
}
