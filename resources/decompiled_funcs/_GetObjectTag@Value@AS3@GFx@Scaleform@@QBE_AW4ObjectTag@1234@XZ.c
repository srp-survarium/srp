Scaleform::GFx::AS3::Value::ObjectTag __thiscall Scaleform::GFx::AS3::Value::GetObjectTag(
        Scaleform::GFx::AS3::Value *this)
{
  Scaleform::GFx::AS3::Value::ObjectTag result; // eax

  switch ( this->Flags & 0x1F )
  {
    case 0xBu:
      result = otNamespace;
      break;
    case 0xCu:
      result = otObject;
      break;
    case 0xDu:
      result = otClass;
      break;
    case 0xEu:
      result = otFunction;
      break;
    default:
      result = otInvalid;
      break;
  }
  return result;
}
