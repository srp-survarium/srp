BOOL __thiscall Scaleform::GFx::AS3::Value::IsNullOrUndefined(Scaleform::GFx::AS3::Value *this)
{
  return (this->Flags & 0x1F) == 0 || (this->Flags & 0x1F) - 12 <= 3 && !this->value.VS._1.VInt;
}
