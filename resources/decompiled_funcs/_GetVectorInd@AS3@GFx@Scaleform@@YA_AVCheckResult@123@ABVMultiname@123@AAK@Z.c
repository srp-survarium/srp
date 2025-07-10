Scaleform::GFx::AS3::CheckResult *__cdecl Scaleform::GFx::AS3::GetVectorInd(
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Value::V1U *ind)
{
  bool v3; // bl
  Scaleform::GFx::AS3::CheckResult *v4; // eax
  Scaleform::GFx::AS3::Value::V1U v5; // eax
  double X; // st7
  Scaleform::GFx::AS3::Value::V1U *v7; // edx
  double num; // [esp+10h] [ebp-10h]
  double n; // [esp+18h] [ebp-8h] BYREF

  switch ( prop_name->Name.Flags & 0x1F )
  {
    case 2u:
      v5 = prop_name->Name.value.VS._1;
      if ( v5.VInt < 0 )
        goto LABEL_10;
      *ind = v5;
      v4 = result;
      result->Result = 1;
      break;
    case 3u:
      *ind = prop_name->Name.value.VS._1;
      v4 = result;
      result->Result = 1;
      break;
    case 4u:
      X = prop_name->Name.value.VNumber;
      num = X;
      if ( X < 0.0 || modf(X, &n) != 0.0 || num > 4294967295.0 )
        goto LABEL_10;
      v7 = ind;
      v4 = result;
      result->Result = 1;
      v7->VInt = (__int64)num;
      break;
    case 0xAu:
      v3 = Scaleform::GFx::AS3::GetVectorInd(
             (Scaleform::GFx::AS3::CheckResult *)&prop_name,
             prop_name->Name.value.VS._1.VStr,
             (unsigned int *)ind)->Result;
      v4 = result;
      result->Result = v3;
      break;
    default:
LABEL_10:
      v4 = result;
      result->Result = 0;
      break;
  }
  return v4;
}
