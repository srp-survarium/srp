void __thiscall Scaleform::GFx::AS2::Value::SetNull(Scaleform::GFx::AS2::Value *this)
{
  Scaleform::GFx::AS2::Value::DropRefs(this);
  this->T.Type = 1;
}
