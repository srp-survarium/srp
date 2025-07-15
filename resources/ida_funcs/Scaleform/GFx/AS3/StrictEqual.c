bool __cdecl Scaleform::GFx::AS3::StrictEqual(const Scaleform::GFx::AS3::Value *x, const Scaleform::GFx::AS3::Value *y)
{
  unsigned int v2; // esi
  unsigned int v3; // edx
  unsigned int v4; // edx
  bool result; // al
  Scaleform::GFx::AS3::Value::V1U v7; // ecx
  unsigned int v8; // edx

  v2 = x->Flags & 0x1F;
  v3 = y->Flags & 0x1F;
  if ( v2 == v3 )
    goto LABEL_18;
  if ( v2 - 2 > 2 || v3 - 2 > 2 )
    return 0;
  if ( v2 != 2 && v2 != 3 )
  {
    if ( v2 != 4 )
      goto LABEL_18;
    v8 = v3 - 2;
    if ( v8 )
    {
      if ( v8 != 1 )
        goto LABEL_18;
      return (double)y->value.VS._1.VUInt == x->value.VNumber;
    }
    else
    {
      return (double)y->value.VS._1.VInt == x->value.VNumber;
    }
  }
  v4 = v3 - 2;
  if ( !v4 )
  {
    v7 = y->value.VS._1;
    if ( v7.VInt >= 0 )
      return x->value.VS._1.VInt == v7.VInt;
    return 0;
  }
  if ( v4 == 2 )
    return (double)x->value.VS._1.VUInt == y->value.VNumber;
LABEL_18:
  switch ( v2 )
  {
    case 0u:
      return 1;
    case 1u:
      return x->value.VS._1.VBool == y->value.VS._1.VBool;
    case 2u:
    case 3u:
    case 0xAu:
    case 0xBu:
      return x->value.VS._1.VInt == y->value.VS._1.VInt;
    case 4u:
      return y->value.VNumber == x->value.VNumber;
    case 5u:
      return x->value.VS._1.VInt == y->value.VS._1.VInt;
    case 7u:
      return x->value.VS._1.VInt == y->value.VS._1.VInt && x->value.VS._2.VObj == y->value.VS._2.VObj;
    case 0xCu:
    case 0xDu:
    case 0xEu:
    case 0xFu:
      goto $LN11_68;
    case 0x10u:
    case 0x11u:
      if ( x->value.VS._2.VObj != y->value.VS._2.VObj )
        return 0;
$LN11_68:
      if ( x->value.VS._1.VInt != y->value.VS._1.VInt )
        return 0;
      result = 1;
      break;
    default:
      return 0;
  }
  return result;
}
