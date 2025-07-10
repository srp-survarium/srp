Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::InstanceTraits::UserDefined::PreInit(
        Scaleform::GFx::AS3::InstanceTraits::UserDefined *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Value *_this)
{
  this->SetupSlotValues(this, result, (Scaleform::GFx::AS3::Object *)_this->value.VS._1.VInt);
  return result;
}
