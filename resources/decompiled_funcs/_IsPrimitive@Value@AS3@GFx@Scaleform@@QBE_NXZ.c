BOOL __thiscall Scaleform::GFx::AS3::Value::IsPrimitive(Scaleform::GFx::AS3::Value *this)
{
  return (this->Flags & 0x1F) < 5 || (this->Flags & 0x1F) == 0xA;
}
