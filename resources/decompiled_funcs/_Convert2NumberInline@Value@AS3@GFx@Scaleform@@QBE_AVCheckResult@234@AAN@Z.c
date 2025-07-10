Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Value::Convert2NumberInline(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::CheckResult *result,
        long double *resulta)
{
  Scaleform::GFx::AS3::CheckResult *v3; // eax
  double v4; // st7
  double v5; // st7

  switch ( this->Flags & 0x1F )
  {
    case 0u:
      v4 = Scaleform::GFx::NumberUtil::NaN();
      v3 = result;
      *resulta = v4;
      result->Result = 1;
      break;
    case 1u:
      if ( this->value.VS._1.VBool )
      {
        v3 = result;
        *resulta = 1.0;
      }
      else
      {
        v5 = Scaleform::GFx::NumberUtil::POSITIVE_ZERO();
        v3 = result;
        *resulta = v5;
      }
      result->Result = 1;
      break;
    case 2u:
      *resulta = (double)this->value.VS._1.VInt;
      v3 = result;
      result->Result = 1;
      break;
    case 3u:
      v3 = result;
      *resulta = (double)this->value.VS._1.VUInt;
      result->Result = 1;
      break;
    case 4u:
      *resulta = this->value.VNumber;
      v3 = result;
      result->Result = 1;
      break;
    default:
      Scaleform::GFx::AS3::Value::Convert2NumberInternal(
        this,
        result,
        resulta,
        (Scaleform::GFx::AS3::Value::KindType)(this->Flags & 0x1F));
      v3 = result;
      break;
  }
  return v3;
}
