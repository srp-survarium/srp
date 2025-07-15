Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafe(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Value *resulta,
        Scaleform::GFx::AS3::Value::Hint hint)
{
  unsigned int v5; // eax
  Scaleform::GFx::AS3::CheckResult *v6; // eax

  v5 = this->Flags & 0x1F;
  if ( v5 < 5 || v5 == 10 || v5 - 12 <= 3 && !this->value.VS._1.VInt )
  {
    Scaleform::GFx::AS3::Value::Assign(resulta, this);
LABEL_11:
    v6 = result;
    result->Result = 1;
  }
  else
  {
    switch ( v5 )
    {
      case 5u:
      case 7u:
      case 0x10u:
      case 0x11u:
        Scaleform::GFx::AS3::Value::SetNumber(resulta, 0.0);
        v6 = result;
        result->Result = 1;
        break;
      case 0xBu:
        Scaleform::GFx::AS3::Value::operator=(resulta, (const Scaleform::GFx::ASString *)(this->value.VS._1.VInt + 28));
        v6 = result;
        result->Result = 1;
        break;
      default:
        Scaleform::GFx::AS3::Object::GetDefaultValueUnsafe(this->value.VS._1.VObj, resulta, hint);
        if ( !*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this->value.VS._1.VInt + 20) + 64) + 96) )
          goto LABEL_11;
        v6 = result;
        result->Result = 0;
        break;
    }
  }
  return v6;
}
