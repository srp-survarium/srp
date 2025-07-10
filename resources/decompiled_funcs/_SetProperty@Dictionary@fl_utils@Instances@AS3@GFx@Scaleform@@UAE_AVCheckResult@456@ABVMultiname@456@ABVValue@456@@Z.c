Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::SetProperty(
        Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Multiname *prop_name,
        const Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::CheckResult *v4; // eax

  this->AddDynamicSlotValuePair(this, &prop_name->Name, value, aNone);
  v4 = result;
  result->Result = 1;
  return v4;
}
