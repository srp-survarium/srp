BOOL __thiscall Scaleform::GFx::AS3::Value::IsCallable(Scaleform::GFx::AS3::Value *this)
{
  unsigned int v1; // eax

  v1 = this->Flags & 0x1F;
  return v1 > 0xF || v1 == 14 || v1 == 5 || v1 == 15 || v1 == 6 || v1 == 7 || v1 == 12 || v1 == 13;
}
