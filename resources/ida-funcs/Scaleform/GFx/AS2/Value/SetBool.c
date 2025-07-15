void __thiscall Scaleform::GFx::AS2::Value::SetBool(Scaleform::GFx::AS2::Value *this, bool val)
{
  Scaleform::GFx::AS2::Value::DropRefs(this);
  this->T.Type = 2;
  this->V.BooleanValue = val;
}
