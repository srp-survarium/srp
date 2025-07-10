Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl::XML::GetProperty(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::CheckResult *v5; // eax
  Scaleform::GFx::AS3::Value *v6; // esi
  unsigned int ind; // [esp+4h] [ebp-4h] BYREF

  if ( Scaleform::GFx::AS3::GetVectorInd((Scaleform::GFx::AS3::CheckResult *)&prop_name, prop_name, &ind)->Result )
  {
    if ( !ind )
    {
      Scaleform::GFx::AS3::Value::Assign(value, this);
      v5 = result;
      result->Result = 1;
      return v5;
    }
    v6 = value;
    if ( (value->Flags & 0x1F) > 9 )
    {
      if ( (value->Flags & 0x200) != 0 )
      {
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(value);
        v5 = result;
        v6->Flags &= 0xFFFFFFE0;
        result->Result = 0;
        return v5;
      }
      Scaleform::GFx::AS3::Value::ReleaseInternal(value);
    }
    v6->Flags &= 0xFFFFFFE0;
  }
  v5 = result;
  result->Result = 0;
  return v5;
}
