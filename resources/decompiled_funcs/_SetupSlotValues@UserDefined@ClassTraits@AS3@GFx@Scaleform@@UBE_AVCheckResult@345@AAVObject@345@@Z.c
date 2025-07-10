Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::ClassTraits::UserDefined::SetupSlotValues(
        Scaleform::GFx::AS3::ClassTraits::UserDefined *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Object *for_obj)
{
  Scaleform::GFx::AS3::Traits::SetupSlotValues(this, result, this->File.pObject, &this->class_info->stat_info, for_obj);
  return result;
}
