bool __thiscall Scaleform::GFx::AS3::Value::Convert2Boolean(Scaleform::GFx::AS3::Value *this)
{
  unsigned int v2; // ecx
  bool result; // al
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  double VNumber; // [esp+Ch] [ebp-8h]

  v2 = this->Flags & 0x1F;
  result = 0;
  switch ( v2 )
  {
    case 0u:
    case 0xBu:
      goto $LN18_45;
    case 1u:
      return this->value.VS._1.VBool;
    case 2u:
    case 3u:
      return this->value.VS._1.VInt != 0;
    case 4u:
      VNumber = this->value.VNumber;
      if ( ((HIDWORD(VNumber) & 0x7FF00000) != 0x7FF00000
         || !((unsigned int)&loc_FFFFF & HIDWORD(VNumber) | LODWORD(VNumber)))
        && !Scaleform::GFx::NumberUtil::IsPOSITIVE_ZERO(this->value.VNumber)
        && !Scaleform::GFx::NumberUtil::IsNEGATIVE_ZERO(this->value.VNumber) )
      {
        goto $LN2_80;
      }
      result = 0;
      break;
    case 5u:
    case 7u:
    case 0x10u:
    case 0x11u:
      goto $LN2_80;
    case 0xAu:
      v4 = this->value.VS._1;
      if ( !v4.VInt )
        goto $LN18_45;
      result = *(_DWORD *)(v4.VInt + 20) != 0;
      break;
    case 0xCu:
    case 0xDu:
    case 0xEu:
    case 0xFu:
      if ( v2 - 12 > 3 || this->value.VS._1.VInt )
$LN2_80:
        result = 1;
      else
$LN18_45:
        result = 0;
      break;
    default:
      return result;
  }
  return result;
}
