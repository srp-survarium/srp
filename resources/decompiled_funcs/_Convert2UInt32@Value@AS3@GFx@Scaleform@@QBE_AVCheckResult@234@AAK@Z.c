Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Value::Convert2UInt32(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Value::V1U *resulta)
{
  unsigned int v3; // eax
  Scaleform::GFx::AS3::CheckResult *v4; // eax
  long double n; // st7
  Scaleform::GFx::AS3::CheckResult v6; // [esp+Dh] [ebp-13h] BYREF
  Scaleform::GFx::AS3::CheckResult v7; // [esp+Eh] [ebp-12h] BYREF
  Scaleform::GFx::AS3::CheckResult v8; // [esp+Fh] [ebp-11h] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+10h] [ebp-10h] BYREF

  v3 = this->Flags & 0x1F;
  switch ( v3 )
  {
    case 0u:
    case 5u:
    case 0xFu:
      goto $LN14_77;
    case 1u:
      resulta->VInt = this->value.VS._1.VBool;
      v4 = result;
      result->Result = 1;
      return v4;
    case 2u:
      *resulta = this->value.VS._1;
      v4 = result;
      result->Result = 1;
      return v4;
    case 3u:
      v4 = result;
      *resulta = this->value.VS._1;
      result->Result = 1;
      return v4;
    case 4u:
      n = this->value.VNumber;
      goto LABEL_7;
    case 0xAu:
      if ( this->value.VS._1.VInt )
      {
        Scaleform::GFx::AS3::Value::Convert2NumberInline(this, &v6, (long double *)&v.Flags);
        if ( v6.Result )
        {
          n = *(double *)&v.Flags;
LABEL_7:
          resulta->VInt = Scaleform::GFx::AS3::ConvertDouble2SInt32(n);
          v4 = result;
          result->Result = 1;
        }
        else
        {
          v4 = result;
          result->Result = 0;
        }
      }
      else
      {
        v4 = result;
        resulta->VInt = 0;
        result->Result = 1;
      }
      return v4;
    default:
      if ( v3 - 12 > 3 || this->value.VS._1.VInt )
      {
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0;
        if ( Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafe(this, &v7, &v, hintNone)->Result
          && Scaleform::GFx::AS3::Value::Convert2UInt32(&v, &v8, (unsigned int *)resulta)->Result )
        {
          Scaleform::GFx::AS3::Value::~Value(&v);
          v4 = result;
          result->Result = 1;
        }
        else
        {
          result->Result = 0;
          Scaleform::GFx::AS3::Value::~Value(&v);
          return result;
        }
      }
      else
      {
$LN14_77:
        resulta->VInt = 0;
        v4 = result;
        result->Result = 1;
      }
      return v4;
  }
}
