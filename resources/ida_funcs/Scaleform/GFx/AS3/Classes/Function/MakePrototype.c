Scaleform::Pickable<Scaleform::GFx::AS3::Object> *__thiscall Scaleform::GFx::AS3::Classes::Function::MakePrototype(
        Scaleform::GFx::AS3::Classes::Function *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v2; // esi
  Scaleform::GFx::AS3::Instances::FunctionBase *v3; // eax
  Scaleform::GFx::AS3::Object *v4; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Object> *v5; // eax

  v2 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject[1].__vftable;
  v3 = (Scaleform::GFx::AS3::Instances::FunctionBase *)Scaleform::GFx::AS3::Traits::Alloc(v2);
  if ( v3 )
  {
    Scaleform::GFx::AS3::Instances::FunctionBase::FunctionBase(v3, v2);
    result->pV = v4;
    return result;
  }
  else
  {
    v5 = result;
    result->pV = 0;
  }
  return v5;
}
