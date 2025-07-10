Scaleform::GFx::AS3::CheckResult *__cdecl Scaleform::GFx::AS3::GetVectorInd(
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::ASStringNode *sn,
        unsigned int *ind)
{
  long double v3; // st7
  Scaleform::GFx::AS3::CheckResult *v4; // eax
  Scaleform::GFx::AS3::CheckResult v5[2]; // [esp+6h] [ebp-Ah] BYREF
  double num; // [esp+8h] [ebp-8h] BYREF

  if ( Scaleform::GFx::AS3::GetStrNumber(v5, sn, &num)->Result && (v3 = num, num <= 4294967295.0) )
  {
    *(_QWORD *)&num = (__int64)num;
    *ind = (__int64)v3;
    v4 = result;
    result->Result = 1;
  }
  else
  {
    v4 = result;
    result->Result = 0;
  }
  return v4;
}
