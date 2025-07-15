void __thiscall Scaleform::GFx::AS2::Value::SetInt(Scaleform::GFx::AS2::Value *this, unsigned int val)
{
  if ( this->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(this);
  this->NV.Int32Value = val;
  this->T.Type = 4;
}
