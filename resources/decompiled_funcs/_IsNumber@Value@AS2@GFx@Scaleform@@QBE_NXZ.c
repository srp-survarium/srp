BOOL __thiscall Scaleform::GFx::AS2::Value::IsNumber(Scaleform::GFx::AS2::Value *this)
{
  return this->T.Type == 3 || this->T.Type == 4;
}
