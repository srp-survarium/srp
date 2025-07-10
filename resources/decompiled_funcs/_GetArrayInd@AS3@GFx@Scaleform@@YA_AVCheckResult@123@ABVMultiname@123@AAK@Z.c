Scaleform::GFx::AS3::CheckResult *__cdecl Scaleform::GFx::AS3::GetArrayInd(
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Value::V1U *ind)
{
  unsigned int v3; // eax
  Scaleform::GFx::AS3::CheckResult *v4; // eax

  v3 = prop_name->Name.Flags & 0x1F;
  if ( v3 == 10 )
  {
    result->Result = Scaleform::GFx::AS3::GetArrayInd(
                       (Scaleform::GFx::AS3::CheckResult *)&prop_name,
                       prop_name->Name.value.VS._1.VStr,
                       (unsigned int *)ind)->Result;
    return result;
  }
  else if ( v3 - 2 > 2 )
  {
    v4 = result;
    result->Result = 0;
  }
  else
  {
    result->Result = Scaleform::GFx::AS3::Value::Convert2UInt32(
                       &prop_name->Name,
                       (Scaleform::GFx::AS3::CheckResult *)&prop_name,
                       ind)->Result;
    return result;
  }
  return v4;
}
