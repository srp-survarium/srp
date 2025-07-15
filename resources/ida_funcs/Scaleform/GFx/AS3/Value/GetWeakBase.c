Scaleform::GFx::AS3::GASRefCountBase *__thiscall Scaleform::GFx::AS3::Value::GetWeakBase(
        Scaleform::GFx::AS3::Value *this)
{
  Scaleform::GFx::AS3::GASRefCountBase *result; // eax

  result = 0;
  switch ( this->Flags & 0x1F )
  {
    case 0xBu:
    case 0xCu:
    case 0xDu:
    case 0xEu:
    case 0xFu:
      result = this->value.VS._1.VObj;
      break;
    case 0x10u:
    case 0x11u:
      result = this->value.VS._2.VObj;
      break;
    default:
      return result;
  }
  return result;
}
