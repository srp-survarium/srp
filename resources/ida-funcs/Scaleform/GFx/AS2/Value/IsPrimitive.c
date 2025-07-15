BOOL __thiscall Scaleform::GFx::AS2::Value::IsPrimitive(Scaleform::GFx::AS2::Value *this)
{
  unsigned __int8 Type; // al

  Type = this->T.Type;
  return this->T.Type == 5 || Type == 2 || Type == 1 || Type == 3 || Type == 4;
}
