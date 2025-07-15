void __thiscall Scaleform::GFx::Value::~Value(Scaleform::GFx::Value *this)
{
  if ( (this->Type & 0x40) != 0 )
    Scaleform::GFx::Value::ReleaseManagedValue(this);
  this->Type = VT_Undefined;
}
