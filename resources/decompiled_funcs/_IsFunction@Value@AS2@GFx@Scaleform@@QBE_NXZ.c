BOOL __thiscall Scaleform::GFx::AS2::Value::IsFunction(Scaleform::GFx::AS2::Value *this)
{
  return this->T.Type == 8 || this->T.Type == 11;
}
