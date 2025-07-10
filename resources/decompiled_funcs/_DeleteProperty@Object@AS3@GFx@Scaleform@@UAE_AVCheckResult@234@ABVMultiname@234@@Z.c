Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Object::DeleteProperty(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Multiname *prop_name)
{
  Scaleform::GFx::AS3::CheckResult *v3; // eax

  if ( (this->pTraits.pObject->Flags & 2) != 0 )
  {
    Scaleform::GFx::AS3::Object::DeleteDynamicSlotValuePair(this, result, prop_name);
    return result;
  }
  else
  {
    v3 = result;
    result->Result = 0;
  }
  return v3;
}
