BOOL __thiscall Scaleform::GFx::AS3::Value::IsInt(Scaleform::GFx::AS3::Value *this)
{
  unsigned int v1; // eax

  v1 = this->Flags & 0x1F;
  return v1 == 2 || v1 == 3;
}
