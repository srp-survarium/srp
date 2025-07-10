void __thiscall Scaleform::GFx::AS2::Value::SetNumber(Scaleform::GFx::AS2::Value *this, long double val)
{
  if ( this->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(this);
  this->T.Type = 3;
  this->NV.NumberValue = val;
}
