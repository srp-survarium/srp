bool __thiscall Scaleform::GFx::AS3::ClassTraits::Function::CoerceValue(
        Scaleform::GFx::AS3::ClassTraits::Function *this,
        const Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::Value *result)
{
  bool v3; // al
  Scaleform::GFx::AS3::Value::V1U v4; // edx
  int v5; // edx

  switch ( value->Flags & 0x1F )
  {
    case 5u:
    case 7u:
    case 0xEu:
    case 0xFu:
    case 0x10u:
    case 0x11u:
      Scaleform::GFx::AS3::Value::Assign(result, value);
      v3 = 1;
      break;
    case 0xCu:
      v4 = value->value.VS._1;
      if ( !v4.VInt )
        goto LABEL_7;
      v5 = *(_DWORD *)(v4.VInt + 20);
      if ( *(_DWORD *)(v5 + 60) != 9 || (*(_DWORD *)(v5 + 56) & 0x20) != 0 )
        goto LABEL_7;
      Scaleform::GFx::AS3::Value::operator=(result, value);
      v3 = 1;
      break;
    default:
LABEL_7:
      v3 = Scaleform::GFx::AS3::ClassTraits::Traits::CoerceValue(this, value, result);
      break;
  }
  return v3;
}
