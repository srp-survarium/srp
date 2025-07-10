BOOL __thiscall Scaleform::GFx::AS2::Value::IsUndefined(Scaleform::GFx::AS2::Value *this)
{
  return !this->T.Type || this->T.Type == 10;
}
